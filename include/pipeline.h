#ifndef PIPELINE_H
#define PIPELINE_H

#include "pcb.h"

// Função para simular a execução do núcleo (pipeline)
void* core_execution(void* arg);

// Função para obter o tempo atual (em segundos)
double get_time();

#endif // PIPELINE_H
