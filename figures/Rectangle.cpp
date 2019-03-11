#include <QRect>
#include "Rectangle.h"

void Rectangle::draw(QPainter* painter, QPoint corner) {
    int x = std::min(points->at(0).x(), corner.x());
    int y = std::min(points->at(0).y(), corner.y());

    int w = std::abs(points->at(0).x() - corner.x());
    int h = std::abs(points->at(0).y() - corner.y());

    painter->drawRect(x, y, w, h);
}

void Rectangle::draw(QPainter* painter) {
    draw(painter, points->back());
}

Rectangle::Rectangle(): Shape() {
    points_num = 2;
}

Rectangle::~Rectangle() {};
