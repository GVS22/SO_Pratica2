#ifndef PIPELINE_H
#define PIPELINE_H

#include "pcb.h"

// Declaração da função de execução do núcleo
void* core_execution(void* arg);

// Simulação de um estágio do pipeline
void simulate_pipeline_stage(const char* stage, int process_id, PCB* pcb, int stage_index);

#endif // PIPELINE_H
