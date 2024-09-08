#include "direction.h"

#include <stdio.h>

void print_direction(const Direction direction) {
    switch (direction) {
        case UP:
            printf("UP\n");
            break;
        case DOWN:
            printf("DOWN\n");
            break;
        case LEFT:
            printf("LEFT\n");
            break;
        case RIGHT:
            printf("RIGHT\n");
            break;
        case NONE:
            printf("NONE\n");
            break;
    }
}
