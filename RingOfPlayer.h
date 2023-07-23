#pragma once

#include "Circle.h"
#include "Counter.h"
#include "GeomMaster.h"
#include "Engine.h"
#include "cmath"
#include <stdint.h>

#define M_PI           3.14159265358979323846  /* pi */


class PlayerCircles {
private:
	double centerDist_;
	double radius_;
	double veloc_ = 130;
	double angle_ = 0;
	double prevShift_ = 0;
	double cooldown_ = 0.3;
	uint32_t color_;

	Point angp_[2] = {{0, 0}, {0, 0}};

public:
	size_t score_ = 0;
	bool clockwise_ = true;
	bool alive_ = true;

	PlayerCircles(double centerDist, double rad, uint32_t color) {
		centerDist_ = centerDist;
		radius_ = rad;
		color_ = color;
	}

	bool TryChangeDirection() {
		if (prevShift_ < cooldown_)
			return false;
		clockwise_ = !clockwise_;
		prevShift_ = 0;
		return true;
	}

	void UpdateState(float dt) {
		if (clockwise_)
			angle_ += veloc_ * dt;
		else
			angle_ -= veloc_ * dt;

		while (angle_ >= 360 || angle_ < 0)	{
			if (angle_ < 0)
				angle_ += 360;
			if (angle_ >= 360)
				angle_ -= 360;
		}
		veloc_ += dt;
		prevShift_ += dt;

		UpdateCircleCents();
	}

	uint32_t GetColor()	{
		return color_;
	}

	void UpdateCircleCents() {
		double radAngle = angle_ * M_PI / 180;
		double x1 = screenCenter.x + centerDist_ * std::cos(radAngle),
			x2 = screenCenter.x - centerDist_ * std::cos(radAngle),
			y1 = screenCenter.y + centerDist_ * std::sin(radAngle),
			y2 = screenCenter.y - centerDist_ * std::sin(radAngle);

		angp_[0].x = x1;
		angp_[0].y = y1;
		angp_[1].x = x2;
		angp_[1].y = y2;
	}

	bool GetCircleCollision(Point p, double rad) {
		bool res = (dist(p, angp_[0]) <= radius_ + rad) || (dist(p, angp_[1]) <= radius_ + rad);

		return res;
	}

	void Draw()	{
		const int red = 16711680;
		fillCircle(angp_[0].x, angp_[0].y, radius_, color_);
		fillCircle(angp_[1].x, angp_[1].y, radius_, color_);

		DrawScore(score_, red);
	}

	// required to draw the central ring, on which "a player rides"
	void drawCentralRing() {
		const int ring_color = 6000000;
		const int background_color = 0xD3D3D3;
		fillCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 137, ring_color);
		fillCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 125, background_color);  // 0xC0C0C0?
	}
};

