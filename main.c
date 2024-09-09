#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "solve/bfs.h"

int main() {
    Puzzle start = {7, {1, 2, 3, 4, 5, 6, 7, 0, 8}};
    Puzzle goal = create_goal_puzzle("inline");

    // Appelle la fonction BFS pour résoudre le puzzle
    Node* solution = bfs_solve(&start, &goal);

    if (solution) {
        printf("Solution found!\n");
        Node* current = solution;
        while (current != NULL) {
            print_node(current);
            current = current->parent;
        }
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
