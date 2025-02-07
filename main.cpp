#include <iostream>
#include "raylib.h"

typedef enum SimulationScreen { INTRO, SIMULATION } SimulationScreen;

int main(void) {
    InitWindow(1000, 800, "The Problem of the Three Bodies Simulation");
    SetTargetFPS(60);

    SimulationScreen currentScreen = INTRO;

    while (!WindowShouldClose()) {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        switch (currentScreen){

          case INTRO:
          {
            if (IsKeyPressed(KEY_SPACE)){
              currentScreen = SIMULATION;
            }
          } break;

          case SIMULATION:
          {
            if (IsKeyPressed(KEY_Q)){
              currentScreen = INTRO;
            }
          } break;

        }
         

        // Draw
        //---------------------------------------------------------------------------------- 
        BeginDrawing();
        ClearBackground(BLACK);
        switch (currentScreen){
          case INTRO:
            {
               DrawText("Welcome to the Three Bodies Problem Simulation!", 100, 360, 32, RAYWHITE);
               DrawText("Press SPACE for starting the simulation...", 250, 420, 24, RAYWHITE);
            } break;

          case SIMULATION:
            {
              DrawCircle(500, 200, 32.0, RED);
              DrawCircle(750, 750, 48.0, YELLOW);
              DrawCircle(100, 600, 16.0, BLUE);
            } break;
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

