#include "appframe.h"
#include <QScreen>
#include "window.h"
#include "clipping.h"
#include "translation3d.h"
#include "rotation3d.h"
#include "scale3d.h"
#include "line.h"
#include <QLine>
#include "readobj.h"
#include "elementscombobox.h"
#include "house.h"

int xGlobal = 0;
int yGlobal = 0;
int SCALE = 300;
int Angle = 0;
float scaleObject = 0;
int maxVPX;
int maxVPY;
ReadObj fileUser;

AppFrame::AppFrame(QWidget *parent): QFrame{parent}
{
    QList<House> houses = {House(-100,10), House(-500,50), House(0,200)};





    for(House house : houses){
       house.houseName = "House" + QString::number(house.getHouseIdentifier());
       ElementsComboBox::AddObject(house.houseName);
       this->worldObjectList.append(house.houseBuilder());
    }
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

    fileUser.fileObjReader((char*)"/home/felipe-izidorio/Documentos/UTFPR/4 período/Computação Gráfica/Pikachu.obj");

    QList<QList<QLine>> viewPortObjects;

    Window window(maxVPX, maxVPY, xGlobal, xGlobal+SCALE, yGlobal, yGlobal+SCALE);

    QList<QPoint> framePoints = {QPoint(-100 + xGlobal, 100 + yGlobal), QPoint(100 + xGlobal, 100 + yGlobal),
                                 QPoint(100 + xGlobal, -100 + yGlobal), QPoint(-100 + xGlobal, -100 + yGlobal)};

    Clipping frame(window.viewPortTransformPoint(framePoints));

    for(QList<QLine>& object : this->worldObjectList){
        viewPortObjects.append(frame.listClipping(window.viewPortTransformLine(object)));
    }

    QList<Line> teste1;
    QList<Line> teste2;
    QList<QLine> teste3;
    QList<QLine> teste4;

    for(Line line : fileUser.readLines) {
        teste1.append(Line(Rotation3D(Point(line.x1, line.y1, line.z1), 40+Angle).getRotationXAroundX(),
                           Rotation3D(Point(line.x1, line.y1, line.z1), 40+Angle).getRotationYAroundX(),
                           Rotation3D(Point(line.x2, line.y2, line.z2), 40+Angle).getRotationXAroundX(),
                           Rotation3D(Point(line.x2, line.y2, line.z2), 40+Angle).getRotationYAroundX()));
    }

    for(Line line : teste1) {
        teste2.append(Line(Scale3D(Point(line.x1, line.y1, line.z1), 1+scaleObject).getScaleX(),
                           Scale3D(Point(line.x1, line.y1, line.z1), 1+scaleObject).getScaleY(),
                           Scale3D(Point(line.x2, line.y2, line.z2), 1+scaleObject).getScaleX(),
                           Scale3D(Point(line.x2, line.y2, line.z2), 1+scaleObject).getScaleY()));
    }

    for(Line line : teste2) {
        teste3.append(QLine(Translation3D(Point(line.x1, line.y1, line.z1), 0, 0, 0).getTranslationX(),
                           Translation3D(Point(line.x1, line.y1, line.z1), 0, 0, 0).getTranslationY(),
                           Translation3D(Point(line.x2, line.y2, line.z2), 0, 0, 0).getTranslationX(),
                           Translation3D(Point(line.x2, line.y2, line.z2), 0, 0, 0).getTranslationY()));
    }

    teste4.append(frame.listClipping(window.viewPortTransformLine(teste3)));

    /*viewport definition*/

    /*draw*/

//    for(QList<QLine>& object : viewPortObjects){
//        for(int i = 0; i < object.length(); i++) {
//            painter.drawLine(object.at(i));
//        }
//    }

//    for(QLine line : teste2){
//        painter.drawLine(line);
//    }

    for(QLine line : teste4){
        painter.drawLine(line);
    }

//    for(QLine line : teste6){
//        painter.drawLine(line);
//    }

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

void AppFrame::plusObjectAngle() {
    Angle += 15;
}

void AppFrame::downObjectAngle() {
    Angle -= 15;
}

void AppFrame::plusObjectScale() {
    scaleObject += 2;
}

void AppFrame::downObjectScale() {
    scaleObject -= 2;
}

QLine AppFrame::transformLineToQLine(Line line) {
    return QLine(line.x1, line.y1, line.x2, line.y2);
}

QList<QLine> AppFrame::transformListOfLinesToListOfQLines(QList<Line> list) {
    QList<QLine> newList;
    for(Line line: list) {
        newList.append(transformLineToQLine(line));
    }
    return newList;
}
