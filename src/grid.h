#ifndef GRID_H
#define GRID_H

#include <stdint.h>
#include "cell.h"

typedef struct worldGrid {
    uint32_t width;
    uint32_t height;
    uint32_t size; // grid square size, 1 = 1px
    Cell **cells;
    bool redraw
} worldGrid;

worldGrid init_grid(uint32_t w, uint32_t h, uint32_t s);
void free_grid(worldGrid *g);
Cell* get_cell_by_pos(worldGrid g, uint32_t x, uint32_t y);
void draw_grid(worldGrid g);

#endif //GRID_H
