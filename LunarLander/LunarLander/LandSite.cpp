#include "LandSite.h"

LandSite::LandSite(std::string texturePathP, float xPosP, float yPosP) :
	texturePath{ texturePathP },
	xPos{ xPosP },
	yPos{ yPosP }
{
}

void LandSite::load()
{
	texture = LoadTexture(texturePath.c_str());
}

void LandSite::draw()
{
	DrawTexture(texture, xPos, yPos, WHITE);
}

void LandSite::unload()
{
	UnloadTexture(texture);
}
