#pragma once

#include "Square.h"


class FoodSq : public Square {
private:
    const int white = 16777215;

    uint32_t GetColor_() {
        return white;
    }

    void KilledInAction_(PlayerCircles* p) {
        ++p->score_;
    }
};

