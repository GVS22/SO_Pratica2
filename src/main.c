#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "pcb.h"
#include "queue.h"
#include "scheduler.h"
#include "pipeline.h"
#include "cache.h"

#define NUM_PROCESSES 10
#define NUM_CORES 4
#define TIME_SLICE 2

// Definição da variável global ready_queue (única definição, aqui)
Queue* ready_queue;

PCB* processes[NUM_PROCESSES];
Scheduler* scheduler;

// Função para inicializar os processos.
// Parâmetros:
//   identical_jobs: se verdadeiro, todos os processos terão o mesmo cache_id (jobs idênticos)
//   similar_jobs: se verdadeiro, aproximadamente 70% dos processos compartilharão dados similares (cache_id baseado em i % 3)
void initialize_processes(int identical_jobs, int similar_jobs) {
    for (int i = 0; i < NUM_PROCESSES; i++) {
        int priority = rand() % 5 + 1; // Prioridade entre 1 e 5
        int runtime = rand() % 5 + 2;  // Tempo de execução entre 2 e 6 ciclos
        int cache_id = i;
        if (identical_jobs) {
            cache_id = 1; // Todos os processos compartilham os mesmos dados
        } else if (similar_jobs) {
            cache_id = i % 3; // Aproximadamente 70% dos processos compartilham dados similares
        }
        // Aqui, você pode também definir o start_time como o tempo atual, se desejar calcular tempos relativos:
        processes[i] = create_pcb(i, READY, priority, runtime, cache_id);
        processes[i]->start_time = get_time();  // Inicia a contagem do tempo de cada processo
        enqueue(ready_queue, processes[i]);
    }
}

void initialize_scheduler() {
    scheduler = create_scheduler(ROUND_ROBIN, TIME_SLICE);
}

void print_process_report() {
    printf("\n=== Relatorio Final dos Processos ===\n");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        PCB* process = processes[i];
        printf("Processo %d | Prioridade: %d | Estado Final: %s | Tempo Total: %.2fs\n",
               process->id, process->priority,
               process->completed ? "Concluido" : "Nao Conclu'ido",
               process->total_execution_time);
    }
}

// Função que executa a simulação com base na política de escalonamento, número de cores e cenário de cache.
void run_simulation(SchedulingPolicy policy, int cores, int identical_jobs, int similar_jobs) {
    printf("\n🔹 Rodando Simulacao - %s com %d Core(s) 🔹\n", 
           (policy == FCFS) ? "FCFS" : "Round Robin", cores);

    ready_queue = create_queue();
    initialize_cache();
    initialize_processes(identical_jobs, similar_jobs);
    scheduler = create_scheduler(policy, TIME_SLICE);

    pthread_t core_threads[cores];
    for (int i = 0; i < cores; i++) {
        int* core_id = malloc(sizeof(int));
        *core_id = i;
        pthread_create(&core_threads[i], NULL, core_execution, core_id);
    }

    for (int i = 0; i < cores; i++) {
        pthread_join(core_threads[i], NULL);
    }

    printf("Simulacao Finalizada!\n");
    print_process_report();

    destroy_queue(ready_queue);
    destroy_scheduler(scheduler);
    for (int i = 0; i < NUM_PROCESSES; i++) {
        free(processes[i]);
    }
}

int main() {
    srand(time(NULL));

    // Testes 1: FCFS com 1 core, sem cache otimizada, jobs idênticos e jobs similares
   // run_simulation(FCFS, 1, 0, 0);
   // run_simulation(FCFS, 1, 1, 0);
    //run_simulation(FCFS, 1, 0, 1);

    // Testes 2: Round Robin com 1 core, sem cache otimizada otimizada, jobs idênticos e jobs similares
    run_simulation(ROUND_ROBIN, 1, 0, 0);
   run_simulation(ROUND_ROBIN, 1, 0, 0);
    run_simulation(ROUND_ROBIN, 1, 1, 0);

    // Testes 3: FCFS com 2 cores, sem cache otimizada jobs idênticos e jobs similares
    //run_simulation(FCFS, 2, 0, 0);
    //run_simulation(FCFS, 2, 1, 0);
    //run_simulation(FCFS, 2, 0, 1);

    // Testes 4: Round Robin com 2 cores, sem cache otimizada
    run_simulation(ROUND_ROBIN, 2, 0, 0);
    run_simulation(ROUND_ROBIN, 2, 1, 0);
    run_simulation(ROUND_ROBIN, 2, 0, 1);

    // Teste 5: FCFS com 4 cores 
   // run_simulation(FCFS, 4, 0, 0);
   // run_simulation(FCFS, 4, 1, 0);
   // run_simulation(FCFS, 4, 1, 1);


    return 0;
}
