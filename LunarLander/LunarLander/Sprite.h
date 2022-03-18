#pragma once
#include "raylib.h"
#include <string>

class Sprite
{
public:
	Sprite();
	Sprite(std::string texturePathP, float xPosP, float yPosP, float rotationP, bool centeredP);

	virtual void load();
	virtual void draw();
	virtual void unload();

	float getXPos() { return xPos; }
	float getYPos() { return yPos; }
	float getRotation() { return rotation; }
	bool getVisible() { return visible; }
	Rectangle getRectangle();

	void setXPos(float xPosP) { xPos = xPosP; }
	void setYPos(float yPosP) { yPos = yPosP; }
	void setRotation(float rotationP) { rotation = rotationP; }
	void setVisible(bool visibleP) { visible = visibleP; }

protected:
	Texture2D texture;
	std::string texturePath{ "" };

	Rectangle srcRect{ 0.0f,0.0f,0.0f,0.0f };
	Rectangle dstRect{ 0.0f,0.0f,0.0f,0.0f };
	Vector2 origin{ 0.0f,0.0f };

	float xPos{ 0.0f };
	float yPos{ 0.0f };
	float rotation{ 0.0f };

	bool visible{ true };
	bool centered{ false };
};

