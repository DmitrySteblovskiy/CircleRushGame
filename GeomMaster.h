#pragma once

#include "Engine.h"
#include "Point.h"

#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <memory.h>
#include <numbers>


void drawLine(double x1, double y1, double x2, double y2, uint32_t color);
void drawLine(Point &p1, Point &p2, uint32_t color);

double multip(double x1, double y1, double x2, double y2, double x3, double y3);
double multip(Point &p1, Point &p2, Point &p3);
