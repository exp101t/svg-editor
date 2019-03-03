#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QCursor>
#include "line.cpp"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    active_shape = new Line();

    pixmap = new QPixmap(1000, 1000);
    pixmap->fill(Qt::white);

    this->setMouseTracking(true);
}

void Widget::mousePressEvent(QMouseEvent* event) {
    qDebug() << "Widget::mousePressEvent called";

    if (active_shape->points_num != active_shape->points->length() + 1) {
        active_shape->points->push_back(event->pos());
    } else {
        active_shape->points->push_back(event->pos());
        shapes.push_back(active_shape);
        active_shape = new Line();
    }
}

// Calls when window graphics need to be updated
void Widget::paintEvent(QPaintEvent* event) {
    qDebug() << "Widget::paintEvent called";
    painter = new QPainter(this);

    // What the reason to use QPixmap?!
    // It is absolutely useless
    // painter->drawPixmap(0, 0, *pixmap);

    painter->setPen(QPen(Qt::blue, 5));

    // Drawing existing figures
    for (Shape* figure: shapes)
        figure->draw(painter);

    // Drawing active figure
    if (active_shape->points_num == active_shape->points->length() + 1) {
        QPoint end = this->mapFromGlobal(QCursor::pos());
        active_shape->draw(painter, end);
    }
}

void Widget::mouseMoveEvent(QMouseEvent* event) {
    qDebug() << "Mouse event";
    if (active_shape->points_num == active_shape->points->length() + 1)
        update();
}

Widget::~Widget() {
    delete ui;
}
