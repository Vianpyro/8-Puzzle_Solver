#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "node.h"

int main() {
    srand(time(NULL));  // Seed the random number generator

    Puzzle p = create_root_puzzle();
    Node root = {NULL, &p, NONE, 0};

    // Print root puzzle
    print_puzzle(root.state);
    printf("\n");

    // Create root node and its children and print them
    int num_children;
    Node **children = generate_children(&root, &num_children);

    for (int i = 0; i < num_children; i++) {
        print_puzzle(children[i]->state);
        printf("\n");
    }

    return 0;
}
