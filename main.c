#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

#include "Visualizer.h"



int main() {
    InitWindow(800, 450, "viSim");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hallo aus CLion!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}