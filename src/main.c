#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"


struct Vector2d{
    int x;
    int y;
};

const int screenWidth   = 800;
const int screenHeight  = 600;

const struct Vector2d size = {10, 10};
struct Vector2d pos;


const int areaCell = size.x * size.y;
int main(){
    bool cells[(screenHeight * screenWidth) / (areaCell)];
    cells[0] = 1;
    // srand(time(NULL));
    // pos.x =  rand() % screenWidth;
    // pos.y =  rand() % screenHeight;
    InitWindow(screenWidth, screenHeight, "Game Of Life");

    pos.x = 666;
    pos.y = 333;
    printf("------------\n");
    printf("x: %d, y: %d", pos.x, pos.y);
    printf("------------\n");
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(BLACK);
            // The Cell
            DrawRectangle(pos.x,pos.y,size.x,size.y,RED);

            // Top of Cell
            DrawRectangle(pos.x,pos.y-(1*size.y),size.x,size.y,GREEN);
            // Top Right of Cell
            DrawRectangle(pos.x+(1*size.x),pos.y-(1*size.y),size.x,size.y,ORANGE);
            // Top Left of Cell
            DrawRectangle(pos.x-(1*size.x),pos.y-(1*size.y),size.x,size.y,PURPLE);

            // Down of Cell
            DrawRectangle(pos.x,pos.y+(1*size.y),size.x,size.y,YELLOW);
            // Down Right of Cell
            DrawRectangle(pos.x+(1*size.x),pos.y+(1*size.y),size.x,size.y,VIOLET);
            // Down Left of Cell
            DrawRectangle(pos.x-(1*size.x),pos.y+(1*size.y),size.x,size.y,BEIGE);

            // Right of Cell
            DrawRectangle(pos.x+(1*size.x),pos.y,size.x,size.y,WHITE);
            // Left of Cell
            DrawRectangle(pos.x-(1*size.x),pos.y,size.x,size.y,LIGHTGRAY);
            cells[(pos.x * pos.y)/(size.x * size.y)] = 1;
        EndDrawing();
    };
    return 0;
};
