#include "puzzle.h"

#include <stdio.h>
#include <stdlib.h>

void print_puzzle(Puzzle p) {
    for (int i = 0; i < 9; i++) {
        printf("%d ", p.board[i]);
        if (i % 3 == 2) {
            printf("\n");
        }
    }
}

void shuffle(Puzzle *p) {
    // Initialize the array with values from 0 to length-1
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        p->board[i] = i;
    }

    // Shuffle the array using the Fisher-Yates algorithm
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        int j = rand() % PUZZLE_DIMENSION;
        int temp = p->board[i];
        p->board[i] = p->board[j];
        p->board[j] = temp;
    }
}
