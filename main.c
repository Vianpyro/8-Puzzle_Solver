#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "node.h"

int main() {
    srand(time(NULL));  // Seed the random number generator

    Puzzle p;

    // Initialize the board
    p.blank_index = 0;
    for (int i = 0; i < 9; i++) {
        p.board[i] = i;
    }

    // Shuffle and print the board
    shuffle(&p);
    print_puzzle(&p);
    printf("\n");

    // Create root node and its children and print them
    Node root = {NULL, &p, {UP, DOWN, LEFT, RIGHT}, 0};
    int num_children;
    Node **children = generate_children(&root, &num_children);

    for (int i = 0; i < num_children; i++) {
        print_puzzle(children[i]->state);
        printf("\n");
    }

    return 0;
}
