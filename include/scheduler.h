#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef enum {
    ROUND_ROBIN,
    FCFS
} SchedulingPolicy;

typedef struct Scheduler {
    SchedulingPolicy policy;
    int time_slice;
} Scheduler;

Scheduler* create_scheduler(SchedulingPolicy policy, int time_slice);
void destroy_scheduler(Scheduler* scheduler);

#endif // SCHEDULER_H
