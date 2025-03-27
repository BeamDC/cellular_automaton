#include "game.h"


uint8_t count_neighbours(worldGrid g, uint32_t x, uint32_t y) {
    uint8_t neighbours = 0;
    // top row
    neighbours += x > 0 && y > 0 && get_cell_by_pos(g, x-1, y-1)->alive;
    neighbours += y > 0 && get_cell_by_pos(g, x, y-1)->alive;
    neighbours += x+1 < g.width && y > 0 && get_cell_by_pos(g, x+1, y-1)->alive;

    // middle
    neighbours += x > 0 && get_cell_by_pos(g, x-1, y)->alive;
    neighbours += x+1 < g.width && get_cell_by_pos(g, x+1, y)->alive;

    // bottom row
    neighbours += x > 0 && y+1 < g.height && get_cell_by_pos(g, x-1, y+1)->alive;
    neighbours += y+1 < g.height && get_cell_by_pos(g, x, y+1)->alive; // segfaults when called on bottom row
    neighbours += x+1 < g.width && y+1 < g.height && get_cell_by_pos(g, x+1, y+1)->alive;

    return neighbours;
}

bool game_of_life(worldGrid g, uint32_t x, uint32_t y) {
    Cell *cell = get_cell_by_pos(g, x, y);
    uint8_t neighbours = count_neighbours(g, x, y);
    // conway rule 1 & 3
    if (cell->alive && (neighbours < 2 || neighbours > 3)) {
        return false;
    }
    if (cell->alive && (neighbours == 2 || neighbours == 3)) {
        return true;
    }
    // conway rule 4
    if (!cell->alive && neighbours == 3) {
        return true;
    }
    return false;
}

void apply_to_grid(worldGrid *g) {
    worldGrid new_turn = init_grid(g->width, g->height, g->size);
    for (int i = 0; i < g->width; ++i) {
        for (int j = 0; j < g->height; ++j) {
            new_turn.cells[j][i].alive = game_of_life(*g, i, j);
        }
    }
    free_grid(g);
    *g = new_turn;
}
