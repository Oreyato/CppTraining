#pragma once
#include "raylib.h"
#include <string>

class Lander
{
public: 
	Lander();
	Lander(std::string texturePathP, float xPosP, float yPosP, std::string flameTexturePathP);

	void load();
	void update(float dtP);
	void draw();
	void unload();

private:
	const float GRAVITY{ 100.0f };
	const float THRUSTER{ -200.0f };
	const float ROTATION_SPEED{ 100.0f };

	Texture2D texture;
	Texture2D flameTexture;
	std::string texturePath{ "" };
	std::string flameTexturePath{ "" };

	bool isFlameVisible{ false };

	Rectangle srcRect{ 0.0f,0.0f,0.0f,0.0f };
	Rectangle dstRect{ 0.0f,0.0f,0.0f,0.0f };
	Vector2 origin{ 0.0f,0.0f };

	float xPos{ 0.0f };
	float yPos{ 0.0f };
	float xSpeed{ 0.0f };
	float ySpeed{ 0.0f };
	float rotation{ -PI / 2.0f };
};

