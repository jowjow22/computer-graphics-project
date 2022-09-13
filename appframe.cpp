#include "appframe.h"
#include "rectangle.h"
#include "line.h"
#include "point.h"
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
    Rectangle rect(200, 200, 60);
    Rectangle rect2(10, 100, 30);
    Line line(10, 10, 100, 100);
    Point point(150, 150);

    worldObjectList.append(&rect);
    worldObjectList.append(&rect2);
    worldObjectList.append(&line);
    worldObjectList.append(&point);



    for(GenericObject *list : worldObjectList){
        list->drawObject(&painter);
    }
    update();
}

void AppFrame::resizeEvent(QResizeEvent *event){
    CoordsEngine *coords = new CoordsEngine();
    QSize size(coords->getWindowWidth() / 2, coords->getWindowHeight() - 40);
    std::cout << coords->getWindowHeight();
    QFrame::resizeEvent(event);
    AppFrame::resize(size);
}



