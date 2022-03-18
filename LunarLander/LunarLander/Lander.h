#pragma once
#include "raylib.h"
#include <string>

#include "Sprite.h"
#include "Consts.h"

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

	void reset();

private:
	Sprite flame{ "../assets/images/lander_flame.png", 0.0f, 0.0f, 0.0f, true };
	bool isFlameVisible{ false };

	int rotation360{ 0 };

	float xSpeed{ 0.0f };
	float ySpeed{ 0.0f };

	float initXPos{ 0.0f };
	float initYPos{ 0.0f };
};

