#include "bfs.h"

#include <stdio.h>
#include <stdlib.h>

// Function to solve the puzzle using BFS
Node* bfs_solve(Puzzle* start, Puzzle* goal) {
    Queue* queue = create_queue(100000);
    HashSet visited;         // Declare the HashSet for visited states
    init_hashset(&visited);  // Initialize the HashSet

    // Create the root node
    Node* root = (Node*)malloc(sizeof(Node));
    root->parent = NULL;
    root->state = start;
    root->move = NONE;
    root->cost = 0;

    enqueue(queue, root);
    insert(&visited, start);  // Mark the start state as visited

    while (!is_queue_empty(queue)) {
        Node* current = dequeue(queue);

        if (compare_puzzles(current->state, goal)) {
            // Free the remaining nodes in the queue
            while (!is_queue_empty(queue)) {
                Node* temp = dequeue(queue);
                free(temp);
            }
            free_queue(queue);
            free_hashset(&visited);  // Free the HashSet memory
            return current;          // Found the goal
        }

        // Generate the children nodes of the current node
        int num_children;
        Node** children = generate_children(current, &num_children);

        for (int i = 0; i < num_children; i++) {
            // Check if the child state has been visited
            if (!contains(&visited, children[i]->state)) {
                enqueue(queue, children[i]);           // Enqueue unvisited child
                insert(&visited, children[i]->state);  // Mark as visited
            } else {
                free(children[i]);  // Free memory for already visited child
            }
        }

        // Free memory for children array
        free(children);
    }

    // If the queue is empty and no solution is found
    free_queue(queue);
    free_hashset(&visited);
    return NULL;
}
