#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "pipeline.h"
#include "queue.h"

// Função para obter o timestamp atual em segundos
double current_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + (ts.tv_nsec / 1e9);
}

void* core_execution(void* arg) {
    int core_id = *(int*)arg; // Identificador do núcleo
    free(arg); // Libera a memória alocada para o ID do núcleo

    while (1) {
        PCB* process = dequeue(ready_queue); // Obtém um processo da fila
        if (!process) break; // Sai do loop se não houver mais processos na fila

        printf("Core %d executando processo %d (Prioridade: %d, Tamanho: %dms)\n",
               core_id, process->id, process->priority, process->total_execution_time);

        // Tempo de início do processo
        double start_time = current_time();

        // Simula os estágios do pipeline
        const char* stages[] = {"IF (Instruction Fetch)", 
                                "ID (Instruction Decode)", 
                                "EX (Execute)", 
                                "MEM (Memory Access)", 
                                "WB (Write Back)"};

        for (int i = 0; i < 5; i++) {
            printf("[Processo %d] Estágio: %s\n", process->id, stages[i]);
            usleep(process->total_execution_time * 1000 / 5); // Divide o tempo total por 5 estágios
        }

        // Tempo de finalização do processo
        double end_time = current_time();

        // Calcula o tempo total de execução do processo
        double total_time = end_time - start_time;
        printf("Core %d finalizou o processo %d | Tempo total: %.2fs\n", core_id, process->id, total_time);

        // Atualiza o estado do processo e grava seus tempos
        process->completed = 1;
        process->start_time = start_time;
        process->end_time = end_time;
    }

    return NULL;
}
