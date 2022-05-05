#include "LandSite.h"
#include "Consts.h"

LandSite::LandSite(std::string texturePathP, float xPosP, float yPosP) :
	Sprite{ texturePathP, xPosP, yPosP, 0.0f, false }
{
}

void LandSite::changeSite()
{
	float numberFromZeroToOne = (float)rand() / (float)RAND_MAX;
	xPos = numberFromZeroToOne * (Consts::SCREEN_WIDTH - Consts::LANDSITE_WIDTH);

	numberFromZeroToOne = (float)rand() / (float)RAND_MAX;
	yPos = numberFromZeroToOne * (Consts::SCREEN_HEIGHT - Consts::LANDSITE_MIN_YPOS) + Consts::LANDSITE_MIN_YPOS;
}
