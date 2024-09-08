#ifndef QUEUE_H_
#define QUEUE_H_

#include "node.h"

typedef struct Queue {
    Node** data;
    int front;
    int rear;
    int capacity;
} Queue;

int are_puzzles_equal(const Puzzle* p1, const Puzzle* p2);
Queue* create_queue(int capacity);
void free_queue(Queue* queue);
int is_queue_empty(Queue* queue);
void enqueue(Queue* queue, Node* node);
Node* dequeue(Queue* queue);

#endif  // QUEUE_H_
