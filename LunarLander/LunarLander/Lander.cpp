#include "Lander.h"
#include <cmath>
#include <iostream>

Lander::Lander() :
	texturePath{ "../assets/images/lander.png" }
{
}

Lander::Lander(std::string texturePathP, float xPosP, float yPosP, std::string flameTexturePathP) :
	texturePath{ texturePathP },
	xPos{ xPosP },
	yPos{ yPosP },
	flameTexturePath{ flameTexturePathP },
	rotation{ -90.0f }
{
}

void Lander::load() {
	// Set textures
	texture = LoadTexture(texturePath.c_str());
	flameTexture = LoadTexture(flameTexturePath.c_str());

	// Define origin - don't forget to cast the texture width/height to float (were int)
	origin = { (float)(texture.width / 2), (float)(texture.height / 2) };

	// Center position on constructor parameters
	xPos = xPos - origin.x;
	yPos = yPos - origin.y;

	// Define source rectangle
	srcRect = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
}

void Lander::update(float dtP) {
	// Accelerating upward when pressing space bar
	if (IsKeyDown(KEY_SPACE)) {
		xSpeed += cos(rotation * PI / 180) * abs(THRUSTER) * dtP;
		ySpeed += sin(rotation * PI / 180) * abs(THRUSTER) * dtP;

		// Changing boolean value to draw the thruster
		isFlameVisible = true;
	}
	if (IsKeyReleased(KEY_SPACE)) {
		isFlameVisible = false;
	}

	if (IsKeyDown(KEY_Q)) {
		rotation -= ROTATION_SPEED * dtP;
	}
	else if (IsKeyDown(KEY_E)) {
		rotation += ROTATION_SPEED * dtP;
	}

	// Accelerating lander vertical speed with the acceleration "GRAVITY"
	ySpeed += GRAVITY * dtP;
	// Updating lander position
	xPos += xSpeed * dtP;
	yPos += ySpeed * dtP;
}

void Lander::draw() {
	// Define destination rectangle
	dstRect = { xPos, yPos, (float)texture.width, (float)texture.height };
	// Draw default texture
	DrawTexturePro(texture, srcRect, dstRect, origin, rotation, WHITE);

	if (isFlameVisible) {
		DrawTexturePro(flameTexture, srcRect, dstRect, origin, rotation, WHITE);
	}
}

void Lander::unload() {
	UnloadTexture(texture);
	UnloadTexture(flameTexture);
}