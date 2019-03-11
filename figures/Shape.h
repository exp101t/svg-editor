#include <QVector>
#include <QPoint>
#include <QPainter>
#pragma once

class Shape {
public:
    QVector<QPoint>* points; int points_num;

    virtual void draw(QPainter*) = 0;
    virtual void draw(QPainter*, QPoint) = 0;

    virtual ~Shape(); explicit Shape();
};
