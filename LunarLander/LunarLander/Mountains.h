#pragma once

#include "Line.h"
#include <vector>

class Mountains
{
public:
	Mountains(float siteXposP, float siteYposP);
	
	void draw();
	void eraseLines();
	void addLine(Vector2 startP, Vector2 endP);
	void drawLines(float siteXposP, float siteYposP);

	std::vector<Line> getLines() { return lines; }
	std::vector<Vector2> getPointsCoordinates() { return pointsCoordinates; }

	void setLines(std::vector<Line> linesP) { lines = linesP; }

private:
	std::vector<Line> lines;
	std::vector<Vector2> pointsCoordinates;
};

