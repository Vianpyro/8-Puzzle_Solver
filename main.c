#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "puzzle.h"

int main() {
    Puzzle p;

    // Initialize the board
    p.blank_index = 0;
    for (int i = 0; i < 9; i++) {
        p.board[i] = i;
    }

    // Print the board
    for (int i = 0; i < 9; i++) {
        printf("%d ", p.board[i]);
        if (i % 3 == 2) {
            printf("\n");
        }
    }

    return 0;
}
