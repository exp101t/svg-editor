#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPixmap>
#include "figures/Shape.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QRadioButton>
#include <QGroupBox>
#include <QIcon>

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

    QGroupBox* radio_group, *button_group, *additional_group;
    QRadioButton *move, *rotate;
    QPushButton *line, *rect;

    QVBoxLayout *tool_list, *instruments, *additional;
    QHBoxLayout* h_layout;
    QGridLayout* buttons;

    QLabel *footer_test, *main_test;
    QWidget* v_widget;
};
