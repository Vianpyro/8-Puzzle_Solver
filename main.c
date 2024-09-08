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
    print_puzzle(p);
    shuffle(&p);
    print_puzzle(p);

    return 0;
}
