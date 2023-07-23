#pragma once

#include "Counter.h"
#include "GeomMaster.h"
#include "Engine.h"
#include "cmath"
#include <stdint.h>

#define M_PI           3.14159265358979323846  /* pi */

/*
class Circle {
private:
	double centerDist_;
	double radius_;
	uint32_t color_;

	double veloc_ = 120;
	double angle_ = 0;
	double timeSinceLastChange_ = 0;
	double cooldown_ = 0.3;

	Point angp_[2] = {{0, 0}, {0, 0}};

public:
	size_t score_ = 0;
	bool clockwise_ = true;
	bool alive_ = true;

	Circle(double centerDist, double rad, uint32_t color) {
		centerDist_ = centerDist;
		radius_ = rad;
		color_ = color;
	}

	bool TryChangeDirection() {}

	void UpdateState(float dt) {}

	uint32_t GetColor() {}

	void UpdateCircleCents() {}

	bool GetCircleCollision(Point p, double rad) {}

	void Draw() {}
};
*/
void fillCircle(double x, double y, double rad, uint32_t color) {
	for (int i = x - rad; i <= x + rad; ++i) {
		for (int j = y - rad; j <= y + rad; ++j) {
			if (dist(i, j, x, y) <= rad)
				drawPix(i, j, color);
		}
	}
}

void fillCircle(Point& cen, double rad, uint32_t color) {
	for (int i = cen.x - rad; i <= cen.x + rad; ++i) {
		for (int j = cen.y - rad; j <= cen.y + rad; ++j) {
			if (dist(i, j, cen.x, cen.y) <= rad)
				drawPix(i, j, color);
		}
	}
}
