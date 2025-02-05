#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

// Note: Não defina a variável global ready_queue aqui; ela está definida em main.c

Queue* create_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        perror("Erro ao criar a fila");
        return NULL;
    }
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

void destroy_queue(Queue* queue) {
    if (queue)
        free(queue);
}

void enqueue(Queue* queue, PCB* process) {
    if (queue->rear == QUEUE_SIZE) {
        printf("Fila cheia\\n");
        return;
    }
    queue->processes[queue->rear++] = process;
}

PCB* dequeue(Queue* queue) {
    if (queue->front >= queue->rear) {
        return NULL;
    }
    return queue->processes[queue->front++];
}
