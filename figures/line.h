#include "shape.h"
#pragma once

class Line: public Shape {
public:
    void draw(QPainter*) override;
    void draw(QPainter*, QPoint) override;

    ~Line() override; explicit Line();
};
