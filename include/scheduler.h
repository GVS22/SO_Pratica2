#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "queue.h"

typedef enum {
    FCFS,        // First Come, First Served
    ROUND_ROBIN  // Round Robin
} SchedulingPolicy;

typedef struct Scheduler {
    SchedulingPolicy policy;
    int time_slice;
} Scheduler;

Scheduler* create_scheduler(SchedulingPolicy policy, int time_slice);
void schedule_processes(Queue* ready_queue, SchedulingPolicy policy);
void destroy_scheduler(Scheduler* scheduler);

#endif // SCHEDULER_H
