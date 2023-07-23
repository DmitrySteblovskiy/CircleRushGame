#pragma once

#include "GeomMaster.h"

#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <memory.h>


bool pointInTriangle(double x, double y, Point& v1, Point& v2, Point& v3) {
	double d1, d2, d3;
	bool has_neg, has_pos;

	d1 = multip(x, y, v1.x, v1.y, v2.x, v2.y);
	d2 = multip(x, y, v2.x, v2.y, v3.x, v3.y);
	d3 = multip(x, y, v3.x, v3.y, v1.x, v1.y);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}

bool pointInTriangle(Point& pt, Point& v1, Point& v2, Point& v3) {
	return pointInTriangle(pt.x, pt.y, v1, v2, v3);
}

void fillTriangle(Point& p1, Point& p2, Point& p3, uint32_t color) {
	int minX = std::min({ p1.x, p2.x, p3.x }), maxX = std::max({ p1.x, p2.x, p3.x });
	int minY = std::min({ p1.y, p2.y, p3.y }), maxY = std::max({ p1.y, p2.y, p3.y });

	for (int i = minX; i <= maxX; ++i) {
		bool flag = false;
		for (int j = minY; j < maxY; ++j) {
			if (pointInTriangle(i, j, p1, p2, p3)) {
				flag = true;
				drawPix(i, j, color);
			}
			else if (flag) {
				break;
			}
		}
	}
}

void fillPolygon(Point pointArray[], int pointCount, uint32_t color) {
	for (int i = 1; i < pointCount - 1; ++i) {
		fillTriangle(pointArray[0], pointArray[i], pointArray[i + 1], color);
	}
}