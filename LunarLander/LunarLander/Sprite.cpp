#include "Sprite.h"

Sprite::Sprite(std::string texturePathP, float xPosP, float yPosP, float rotationP, bool centeredP) :
	texturePath{texturePathP},
	xPos{xPosP},
	yPos{yPosP},
	rotation{rotationP},
	centered{centeredP}
{
}

void Sprite::load()
{
}

void Sprite::draw()
{
}

void Sprite::unload()
{
}
