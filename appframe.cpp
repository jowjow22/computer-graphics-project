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
#include "clipping.h"
#include <QLine>

int xGlobal = 0;
int yGlobal = 0;
int SCALE = 300;
int Angle = 0;
float scaleObject = 0;

AppFrame::AppFrame(QWidget *parent): QFrame{parent}
{

}

void AppFrame::paintEvent(QPaintEvent *event){
    /*world definition in memory*/
    QFrame::paintEvent(event);
//    Point p1(100, 200);
//    Point p2(200, 200);
//    Point p3(200, 100);
//    Point p4(100, 100);

//    QList<QPoint> pointsNorm = {QPoint(p1.x, p1.y), QPoint(p2.x, p2.y), QPoint(p3.x, p3.y), QPoint(p4.x, p4.y)};

//    GeometricTransformation rotateAndScale(150, 150, 1 + scaleObject, 1 + scaleObject, 60 + Angle);

//    QList<QPoint> points = rotateAndScale.getGeometricTransformation(pointsNorm);

    /*world definition in memory*/

    /*window definition*/
    int maxVPX = this->width();
    int maxVPY = this->height();

    Window window(maxVPX, maxVPY, xGlobal, xGlobal+SCALE, yGlobal, yGlobal+SCALE);
    /*window definition*/

    /*viewport definition*/
    //QList<GenericObject *> displayFile;

    QList<QPoint> framePoints = {QPoint(-100 + xGlobal, 100 + yGlobal), QPoint(100 + xGlobal, 100 + yGlobal),
                                 QPoint(100 + xGlobal, -100 + yGlobal), QPoint(-100 + xGlobal, -100 + yGlobal)};

    Clipping frame(window.viewPortTransform(framePoints));

//    Rectangle rectVp(window.viewPortTransform(points));
//    Rectangle rectNorm(window.viewPortTransform(pointsNorm));

//    displayFile.append(&rectVp);
//    displayFile.append(&rectNorm);

    QList<QLine> teste = {QLine(window.gVPX(0), window.gVPY(0), window.gVPX(-150), window.gVPY(-150))};
    QList<QLine> testeFinal = frame.listClipping(teste);
    /*viewport definition*/

    /*draw*/
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(5);

    painter.setPen(pen);

    for(int i = 0; i < testeFinal.length(); i++) {
        painter.drawLine(testeFinal.at(i));
    }

    frame.drawFrame(&painter);

//    for(GenericObject *list : displayFile){
//        list->drawObject(&painter);
//    }
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

void AppFrame::plusWindowsScale(){
    SCALE += 50;
}

void AppFrame::downWindowsScale(){
    SCALE = SCALE > 0? SCALE - 50: 0;
}

void AppFrame::plusObjectAngle() {
    Angle += 10;
}

void AppFrame::downObjectAngle() {
    Angle -= 10;
}

void AppFrame::plusObjectScale() {
    scaleObject += 0.25;
}

void AppFrame::downObjectScale() {
    scaleObject -= 0.25;
}
