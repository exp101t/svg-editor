#include <QLine>
#include "line.h"

void Line::draw(QPainter* painter) {
    painter->drawLine(points->at(0), points->at(1));
}

void Line::draw(QPainter* painter, QPoint end) {
    painter->drawLine(points->at(0), end);
}

Line::Line(): Shape() {
    points_num = 2;
}

Line::~Line() {};
