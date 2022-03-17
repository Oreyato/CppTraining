#pragma once
#include "raylib.h"
#include <string>

class LandSite
{
public:
	LandSite(std::string texturePathP, float xPosP, float yPosP);

	void load();
	void draw();
	void unload();

private:
	std::string texturePath{ "" };
	Texture2D texture;

	float xPos{ 0.0f };
	float yPos{ 0.0f };
};

