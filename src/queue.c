#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* create_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        perror("Erro ao criar fila");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, PCB* process) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->process = process;
    new_node->next = NULL;

    if (queue->rear) {
        queue->rear->next = new_node;
    } else {
        queue->front = new_node;
    }
    queue->rear = new_node;
}

PCB* dequeue(Queue* queue) {
    if (!queue->front) return NULL;
    Node* temp = queue->front;
    PCB* process = temp->process;
    queue->front = temp->next;
    if (!queue->front) queue->rear = NULL;
    free(temp);
    return process;
}

int is_empty(Queue* queue) {
    return queue->front == NULL;
}

void destroy_queue(Queue* queue) {
    while (!is_empty(queue)) {
        free(dequeue(queue));
    }
    free(queue);
}
