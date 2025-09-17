#include "raylib.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
    const int screenWidth = 400;
    const int screenHeight = 800;
    const int squareSize = 40;
    int grid[10][20];
    memset(grid,0,sizeof(grid)); 


    InitWindow(screenWidth, screenHeight, "Tetris");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        // TODO: Update your variables here

        // Draw
        BeginDrawing();
        for(int i = 0; i < 10; i++){
          for(int j = 0; j < 20; j++){
            if(grid[i][j] == 0){
              DrawRectangleLines(i*40,j*40,40,40,RAYWHITE);
            }      
          }
        }
        ClearBackground(BLACK);


        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}
