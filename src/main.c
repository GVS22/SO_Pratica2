#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "pcb.h"
#include "queue.h"
#include "core.h"

#define NUM_CORES 2
#define NUM_PROCESSES 4

int main() {
    Queue* ready_queue = create_queue();
    pthread_t cores[NUM_CORES];

    // Cria os processos
    PCB* process1 = create_pcb(1, 1, 5);
    PCB* process2 = create_pcb(2, 2, 3);
    PCB* process3 = create_pcb(3, 3, 8);
    PCB* process4 = create_pcb(4, 1, 2);

    enqueue(ready_queue, process1);
    enqueue(ready_queue, process2);
    enqueue(ready_queue, process3);
    enqueue(ready_queue, process4);

    // Executa os núcleos
    for (int i = 0; i < NUM_CORES; i++) {
        pthread_create(&cores[i], NULL, core_execution, ready_queue);
    }

    for (int i = 0; i < NUM_CORES; i++) {
        pthread_join(cores[i], NULL);
    }

    destroy_queue(ready_queue);
    return 0;
}
