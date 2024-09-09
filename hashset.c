#include "hashset.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hash function for Puzzle (simple but can be improved)
unsigned int hash_function(const Puzzle* puzzle) {
    unsigned int hash = 0;
    for (int i = 0; i < PUZZLE_DIMENSION; i++) {
        hash = hash * 31 + puzzle->board[i];  // Using a prime multiplier
    }
    return hash % TABLE_SIZE;
}

// Initialize HashSet
void init_hashset(HashSet* set) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        set->table[i] = NULL;
    }
}

// Insert a Puzzle into the HashSet
void insert(HashSet* set, const Puzzle* puzzle) {
    unsigned int index = hash_function(puzzle);
    HashNode* current = set->table[index];

    // Check if the Puzzle already exists
    while (current != NULL) {
        if (compare_puzzles(&current->puzzle, puzzle)) {
            return;  // Puzzle already in the set, no duplicates allowed
        }
        current = current->next;
    }

    // Insert new Puzzle
    HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
    new_node->puzzle = *puzzle;
    new_node->next = set->table[index];
    set->table[index] = new_node;
}

// Search for a Puzzle in the HashSet
int contains(const HashSet* set, const Puzzle* puzzle) {
    unsigned int index = hash_function(puzzle);
    HashNode* current = set->table[index];

    while (current != NULL) {
        if (compare_puzzles(&current->puzzle, puzzle)) {
            return 1;  // Found
        }
        current = current->next;
    }

    return 0;  // Not found
}

// Clean up and free memory for HashSet
void free_hashset(HashSet* set) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* current = set->table[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
}
