#include "bfs.h"

#include <stdio.h>
#include <stdlib.h>

// Function to solve the puzzle using BFS
Node* bfs_solve(Puzzle* start, Puzzle* goal) {
    Queue* queue = create_queue(100000);
    Node* root = (Node*)malloc(sizeof(Node));
    root->parent = NULL;
    root->state = start;
    root->move = NONE;
    root->cost = 0;

    enqueue(queue, root);

    while (!is_queue_empty(queue)) {
        Node* current = dequeue(queue);

        if (compare_puzzles(current->state, goal)) {
            // Free the remaining nodes in the queue
            while (!is_queue_empty(queue)) {
                Node* temp = dequeue(queue);
                free(temp);
            }
            free_queue(queue);
            return current;  // Found the goal
        }

        // Create current node's children
        int num_children;
        Node** children = generate_children(current, &num_children);

        for (int i = 0; i < num_children; i++) {
            enqueue(queue, children[i]);
        }

        // Free memory for children array
        free(children);

        // Free the current node
        free(current);
    }

    // If the queue is empty, the goal is not reachable
    free_queue(queue);
    return NULL;
}
