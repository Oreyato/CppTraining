#pragma once

#include "Lander.h"
#include <string>

class LanderInterface
{
public:
	LanderInterface(int xPosP, int yPosP, Lander& landerP);
	
	void update(float dtP);
	void draw();

	std::string xPosFormat(float xPosP);
	std::string yPosFormat(float yPosP);
	std::string xSpeedFormat(float xSpeedP);
	std::string ySpeedFormat(float ySpeedP);
	std::string rotationFormat(int angleP);

	std::string streakFormat(float streakP);
	std::string bestStreakFormat(float bestStreakP);

	void showEndText(int state);
	void hideEndText();

private:
	Lander& lander;

	bool isEndTextVisible{ false };

	bool xSpeedOk{ false };
	bool ySpeedOk{ false };
	bool rotationOk{ false };

	int xPos{ 0 };
	int yPos{ 0 };

	std::string xPosLabel{ "X pos: 0" };
	std::string yPosLabel{ "Y pos: 0" };

	std::string xSpeedLabel{ "X speed: 0" };
	std::string ySpeedLabel{ "Y speed: 0" };
	std::string rotationLabel{ "Angle: 0" };

	int streakTextSize{ 0 };
	std::string streakLabel{ "Current streak: 0" };
	std::string bestStreakLabel{ "Best streak: 0" };

	int endTextSize{ 0 };
	std::string endText{ "End text" };
	Color endTextColor{WHITE};
};

