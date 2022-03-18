#include "LanderInterface.h"
#include "raylib.h"

LanderInterface::LanderInterface(int xPosP, int yPosP, Lander& landerP) :
	xPos(xPosP),
	yPos(yPosP),
	lander(landerP)
{
}

void LanderInterface::update(float dtP)
{
	xSpeedLabel = "X speed: " + std::to_string(lander.getXSpeed());
	ySpeedLabel = "Y speed: " + std::to_string(lander.getYSpeed());
	rotationLabel = "Angle: " + std::to_string(lander.getRotation());
}

void LanderInterface::draw()
{
	DrawText(xSpeedLabel.c_str(), xPos, yPos, 10, WHITE);
	DrawText(ySpeedLabel.c_str(), xPos, yPos + VERTICAL_SPACING, 10, WHITE);
	DrawText(rotationLabel.c_str(), xPos, yPos + VERTICAL_SPACING * 2, 10, WHITE);
}
