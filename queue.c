#include "queue.h"

#include <stdlib.h>

int are_puzzles_equal(const Puzzle* p1, const Puzzle* p2) {
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        if (p1->board[i] != p2->board[i]) {
            return 0;
        }
    }
    return 1;
}

Queue* create_queue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (Node**)malloc(capacity * sizeof(Node*));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

void free_queue(Queue* queue) {
    free(queue->data);
    free(queue);
}

int is_queue_empty(Queue* queue) {
    return queue->front > queue->rear;
}

void enqueue(Queue* queue, Node* node) {
    if (queue->rear + 1 < queue->capacity) {
        queue->data[++queue->rear] = node;
    }
}

Node* dequeue(Queue* queue) {
    if (!is_queue_empty(queue)) {
        return queue->data[queue->front++];
    }
    return NULL;
}
