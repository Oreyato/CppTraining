#pragma once
#include "raylib.h"
#include <string>

#include "Sprite.h"

class Lander :
	public Sprite
{
public: 
	Lander();
	Lander(std::string texturePathP, float xPosP, float yPosP, bool centeredP);

	void update(float dtP);
	
	// Sprite functions overrides, for the flame
	void load() override;
	void draw() override;
	void unload() override;

	float getXSpeed() { return xSpeed; }
	float getYSpeed() { return ySpeed; }
	int getRotation360() { return rotation360; }

	void setXSpeed(float xSpeedP) { xSpeed = xSpeedP; }
	void setYSpeed(float ySpeedP) { ySpeed = ySpeedP; }
	void setIsFlameVisible(bool isFlameVisibleP) { isFlameVisible = isFlameVisibleP; }

	int rotationFormat();
	bool goodLanding();

private:
	const float GRAVITY{ 100.0f };
	const float THRUSTER{ -200.0f };
	const float ROTATION_SPEED{ 3.0f };

	Sprite flame{ "../assets/images/lander_flame.png", 0.0f, 0.0f, 0.0f, true };
	bool isFlameVisible{ false };

	int rotation360{ 0 };

	float xSpeed{ 0.0f };
	float ySpeed{ 0.0f };

	// Landing variables
	const float ROTATION_MAX_DEGREE{ 8.0f };
	const float MAX_XSPEED{ 1.0f };
	const float MAX_YSPEED{ 1.0f };
};

