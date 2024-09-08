#include "node.h"

#include <stdio.h>
#include <stdlib.h>

Node *generate_child_node(const Node *parent, Direction direction) {
    if (!is_valid_move(parent->state, direction)) {
        return NULL;
    }

    Puzzle *new_state = (Puzzle *)malloc(sizeof(Puzzle));
    if (!new_state) return NULL;

    *new_state = *(parent->state);

    move(new_state, direction);

    Node *child = (Node *)malloc(sizeof(Node));
    if (!child) {
        free(new_state);
        return NULL;
    }

    child->parent = (Node *)parent;
    child->state = new_state;
    child->move = direction;
    child->cost = parent->cost;

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
        }
    }

    return children;
}

void print_node(Node *n) {
    printf("Move: ");
    switch (n->move) {
        case UP:
            printf("UP\n");
            break;
        case DOWN:
            printf("DOWN\n");
            break;
        case LEFT:
            printf("LEFT\n");
            break;
        case RIGHT:
            printf("RIGHT\n");
            break;
        case NONE:
            printf("NONE\n");
            break;
    }
    printf("Cost: %d\n", n->cost);
    print_puzzle(n->state);
}
