#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "solve/bfs.h"

int main(int argc, char* argv[]) {
    // Command-line arguments
    char* mode = "bfs";  // Default mode
    char* puzzle = "";

    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--mode") == 0 || strcmp(argv[i], "-m") == 0) {
            mode = argv[++i];
        } else if (strcmp(argv[i], "--puzzle") == 0 || strcmp(argv[i], "-p") == 0) {
            puzzle = argv[++i];
        } else {
            printf("Unknown argument: %s\n", argv[i]);
            return 1;
        }
    }

    // Display the mode
    printf("Mode: %s\n", mode);

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the puzzle
    Puzzle start;

    if (strlen(puzzle) == 9) {
        start = create_puzzle(puzzle);
    } else {
        start = create_random_puzzle();
    }

    print_puzzle(&start, 0);

    // Check if the puzzle is solvable
    if (is_solvable(start)) {
        printf("Solving puzzle...\n");
    } else {
        printf("Puzzle is not solvable\n");
        return 1;
    }

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
