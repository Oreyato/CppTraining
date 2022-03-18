#include "Lander.h"
#include <cmath>
#include <iostream>

Lander::Lander(std::string texturePathP, float xPosP, float yPosP, bool centeredP) :
	Sprite {texturePathP, xPosP, yPosP, - PI / 2, centeredP}
{
}

void Lander::update(float dtP) {
	// Accelerating upward when pressing space bar
	if (IsKeyDown(KEY_SPACE)) {
		xSpeed += cos(rotation) * abs(THRUSTER) * dtP;
		ySpeed += sin(rotation) * abs(THRUSTER) * dtP;

		// Changing boolean value to draw the thruster
		isFlameVisible = true;
	}
	if (IsKeyReleased(KEY_SPACE)) {
		isFlameVisible = false;
	}

	if (IsKeyDown(KEY_Q)) {
		rotation -= ROTATION_SPEED * dtP;
		// Keep rotation inside the trigonometric circle
		if (rotation < 0.0f) {
			rotation = 2 * PI + rotation;
		}
	}
	else if (IsKeyDown(KEY_E)) {
		rotation += ROTATION_SPEED * dtP;
		// Keep rotation inside the trigonometric circle
		if (rotation > 2 * PI) {
			rotation = rotation - 2 * PI;
		}
	}

	// Accelerating lander vertical speed with the acceleration "GRAVITY"
	ySpeed += GRAVITY * dtP;
	// Updating lander position
	xPos += xSpeed * dtP;
	yPos += ySpeed * dtP;
}