#include "raylib.h"

#include <string.h>
#include <stdio.h>
#include "shapes.h"

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 800

int main(void)
{   
    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");

  
    SetTargetFPS(60);  


    while (!WindowShouldClose())   
    {
        

        // Draw
        BeginDrawing();  
          ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();        

    return 0;
}
