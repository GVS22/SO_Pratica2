#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "pcb.h"
#include "queue.h"
#include "scheduler.h"
#include "pipeline.h"

#define NUM_PROCESSES 8
#define NUM_CORES 4
#define TIME_SLICE 2

PCB* processes[NUM_PROCESSES];
Scheduler* scheduler;


void initialize_processes() {
    srand(time(NULL)); 

    for (int i = 0; i < NUM_PROCESSES; i++) {
        int random_priority = rand() % 5;         
        int random_time = (rand() % 500) + 100;  // Tempo total aleatório (100ms a 300ms)
        processes[i] = create_pcb(i, READY, random_priority, 0, 0);
        processes[i]->total_execution_time = random_time;

        enqueue(ready_queue, processes[i]);
        printf("Processo %d criado | Prioridade: %d | Tamanho: %dms\n",
               i, random_priority, random_time);
    }
}

// Inicializa o escalonador
void initialize_scheduler() {
    scheduler = create_scheduler(ROUND_ROBIN, TIME_SLICE);
}

// Imprime um relatório final detalhado dos processos
void print_process_report() {
    printf("\n=== Relatório Final dos Processos ===\n");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        PCB* process = processes[i];
        printf("Processo %d | Prioridade: %d | Estado Final: %s | Tempo Total: %.2fs\n",
               process->id, process->priority,
               process->completed ? "Concluído" : "Não Concluído",
               process->end_time - process->start_time);
    }
}

int main() {
    printf("Iniciando Simulador Multicore com Pipeline MIPS\n");

    ready_queue = create_queue(); // Inicializa a fila de prontos
    initialize_processes();
    initialize_scheduler();

    pthread_t core_threads[NUM_CORES];
    for (int i = 0; i < NUM_CORES; i++) {
        int* core_id = malloc(sizeof(int));
        *core_id = i;
        pthread_create(&core_threads[i], NULL, core_execution, core_id);
    }

    for (int i = 0; i < NUM_CORES; i++) {
        pthread_join(core_threads[i], NULL);
    }

    printf("Simulação Finalizada!\n");

    print_process_report(); // Relatório final dos processos

    destroy_queue(ready_queue);
    destroy_scheduler(scheduler);
    for (int i = 0; i < NUM_PROCESSES; i++) {
        free(processes[i]);
    }
    return 0;
}
