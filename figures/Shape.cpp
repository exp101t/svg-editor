#include "Shape.h"

Shape::Shape() {
    points = new QVector<QPoint>;
}

Shape::~Shape() {
    delete points;
}
