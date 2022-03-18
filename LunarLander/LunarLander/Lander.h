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

private:
	const float GRAVITY{ 100.0f };
	const float THRUSTER{ -200.0f };
	const float ROTATION_SPEED{ 3.0f };

	bool isFlameVisible{ false };

	float xSpeed{ 0.0f };
	float ySpeed{ 0.0f };
};

