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
    Point p(0,0);
    Point p1(100,100);
    Line lin(p,p1);
    Rectangle r(p, 100);

    worldObjectList.append(&r);
    worldObjectList.append(&lin);
    /*world definition in memory*/

    /*window definition*/
    int maxVPX = this->width();
    int maxVPY = this->height();

    Window window(maxVPX, maxVPY, xGlobal, xGlobal+SCALE, yGlobal, yGlobal+SCALE);
    /*window definition*/

    QList<GenericObject *> displayFile;
    int pvpX = window.gVPX(p.x);
    int pvpY = window.gVPY(p.y);
    int pvpX1 = window.gVPX(p1.x);
    int pvpY1 = window.gVPY(p1.y);

    Point pVp(pvpX, pvpY);
    Point pVp1(pvpX1, pvpY1);
    Line lVp(pVp, pVp1);
    Rectangle rVp(pVp, 100);
    displayFile.append(&rVp);
    displayFile.append(&lVp);

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
