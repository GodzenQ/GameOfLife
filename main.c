#include <stdio.h>
#include "raylib.h"

int main(){
    const int screenWidth   = 800;
    const int screenHeight  = 600;
    InitWindow(screenWidth, screenHeight, "Game Of Life");
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    };

    printf("Hello World\n");
    printf("New world\n");
    return 0;
};
