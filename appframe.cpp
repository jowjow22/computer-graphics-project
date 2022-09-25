#include "appframe.h"
#include "line.h"
#include "point.h"
#include "rectangle.h"
#include <QScreen>
#include "window.h"

int xGlobal = 0;
int yGlobal = 0;

AppFrame::AppFrame(QWidget *parent): QFrame{parent}
{

}

void AppFrame::paintEvent(QPaintEvent *event){
    /*world definition in memory*/
    QFrame::paintEvent(event);
    QList<GenericObject *> worldObjectList;
    Point p(0,0);
    Rectangle r(p, 100);

    worldObjectList.append(&r);
    /*world definition in memory*/

    /*window definition*/
    int maxVPX = this->width();
    int maxVPY = this->height();

    Window window(maxVPX, maxVPY, xGlobal, xGlobal+300, yGlobal, yGlobal+300);
    /*window definition*/

    QList<GenericObject *> displayFile;
    int pvpX = window.gVPX(p.x);
    int pvpY = window.gVPY(p.y);

    Point pVp(pvpX, pvpY);
    Rectangle rVp(pVp, 100);
    displayFile.append(&rVp);

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

