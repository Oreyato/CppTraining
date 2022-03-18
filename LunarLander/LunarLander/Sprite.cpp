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
	texture = LoadTexture(texturePath.c_str());
	if (centered) {
		origin = { (float)(texture.width / 2), (float)(texture.height / 2) };
	}
	srcRect = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
}

void Sprite::draw()
{
	if (visible) {
		float rotationInDegrees = rotation * 180.0f / PI;
		dstRect = { xPos, yPos, (float)texture.width, (float)texture.height };
		DrawTexturePro(texture, srcRect, dstRect, origin, rotationInDegrees, WHITE);
	}
}

void Sprite::unload()
{
	UnloadTexture(texture);
}

Rectangle Sprite::getRectangle()
{
	Rectangle rect{ xPos - origin.x, yPos - origin.y, (float)texture.width, (float)texture.height };

	return rect;
}
