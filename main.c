#include "raylib.h"
#include <string.h>
#include <stdio.h>
#include "shapes.h"

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 800
#define SQ_SIZE 40

void initGrid(int (*grid)[20]){
  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 10; j++){
      grid[i][j] = 0;
    }
  }
}

int isValid(int x, int y, int (*grid)[20]){
  // check walls  
 // if(x >= 9 || x < 0){
   // return 0;
  //}
  // check bottom
  if(y >= 20){
    return 0;
  }
  
  // check for shapes in grids 
  if(grid[y][x] != 0){
    return 0;
  }

  return 1;
}


void drawCurrent(int (*currentShape)[4], int x, int y, int (*grid)[20]){
  int safeToDraw = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(currentShape[i][j] == 1){
        int gridPosX = (x+j);
        int gridPosY = (y+i); 
        if(!isValid(gridPosX,gridPosY,grid)){
          safeToDraw++;
        }
      }
    }
  }
  if(safeToDraw == 0){
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
        if(currentShape[i][j] != 0){
          DrawRectangle((x+j)*40,(y+i)*40,SQ_SIZE,SQ_SIZE, BLUE);
        }
      }
    }
  }
}

void drawGrid(int (*grid)[20]){
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 20; j++){
      if(grid[i][j] == 0){
        DrawRectangleLines(i*SQ_SIZE,j*SQ_SIZE,SQ_SIZE,SQ_SIZE,RAYWHITE);
      }          
    }
  }
}

void placeCurrentToGrid(int (*grid)[20], int (*curr)[4], int x, int y){
  




}

int getWidth(int (*curr)[4]){
  int width = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(curr[i][j] == 1){
        if(j > width){
          width = j;
        }
      }
    }
  }
  return width;
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

    initGrid(grid);
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        // TODO: Update your variables here
        clock++;
        if(currentY < 18 & clock > 15){ // clock > 15 cets the speed that the blocks fall
          printf("Inside of curY++ %d\n", currentY);
          currentY++;
          clock = 0; 
        }
        if(IsKeyDown(KEY_S)){
          currentY++;
        }
        if(IsKeyDown(KEY_A) && currentX >=0){
          currentX--;
        }
        if(IsKeyDown(KEY_D) && currentX+getWidth(currentShape)+1 < 10){

          currentX++;
        }

        // Draw
        BeginDrawing();
        drawGrid(grid);
        drawCurrent(currentShape,currentX,currentY,grid);
        ClearBackground(BLACK);


        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}
