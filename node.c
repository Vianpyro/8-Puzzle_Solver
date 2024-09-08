#include "node.h"

#include <stdlib.h>  // Include the header file for NULL

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
