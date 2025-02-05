#include <stdlib.h>
#include <stdio.h>
#include "pcb.h"

PCB* create_pcb(int id, ProcessState state, int priority, int runtime, int cache_id) {
    PCB* pcb = (PCB*)malloc(sizeof(PCB));
    if (!pcb) {
        perror("Erro ao alocar memoria para PCB");
        return NULL;
    }
    pcb->id = id;
    pcb->state = state;
    pcb->priority = priority;
    pcb->completed = 0;
    pcb->start_time = 0.0;
    pcb->end_time = 0.0;
    pcb->remaining_time = runtime;
    pcb->arrival_time = 0; // Pode ser atualizado conforme necessário
    pcb->cache_id = cache_id;
    pcb->total_execution_time = 0.0;
    return pcb;
}

void destroy_pcb(PCB* pcb) {
    if (pcb)
        free(pcb);
}
