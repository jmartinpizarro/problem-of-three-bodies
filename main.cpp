#include <iostream>
#include <cmath>
#include "raylib.h"
#include "body.h"

typedef enum SimulationScreen { INTRO, SIMULATION1, SIMULATION2 } SimulationScreen;
const int WIDTH = 1000;
const int HEIGHT = 800;

constexpr double G = 6.67430e-11;

int main(void) {
    InitWindow(WIDTH, HEIGHT, "The Problem of the Three Bodies Simulation");
    SetTargetFPS(60);

    body planet1, planet2, planet3;

    SimulationScreen currentScreen = INTRO;

    while (!WindowShouldClose()) {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        switch (currentScreen){

          case INTRO:
          {
            if (IsKeyPressed(KEY_ONE)){
              
              planet1 = {4.6, 10000, 500, 400, 0, 0, 0, 0}; // central body
              planet2 = {3.1, 4000, 600, 600, 0, 0, 0, 0};  // satellite

              currentScreen = SIMULATION1;
            }
            if (IsKeyPressed(KEY_TWO)){ 
              planet1 = {4.6, 10000, 500, 200, 0, 0, 0, 0};
              planet2 = {3.1, 4000, 750, 750, 0, 0, 0, 0};
              planet3 = {9.8, 50000, 100, 600, 0, 0, 0, 0};
              
              currentScreen = SIMULATION2;
            }
          } break;

          case SIMULATION1: // two bodies problem
          {
            // based on the Newtonian Formula: F = G * (M * m) / r² 
            if (IsKeyPressed(KEY_Q)){
              currentScreen = INTRO;
            }
            
            double a = planet2.px - planet1.px;
            double b = planet2.py - planet1.px;

            double r = sqrt(pow(a, 2) + pow(b, 2));

            std::cout << r;

          } break;

          case SIMULATION2: // three bodies problem
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
               DrawText("Press 1 for starting the simulation of a two bodies problem.", 150, 420, 24, RAYWHITE);
               DrawText("Press 2 for starting the simulation of the three bodies problem.", 150, 450, 24, RAYWHITE);
            } break;

           case SIMULATION1:
            {
              DrawCircle(planet1.px, planet1.py, 48.0, RED);
              DrawCircle(planet2.px, planet2.py, 32.0, YELLOW);
            } break;

          case SIMULATION2:
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

