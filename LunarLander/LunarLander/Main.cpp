#include <iostream>
#include <stdio.h>  
#include <math.h> 
#include <vector>
#include <string>

#include "Lander.h"
#include "LandSite.h"

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
Lander lander { "../assets/images/lander.png", SCREEN_WIDTH / 2, 25, true};
LandSite landSite { "../assets/images/land_site.png", 400, 400 };

int streak = 0;
int bestStreak = 0;

void resetGame();

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
    string windowName = "Lander";
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowName.c_str());
    SetWindowPosition(0, 10);
    SetTargetFPS(60);

    //v Sounds init ==================================================
    // Enable raylib audio system
    InitAudioDevice();

    //^ Sounds init ==================================================
    //v Game specifics ===============================================

    //v Textures =====================
    lander.load();
    landSite.load();

    //^ Textures =====================
    
    //^ Game specifics ===============================================
}

// Unload game
void unload()
{
    lander.unload();
    landSite.unload();

    CloseWindow();
}

// Game update
void update()
{
    // A world of justice... Adding delta time
    float dt = GetFrameTime();

    if (state == 0) { // Main game loop
        lander.update(dt);

        // Raylib collision check
        Rectangle rectLander = lander.getRectangle();
        Rectangle rectLandSite = landSite.getRectangle();
        // Do both rects intersects?
        if (CheckCollisionRecs(rectLander, rectLandSite)) {
            // Get rectangles limits on the right (on the left: rectLander.x and rectLandSite.x)
            float maxXPosLander = rectLander.x + rectLander.width;
            float maxXPosLandSite = rectLandSite.x + rectLandSite.width;

            // If so, is the lander entirely on the landsite? && is it a good landing?
            if (rectLander.x >= rectLandSite.x && maxXPosLander <= maxXPosLandSite && lander.goodLanding()) {
                state = 1;
            }
            else {
                state = 2;
            }
        }
    }
    else if (state == 1) { // If the player win
        if (IsKeyPressed(KEY_R)) {
            streak++;

            if (streak > bestStreak) {
                bestStreak = streak;
            }

            resetGame();
        }
    }
    else if (state == 2) { // If the player lose
        if (IsKeyPressed(KEY_R)) {
            streak = 0;
            resetGame();
        }
    }
}

// Draw game
void draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    lander.draw();
    landSite.draw();

    drawUi();
    EndDrawing();
}

// Draw UI
void drawUi()
{

}

// Reset game
void resetGame() {
    // Reset lander parameters
    lander.setRotation(-PI / 2);
    lander.setXPos(SCREEN_WIDTH / 2);
    lander.setYPos(25);   
    
    state = 0;
}