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
int const WIDTH_SCREEN = 960;
int const HEIGHT_SCREEN = 540;

// State
int state = 0;
//^ Global init ==================================================
//v Game specific init ===========================================
// Ball
const int SIZE_BALL = 32;
const int SPEED_BALL = 5;

int xPosBall = 250;
int yPosBall = 250;

// Paddle
const int WIDTH_PADDLE = 300;
const int HEIGHT_PADDLE = 32;
const int SPEED_PADDLE = 5;
const int YPOS_PADDLE = HEIGHT_SCREEN - (HEIGHT_PADDLE + 10);

int xPosPaddle = WIDTH_SCREEN / 2 - WIDTH_PADDLE / 2;
Rectangle paddle {xPosPaddle, YPOS_PADDLE, WIDTH_PADDLE, HEIGHT_PADDLE};

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
    InitWindow(WIDTH_SCREEN, HEIGHT_SCREEN, windowName.c_str());
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

    // Draw ball
    DrawRectangle(xPosBall, yPosBall, SIZE_BALL, SIZE_BALL, WHITE);

    // Draw paddle
    DrawRectangleRec(paddle, WHITE);

    drawUi();
    EndDrawing();
}

// Draw UI
void drawUi()
{

}