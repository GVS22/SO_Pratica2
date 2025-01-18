#ifndef QUEUE_H
#define QUEUE_H

#include "pcb.h"

typedef struct Queue {
    PCB* processes[256];
    int front;
    int rear;
} Queue;

// Declaração de `ready_queue` como uma variável global externa
extern Queue* ready_queue;

Queue* create_queue();
void destroy_queue(Queue* queue);
void enqueue(Queue* queue, PCB* process);
PCB* dequeue(Queue* queue);

#endif // QUEUE_H
