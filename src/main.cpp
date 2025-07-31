#include "raylib.h"
#include "brella.hpp"
#include "colors.hpp"
#include "constants.hpp"

int main() { 
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pixel Art Maker");
    SetWindowIcon(LoadImage("icon.png"));
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

    Brella umbrella;

    while (!WindowShouldClose()) {     
        
        umbrella.HandleInputs();

        BeginDrawing();

        ClearBackground(black);

        umbrella.Draw();

        EndDrawing();

        // umbrella.PrintFPS();
    }

    CloseWindow();
    return 0;
}