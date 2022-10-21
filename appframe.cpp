#include "appframe.h"
#include <QScreen>
#include "window.h"
#include "scale.h"
#include "translation.h"
#include "rotation.h"
#include "geometrictransformation.h"
#include "clipping.h"
#include <QLine>
#include "elementscombobox.h"
#include "house.h"

int xGlobal = 0;
int yGlobal = 0;
int SCALE = 300;
int Angle = 0;
float scaleObject = 0;
int maxVPX;
int maxVPY;


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
    pen.setWidth(5);
    painter.setPen(pen);

    maxVPX = this->width();
    maxVPY = this->height();

    QList<QList<QLine>> viewPortObjects;

    GeometricTransformation rotateAndScale(150, 150, 1 + scaleObject, 1 + scaleObject, 60 + Angle);


    Window window(maxVPX, maxVPY, xGlobal, xGlobal+SCALE, yGlobal, yGlobal+SCALE);

    QList<QPoint> framePoints = {QPoint(-100 + xGlobal, 100 + yGlobal), QPoint(100 + xGlobal, 100 + yGlobal),
                                 QPoint(100 + xGlobal, -100 + yGlobal), QPoint(-100 + xGlobal, -100 + yGlobal)};

    Clipping frame(window.viewPortTransformPoint(framePoints));




    for(QList<QLine>& object : this->worldObjectList){
        viewPortObjects.append(frame.listClipping(window.viewPortTransformLine(object)));
    }


    /*viewport definition*/

    /*draw*/



    for(QList<QLine>& object : viewPortObjects){
        for(int i = 0; i < object.length(); i++) {
            painter.drawLine(object.at(i));
        }
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

void AppFrame::plusObjectAngle() {
    Angle += 10;
}

void AppFrame::downObjectAngle() {
    Angle -= 10;
}

void AppFrame::plusObjectScale() {
    scaleObject += 0.25;
}

void AppFrame::downObjectScale() {
    scaleObject -= 0.25;
}
