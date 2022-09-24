#include "appframe.h"
#include "line.h"
#include "point.h"
#include "rectangle.h"
#include <QScreen>
#include "window.h"

AppFrame::AppFrame(QWidget *parent): QFrame{parent}
{

}

void AppFrame::paintEvent(QPaintEvent *event){
    /*world definition in memory*/
    QList<GenericObject *> worldObjectList;
    Point p(100,0);
    Rectangle r(p, 100);

    worldObjectList.append(&r);
    /*world definition in memory*/

    /*window definition*/
    int maxVPX = this->width();
    int maxVPY = this->height();

    Window window(maxVPX, maxVPY, 100, 300, 0, 300);
    /*window definition*/

    QList<GenericObject *> displayFile;
    int pvpX = window.gVPX(p.x);
    int pvpY = window.gVPY(p.y);
    //std::cout << "x:" << pvpX << "y:" << pvpY << std::endl;
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
