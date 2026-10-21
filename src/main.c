#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"



struct Vector2d{
    int x;
    int y;
};

const int screenWidth   = 1900;
const int screenHeight  = 1000;

const struct Vector2d size = {10, 10};
struct Vector2d pos;

const int areaCell = size.x * size.y;
const int pixels = screenWidth * screenHeight;

int deadOrAlive(bool cellGrid[pixels * areaCell], int cellPositionx, int cellPositiony){
    int alive = 0;
    // Top 
    if(cellGrid[cellPositionx * (cellPositiony-size.y)] == 1){ alive += 1; }
    if(cellGrid[(cellPositionx+size.x) * (cellPositiony-size.y)] == 1){ alive += 1;}
    if(cellGrid[(cellPositionx-size.x) * (cellPositiony-size.y)] == 1){ alive += 1;}

    // Down
    if(cellGrid[cellPositionx * (cellPositiony+size.y)] == 1){ alive += 1; }
    if(cellGrid[(cellPositionx-size.x) * (cellPositiony+size.y)] == 1){ alive += 1;}
    if(cellGrid[(cellPositionx+size.x) * (cellPositiony+size.y)] == 1){ alive += 1;}

    // Left and Right
    if(cellGrid[(cellPositionx+size.x) * cellPositiony] == 1){ alive += 1; }
    if(cellGrid[(cellPositionx-size.x) * cellPositiony] == 1){ alive += 1; }
    return alive;
};

int main(){
    bool cells[pixels / areaCell];
    for(size_t i = 0; i < (sizeof(cells)/sizeof(cells[0])); i++){
        cells[i] = 1;
    };
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
            for(int x=0; x < screenWidth; x++){
                for(int y=0; y < screenHeight; y++){
                    int alive = deadOrAlive(cells, x, y);
                    if(alive < 2){
                        cells[x*y/(areaCell)] = 0;
                        DrawRectangle(x, y, size.x, size.y, BLACK);
                    }
                    else if(alive == 2 || alive == 3){
                        cells[x*y/(areaCell)] = 1;
                        DrawRectangle(x, y, size.x, size.y, WHITE);
                    }
                    else if(alive > 3){
                        cells[x*y/(areaCell)] = 0;
                        DrawRectangle(x, y, size.x, size.y, BLACK);
                    };
                }
            };
        EndDrawing();
            // // The Cell
            // DrawRectangle(pos.x,pos.y,size.x,size.y,RED);
            //
            // // Top of Cell
            // DrawRectangle(pos.x,pos.y-(1*size.y),size.x,size.y,GREEN);
            // // Top Right of Cell
            // DrawRectangle(pos.x+(1*size.x),pos.y-(1*size.y),size.x,size.y,ORANGE);
            // // Top Left of Cell
            // DrawRectangle(pos.x-(1*size.x),pos.y-(1*size.y),size.x,size.y,PURPLE);
            //
            // // Down of Cell
            // // Down Right of Cell
            // DrawRectangle(pos.x+(1*size.x),pos.y+(1*size.y),size.x,size.y,VIOLET);
            // // Down Left of Cell
            // DrawRectangle(pos.x-(1*size.x),pos.y+(1*size.y),size.x,size.y,BEIGE);
            //
            // // Right of Cell
            // DrawRectangle(pos.x+(1*size.x),pos.y,size.x,size.y,WHITE);
            // // Left of Cell
            // DrawRectangle(pos.x-(1*size.x),pos.y,size.x,size.y,LIGHTGRAY);
            // cells[(pos.x * pos.y)/(size.x * size.y)] = 1;
            // cells[(pos.x * (pos.y+size.y))/(size.x * size.y)] = 1;
            // if(cells[(pos.x * (pos.y+size.y))/(size.x * size.y)]){
            //     DrawRectangle(pos.x,pos.y+(1*size.y),size.x,size.y,YELLOW);
            // }
    };
    return 0;
};
