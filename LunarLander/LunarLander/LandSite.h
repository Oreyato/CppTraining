#pragma once
#include "Sprite.h"

class LandSite :
	public Sprite
{
public:
	LandSite(std::string texturePathP, float xPosP, float yPosP);

	void changeSite();

};

