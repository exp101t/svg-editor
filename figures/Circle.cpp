#include <QPolygon>
#include <math.h>
#include "Circle.h"

void Circle::draw(QPainter* painter, QPoint corner) {
    int radius = static_cast<int>(sqrt(
        pow(points->at(0).x() - corner.x(), 2) +
        pow(points->at(0).y() - corner.y(), 2)
    ));

    painter->drawEllipse(points->at(0), radius, radius);
}

void Circle::draw(QPainter* painter) {
    draw(painter, points->back());
}

Circle::Circle(): Shape() {
    points_num = 2;
}

Circle::~Circle() {};
