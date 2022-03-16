#include "raylib.h"
#include <iostream>
#include <stdio.h>  
#include <math.h> 
#include <vector>
#include <string>

using namespace std;

//v ==============================================================

//v Global init ==================================================
// Methods
void load();
void unload();
void update();
void draw();
void drawUi();

// Screen size
int const SCREEN_WIDTH = 960;
int const SCREEN_HEIGHT = 540;

// State
int state = 0;
//^ Global init ==================================================
//v Game specific init ===========================================

//^ Game specific init ===========================================

int main(int argc, char* argv[])
{
    load();

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        update();
        draw();
    }

    unload();

    return 0;
}

// Load game
void load()
{
    // Create the window 
    string windowName = "GameWindow";
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowName.c_str());
    SetWindowPosition(0, 10);
    SetTargetFPS(60);

    //v Sounds init ==================================================
    // Enable raylib audio system
    InitAudioDevice();

    //^ Sounds init ==================================================
}

// Unload game
void unload()
{
    CloseWindow();
}

// Game update
void update()
{
    if (state == 0) {

    }
    else if (state == 1) {
        // If the player win
    }
    else {
        // If the player lose
    }
}

// Draw game
void draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    drawUi();
    EndDrawing();
}

// Draw UI
void drawUi()
{

}