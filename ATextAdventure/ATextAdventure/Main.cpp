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

//^ Global init ==================================================
//v Game specific init ===========================================
string changeDescription();
void changeState(string newState);

string description;
string state;

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
    //v Game specific ================================================
    changeState("start");

    //^ Game specific ================================================
}

// Unload game
void unload()
{
    CloseWindow();
}

// Game update
void update()
{
    if (state == "start") {
        if (IsKeyPressed(KEY_Q)) {
            changeState("deception");
        }
        else if (IsKeyPressed(KEY_E)) {
            changeState("expectations");
        }
    }
    else if (state == "deception") {
        if (IsKeyPressed(KEY_Q)) {
            changeState("start");
        }
        else if (IsKeyPressed(KEY_E)) {
            changeState("");
        }
    }
    else if (state == "expectations") {
        if (IsKeyPressed(KEY_Q)) {
            changeState("deception");
        }
        else if (IsKeyPressed(KEY_E)) {
            changeState("");
        }
    }
    else if (state == "") {
        changeState("");
    }
}

// Draw game
void draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    // Draw description
    DrawText(description.c_str(), 50, 20, 20, WHITE);

    drawUi();
    EndDrawing();
}

// Draw UI
void drawUi()
{

}

string changeDescription() {
    if (state == "start") {
        return(
            "Writing an adventure game\n"
            "Yes. Again. But that's a great practice!\n\n"
            "\t~and it will help my project\n\n"
            "\t\t A- Honestly, I don't care at all\n"
            "\t\t E- Yeah! A new project!\n"
            );
    }
    else if (state == "deception") {
        return (
            "Oh...\n"
            "You are joking right?\n\n"
            "\t\t A- Obviously!\n"
            "\t\t E- I am not"
            );
    }
    else if (state == "expectations") {
        return (
            "Thanks!\n"
            "What do you expect?\n\n"
            "\t\t A- Schweppes!"
            "\t\t E- An adventure text...?"
            );
    }
    else {
        return "...";
    }

}

void changeState(string newState) {
    state = newState;
    description = changeDescription();
}