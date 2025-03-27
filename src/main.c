#include <stdio.h>

#include "grid.h"
#include "cell.h"
#include "game.h"
#include "input.h"
#include "raylib.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define FPS 60

int main(void) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "cellular automaton thing");
    SetTargetFPS(FPS);
    SetTraceLogLevel(LOG_ERROR);

    worldGrid g = init_grid(WINDOW_WIDTH, WINDOW_HEIGHT, 20);
    bool run = false;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            toggle_on_click(g);
        }
        // start/stop game on spacebar
        if (IsKeyPressed(KEY_SPACE)) run = !run;
        if (run) apply_to_grid(&g);

        // render the cells
        if (g.redraw) draw_grid(g);

        EndDrawing();
    }

    CloseWindow();
    free_grid(&g);
    return 0;
}
