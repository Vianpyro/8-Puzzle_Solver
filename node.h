#ifndef NODE_H_
#define NODE_H_

#include "direction.h"
#include "puzzle.h"

typedef struct Node {
    struct Node* parent;
    Puzzle* state;
    Direction move;
    int cost;
} Node;

Node* generate_child_node(const Node* parent, const Direction direction);
Node** generate_children(const Node* parent, int* num_children);
void print_node(const Node* n, int debug);

#endif  // NODE_H_
