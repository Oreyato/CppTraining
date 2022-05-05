#include "Mountains.h"
#include "Consts.h"
#include <math.h>

Mountains::Mountains(float siteXposP, float siteYposP)
{
	drawLines(siteXposP, siteYposP);
}

void Mountains::draw()
{
	for (Line line : lines) {
		DrawLineV(line.start, line.end, WHITE);
	}
}

void Mountains::eraseLines()
{
	lines.clear();
}

void Mountains::addLine(Vector2 startP, Vector2 endP)
{
	// Create a new line and add it inside the vector
	Line line{ startP, endP };
	lines.push_back(line);

	// Line equation ========================
	// Find a
	float a = (endP.y - startP.y) / (endP.x - startP.x);
	float range = endP.x - startP.x;

	// Add points along the line to pointsCoordinates vector
	for (int x = startP.x; x < range; x += Consts::MOUNTAIN_POINTS_SPACING)
	{
		Vector2 point{ x, a * x };

		pointsCoordinates.push_back(point);
	}
}

void Mountains::drawLines(float siteXposP, float siteYposP)
{
	int summitNumber = Consts::SCREEN_WIDTH / Consts::MOUNTAIN_SUMMIT_SEPARATOR;

	Vector2 start{ 0, (float)Consts::MOUNTAIN_HEIGHT_START };
	Vector2 end{ 0, (float)Consts::MOUNTAIN_HEIGHT_START };

	int iSiteStart = floor(((int)siteXposP - 1) / Consts::MOUNTAIN_SUMMIT_SEPARATOR);
	bool mustDrawEnd = false;

	int i = 0;
	while (i < summitNumber) {
		// Draw line before site
		if (i == iSiteStart && !mustDrawEnd) {
			end = { siteXposP, siteYposP };
			addLine(start, end);
			start = { end.x + Consts::LANDSITE_WIDTH, end.y };

			if (start.x >= (i + 1) * Consts::MOUNTAIN_SUMMIT_SEPARATOR) {
				// Give summit from where to start to draw again
				i = floor(start.x / Consts::MOUNTAIN_SUMMIT_SEPARATOR);
			}
			// If the site is to short to go to the next summit
			else {
				mustDrawEnd = true;
			}

		}
		// Draw line after site
		else if (i == iSiteStart && mustDrawEnd) {
			// Define end point
			float randNum = (float)rand() / (float)RAND_MAX;
			end = { (float)((i + 1) * Consts::MOUNTAIN_SUMMIT_SEPARATOR), randNum * (Consts::SCREEN_HEIGHT - Consts::MOUNTAIN_HEIGHT_MIN) + Consts::MOUNTAIN_HEIGHT_MIN };

			// Add line
			addLine(start, end);

			// Define new line start
			start = { end.x, end.y };

			++i;
		}
		// Other lines
		else {
			// Define end point
			float randNum = (float)rand() / (float)RAND_MAX;
			end = { (float)(start.x + Consts::MOUNTAIN_SUMMIT_SEPARATOR), randNum * (Consts::SCREEN_HEIGHT - Consts::MOUNTAIN_HEIGHT_MIN) + Consts::MOUNTAIN_HEIGHT_MIN };

			// Add line
			addLine(start, end);

			// Define new line start
			start = { end.x, end.y };

			++i;
		}
	}
}
