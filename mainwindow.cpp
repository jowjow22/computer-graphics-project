#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScreen>
#include <QPainter>
#include <QScreen>
#include "window.h"
#include "clipping.h"
#include "line.h"
#include <QLine>
#include "readobj.h"

int xGlobal = 0;
int yGlobal = 0;
int SCALE = 300;
int AngleX = 0;
int AngleY = 0;
int AngleZ = 0;
int posX = 0;
int posY = 0;
int posZ = 0;
float scaleObject = 10;
int maxVPX;
int idx;
int maxVPY;
ReadObj squirtleObj("cubone", Qt::blue, 100);
ReadObj cuboneObj("zoubat", Qt::green, 0);

QList<ReadObj> objects = {};

int currentObject;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    squirtleObj.fileObjReader();
    cuboneObj.fileObjReader();

    objects.append(squirtleObj);
    objects.append(cuboneObj);

    for(ReadObj& obj : objects){
        ui->comboBox->addItem(obj.fileName);
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(1);
    painter.setPen(pen);

    maxVPX = 1000;
    maxVPY = 1000;

    Window window(maxVPX, maxVPY, xGlobal, xGlobal+SCALE, yGlobal, yGlobal+SCALE);

    QList<QPoint> framePoints = {QPoint(-100 + xGlobal, 100 + yGlobal), QPoint(100 + xGlobal, 100 + yGlobal),
                                 QPoint(100 + xGlobal, -100 + yGlobal), QPoint(-100 + xGlobal, -100 + yGlobal)};

    Clipping frame(window.viewPortTransformPoint(framePoints));

        objects[idx].x = posX;
        objects[idx].y = posY;
        objects[idx].z = posZ;
        objects[idx].angleX = AngleX;
        objects[idx].angleY = AngleY;
        objects[idx].angleZ = AngleZ;
        objects[idx].size = scaleObject;

        for(ReadObj object : objects){
            for(QLine line : object.draw(&window, &frame)){
                painter.drawLine(line);
            }
        }


    frame.drawFrame(&painter);
}

QLine MainWindow::transformLineToQLine(Line line) {
    return QLine(line.x1, line.y1, line.x2, line.y2);
}

QList<QLine> MainWindow::transformListOfLinesToListOfQLines(QList<Line> list) {
    QList<QLine> newList;
    for(Line& line : list) {
        newList.append(transformLineToQLine(line));
    }
    return newList;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    currentObject = index;
    scaleObject = objects[index].size;
    posX = objects[index].x;
    posY = objects[index].y;
    posZ = objects[index].z;
    AngleX = objects[index].angleX;
    AngleY = objects[index].angleY;
    AngleZ = objects[index].angleZ;
    idx = index;
    ui->spinBox->setValue(posX);
    ui->spinBox_3->setValue(posY);
    ui->spinBox_4->setValue(posZ);
    ui->spinBox_5->setValue(scaleObject);
    update();
}


void MainWindow::on_verticalSlider_sliderMoved(int position)
{
    yGlobal = position;
    update();
}


void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    xGlobal = position;
    update();
}

void MainWindow::on_dial_sliderMoved(int position)
{
   AngleX = position;
   update();
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    posX = arg1;
    update();
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    SCALE = arg1;
    update();
}


void MainWindow::on_dial_2_sliderMoved(int position)
{
    AngleY = position;
    update();
}


void MainWindow::on_dial_3_sliderMoved(int position)
{
    AngleZ = position;
    update();
}


void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    posY = arg1;
    update();
}


void MainWindow::on_spinBox_4_valueChanged(int arg1)
{
    posZ = arg1;
    update();
}


void MainWindow::on_spinBox_5_valueChanged(int arg1)
{
    scaleObject = arg1;
    update();
}

