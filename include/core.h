#ifndef CORE_H
#define CORE_H

#include "pcb.h"
#include "queue.h"

typedef struct {
    int id;
    PCB* current_process;
} Core;

void* core_execution(void* arg);

#endif
