#include "raylib.h"
#include <string.h>
#include <stdio.h>

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 800
#define SQ_SIZE 40

void drawCurrent(int (*currentShape)[4], int x, int y){

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(currentShape[i][j] == 1){
        DrawRectangle((x+i)*40,(y+j)*40,SQ_SIZE,SQ_SIZE, BLUE);
      }
    }
  }

}

int main(void)
{
   // const int screenWidth = 400;
   // const int screenHeight = 800;
    
    const int squareSize = 40;
    int grid[10][20];
    int next_grid[10][20];
//    int currentShape[4][4];
    int currentX = 4;
    int currentY= 0;
    int clock = 0;
    memset(grid,0,sizeof(grid)); 
    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");

  
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // test block I piece
    int currentShape[4][4] = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0}
    };




    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        // TODO: Update your variables here
        clock++;
          if(currentY < 18 & clock > 15){
          printf("Inside of curY++ %d\n", currentY);
          currentY++;
          clock = 0; 
        }
        // Draw
        BeginDrawing();
        for(int i = 0; i < 10; i++){
          for(int j = 0; j < 20; j++){
            if(grid[i][j] == 0){
              DrawRectangleLines(i*SQ_SIZE,j*SQ_SIZE,SQ_SIZE,SQ_SIZE,RAYWHITE);
            }          
          }
        }
        drawCurrent(currentShape,currentX,currentY);
        ClearBackground(BLACK);


        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}
