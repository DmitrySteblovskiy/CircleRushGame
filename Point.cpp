#include "Point.h"

#include <algorithm>
#include <cmath>

#define M_PI           3.14159265358979323846  /* pi */

bool ifOnScreen(double x, double y) {
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
		return true;
	return false;
}

bool ifOnScreen(Point& p) {
	return ifOnScreen(p.x, p.y);
}

void drawPix(double x, double y, uint32_t color) {
	if (ifOnScreen(x, y)) {
		int nx = std::rint(x), ny = std::rint(y);
		buffer[ny][nx] = color;
	}
}

void drawPix(Point& p, uint32_t color) {
	drawPix(p.x, p.y, color);
}

double diagDist(double x1, double y1, double x2, double y2) {
	return std::max(abs(x1 - x2), abs(y1 - y2));
}

double diagDist(Point& p1, Point& p2) {
	return diagDist(p1.x, p1.y, p2.x, p2.y);
}

double dist(double x1, double y1, double x2, double y2) {
	return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
//get max of x-distance and y-distance between set points
double dist(Point& p1, Point& p2) {
	return dist(p1.x, p1.y, p2.x, p2.y);
}

Point rotatePoint(Point& v, Point& p, double angle) {
	int x = v.x - p.x;
	int y = v.y - p.y;

	double radAngle = angle * M_PI / 180;
	double cosA = cos(radAngle), sinA = sin(radAngle);

	v.x = std::rintf(x * cosA - y * sinA + p.x);
	v.y = std::rintf(x * sinA + y * cosA + p.y);

	return v;
}

Point rotatePoint(int x, int y, Point& p, double angle) {
	int nx = x - p.x;
	int ny = y - p.y;

	double radAngle = angle * M_PI / 180;
	double cosA = cos(radAngle), sinA = sin(radAngle);

	Point v = {
		std::rintf(nx * cosA - ny * sinA + p.x),
		std::rintf(nx * sinA + ny * cosA + p.y) };

	return v;
}