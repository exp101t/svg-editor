#include "Shape.h"
#pragma once

class Triangle: public Shape {
public:
    void draw(QPainter*) override;
    void draw(QPainter*, QPoint) override;

    ~Triangle() override; explicit Triangle();
};
