#include "shape.h"
#pragma once

class Rectangle: public Shape {
public:
    void draw(QPainter*) override;
    void draw(QPainter*, QPoint) override;

    ~Rectangle() override; explicit Rectangle();
};
