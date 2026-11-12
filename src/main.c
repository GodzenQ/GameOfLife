#include <stdbool.h>
#include "raylib.h"


const int screenWidth   = 1920;
const int screenHeight  = 1080;
const int box = 10;
const int areaCell = box*box;
const int pixels = screenWidth * screenHeight;
const int w = screenWidth/box;
// returns the no. of neighbours of a cell in a cell-grid
int neighbour_count(bool grid[], int idx){
    int neighbours = 0;
    /* Now in 2d world */
    // Start from top left
    int offsets[18] = { -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0};
    for(int i=0; i < 15; i++){
        if(i%2==1) { }
        else{
            int nx = idx%(w) + offsets[i];
            int ny = idx/(w) + offsets[i+1];
            // Don't know why the nx > ... check same with ny > ... but assuming its correct
            if(nx < 0 || nx > (w) - 1 || ny < 0 || ny > (screenHeight/box) - 1){
                neighbours += 0;
            }else{
                if(grid[ny * (w) + nx]){
                    neighbours++;
                }
            };
        };
    };
    return neighbours;

};
int main(){
    // there were garbage ram values inserted, so explicitly allocated 0 to all index
    SetTargetFPS(10);
    bool input[pixels/areaCell]  = {0};
    bool output[pixels/areaCell] = {0};
    // for(size_t i = 0; i < (sizeof(cells)/sizeof(cells[0])); i++){ cells[i] = 1; };
    // Result: All cells dead in next generation
    SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    InitWindow(screenWidth, screenHeight, "Game Of Life");

    // Center of the screen
    int sx = w/2; 
    int sy = screenHeight/(box*2); 
    /* Block and hor-vert flip
    input[10 * w + 10] = 1;
    input[10 * w + 11] = 1;
    input[11 * w + 10] = 1;
    input[11 * w + 11] = 1;
    input[20 * w + 15] = 1;
    input[21 * w + 15] = 1;
    input[22 * w + 15] = 1;
    */

    /* Glider 
    input[5 * w + 21] = 1;
    input[6 * w + 22] = 1;
    input[7 * w + 20] = 1;
    input[7 * w + 21] = 1;
    input[7 * w + 22] = 1;
    */

    /* The Achorn */
    input[(sy)*w + (sx+1)] = 1;
    input[(sy+1)*w + (sx+3)] = 1;
    input[(sy+2)*w + sx] = 1;
    input[(sy+2)*w + (sx+1)] = 1;
    input[(sy+2)*w + (sx+4)] = 1;
    input[(sy+2)*w + (sx+5)] = 1;
    input[(sy+2)*w + (sx+6)] = 1;
    

    /* R-Pentomino - Drops dead center 
    input[(sy-1)*w + sx+1] = 1; input[(sy-1)*w + sx+2] = 1;
    input[sy*w + sx] = 1; input[sy*w + sx+1] = 1;
    input[(sy+1)*w + sx+1] = 1;
    */

    /* Diehard - Detonates and deletes itself
    input[sy*w + sx] = 1; input[sy*w + sx+1] = 1;
    input[(sy+1)*w + sx+1] = 1;
    input[(sy-1)*w + sx+6] = 1;
    input[(sy+1)*w + sx+5] = 1; input[(sy+1)*w + sx+6] = 1; input[(sy+1)*w + sx+7] = 1;
    */

    /* LWSS - Flies perfectly straight to the right 
    input[(sy-1)*w + sx+1] = 1; input[(sy-1)*w + sx+2] = 1; input[(sy-1)*w + sx+3] = 1; input[(sy-1)*w + sx+4] = 1;
    input[sy*w + sx] = 1; input[sy*w + sx+4] = 1;
    input[(sy+1)*w + sx+4] = 1;
    input[(sy+2)*w + sx] = 1; input[(sy+2)*w + sx+3] = 1;
    */
    while(!WindowShouldClose()){

        for(int idx=0; idx < pixels/areaCell; idx++){
            int alive = neighbour_count(input, idx);
            if(alive < 2 && input[idx]) { output[idx]  = 0; }
            else if((alive == 2 || alive == 3) && input[idx])    { output[idx] = 1; } 
            else if( alive == 3 && input[idx] == 0 )             { output[idx] = 1; }
            else if( alive > 3  && input[idx])                   { output[idx] = 0; }
            else                                                 { output[idx] = 0; }
        };
        BeginDrawing();
        ClearBackground(BLACK);
        // Gives us the column of the current element
        // Gives the row of the current element
        /* screenHeight/box - 1 => 53, because this will become the idex for our 
           2D -> 1D formula, and as range goes from [0, 54). We use 53 as last idx */
        for(int i=0; i < pixels/areaCell; i++){
            if(output[i]){
                DrawRectangle(i%(w) * box , i/(w) * box, box, box, GREEN);
            };
        };
        EndDrawing();
        for(int x=0; x < pixels/areaCell; x++){
            input[x] = output[x];
        };
    };
    return 0;
};
