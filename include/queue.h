#ifndef QUEUE_H
#define QUEUE_H

#include "pcb.h"

#define QUEUE_SIZE 256

typedef struct Queue {
    PCB* processes[QUEUE_SIZE];
    int front;
    int rear;
} Queue;


extern Queue* ready_queue;

Queue* create_queue();
void destroy_queue(Queue* queue);
void enqueue(Queue* queue, PCB* process);
PCB* dequeue(Queue* queue);

#endif // QUEUE_H
