#include "raylib.h"
#include <iostream>
#include <stdio.h>  
#include <math.h> 
#include <vector>
#include <string>

using namespace std;

//v ==============================================================

//v Variables init ===============================================
// Editor variables
void init();
void update();
void draw();
void drawUi();

// Screen size
int const SCREEN_WIDTH = 960;
int const SCREEN_HEIGHT = 540;
//^ Variables init ===============================================

int main(int argc, char* argv[])
{
    // Create the window 
    string windowName = "GameWindow";
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowName.c_str());
    SetWindowPosition(0, 10);
    SetTargetFPS(60);

    init();

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        update();
        draw();
    }

    CloseWindow();

    return 0;
}

void init()
{

}

void update()
{

}

void draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    drawUi();
    EndDrawing();
}

void drawUi()
{

}