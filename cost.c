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

int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
