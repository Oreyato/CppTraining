#pragma once

#include "Lander.h"
#include <string>

class LanderInterface
{
public:
	LanderInterface(int xPosP, int yPosP, Lander& landerP);
	
	void update(float dtP);
	void draw();

	std::string xSpeedFormat(float xSpeedP);
	std::string ySpeedFormat(float ySpeedP);
	std::string rotationFormat(int angleP);

private:
	Lander& lander;

	int xPos{ 0 };
	int yPos{ 0 };

	std::string xSpeedLabel{ "X speed: 0" };
	std::string ySpeedLabel{ "Y speed: 0" };
	std::string rotationLabel{ "Angle: 0" };
};

