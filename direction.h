#ifndef DIRECTION_H_
#define DIRECTION_H_

#define DIRECTION_COUNT 4

typedef enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
} Direction;

void print_direction(const Direction direction);

#endif  // DIRECTION_H_
