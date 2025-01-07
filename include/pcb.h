#ifndef PCB_H
#define PCB_H

typedef enum {
    READY,
    BLOCKED,
    RUNNING
} ProcessState;

typedef struct {
    int id;
    ProcessState state;
    int priority;
    int remaining_time;
    int base_address;
    int limit_address;
} PCB;

PCB* create_pcb(int id, int priority, int remaining_time);
void destroy_pcb(PCB* pcb);

#endif
