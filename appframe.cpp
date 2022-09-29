#include "appframe.h"
#include "line.h"
#include "point.h"
#include "rectangle.h"
#include <QScreen>
#include "window.h"
#include "rotation.h"
#include "geometrictransformation.h"

int xGlobal = 0;
int yGlobal = 0;
int SCALE = 300;
AppFrame::AppFrame(QWidget *parent): QFrame{parent}
{

}

void AppFrame::paintEvent(QPaintEvent *event){
    /*world definition in memory*/
    QFrame::paintEvent(event);
    QList<GenericObject *> worldObjectList;
    Point p1(0,100);
    Point p2(100,100);
    Point p3(0, 0);
    Point p4(100, 0);

    Rectangle rect1(p1, p2, p3, p4);

    GeometricTransformation pVp01(p1.x, p1.y, 100, 100, 60);
    GeometricTransformation pVp02(p2.x, p2.y, 100, 100, 60);
    GeometricTransformation pVp03(p3.x, p3.y, 100, 100, 60);
    GeometricTransformation pVp04(p4.x, p3.y, 100, 100, 60);

    Rectangle rectTr(Point(pVp01.getTransformationX(), pVp01.getTransformationY()), Point(pVp02.getTransformationX(), pVp02.getTransformationY()),
                     Point(pVp03.getTransformationX(), pVp03.getTransformationY()), Point(pVp04.getTransformationX(), pVp04.getTransformationY()));


    worldObjectList.append(&rect1);
    worldObjectList.append(&rectTr);
    /*world definition in memory*/

    /*window definition*/
    int maxVPX = this->width();
    int maxVPY = this->height();

    Window window(maxVPX, maxVPY, xGlobal, xGlobal+SCALE, yGlobal, yGlobal+SCALE);
    /*window definition*/

    /*viewport definition*/
    QList<GenericObject *> displayFile;
    int pvpX1 = window.gVPX(p1.x);
    int pvpY1 = window.gVPY(p1.y);
    int pvpX2 = window.gVPX(p2.x);
    int pvpY2 = window.gVPY(p2.y);
    int pvpX3 = window.gVPX(p3.x);
    int pvpY3 = window.gVPY(p3.y);
    int pvpX4 = window.gVPX(p4.x);
    int pvpY4 = window.gVPY(p4.y);

    Point pVp1(pvpX1, pvpY1);
    Point pVp2(pvpX2, pvpY2);
    Point pVp3(pvpX3, pvpY3);
    Point pVp4(pvpX4, pvpY4);
    Rectangle rectVp(pVp1, pVp2, pVp3, pVp4);
    displayFile.append(&rectVp);
    displayFile.append(&rectTr);
    /*viewport definition*/

    /*draw*/
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(5);

    painter.setPen(pen);


    for(GenericObject *list : displayFile){
        list->drawObject(&painter);
    }
    /*draw*/

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

void AppFrame::upScale(){
    SCALE += 50;
}

void AppFrame::downScale(){
    SCALE = SCALE > 0? SCALE - 50: 0;
}
