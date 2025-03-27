#ifndef CELL_H
#define CELL_H

#include <stdbool.h>
#include <stdint.h>

typedef struct Cell {
    bool alive;
    uint32_t x;
    uint32_t y;
} Cell;

#endif //CELL_H
