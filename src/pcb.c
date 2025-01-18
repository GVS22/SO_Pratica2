#include <stdlib.h>
#include "pcb.h"

PCB* create_pcb(int id, ProcessState state, int priority, int completed, double start_time) {
    PCB* pcb = (PCB*)malloc(sizeof(PCB));
    if (!pcb) {
        perror("Erro ao alocar memória para PCB");
        return NULL;
    }
    pcb->id = id;
    pcb->state = state;
    pcb->priority = priority;
    pcb->completed = completed;
    pcb->start_time = start_time;
    pcb->end_time = 0.0;
    for (int i = 0; i < 5; i++) {
        pcb->stage_times[i] = 0.0;
    }
    return pcb;
}

void destroy_pcb(PCB* pcb) {
    if (pcb) free(pcb);
}
