#include "puzzle.h"

#include <stdio.h>
#include <stdlib.h>

Puzzle create_root_puzzle() {
    Puzzle p;
    p.blank_index = 0;
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        p.board[i] = i;
    }
    shuffle(&p);
    return p;
}

int is_valid_move(const Puzzle *p, const Direction direction) {
    switch (direction) {
        case UP:
            return p->blank_index >= PUZZLE_SIZE;
        case DOWN:
            return p->blank_index < PUZZLE_SIZE * (PUZZLE_SIZE - 1);
        case LEFT:
            return p->blank_index % PUZZLE_SIZE != 0;
        case RIGHT:
            return p->blank_index % PUZZLE_SIZE != PUZZLE_SIZE - 1;
        default:
            return 0;
    }
}

void move(Puzzle *p, const Direction direction) {
    int blank_row = p->blank_index / PUZZLE_SIZE;
    int blank_col = p->blank_index % PUZZLE_SIZE;

    int new_row = blank_row;
    int new_col = blank_col;

    switch (direction) {
        case UP:
            new_row--;
            break;
        case DOWN:
            new_row++;
            break;
        case LEFT:
            new_col--;
            break;
        case RIGHT:
            new_col++;
            break;
        case NONE:
            return;
    }

    if (new_row < 0 || new_row >= PUZZLE_SIZE || new_col < 0 || new_col >= PUZZLE_SIZE) {
        return;
    }

    int new_index = new_row * PUZZLE_SIZE + new_col;
    swap(&p->board[p->blank_index], &p->board[new_index]);
    p->blank_index = new_index;
}

void print_puzzle(const Puzzle *p) {
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        printf("%d ", p->board[i]);
        if (i % PUZZLE_SIZE == PUZZLE_SIZE - 1) {
            printf("\n");
        }
    }
    printf("Blank index: %d\n", p->blank_index);
}

void shuffle(Puzzle *p) {
    // Initialize the array with values from 0 to length-1
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        p->board[i] = i;
    }

    // Shuffle the array using the Fisher-Yates algorithm
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        int j = rand() % PUZZLE_DIMENSION;
        swap(&p->board[i], &p->board[j]);
    }

    // Update blank index
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        if (p->board[i] == 0) {
            p->blank_index = i;
            break;
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
