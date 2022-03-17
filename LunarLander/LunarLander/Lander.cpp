#include "Lander.h"

Lander::Lander() :
	texturePath{ "../assets/images/lander.png" }
{
}

Lander::Lander(std::string texturePathP, float xPosP, float yPosP, std::string flameTexturePathP) :
	texturePath(texturePathP),
	xPos(xPosP),
	yPos(yPosP),
	flameTexturePath(flameTexturePathP)
{
}

void Lander::load() {
	// Set textures
	texture = LoadTexture(texturePath.c_str());
	flameTexture = LoadTexture(flameTexturePath.c_str());

	// Define origin
	origin = { (float)(texture.width / 2), (float)(texture.height / 2) };

	// Center position on constructor parameters
	xPos = xPos - origin.x;
	yPos = yPos - origin.y;

	// Define source rectangle
	srcRect = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
}

void Lander::update() {
	// Accelerating upward when pressing space bar
	if (IsKeyDown(KEY_SPACE)) {
		ySpeed += THRUSTER;

		// Changing boolean value to draw the thruster
		isFlameVisible = true;
	}
	if (IsKeyReleased(KEY_SPACE)) {
		isFlameVisible = false;
	}

	if (IsKeyDown(KEY_Q)) {
		rotation -= ROTATION_SPEED;
	}
	else if (IsKeyDown(KEY_E)) {
		rotation += ROTATION_SPEED;
	}

	// Accelerating lander vertical speed with the acceleration "GRAVITY"
	ySpeed += GRAVITY;
	// Updating lander position
	xPos += xSpeed;
	yPos += ySpeed;
}

void Lander::draw() {
	// Define destination rectangle
	dstRect = { xPos, yPos, (float)texture.width, (float)texture.height };
	// Draw default texture
	DrawTexturePro(texture,srcRect, dstRect, origin, rotation, WHITE);

	if (isFlameVisible) {
		DrawTexturePro(flameTexture, srcRect, dstRect, origin, rotation, WHITE);
	}
}

void Lander::unload() {
	UnloadTexture(texture);
	UnloadTexture(flameTexture);
}