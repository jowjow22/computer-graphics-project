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
    pen.setWidth(5);
    painter.setPen(pen);

    maxVPX = this->width();
    maxVPY = this->height();

    fileUser.fileObjReader((char*)"/home/felipe-izidorio/Documentos/UTFPR/4 período/Computação Gráfica/Pikachu OBJ.obj");

    QList<QList<QLine>> viewPortObjects;

    Window window(maxVPX, maxVPY, xGlobal, xGlobal+SCALE, yGlobal, yGlobal+SCALE);

    QList<QPoint> framePoints = {QPoint(-100 + xGlobal, 100 + yGlobal), QPoint(100 + xGlobal, 100 + yGlobal),
                                 QPoint(100 + xGlobal, -100 + yGlobal), QPoint(-100 + xGlobal, -100 + yGlobal)};

    Clipping frame(window.viewPortTransformPoint(framePoints));

    for(QList<QLine>& object : this->worldObjectList){
        viewPortObjects.append(frame.listClipping(window.viewPortTransformLine(object)));
    }

    QList<QLine> teste;

    teste.append(frame.listClipping(window.viewPortTransformLine(fileUser.readLines)));

    /*viewport definition*/

    /*draw*/

    for(QList<QLine>& object : viewPortObjects){
        for(int i = 0; i < object.length(); i++) {
            painter.drawLine(object.at(i));
        }
    }

    for(QLine line : teste){
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
