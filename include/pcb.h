#ifndef PCB_H
#define PCB_H

typedef enum {
    READY,
    RUNNING,
    WAITING,
    TERMINATED
} ProcessState;

typedef struct PCB {
    int id;
    ProcessState state;
    int priority;
    int completed;
    double start_time;
    double end_time;
    double stage_times[5]; 
    double total_execution_time;
} PCB;

PCB* create_pcb(int id, ProcessState state, int priority, int completed, double start_time);
void destroy_pcb(PCB* pcb);

#endif // PCB_H
