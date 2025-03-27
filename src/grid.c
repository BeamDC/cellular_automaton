#include "grid.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"

worldGrid init_grid(uint32_t w, uint32_t h, uint32_t s) {
    Cell **cells = malloc(sizeof(Cell*) * h);
    // printf("Num cells: %d", w * h);
    for (int i = 0; i < h; ++i) {
        Cell *row = malloc(sizeof(Cell) * w);
        for (int j = 0; j < w; ++j) {
            row[j] = (Cell){false, j, i};
        }
        cells[i] = row;
    }

    worldGrid g = {
        w,h,s,
        cells,
        true
    };
    return g;
}

void free_grid(worldGrid *g) {
    for (int i = 0; i < g->height; ++i) {
        free(g->cells[i]);
    }
    free(g->cells);
    g->cells = NULL;
}

Cell* get_cell_by_pos(worldGrid g, uint32_t x, uint32_t y) {
    if (x > g.width) {
        fprintf(stderr, "X OUT OF BOUNDS");
        exit(1);
    }
    if (y > g.height) {
        fprintf(stderr, "Y OUT OF BOUNDS");
        exit(1);
    }

    return &g.cells[y][x];
}

void draw_grid(worldGrid g) {
    // draw cells
    for (int i = 0; i < g.height; ++i) {
        for (int j = 0; j < g.width; ++j) {
            if (g.cells[i][j].alive) {
                DrawRectangle(
                    g.cells[i][j].x * g.size,
                    g.cells[i][j].y * g.size,
                    g.size,
                    g.size,
                    (Color){255,255,255,255}
                );
            }
        }
    }

    // the +1 to keep uniform space may mean that in the future,
    // the bottom row and rightmost column will never be used
    uint32_t x_count = ceil(g.width / g.size) + 1;
    uint32_t y_count = ceil(g.height / g.size) + 1;

    // horizontal lines
    for (int32_t i = 0; i < y_count; ++i) {
        double pos = g.size * i;
        if (pos > g.height) break;

        DrawLineEx(
            (Vector2){0, pos},
            (Vector2){g.width, pos},
            1.0f,
            (Color){64,64,64,255}
        );
    }

    // vertical lines
    for (int32_t i = 0; i < x_count; ++i) {
        double pos = g.size * i;
        if (pos > g.width) break;

        DrawLineEx(
            (Vector2){pos, 0},
            (Vector2){pos, g.height},
            1.0f,
            (Color){64,64,64,255}
        );
    }
}
