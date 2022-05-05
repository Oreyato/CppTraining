#pragma once

class Consts
{
public:
	//v ==============================================================
	//	IMPORTANT NOTE:
	//	
	//	When working with static variables, it is very important
	//	to declare them in a .cpp file, not directly in the .h 
	//^ ==============================================================

	//
	static const float SCREEN_WIDTH;
	static const float SCREEN_HEIGHT;

	// UI
	static const int VERTICAL_SPACING;
	static const int XPOS_END_TEXT;
	static const int YPOS_END_TEXT;

	// Lander
	static const float GRAVITY;
	static const float THRUSTER;
	static const float ROTATION_SPEED;
	static const float ROTATION_MAX_DEGREE;
	static const float MAX_XSPEED;
	static const float MAX_YSPEED;

	// Landsite
	static const float LANDSITE_START_XPOS;
	static const float LANDSITE_START_YPOS;
	static const float LANDSITE_MIN_YPOS;
	static const float LANDSITE_WIDTH;

	// Mountains
	static const int MOUNTAIN_HEIGHT_START;
	static const int MOUNTAIN_SUMMIT_SEPARATOR;
	static const int MOUNTAIN_HEIGHT_MIN;
	static const int MOUNTAIN_POINTS_SPACING;
};