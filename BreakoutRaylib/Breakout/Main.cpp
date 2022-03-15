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
int const WIDTH_SCREEN = 1000;
int const HEIGHT_SCREEN = 540;

// State
int state = 0;
//^ Global init ==================================================
//v Game specific init ===========================================
bool AABBAlgorithm(Rectangle a, Rectangle b);
// Ball ===============================
const int SIZE_BALL = 32;
const int SPEED_BALL = 5;
int xSpeedBall = SPEED_BALL;
int ySpeedBall = SPEED_BALL;

// Initial position
const int X_POS_BALL = 250;
const int Y_POS_BALL = 250;

Rectangle ball{ X_POS_BALL, Y_POS_BALL, SIZE_BALL, SIZE_BALL };

// ====================================
// Paddle =============================
const int WIDTH_PADDLE = 128;
const int HEIGHT_PADDLE = 32;
const int SPEED_PADDLE = 10;

// Initial position
const int Y_POS_PADDLE = HEIGHT_SCREEN - (HEIGHT_PADDLE + 10);
const int X_POS_PADDLE = WIDTH_SCREEN / 2 - WIDTH_PADDLE / 2;

Rectangle paddle { X_POS_PADDLE, Y_POS_PADDLE, WIDTH_PADDLE, HEIGHT_PADDLE};
// ====================================
// Bricks =============================
// Single brick
struct Brick {
    Rectangle rect;
    bool isVisible;
};

const int WIDTH_BRICK = 100;
const int HEIGHT_BRICK = 32;

Rectangle rect{ 0, 0, WIDTH_BRICK, HEIGHT_BRICK };
Brick brick{ rect, true };

// Creating multiple bricks
const int ROW_BRICKS = 10;
const int COLUMN_BRICKS = 6;

const int SPACING_BRICKS = 2;

vector<Brick> bricks;

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

    //v Game specifics ===============================================
    // Initiate the grid of bricks~
    // Filling it with the bricks
    for (int i = 0; i < ROW_BRICKS; i++)
    {
        for (int j = 0; j < COLUMN_BRICKS; j++)
        {
            // Brick position
            int xPos = WIDTH_BRICK * i;
            int yPos = HEIGHT_BRICK * j;

            // Rectangle to fit in the Brick struct
            Rectangle rect{ xPos, yPos, WIDTH_BRICK - SPACING_BRICKS, HEIGHT_BRICK - SPACING_BRICKS };

            // Create the brick
            Brick brick{ rect, true };
            // ... and add it to the bricks vector
            bricks.push_back(brick);
        }
    }

    //^ Game specifics ===============================================
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
            // Reset ball position
            ball.y = 0;
        }
// TEMP // ... from the bottom 
        else if (ball.y >= HEIGHT_SCREEN - ball.height) {
            // Reverse speed along the y axis
            ySpeedBall *= -1;
            // Reset ball position
            ball.y = HEIGHT_SCREEN - ball.height;
        }
// TEMP
        // ... from the left or the right
        else if (ball.x <= 0) {
            // Reverse speed along the x axix
            xSpeedBall *= -1;
            // Reset ball position 
            ball.x = 0;
        }
        // ... from the left or the right
        else if (ball.x >= WIDTH_SCREEN - ball.width) {
            // Reverse speed along the x axix
            xSpeedBall *= -1;
            // Reset ball position 
            ball.x = WIDTH_SCREEN - ball.width;
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
        //v Collisions ===================================================
        // Testing if the ball collides with the paddle
        if (AABBAlgorithm(ball, paddle)) {
            // Reverse ball speed along the y axis
            ySpeedBall *= -1;
            // Reset ball position at the top of the paddle
            ball.y = Y_POS_PADDLE - ball.height;
        }
        // Testing if the ball collides with the bricks
        for (Brick& brick : bricks)
        {
            if (brick.isVisible)
            {
                if (AABBAlgorithm(ball, brick.rect)) {
                    // Reverse ball speed along the y axis
                    ySpeedBall *= -1;
                    // Reset ball position at the bottom of the brick
                    ball.y = brick.rect.y + brick.rect.height;
                    // Set the brick visibility to false
                    brick.isVisible = false;
                }
            }
        }
        //^ Collisions ===================================================
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
    // Draw all bricks
    for (Brick brick : bricks)
    {
        if (brick.isVisible) {
            DrawRectangleRec(brick.rect, GREEN);
        }
    }

    drawUi();
    EndDrawing();
}

// Draw UI
void drawUi()
{

}

bool AABBAlgorithm(Rectangle a, Rectangle b) {
    // Initiate boolean
    bool isColliding = false;
    // Initiate ball variables
    int xMinA= a.x;
    int yMinA = a.y;
    int xMaxA = a.x + a.width;
    int yMaxA = a.y + a.height;
    // Initiate paddle variables
    int xMinB = b.x;
    int yMinB = b.y;
    int xMaxB = b.x + b.width;
    int yMaxB = b.y + b.height;

    if (!(xMinB > xMaxA || yMinB > yMaxA || xMaxB < xMinA || yMaxB < yMinA)) {
        isColliding = true;
    }

    return isColliding;
}