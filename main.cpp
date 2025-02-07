#include <iostream>
#include "raylib.h"
#include "body.h"

typedef enum SimulationScreen { INTRO, SIMULATION } SimulationScreen;

int main(void) {
    InitWindow(1000, 800, "The Problem of the Three Bodies Simulation");
    SetTargetFPS(60);

    SimulationScreen currentScreen = INTRO;

    body planet1{4.6, 10000, 500, 200, 0, 0, 0, 0};
    body planet2{3.1, 4000, 750, 750, 0, 0, 0, 0};
    body planet3{9.8, 50000, 100, 600, 0, 0, 0, 0}; 

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
              DrawCircle(planet1.px, planet1.py, 32.0, RED);
              DrawCircle(planet2.px, planet2.py, 48.0, YELLOW);
              DrawCircle(planet3.px, planet3.py, 16.0, BLUE);
            } break;
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

