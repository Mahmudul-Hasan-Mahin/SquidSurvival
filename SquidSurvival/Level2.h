#pragma once

#include "Level3.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Variables.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initLevel2();

// numPoints evenly spaced points around a circle of the given radius.
// stepMultiplier=1 gives a plain regular polygon (triangle, pentagon, ...).
// stepMultiplier=2 (only valid when numPoints is odd, e.g. 5) skips every
// other point, tracing a classic one-stroke crossing-line star instead.
void generatePolygonShape(int numPoints, double radius, double stepMultiplier);

// A numPoints-tipped star traced as one continuous outline: alternates
// between outerRadius (the tips) and innerRadius (the notches between
// them). This is how the Star of David is drawn here, since two separate
// triangles can't be traced in a single continuous stroke.
void generateStarShape(int numPoints, double outerRadius, double innerRadius);

double distToSegment(double px, double py, double x1, double y1, double x2, double y2);

void iMouseMove(int mx, int my);