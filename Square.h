#pragma once

#include "GeomMaster.h"
#include "Engine.h"
#include "PolygonDrawer.h"
#include "RingOfPlayer.h"

#include <stdlib.h>

const int red = 16711680;

class Square {
private:
	Point pos = { 0, 0 };

	double size_ = 25;
	double vel_x_, vel_y_;
	double ang_, ang_vel_;

	Point angp_[4] = { {0,0}, {0,0}, {0,0}, {0,0} };

	virtual void KilledInAction_(PlayerCircles* p) {};
	
	virtual uint32_t GetColor_() {
		return red;
	};

public:
	Square* prev = NULL;
	Square* next = NULL;

	Square() {
		int side = rand() % 4;
		int x = rand() % SCREEN_WIDTH, y = rand() % SCREEN_HEIGHT;
		ang_ = rand() % 360;
		ang_vel_ = rand() % 360;

		switch (side) {
		case 0:
			y = 0;
			break;
		case 1:
			x = SCREEN_WIDTH;
			break;
		case 2:
			y = SCREEN_HEIGHT;
			break;
		case 4:

		default:
			x = 0;
			break;
		}

		pos.x = x;
		pos.y = y;

		vel_x_ = (SCREEN_WIDTH / 2 - pos.x) / 0.9;	// 1.0  0.5
		vel_y_ = (SCREEN_HEIGHT / 2 - pos.y) / 0.9;
	}

	void UpdateState(float dt) {
		pos.x += vel_x_ * dt;
		pos.y += vel_y_ * dt;
		ang_ += ang_vel_ * dt;

		while (ang_ >= 360 || ang_ < 0) {
			if (ang_ < 0)
				ang_ += 360;
			if (ang_ >= 360)
				ang_ -= 360;
		}
		UpdateSquareCorns();
	}

	bool CheckCollision(PlayerCircles* p) {
		if (p->GetCircleCollision(pos, size_ * 0.9)) {
			KilledInAction_(p);
			return true;
		}
		return false;
	}

	void UpdateSquareCorns() {
		double radAngle = ang_ * M_PI / 180;
		angp_[0].x = pos.x + size_ * cos(radAngle);
		angp_[0].y = pos.y + size_ * sin(radAngle);
		angp_[1].x = pos.x - size_ * sin(radAngle);
		angp_[1].y = pos.y + size_ * cos(radAngle);
		angp_[2].x = pos.x - size_ * cos(radAngle);
		angp_[2].y = pos.y - size_ * sin(radAngle);
		angp_[3].x = pos.x + size_ * sin(radAngle);
		angp_[3].y = pos.y - size_ * cos(radAngle);
	}

	void Draw() {
		fillPolygon(angp_, 4, GetColor_());
	}
};

