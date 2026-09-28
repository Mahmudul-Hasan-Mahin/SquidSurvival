#include "Level2.h"

void generatePolygonShape(int numPoints, double radius, double stepMultiplier) {
	numCheckpoints = numPoints;
	for (int i = 0; i < numPoints; i++) {
		double angle = (i * stepMultiplier * 2.0 * M_PI / numPoints) - (M_PI / 2.0);
		starX[i] = candyCenterX + radius * cos(angle);
		starY[i] = candyCenterY + radius * sin(angle);
		checkpointsVisited[i] = 0;
	}
}

void generateStarShape(int numPoints, double outerRadius, double innerRadius) {
	numCheckpoints = numPoints * 2;
	for (int i = 0; i < numCheckpoints; i++) {
		double r = (i % 2 == 0) ? outerRadius : innerRadius;
		double angle = (i * M_PI / numPoints) - (M_PI / 2.0);
		starX[i] = candyCenterX + r * cos(angle);
		starY[i] = candyCenterY + r * sin(angle);
		checkpointsVisited[i] = 0;
	}
}

void initLevel2() {
	// Easy = shapes 0-2, Medium = shapes 3-5, Hard = shapes 6-8. Falls back
	// to Medium if difficulty was never explicitly chosen.
	int poolStart;
	if (difficulty == DIFFICULTY_EASY) poolStart = 0;
	else if (difficulty == DIFFICULTY_HARD) poolStart = 6;
	else poolStart = 3;

	int shape = poolStart + rand() % 3;

	switch (shape) {
	case 0: generatePolygonShape(12, 100, 1); break;   // circle
	case 1: generatePolygonShape(3, 100, 1); break;    // triangle
	case 2: generatePolygonShape(4, 100, 1); break;    // square
	case 3: generatePolygonShape(5, 100, 1); break;    // pentagon
	case 4: generatePolygonShape(6, 100, 1); break;    // hexagon
	case 5: generatePolygonShape(8, 100, 1); break;    // octagon
	case 6: generateStarShape(6, 100, 58); break;      // Star of David
	case 7: generateStarShape(5, 100, 38); break;       // pentagram (outline only, no crossing lines)
	case 8: generatePolygonShape(13, 100, 1); break;   // umbrella (13-point rim)
	}

	isMouseDown = 0;
}

double distToSegment(double px, double py, double x1, double y1, double x2, double y2){
	double l2 = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
	if (l2 == 0) return hypot(px - x1, py - y1);
	double t = ((px - x1)*(x2 - x1) + (py - y1)*(y2 - y1)) / l2;
	if (t < 0){
		t = 0;
	}
	if (t>1){
		t = 1;
	}
	double projX = x1 + t*(x2 - x1);
	double projY = y1 + t*(y2 - y1);
	return hypot(px - projX, py - projY);
}

//Mouse button press + move
void iMouseMove(int mx, int my)
{
	if (gameState == STATE_LEVEL2 && isMouseDown){
		double minDist = 999999.0;
		for (int i = 0; i < numCheckpoints; i++){
			int next = (i + 1) % numCheckpoints;
			double d = distToSegment(mx, my, starX[i], starY[i], starX[next], starY[next]);
			if (d < minDist){
				minDist = d;
			}

			if (hypot(mx - starX[i], my - starY[i]) < 20){
				checkpointsVisited[i] = 1;
			}
		}

		if (minDist>LEVEL2_RADIUS){
			gameState = STATE_GAMEOVER;
		}

		int allVisited = 1;
		for (int i = 0; i < numCheckpoints; i++){
			if (!checkpointsVisited[i]){
				allVisited = 0;
			}
		}
		if (allVisited){
			score += 500;
			initLevel3();
			gameState = STATE_LEVEL3;
		}
	}
}