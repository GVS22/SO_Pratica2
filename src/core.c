#include <stdio.h>
#include <unistd.h>
#include "core.h"

void* core_execution(void* arg) {
    Queue* ready_queue = (Queue*)arg;

    while (!is_empty(ready_queue)) {
        PCB* process = dequeue(ready_queue);
        if (process) {
            process->state = RUNNING;
            printf("Core executando processo %d\n", process->id);
            sleep(process->remaining_time);
            printf("Processo %d concluído\n", process->id);
            process->state = READY;
            destroy_pcb(process);
        }
    }
    return NULL;
}
