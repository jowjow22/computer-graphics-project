#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rectangle.h"
#include "line.h"
#include "point.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QList<GenericObject *> worldObjectList;
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(5);

    painter.setPen(pen);


    Rectangle rect(600, 200, 30);
    Rectangle rect2(10, 100, 30);
    Line line(10, 10, 100, 100);
    Point point(150, 150);

    worldObjectList.append(&rect);
    worldObjectList.append(&rect2);
    worldObjectList.append(&line);
    worldObjectList.append(&point);

    for(GenericObject *list : worldObjectList){
        list->drawObject(&painter);
    }
}

