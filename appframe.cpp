#include "appframe.h"
#include "line.h"
#include "point.h"
#include "rectangle.h"
#include <QScreen>

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

    painter.setWindow(-50, -50, 300, 300);

    int side = qMin(width(), height());
    int x = (width() - side/2);
    int y = (height() - side/2);

    painter.setViewport(x, y, side, side);

    Rectangle rect1(Point(0,0), 100);
    Rectangle rect2(Point(-40,60), 100);
    Line line1(Point(-10, 10), Point(-20, 30));
    Line line2(Point(-70, 20), Point(30, -90));
    Point point1(-10, -50);
    Point point2(70, 90);
    worldObjectList.append(&rect1);
    worldObjectList.append(&rect2);
    worldObjectList.append(&line1);
    worldObjectList.append(&line2);
    worldObjectList.append(&point1);
    worldObjectList.append(&point2);

    for(GenericObject *list : worldObjectList){
        list->drawObject(&painter);
    }
    update();
}
