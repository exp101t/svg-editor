#include "Shape.h"
#pragma once

class Circle: public Shape {
public:
    void draw(QPainter*) override;
    void draw(QPainter*, QPoint) override;

    ~Circle() override; explicit Circle();
};
