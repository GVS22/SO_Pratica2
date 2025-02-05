#ifndef PCB_H
#define PCB_H

#include <sys/time.h>

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
    int remaining_time; // Tempo restante para o quantum
    int arrival_time;   // Tempo de chegada ao sistema
    int cache_id;       // ID da cache para processos similares
    double total_execution_time; // Tempo total medido para execução
} PCB;

PCB* create_pcb(int id, ProcessState state, int priority, int runtime, int cache_id);
void destroy_pcb(PCB* pcb);

#endif // PCB_H
