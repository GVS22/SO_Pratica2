#ifndef QUEUE_H
#define QUEUE_H

#include "pcb.h"

typedef struct Node {
    PCB* process;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* create_queue();
void enqueue(Queue* queue, PCB* process);
PCB* dequeue(Queue* queue);
int is_empty(Queue* queue);
void destroy_queue(Queue* queue);

#endif
