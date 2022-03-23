#include "Lander.h"
#include <cmath>
#include <iostream>

Lander::Lander(std::string texturePathP, float xPosP, float yPosP, bool centeredP) :
	Sprite {texturePathP, xPosP, yPosP, - PI / 2, centeredP},
	initXPos{xPosP},
	initYPos{yPosP}
{
}

void Lander::update(float dtP) {
	// Accelerating upward when pressing space bar
	if (IsKeyDown(KEY_SPACE)) {
		xSpeed += cos(rotation) * abs(Consts::THRUSTER) * dtP;
		ySpeed += sin(rotation) * abs(Consts::THRUSTER) * dtP;

		// Changing boolean value to draw the thruster
		isFlameVisible = true;
	}
	if (IsKeyReleased(KEY_SPACE)) {
		isFlameVisible = false;
	}

	if (IsKeyDown(KEY_Q)) {
		rotation -= Consts::ROTATION_SPEED * dtP;
		// Keep rotation inside the trigonometric circle
		if (rotation < 0.0f) {
			rotation = 2 * PI + rotation;
		}
	}
	else if (IsKeyDown(KEY_E)) {
		rotation += Consts::ROTATION_SPEED * dtP;
		// Keep rotation inside the trigonometric circle
		if (rotation > 2 * PI) {
			rotation = rotation - 2 * PI;
		}
	}

	// Accelerating lander vertical speed with the acceleration "GRAVITY"
	ySpeed += Consts::GRAVITY * dtP;
	// Updating lander position
	xPos += xSpeed * dtP;
	yPos += ySpeed * dtP;

	rotation360 = rotationFormat();

	// Updating flame sprite coordinates
	flame.setXPos(xPos);
	flame.setYPos(yPos);
	flame.setRotation(rotation);
	flame.setVisible(isFlameVisible);
}

void Lander::load() {
	flame.load();
	Sprite::load();
}

void Lander::draw() {
	Sprite::draw();
	flame.draw();
}

void Lander::unload() {
	flame.unload();
	Sprite::unload();
}

int Lander::rotationFormat()
{
	// Compensate raylib orientation system
	float ajustedRotation = rotation + PI / 2.0f;
	// Convert it to degrees	
	float rotationToDegrees = ajustedRotation * 180.0f / PI;
	// Create a clearer value
	int roundedRotation = round(rotationToDegrees);
	// Keep the rotation between 0 and 360
	rotation360 = roundedRotation % 360;

	return rotation360;
}

bool Lander::isRotationOk()
{
	int rotation360 = rotationFormat();

	return (rotation360 < Consts::ROTATION_MAX_DEGREE) || (rotation360 > 360 - Consts::ROTATION_MAX_DEGREE);
}

bool Lander::goodLanding()
{
	return (isXSpeedOk() && isYSpeedOk() && isRotationOk());
}

void Lander::reset()
{
	rotation = -PI / 2;
	xPos = initXPos;
	yPos = initYPos;
	xSpeed = 0.0f;
	ySpeed = 0.0f;
	isFlameVisible = false;
}
