#pragma once
#include "raylib.h"
#include <string>

class Lander
{
public: 
	Lander();
	Lander(std::string texturePathP, float xPosP, float yPosP, std::string flameTexturePathP);

	void load();
	void update();
	void draw();
	void unload();

private:
	const float GRAVITY{ 0.2f };
	const float THRUSTER{ -0.4f };
	const float ROTATION_SPEED{ 2.0f };

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
	float rotation{ 0.0f };
};

