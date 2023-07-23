#include "GeomMaster.h"

#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <memory.h>

#define M_PI           3.14159265358979323846  /* pi */


void drawLine(double x1, double y1, double x2, double y2, uint32_t color) {
	double N = diagDist(x1, y1, x2, y2);
	double newX, newY;
	for (int i = 0; i < N; ++i)	{
		double t = (N == 0 ? 0.0 : (double)i / N);
		newX = std::lerp((double)x1, (double)x2, t);
		newY = std::lerp((double)y1, (double)y2, t);
		drawPix(newX, newY, color);
	}
}

void drawLine(Point &p1, Point &p2, uint32_t color) {
	drawLine(p1.x, p1.y, p2.x, p2.y, color);
}

double multip(double x1, double y1, double x2, double y2, double x3, double y3) {
	return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
}

double multip(Point &p1, Point &p2, Point &p3) {
	return multip(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
}
