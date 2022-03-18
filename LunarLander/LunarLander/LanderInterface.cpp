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
	xSpeedLabel = xSpeedFormat(lander.getXSpeed());
	ySpeedLabel = ySpeedFormat(lander.getYSpeed());
	rotationLabel = rotationFormat(lander.getRotation360());
}

void LanderInterface::draw()
{
	DrawText(xSpeedLabel.c_str(), xPos, yPos, 10, WHITE);
	DrawText(ySpeedLabel.c_str(), xPos, yPos + VERTICAL_SPACING, 10, WHITE);
	DrawText(rotationLabel.c_str(), xPos, yPos + VERTICAL_SPACING * 2, 10, WHITE);
}

std::string LanderInterface::xSpeedFormat(float xSpeedP)
{
	std::string xSpeedValue{ "" };
	if (xSpeedP < 0.0f) {
		xSpeedValue = std::to_string(xSpeedP).substr(0, 6);
	}
	else {
		xSpeedValue = std::to_string(xSpeedP).substr(0, 5);
	}

	std::string xSpeedText = "X speed: " + xSpeedValue;

	return xSpeedText;
}

std::string LanderInterface::ySpeedFormat(float ySpeedP)
{
	std::string ySpeedValue{ "" };
	if (ySpeedP < 0.0f) {
		ySpeedValue = std::to_string(ySpeedP).substr(0, 6);
	}
	else {
		ySpeedValue = std::to_string(ySpeedP).substr(0, 5);
	}

	std::string ySpeedText = "Y speed: " + ySpeedValue;

	return ySpeedText;
}

std::string LanderInterface::rotationFormat(int angleP)
{
	std::string rotationText = "Angle: " + std::to_string(angleP);
	
	return rotationText;
}
