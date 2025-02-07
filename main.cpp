#include <raylib.h>

int main() {
    InitWindow(800, 600, "The Problem of the Three Bodies Simulation");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hola, Raylib!", 350, 280, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

