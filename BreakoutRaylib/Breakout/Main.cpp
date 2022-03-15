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
// Ball ===============================
const int SIZE_BALL = 32;
const int SPEED_BALL = 5;
int xSpeedBall = SPEED_BALL;
int ySpeedBall = SPEED_BALL;

// Initial position
const int X_POS_BALL = 250;
const int Y_POS_BALL = 250;

Rectangle ball{ X_POS_BALL, Y_POS_BALL, SIZE_BALL, SIZE_BALL };

// Paddle =============================
const int WIDTH_PADDLE = 300;
const int HEIGHT_PADDLE = 32;
const int SPEED_PADDLE = 5;

// Initial position
const int Y_POS_PADDLE = HEIGHT_SCREEN - (HEIGHT_PADDLE + 10);
const int X_POS_PADDLE = WIDTH_SCREEN / 2 - WIDTH_PADDLE / 2;

Rectangle paddle { X_POS_PADDLE, Y_POS_PADDLE, WIDTH_PADDLE, HEIGHT_PADDLE};

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
        //v Ball =========================================================
        ball.x += xSpeedBall;
        ball.y += ySpeedBall;

        // Testing if the ball goes out of screen
        // ... from the top
        if (ball.y <= 0) {
            // Reverse speed along the y axis
            ySpeedBall *= -1;

        }
// TEMP // ... from the bottom 
        else if (ball.y >= HEIGHT_SCREEN - ball.height) {
            // Reverse speed along the y axis
            ySpeedBall *= -1;
        }
// TEMP
        // ... from the left or the right
        else if (ball.x <= 0 || ball.x >= WIDTH_SCREEN - ball.width) {
            // Reverse speed along the x axix
            xSpeedBall *= -1;
        }
        //^ Ball =========================================================
        //v Paddle =======================================================
        // Moving the paddle according to player input
        // Moving left 
        if (IsKeyDown(KEY_A)) {
            paddle.x -= SPEED_PADDLE;
        }
        // Moving right
        else if (IsKeyDown(KEY_D)) {
            paddle.x += SPEED_PADDLE;
        }

        // Testing if the paddle goes out of screen
        // ... from the left
        if (paddle.x <= 0) {
            // Reset paddle x position
            paddle.x = 0;
        }
        // ... from the right
        else if (paddle.x >= WIDTH_SCREEN - paddle.width) {
            // Reset paddle x position
            paddle.x = WIDTH_SCREEN - paddle.width;
        }
        //^ Paddle =======================================================
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
    DrawRectangleRec(ball, WHITE);

    // Draw paddle
    DrawRectangleRec(paddle, WHITE);

    drawUi();
    EndDrawing();
}

// Draw UI
void drawUi()
{

}