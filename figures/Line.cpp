#include <QLine>
#include "Line.h"

void Line::draw(QPainter* painter, QPoint end) {
    painter->drawLine(points->at(0), end);
}

void Line::draw(QPainter* painter) {
    draw(painter, points->back());
}

Line::Line(): Shape() {
    points_num = 2;
}

Line::~Line() {};
