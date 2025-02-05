#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"

Scheduler* create_scheduler(SchedulingPolicy policy, int time_slice) {
    Scheduler* scheduler = (Scheduler*)malloc(sizeof(Scheduler));
    if (!scheduler) {
        perror("Erro ao criar escalonador");
        return NULL;
    }
    scheduler->policy = policy;
    scheduler->time_slice = time_slice;
    return scheduler;
}

void schedule_processes(Queue* ready_queue, SchedulingPolicy policy) {
    if (!ready_queue) return;

    if (policy == ROUND_ROBIN) {
        PCB* process = dequeue(ready_queue);
        if (process) {
            process->remaining_time -= 1;
            if (process->remaining_time > 0) {
                enqueue(ready_queue, process); // Reinsere no final da fila
            }
        }
    } else if (policy == FCFS) {
        // FCFS mantém a fila FIFO sem reordenação
    }
}

void destroy_scheduler(Scheduler* scheduler) {
    if (scheduler)
        free(scheduler);
}
