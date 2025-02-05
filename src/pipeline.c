#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "pipeline.h"
#include "queue.h"
#include "cache.h"

// Retorna o tempo atual em segundos
double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + (tv.tv_usec / 1e6);
}

void* core_execution(void* arg) {
    int core_id = *(int*)arg;
    free(arg);

    while (1) {
        PCB* process = dequeue(ready_queue);
        if (!process) break;

        // Calcula o tempo de espera relativo (a partir do start_time do processo)
        double wait_time = get_time() - process->start_time;

        printf("Core %d executando processo %d (Prioridade: %d)\n", core_id, process->id, process->priority);
        if (is_in_cache(process->cache_id)) {
            printf("Core %d encontrou processo %d na cache! Execucao acelerada.\n", core_id, process->id);
            usleep(20000); 
        } else {
            usleep(50000); 
        }

        update_cache(process->cache_id);

        
        char* stages[] = {"IF (Instruction Fetch)", "ID (Instruction Decode)", "EX (Execute)", "MEM (Memory Access)", "WB (Write Back)"};
        for (int i = 0; i < 5; i++) {
            printf("[Processo %d] Est\\'agio: %s\n", process->id, stages[i]);
            usleep(50000); 
        }

        double execution_time = get_time() - process->start_time;

        printf("Core %d finalizou o processo %d | Tempo Execucao: %.2fs | Tempo de Espera: %.2fs\n", 
               core_id, process->id, execution_time, wait_time);

        process->total_execution_time = execution_time;
        process->completed = 1;
    }

    return NULL;
}
