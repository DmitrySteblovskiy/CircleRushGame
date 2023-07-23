#pragma once

#include "Square.h"


class KillingSquare : public Square {
private:
    const int black = 0;

    uint32_t GetColor_() {
        return black;
    }

    void KilledInAction_(PlayerCircles* p) {
        p->alive_ = false;
    }
};

