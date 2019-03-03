#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPixmap>
#include "shape.h"
#pragma once

namespace Ui {
    class Widget;
}

class Widget: public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
     void mousePressEvent(QMouseEvent*);
     void paintEvent(QPaintEvent*);
     void mouseMoveEvent(QMouseEvent*);

private:
    Ui::Widget* ui;
    QPixmap* pixmap;
    QPainter* painter;
    QVector<Shape*> shapes;
    Shape* active_shape;
};
