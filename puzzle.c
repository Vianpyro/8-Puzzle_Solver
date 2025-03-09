#include "puzzle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two Puzzle boards
int compare_puzzles(const Puzzle *a, const Puzzle *b) {
    return memcmp(a->board, b->board, sizeof(int) * PUZZLE_DIMENSION) == 0;
}

Puzzle create_puzzle(const char *puzzle_string) {
    Puzzle p;
    p.blank_index = 0;

    if (strlen(puzzle_string) == PUZZLE_DIMENSION) {
        for (int i = 0; i < PUZZLE_DIMENSION; i++) {
            p.board[i] = puzzle_string[i] - '0';
            if (p.board[i] == 0) {
                p.blank_index = i;
            }
        }
    } else {
        for (int i = 0; i < PUZZLE_DIMENSION; i++) {
            p.board[i] = i;
        }
    }

    return p;
}

Puzzle create_goal_puzzle(const char *type) {
    Puzzle p;

    if (strcmp(type, "spiral") == 0) {
        p = (Puzzle){4, {1, 2, 3, 8, 0, 4, 7, 6, 5}};
    } else {  // Default to inline
        p = (Puzzle){8, {1, 2, 3, 4, 5, 6, 7, 8, 0}};
    }

    return p;
}

Puzzle create_random_puzzle() {
    Puzzle p = create_puzzle("");
    shuffle(&p);
    return p;
}

int get_blank_index(const Puzzle *p) {
    for (int i = 0; i < PUZZLE_DIMENSION; i++)
        if (p->board[i] == 0) return i;

    return -1;
}

int get_inversion_count(const Puzzle puzzle) {
    int inv_count = 0;

    for (int i = 0; i < PUZZLE_DIMENSION - 1; i++)
        for (int j = i + 1; j < PUZZLE_DIMENSION; j++)
            if (puzzle.board[j] && puzzle.board[i] && puzzle.board[i] > puzzle.board[j])
                inv_count++;

    return inv_count;
}

int is_solvable(const Puzzle puzzle) {
    int inversion_count = get_inversion_count(puzzle);
    return (inversion_count % 2 == 0);
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

int move(Puzzle *p, const Direction direction) {
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
            return 0;  // No move made
    }

    if (new_row < 0 || new_row >= PUZZLE_SIZE || new_col < 0 || new_col >= PUZZLE_SIZE) {
        return 0;  // Move is out of bounds
    }

    int new_index = new_row * PUZZLE_SIZE + new_col;
    swap(&p->board[p->blank_index], &p->board[new_index]);
    p->blank_index = new_index;

    return 1;  // Move successful
}

void print_puzzle(const Puzzle *p, int debug) {
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        printf("%d ", p->board[i]);
        if (i % PUZZLE_SIZE == PUZZLE_SIZE - 1) {
            printf("\n");
        }
    }

    if (debug) {
        printf("Blank index: %d\n", p->blank_index);
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
        swap(&p->board[i], &p->board[j]);
    }

    // Update blank index
    p->blank_index = get_blank_index(p);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
