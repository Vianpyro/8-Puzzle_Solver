#ifndef PUZZLE_H_
#define PUZZLE_H_

#include "direction.h"

#define PUZZLE_SIZE 3
#define PUZZLE_DIMENSION (PUZZLE_SIZE * PUZZLE_SIZE)

typedef struct Puzzle {
    int blank_index;
    int board[9];
} Puzzle;

int are_puzzles_equal(const Puzzle *p1, const Puzzle *p2);
Puzzle create_puzzle();
Puzzle create_goal_puzzle(const char *type);
Puzzle create_root_puzzle();
int is_valid_move(const Puzzle *p, const Direction direction);
void move(Puzzle *p, const Direction direction);
void print_puzzle(const Puzzle *p);
void shuffle(Puzzle *p);
void swap(int *a, int *b);

#endif  // PUZZLE_H_
