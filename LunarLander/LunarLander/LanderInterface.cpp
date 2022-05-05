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
	// Check for landing conditions
	xSpeedOk = lander.isXSpeedOk();
	ySpeedOk = lander.isYSpeedOk();
	rotationOk = lander.isRotationOk();

	// Modify labels
	xPosLabel = xPosFormat(lander.getXPos());
	yPosLabel = yPosFormat(lander.getYPos());

	xSpeedLabel = xSpeedFormat(lander.getXSpeed());
	ySpeedLabel = ySpeedFormat(lander.getYSpeed());
	rotationLabel = rotationFormat(lander.getRotation360());
}

void LanderInterface::draw()
{
	// Modify indications colors 
	// Heavy version
	Color xSpeedColor;
	if (xSpeedOk) {
		xSpeedColor = WHITE;
	}
	else xSpeedColor = RED;
	// Lighter version - ternary operator
	Color ySpeedColor = ySpeedOk ? WHITE : RED;
	Color rotationColor = rotationOk ? WHITE : RED;

	// DrawText(xPosLabel.c_str(), xPos, yPos, 10, WHITE);
	// DrawText(yPosLabel.c_str(), xPos, yPos + Consts::VERTICAL_SPACING * 1, 10, WHITE);

	DrawText(xSpeedLabel.c_str(), xPos, yPos + Consts::VERTICAL_SPACING * 2, 10, xSpeedColor);
	DrawText(ySpeedLabel.c_str(), xPos, yPos + Consts::VERTICAL_SPACING * 3, 10, ySpeedColor);
	DrawText(rotationLabel.c_str(), xPos, yPos + Consts::VERTICAL_SPACING * 4, 10, rotationColor);

	if (isEndTextVisible) {
		DrawText(endText.c_str(), xPos + Consts::XPOS_END_TEXT, yPos + Consts::YPOS_END_TEXT, 20, endTextColor);
		DrawText(streakLabel.c_str(), xPos + Consts::XPOS_END_TEXT, yPos + Consts::YPOS_END_TEXT + Consts::VERTICAL_SPACING * 4, 15, WHITE);
		DrawText(bestStreakLabel.c_str(), xPos + Consts::XPOS_END_TEXT, yPos + Consts::YPOS_END_TEXT + Consts::VERTICAL_SPACING * 5, 15, WHITE);
	}
}

std::string LanderInterface::xPosFormat(float xPosP)
{
	std::string xPosValue = std::to_string(xPosP);

	return xPosValue;
}

std::string LanderInterface::yPosFormat(float yPosP)
{
	std::string yPosValue = std::to_string(yPosP);

	return yPosValue;
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

std::string LanderInterface::streakFormat(float streakP)
{
	std::string streakText = "Current streak: " + std::to_string(streakP).substr(0,1);
	streakLabel = streakText;

	return streakText;
}

std::string LanderInterface::bestStreakFormat(float bestStreakP)
{
	std::string bestStreakText = "Best streak: " + std::to_string(bestStreakP).substr(0, 1);
	bestStreakLabel = bestStreakText;

	return bestStreakText;
}

void LanderInterface::showEndText(int state)
{
	if (state == 1) { // Win state
		endText = "Perfect landing!\nPress \"R\" to try again";
		endTextColor = GREEN;
	}
	else if (state == 2) { // Lose state
		endText = "Lander destroyed...\nPress \"R\" to try again";
		endTextColor = RED;
	}

	isEndTextVisible = true;
}

void LanderInterface::hideEndText()
{
	isEndTextVisible = false;
}
