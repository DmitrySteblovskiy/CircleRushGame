#pragma once

#include "Engine.h"


class Point {
public:
	double x, y;
};

const Point screenCenter = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };

bool ifOnScreen(double x, double y);
bool ifOnScreen(Point& p);


void drawPix(double x, double y, uint32_t color);
void drawPix(Point& p, uint32_t color);

double diagDist(double x1, double y1, double x2, double y2);
double diagDist(Point& p1, Point& p2);

double dist(double x1, double y1, double x2, double y2);
double dist(Point& p1, Point& p2);

Point rotatePoint(Point& v, Point& p, double angle);
Point rotatePoint(int x, int y, Point& p, double angle);
