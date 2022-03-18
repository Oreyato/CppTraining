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

LandSite landSite { "../assets/images/target.png", 400, 400 };

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
    }
    else if (state == 1) { // If the player win
       
    }
    else { // If the player lose
        
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