#include "raylib.h"
#include <iostream>
#include <stdio.h>  
#include <math.h> 
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

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
    // Creating the path and stocking it in "path" string
    string path = "texts/" + state + ".txt";

    cout << path << endl;
    // Input file stream
    ifstream file { path };
    // Create the buffer variable
    stringstream buffer;
    // Read the file buffer and put it inside the buffer variable
    buffer << file.rdbuf();

    return buffer.str();
}

void changeState(string newState) {
    state = newState;
    description = changeDescription();
}