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
#include "elementscombobox.h"

int xGlobal = 0;
int yGlobal = 0;
int SCALE = 300;
int Angle = 0;
int posX = 0;
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

    ElementsComboBox comboBox(parent);

    squirtleObj.fileObjReader();
    cuboneObj.fileObjReader();

    objects.append(squirtleObj);
    objects.append(cuboneObj);

    for(int i = 0; i < objects.length(); i++){
        objects[i].id = i;
    }

    for(ReadObj obj : objects){
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

    maxVPX = 600;
    maxVPY = 600;

    Window window(maxVPX, maxVPY, xGlobal, xGlobal+SCALE, yGlobal, yGlobal+SCALE);

    QList<QPoint> framePoints = {QPoint(-100 + xGlobal, 100 + yGlobal), QPoint(100 + xGlobal, 100 + yGlobal),
                                 QPoint(100 + xGlobal, -100 + yGlobal), QPoint(-100 + xGlobal, -100 + yGlobal)};

    Clipping frame(window.viewPortTransformPoint(framePoints));

        objects[idx].x = posX;
        objects[idx].angle = Angle;
        objects[idx].size = scaleObject;

        for(ReadObj object : objects){
            for(QLine line : object.draw(&window, &frame)){
                painter.drawLine(line);
            }
        }


    frame.drawFrame(&painter);
}

void MainWindow::plusWindowsX(){
    xGlobal += 10;
}

void MainWindow::minusWindowsX(){
    xGlobal -= 10;
}

void MainWindow::plusWindowsY(){
    yGlobal += 10;
}

void MainWindow::minusWindowsY(){
    yGlobal -= 10;
}

void MainWindow::plusObjectAngle() {
    Angle += 15;
}

void MainWindow::downObjectAngle() {
    Angle -= 15;
}

void MainWindow::plusObjectScale() {
    scaleObject += 2;
}
void MainWindow::downObjectScale() {
    scaleObject -= 2;
}
void MainWindow::plusObjectPosX() {
    posX += 2;
}

void MainWindow::downObjectPosX() {
    posX -= 2;
}

QLine MainWindow::transformLineToQLine(Line line) {
    return QLine(line.x1, line.y1, line.x2, line.y2);
}

QList<QLine> MainWindow::transformListOfLinesToListOfQLines(QList<Line> list) {
    QList<QLine> newList;
    for(Line line : list) {
        newList.append(transformLineToQLine(line));
    }
    return newList;
}


void MainWindow::on_pushButton_7_clicked()
{
      Angle += 15;
      update();
}


void MainWindow::on_pushButton_5_pressed()
{
    SCALE = SCALE > 0? SCALE - 25: 0;
          update();
}


void MainWindow::on_pushButton_6_clicked()
{
   SCALE +=25;
         update();
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    currentObject = index;
    scaleObject = objects[index].size;
    posX = objects[index].x;
    Angle = objects[index].angle;
    idx = index;
    ui->spinBox->setValue(posX);
    std::cout << index << std::endl;
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


void MainWindow::on_pushButton_8_pressed()
{
    scaleObject += 2;
    update();
}


void MainWindow::on_dial_sliderMoved(int position)
{
   Angle = position;
   update();
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    posX = arg1;
    update();
}

