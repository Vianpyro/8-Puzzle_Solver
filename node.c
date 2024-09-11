#include "node.h"

#include <stdio.h>
#include <stdlib.h>

Node *generate_child_node(const Node *parent, const Direction direction) {
    if (!is_valid_move(parent->state, direction)) {
        return NULL;
    }

    Puzzle *new_state = (Puzzle *)malloc(sizeof(Puzzle));
    if (!new_state) return NULL;

    *new_state = *(parent->state);

    move(new_state, direction);

    Node *child = (Node *)malloc(sizeof(Node));
    if (!child) {
        free(new_state);  // Ensure to free new_state if child allocation fails
        return NULL;
    }

    child->parent = (Node *)parent;
    child->state = new_state;
    child->move = direction;
    child->cost = 0;

    return child;
}

Node **generate_children(const Node *parent, int *num_children) {
    Node **children = (Node **)malloc(DIRECTION_COUNT * sizeof(Node *));
    *num_children = 0;

    Direction directions[DIRECTION_COUNT] = {UP, DOWN, LEFT, RIGHT};

    for (int i = 0; i < DIRECTION_COUNT; i++) {
        Node *child = generate_child_node(parent, directions[i]);
        if (child != NULL) {
            children[(*num_children)++] = child;
        } else {
            free(child);  // Ensure to free child if not NULL
        }
    }

    return children;
}

void print_node(const Node *n, int debug) {
    printf("Move: ");
    print_direction(n->move);
    printf("Cost: %d\n", n->cost);
    print_puzzle(n->state, debug);
}
