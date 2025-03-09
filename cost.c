#include "cost.h"

#include <stdlib.h>

void find_coord(Puzzle *puzzle, int value, int *x, int *y) {
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        if (puzzle->board[i] == value) {
            *x = i % PUZZLE_SIZE;
            *y = i / PUZZLE_SIZE;
            return;
        }
    }
}

int manhattan_cost(Puzzle *current, Puzzle *goal) {
    int cost = 0;
    for (int j = 0; j < PUZZLE_DIMENSION; j++) {
        if (current->board[j] != 0) {
            int x1, y1, x2, y2;
            find_coord(current, current->board[j], &x1, &y1);
            find_coord(goal, current->board[j], &x2, &y2);
            cost += abs(x1 - x2) + abs(y1 - y2);
        }
    }
    return cost;
}
