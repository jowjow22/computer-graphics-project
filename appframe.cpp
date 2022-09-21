#include "appframe.h"
#include "line.h"
#include "point.h"
#include "rectangle.h"
#include <QScreen>
#include "coordsengine.h"

AppFrame::AppFrame(QWidget *parent): QFrame{parent}
{

}

void AppFrame::paintEvent(QPaintEvent *event){
    QList<GenericObject *> worldObjectList;
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(5);

    painter.setPen(pen);

    Rectangle rect(Point(0,0), 100);
    Rectangle rect2(Point(1060,300), AppFrame::width()/2);
    worldObjectList.append(&rect);
    worldObjectList.append(&rect2);

    for(GenericObject *list : worldObjectList){
        list->drawObject(&painter);
    }
    update();
}





