#include "Counter.h"
#include "Point.h"

#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <memory.h>

void DrawNumber(int x, int y, int num, uint32_t color) {
	Counter cnt;
	static int size = 5;
	for (int nx = x + 5 * size / 2; nx > x - 5 * size / 2; --nx) {
		for (int ny = y + 7 * size / 2; ny > y - 7 * size / 2; --ny)
		{
			int i = (2 * size + nx - x) / size, j = (3 * size + ny - y) / size;
			if (cnt.numbers[num][j][i]) {
				drawPix(nx, ny, color);
			}
		}
	}
}

void DrawScore(int score, uint32_t color) {
	static int size = 5;
	int num = score;
	int chCount = (int)log10(score);

	for (int i = 0; i <= chCount; ++i) {
		DrawNumber(50 + 6 * size * (chCount / 2 - i), 50, num % 10, color);
		num /= 10;
	}
}