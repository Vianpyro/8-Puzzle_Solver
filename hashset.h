#ifndef HASHSET_H
#define HASHSET_H

#define TABLE_SIZE 100

#include "puzzle.h"

// Define a HashNode for collision handling (chaining)
typedef struct HashNode {
    Puzzle puzzle;
    struct HashNode* next;
} HashNode;

// Define the HashSet structure
typedef struct HashSet {
    HashNode* table[TABLE_SIZE];
} HashSet;

/**
 * Initializes the HashSet.
 *
 * @param set Pointer to the HashSet to initialize.
 */
void init_hashset(HashSet* set);

/**
 * Computes the hash value for a given Puzzle.
 *
 * @param puzzle Pointer to the Puzzle to hash.
 * @return Hash value as an unsigned integer.
 */
unsigned int hash_function(const Puzzle* puzzle);

/**
 * Compares two Puzzle boards for equality.
 *
 * @param a Pointer to the first Puzzle.
 * @param b Pointer to the second Puzzle.
 * @return 1 if the puzzles are equal, 0 otherwise.
 */
int compare_puzzles(const Puzzle* a, const Puzzle* b);

/**
 * Inserts a Puzzle into the HashSet.
 *
 * @param set Pointer to the HashSet where the Puzzle will be inserted.
 * @param puzzle Pointer to the Puzzle to insert.
 */
void insert(HashSet* set, const Puzzle* puzzle);

/**
 * Checks if a Puzzle is contained in the HashSet.
 *
 * @param set Pointer to the HashSet to check.
 * @param puzzle Pointer to the Puzzle to check for.
 * @return 1 if the Puzzle is found, 0 otherwise.
 */
int contains(const HashSet* set, const Puzzle* puzzle);

/**
 * Frees the memory allocated for the HashSet.
 *
 * @param set Pointer to the HashSet to free.
 */
void free_hashset(HashSet* set);

#endif  // HASHSET_H
