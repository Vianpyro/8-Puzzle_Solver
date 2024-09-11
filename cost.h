#ifndef COST_H_
#define COST_H_

#include "puzzle.h"

void find_coord(Puzzle *puzzle, int value, int *x, int *y);
int manhattan_cost(Puzzle *current, Puzzle *goal);

#endif  // COST_H_
