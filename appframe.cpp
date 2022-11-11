#include "appframe.h"
#include <QScreen>
#include "window.h"
#include "clipping.h"
#include "line.h"
#include <QLine>
#include "readobj.h"
#include "elementscombobox.h"
#include "transformations3d.h"

int xGlobal = 0;
int yGlobal = 0;
int SCALE = 300;
int angleX = 0;
int angleY = 0;
int angleZ = 0;
int posX = 0;
int posY = 0;
int posZ = 0;
float scaleObject = 0;
int maxVPX;
int maxVPY;
ReadObj fileUser;
ReadObj fileUser2;

AppFrame::AppFrame(QWidget *parent): QFrame{parent}
{
    QString object1 = "squirtle";
    QString object2 = "cubone";
    int index = -1;

    ElementsComboBox comboBox(parent);

    fileUser.fileObjReader(object1);
    fileUser2.fileObjReader(object2);

    comboBox.AddObject(object1);
    comboBox.AddObject(object2);
    comboBox.currentIndexChanged(index);
}

void AppFrame::paintEvent(QPaintEvent *event){
    QFrame::paintEvent(event);
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(1);
    painter.setPen(pen);

    maxVPX = this->width();
    maxVPY = this->height();

    QList<QList<QLine>> viewPortObjects;

    Window window(maxVPX, maxVPY, xGlobal, xGlobal+SCALE, yGlobal, yGlobal+SCALE);

    QList<QPoint> framePoints = {QPoint(-100 + xGlobal, 100 + yGlobal), QPoint(100 + xGlobal, 100 + yGlobal),
                                 QPoint(100 + xGlobal, -100 + yGlobal), QPoint(-100 + xGlobal, -100 + yGlobal)};

    Clipping frame(window.viewPortTransformPoint(framePoints));

    for(QList<QLine>& object : this->worldObjectList){
        viewPortObjects.append(frame.listClipping(window.viewPortTransformLine(object)));
    }

    for(QLine line : frame.listClipping(window.viewPortTransformLine(Transformations3d::getTransformations3d(fileUser2, scaleObject, angleX, angleY, angleZ, posX, posY, posZ)))){
        painter.drawLine(line);
    }

    frame.drawFrame(&painter);

    update();
}

void AppFrame::plusWindowsX(){
    xGlobal += 10;
}

void AppFrame::minusWindowsX(){
    xGlobal -= 10;
}

void AppFrame::plusWindowsY(){
    yGlobal += 10;
}

void AppFrame::minusWindowsY(){
    yGlobal -= 10;
}

void AppFrame::plusWindowsScale(){
    SCALE += 25;
}

void AppFrame::downWindowsScale(){
    SCALE = SCALE > 0? SCALE - 25: 0;
}

void AppFrame::plusObjectScale() {
    scaleObject += 2;
}

void AppFrame::downObjectScale() {
    scaleObject -= 2;
}

void AppFrame::plusObjectAngleAroundX() {
    angleX += 15;
}

void AppFrame::downObjectAngleAroundX() {
    angleX -= 15;
}

void AppFrame::plusObjectAngleAroundY() {
    angleY += 15;
}

void AppFrame::downObjectAngleAroundY() {
    angleY -= 15;
}

void AppFrame::plusObjectAngleAroundZ() {
    angleZ += 15;
}

void AppFrame::downObjectAngleAroundZ() {
    angleZ -= 15;
}

void AppFrame::plusObjectPosX() {
    posX += 2;
}

void AppFrame::downObjectPosX() {
    posX -= 2;
}

void AppFrame::plusObjectPosY() {
    posY += 2;
}

void AppFrame::downObjectPosY() {
    posY -= 2;
}

void AppFrame::plusObjectPosZ() {
    posZ += 2;
}

void AppFrame::downObjectPosZ() {
    posZ -= 2;
}

void AppFrame::resetObject() {
    scaleObject = 0;
    angleX = 0;
    angleY = 0;
    angleZ = 0;
    posX = 0;
    posY = 0;
    posZ = 0;
}

QLine AppFrame::transformLineToQLine(Line line) {
    return QLine(line.x1, line.y1, line.x2, line.y2);
}

QList<QLine> AppFrame::transformListOfLinesToListOfQLines(QList<Line> list) {
    QList<QLine> newList;
    for(Line line : list) {
        newList.append(transformLineToQLine(line));
    }
    return newList;
}
