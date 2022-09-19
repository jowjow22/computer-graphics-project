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
    Point point1(150, 150);
    Point point2(300, 150);
    Point point3(150, 300);
    Point point4(300, 300);

    Point point5(100, 100);
    painter.drawPoint(point5);

//    Line line1(point1, point2);
//    Line line2(point1, point3);
//    Line line3(point3, point4);
//    Line line4(point4, point2);

    Rectangle rect(point1, point2, point3, point4);

    worldObjectList.append(&point1);
    worldObjectList.append(&point2);
    worldObjectList.append(&point3);
    worldObjectList.append(&point4);
//    worldObjectList.append(&line1);
//    worldObjectList.append(&line2);
//    worldObjectList.append(&line3);
//    worldObjectList.append(&line4);
    worldObjectList.append(&rect);

    for(GenericObject *list : worldObjectList){
        list->drawObject(&painter);
    }
    update();
}





