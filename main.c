#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "solve/bfs.h"

int main(int argc, char* argv[]) {
    // Command-line arguments
    char* mode = "bfs";  // Default mode

    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--mode") == 0 || strcmp(argv[i], "-m") == 0) {
            mode = argv[++i];
        } else {
            printf("Unknown argument: %s\n", argv[i]);
            return 1;
        }
    }

    // Display the mode
    printf("Mode: %s\n", mode);

    // Initialize the puzzle
    Puzzle start = {0, {0, 2, 3, 4, 5, 6, 7, 1, 8}};
    Puzzle goal = create_goal_puzzle("inline");

    Node* solution = NULL;

    // Call the BFS solver
    if (strcmp(mode, "bfs") == 0) {
        solution = bfs_solve(&start, &goal);
    } else {
        printf("Unknown mode: %s\n", mode);
        return 1;
    }

    if (solution) {
        printf("Solution found!\n");
        Node* current = solution;
        while (current != NULL) {
            print_node(current, 0);
            current = current->parent;
        }
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
