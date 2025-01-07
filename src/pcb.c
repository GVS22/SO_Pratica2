#include <stdio.h>
#include <stdlib.h>
#include "pcb.h"

PCB* create_pcb(int id, int priority, int remaining_time) {
    PCB* pcb = (PCB*)malloc(sizeof(PCB));
    if (!pcb) {
        perror("Erro ao criar PCB");
        exit(EXIT_FAILURE);
    }
    pcb->id = id;
    pcb->state = READY;
    pcb->priority = priority;
    pcb->remaining_time = remaining_time;
    pcb->base_address = 0;
    pcb->limit_address = 1024; // Exemplo
    return pcb;
}

void destroy_pcb(PCB* pcb) {
    free(pcb);
}
