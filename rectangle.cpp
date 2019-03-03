#include <QRect>
#include "rectangle.h"

void Rectangle::draw(QPainter* painter) {
    int x = std::min(points->at(0).x(), points->at(1).x());
    int y = std::min(points->at(0).y(), points->at(1).y());

    int w = std::abs(points->at(0).x() - points->at(1).x());
    int h = std::abs(points->at(0).y() - points->at(1).y());

    painter->drawRect(x, y, w, h);
}

void Rectangle::draw(QPainter* painter, QPoint corner) {
    int x = std::min(points->at(0).x(), corner.x());
    int y = std::min(points->at(0).y(), corner.y());

    int w = std::abs(points->at(0).x() - corner.x());
    int h = std::abs(points->at(0).y() - corner.y());

    painter->drawRect(x, y, w, h);
}

Rectangle::Rectangle(): Shape() {
    points_num = 2;
}

Rectangle::~Rectangle() {};
