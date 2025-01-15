#include "raylib.h"
#include "grid.hpp"
#include "brella.hpp"

int main() {
    InitWindow(656, 544, "Pixel Art Maker");
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

    Brella umbrella;

    while (!WindowShouldClose()) {     
        
        umbrella.HandleInputs();

        BeginDrawing();

        ClearBackground({26, 28, 44, 255});

        umbrella.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}