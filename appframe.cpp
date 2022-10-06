#include "appframe.h"
#include "line.h"
#include "point.h"
#include "rectangle.h"
#include <QScreen>
#include "window.h"
#include "scale.h"
#include "translation.h"
#include "rotation.h"
#include "geometrictransformation.h"

int xGlobal = 0;
int yGlobal = 0;
int SCALE = 300;
int Angle = 0;
int scaleObject = 0;

AppFrame::AppFrame(QWidget *parent): QFrame{parent}
{

}

void AppFrame::paintEvent(QPaintEvent *event){
    /*world definition in memory*/
    QFrame::paintEvent(event);
    Point p1(100,200);
    Point p2(200,200);
    Point p3(200, 100);
    Point p4(100, 100);

    QList<QPoint> pointsNorm = {QPoint(p1.x, p1.y), QPoint(p2.x, p2.y), QPoint(p3.x, p3.y), QPoint(p4.x, p4.y)};

    GeometricTransformation rotateAndScale(150, 150, 1 + scaleObject, 1 + scaleObject, 60 + Angle);

    QList<QPoint> points = rotateAndScale.getGeometricTransformation(pointsNorm);

    /*world definition in memory*/

    /*window definition*/
    int maxVPX = this->width();
    int maxVPY = this->height();

    Window window(maxVPX, maxVPY, xGlobal, xGlobal+SCALE, yGlobal, yGlobal+SCALE);
    /*window definition*/

    /*viewport definition*/
    QList<GenericObject *> displayFile;

    Rectangle rectVp(window.viewPortTransform(points));
    Rectangle rectNorm(window.viewPortTransform(pointsNorm));

    displayFile.append(&rectVp);
    displayFile.append(&rectNorm);
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

void AppFrame::plusAngle() {
    Angle += 10;
}

void AppFrame::changeScale() {
    scaleObject += 1;
}
