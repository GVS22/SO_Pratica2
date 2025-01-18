#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

// Definição da variável global `ready_queue`
Queue* ready_queue = NULL;

Queue* create_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        perror("Erro ao criar a fila");
        return NULL;
    }
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

void destroy_queue(Queue* queue) {
    if (queue) free(queue);
}

void enqueue(Queue* queue, PCB* process) {
    if (queue->rear == 255) {
        printf("Fila cheia\n");
        return;
    }
    if (queue->front == -1) queue->front = 0;
    queue->processes[++queue->rear] = process;
}

PCB* dequeue(Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        return NULL;
    }
    return queue->processes[queue->front++];
}
