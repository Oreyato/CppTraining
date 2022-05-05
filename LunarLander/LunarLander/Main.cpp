#include <iostream>
#include <stdio.h>  
#include <math.h> 
#include <vector>

#include "Lander.h"
#include "LandSite.h"
#include "LanderInterface.h"
#include "Mountains.h"

using namespace std;

//v ==============================================================

//v Global init ==================================================
// Methods
void load();
void unload();
void update();
bool collidesWithMountains(Rectangle landerP);
bool outOfScreen();
void draw();
void drawUi();

// State
int state = 0;
//^ Global init ==================================================
//v Game specific init ===========================================
Lander lander { "../assets/images/lander.png", Consts::SCREEN_WIDTH / 2, 25, true};
LandSite landSite { "../assets/images/land_site.png", Consts::LANDSITE_START_XPOS, Consts::LANDSITE_START_YPOS };
LanderInterface landerInterface{ 50, 50, lander};
Mountains mountains { Consts::LANDSITE_START_XPOS, Consts::LANDSITE_START_YPOS };

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
    InitWindow(Consts::SCREEN_WIDTH, Consts::SCREEN_HEIGHT, windowName.c_str());
    SetWindowPosition(0, 10);
    SetTargetFPS(60);

    //v Sounds init ==================================================
    // Enable raylib audio system
    InitAudioDevice();

    //^ Sounds init ==================================================
    //v Game specifics ===============================================

    lander.load();
    landSite.load();
    
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


    // Main game loop
    if (state == 0) { 
        lander.update(dt);
        landerInterface.update(dt);

        // Raylib collision check
        Rectangle rectLander = lander.getRectangle();
        Rectangle rectLandSite = landSite.getRectangle();
        // Do both rects intersects?
        if (CheckCollisionRecs(rectLander, rectLandSite)) {
            // Get rectangles limits on the right (on the left: rectLander.x and rectLandSite.x)
            float maxXPosLander = rectLander.x + rectLander.width;
            float maxXPosLandSite = rectLandSite.x + rectLandSite.width;

            // Turn off the flame
            lander.setIsFlameVisible(false);

            // If so, is the lander entirely on the landsite? && is it a good landing?
            if (rectLander.x >= rectLandSite.x && maxXPosLander <= maxXPosLandSite && lander.goodLanding()) {
                streak++;

                if (streak > bestStreak) {
                    bestStreak = streak;
                }

                state = 1;
            }
            else {
                state = 2;
            }
        }
        // Check if the lander touches the mountains
        else if (collidesWithMountains(rectLander)) {
            state = 2;
        }
        // Check if the lander goes out of screen
        else if (outOfScreen()) {
            state = 2;
        }

    }
    else if (state == 1) { // If the player win
        landerInterface.streakFormat(streak);
        landerInterface.bestStreakFormat(bestStreak);

        landerInterface.showEndText(state);
        
        if (IsKeyPressed(KEY_R)) {
            resetGame();
        }
    }
    else if (state == 2) { // If the player lose
        landerInterface.showEndText(state);
        
        if (IsKeyPressed(KEY_R)) {
            streak = 0;
            landerInterface.streakFormat(streak);

            resetGame();
        }
    }
}

bool collidesWithMountains(Rectangle landerP) {
    vector<Vector2> pointsCoordinates = mountains.getPointsCoordinates();

    for (Vector2 point : pointsCoordinates) {
        //if ((lander.getXPos() - Consts::MOUNTAIN_POINTS_SPACING < point.x) && (point.x < lander.getXPos() + Consts::MOUNTAIN_POINTS_SPACING)) {
        //    if ((lander.getYPos() - Consts::MOUNTAIN_POINTS_SPACING < point.y) && (point.y < lander.getYPos() + Consts::MOUNTAIN_POINTS_SPACING)) {
        //        return true;
        //    }
        //}
        if (CheckCollisionPointRec(point, landerP)) {
            return true;
        }
    }

    return false;
}

bool outOfScreen() {
    float landerDim = 25.f / 2.f;

    if (((lander.getXPos() + landerDim < 0) ||
        (lander.getXPos() - landerDim > Consts::SCREEN_WIDTH) || 
        (lander.getYPos( ) + landerDim < 0) || 
        (lander.getYPos() - landerDim > Consts::SCREEN_HEIGHT))) {
        return true;
    }
    else {
        return false;
    }
}

// Draw game
void draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    mountains.draw();
    landSite.draw();
    lander.draw();

    drawUi();
    EndDrawing();
}

// Draw UI
void drawUi()
{
    landerInterface.draw();
}

// Reset game
void resetGame() {
    // Reset lander parameters
    lander.reset();

    // Reset lander interface end message
    landerInterface.hideEndText();

    // Change landsite and mountains accordingly
    landSite.changeSite();
    mountains.eraseLines();
    mountains.drawLines(landSite.getXPos(), landSite.getYPos());

    state = 0;
}