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

void destroy_scheduler(Scheduler* scheduler) {
    if (scheduler) free(scheduler);
}
