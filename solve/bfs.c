#include "bfs.h"

#include <stdio.h>
#include <stdlib.h>

// Function to solve the puzzle using BFS with detailed logging
Node* bfs_solve(Puzzle* start, Puzzle* goal) {
    Queue* queue = create_queue(357913941);  // Increase if needed for complex puzzles
    HashSet visited;                         // Declare the HashSet for visited states
    init_hashset(&visited);                  // Initialize the HashSet

    // Create the root node
    Node* root = (Node*)malloc(sizeof(Node));
    root->parent = NULL;
    root->state = start;
    root->move = NONE;
    root->cost = 0;

    enqueue(queue, root);
    insert(&visited, start);  // Mark the start state as visited

    int depth = 0;           // Track the depth of the current node
    int nodes_expanded = 0;  // Count of nodes expanded
    int max_queue_size = 0;  // Track maximum queue size

    while (!is_queue_empty(queue)) {
        int current_queue_size = queue->rear - queue->front + 1;
        if (current_queue_size > max_queue_size) {
            max_queue_size = current_queue_size;  // Update maximum queue size
        }

        Node* current = dequeue(queue);

        if (compare_puzzles(current->state, goal)) {
            // Free the remaining nodes in the queue
            while (!is_queue_empty(queue)) {
                Node* temp = dequeue(queue);
                free(temp->state);  // Free the state associated with the node
                free(temp);         // Free the node itself
            }
            free_queue(queue);
            free_hashset(&visited);  // Free the HashSet memory
            printf("Solution found at depth %d after expanding %d nodes.\n", depth, nodes_expanded);
            return current;  // Found the goal
        }

        // Generate the children nodes of the current node
        int num_children;
        Node** children = generate_children(current, &num_children);
        nodes_expanded += num_children;  // Increment nodes expanded

        for (int i = 0; i < num_children; i++) {
            // Calculate cost of the child node
            children[i]->cost += manhattan_cost(children[i]->state, goal);

            // Check if the child state has been visited
            if (!contains(&visited, children[i]->state)) {
                enqueue(queue, children[i]);           // Enqueue unvisited child
                insert(&visited, children[i]->state);  // Mark as visited
            } else {
                free(children[i]->state);  // Free state memory for already visited child
                free(children[i]);         // Free memory for already visited child
            }
        }

        // Free memory for children array
        free(children);

        depth++;  // Increment depth after expanding all children at the current level
    }

    // If the queue is empty and no solution is found
    free_queue(queue);
    free_hashset(&visited);
    printf("No solution found after reaching depth %d and after expanding %d nodes.\n", depth, nodes_expanded);
    return NULL;
}
