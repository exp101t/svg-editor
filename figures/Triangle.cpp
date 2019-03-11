#include <QPolygon>
#include "Triangle.h"

void Triangle::draw(QPainter* painter, QPoint corner) {
    points->push_back(corner);
    painter->drawPolygon(points->begin(), 3);
    points->pop_back();
}

void Triangle::draw(QPainter* painter) {
    draw(painter, points->back());
}

Triangle::Triangle(): Shape() {
    points_num = 3;
}

Triangle::~Triangle() {};
