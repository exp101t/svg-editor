#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QCursor>
#include "figures/Line.cpp"
#include "figures/Rectangle.h"
#include "figures/Triangle.h"

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    active_shape = new Triangle();

    pixmap = new QPixmap(1000, 1000);
    pixmap->fill(Qt::white);

    this->setMouseTracking(true);

    // Here is initialising the interface
    h_layout = new QHBoxLayout();
    h_layout->setAlignment(Qt::AlignLeft);

    QIcon line_icon = QIcon(QCoreApplication::applicationDirPath() + "/icons/line.png");
    line = new QPushButton();
    line->setIcon(line_icon);
    line->setFixedSize(30, 30);

    QIcon rect_icon = QIcon(QCoreApplication::applicationDirPath() + "/icons/rect.png");
    rect = new QPushButton();
    rect->setIcon(rect_icon);
    rect->setFixedSize(30, 30);

    buttons = new QGridLayout();
    buttons->setAlignment(Qt::AlignLeft);
    buttons->addWidget(line, 1, 2);
    buttons->addWidget(rect, 2, 1);

    button_group = new QGroupBox(" Lol, simple buttons ");
    button_group->setLayout(buttons);

    move = new QRadioButton("Move object");
    rotate = new QRadioButton("Rotate object");

    instruments = new QVBoxLayout();
    instruments->addWidget(move);
    instruments->addWidget(rotate);
    instruments->addStretch(1);

    radio_group = new QGroupBox(" Lol, radio buttons ");
    radio_group->setLayout(instruments);

    footer_test = new QLabel("Third");

    additional = new QVBoxLayout();
    additional->addWidget(footer_test);

    additional_group = new QGroupBox(" Lol, something else ");
    additional_group->setLayout(additional);

    tool_list = new QVBoxLayout();
    tool_list->addWidget(button_group);
    tool_list->addWidget(radio_group);
    tool_list->addWidget(additional_group);

    // Just for fixed width of tool_list
    // https://stackoverflow.com/a/19816024
    v_widget = new QWidget();
    v_widget->setLayout(tool_list);
    v_widget->setFixedWidth(250);

    h_layout->addWidget(v_widget);

    setLayout(h_layout);
    setWindowTitle(tr("Super Drawer (by @exp101t)"));
}

void Widget::mousePressEvent(QMouseEvent* event) {
    qDebug() << "Widget::mousePressEvent called";

    if (active_shape->points_num != active_shape->points->length() + 1) {
        active_shape->points->push_back(event->pos());
    } else {
        active_shape->points->push_back(event->pos());
        shapes.push_back(active_shape);
        active_shape = new Triangle();
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
    // qDebug() << "Mouse event";
    if (active_shape->points_num == active_shape->points->length() + 1)
        update();
}

Widget::~Widget() {
    delete ui;
}
