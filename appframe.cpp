#include "appframe.h"
#include "line.h"
#include "point.h"
#include "rectangle.h"
#include <QScreen>
#include "window.h"

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
    Point p1(0,0);
    Point p2(0,300);
    Point p3(300, 300);
    Point p4(150, 500);
    Line lin1(p2,p4);
    Line lin2(p4, p3);
    Rectangle rect(p1, p3);

    worldObjectList.append(&rect);
    worldObjectList.append(&lin1);
    worldObjectList.append(&lin2);
    /*world definition in memory*/

    /*window definition*/
    int maxVPX = this->width();
    int maxVPY = this->height();

    Window window(maxVPX, maxVPY, xGlobal, xGlobal+SCALE, yGlobal, yGlobal+SCALE);
    /*window definition*/

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
    Line linVp1(pVp2, pVp4);
    Line linVp2(pVp4, pVp3);
    Rectangle rectVp(pVp1, pVp3);
    displayFile.append(&linVp1);
    displayFile.append(&linVp2);
    displayFile.append(&rectVp);

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
