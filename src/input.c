#include "input.h"

#include <math.h>
#include <stdio.h>

#include "grid.h"
#include "cell.h"
#include "raylib.h"

void toggle_on_click(worldGrid g) {
    g.redraw = true;
    Vector2 pos = GetMousePosition();
    uint32_t x = floor(pos.x / g.size);
    uint32_t y = floor(pos.y / g.size);
    // printf("(%d,%d)\n",x,y);
    Cell *cell = get_cell_by_pos(g, x, y);
    cell->alive = !cell->alive;
}