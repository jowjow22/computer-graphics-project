#include "appframe.h"
#include "line.h"
#include "point.h"
#include "rectangle.h"
#include <QScreen>
#include "window.h"
#include "rotation.h"
#include "geometrictransformation.h"

int xGlobal = 0;
int yGlobal = 0;
int SCALE = 300;
int Angle = 0;

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

    GeometricTransformation pVp01(p1.x, p1.y, 0, 0, 60+Angle);
    GeometricTransformation pVp02(p2.x, p2.y, 0, 0, 60+Angle);
    GeometricTransformation pVp03(p3.x, p3.y, 0, 0, 60+Angle);
    GeometricTransformation pVp04(p4.x, p3.y, 0, 0, 60+Angle);
    QList<QPoint> points = {QPoint(pVp01.getTransformationX(), pVp01.getTransformationY()), QPoint(pVp02.getTransformationX(), pVp02.getTransformationY()),
                            QPoint(pVp03.getTransformationX(), pVp03.getTransformationY()), QPoint(pVp04.getTransformationX(), pVp04.getTransformationY())};

    Rectangle rectTr(points);

    GeometricTransformation pVp05(p1.x, p1.y, p4.x, p4.y, 45);
    GeometricTransformation pVp06(p2.x, p2.y, p4.x, p4.y, 45);
    GeometricTransformation pVp07(p3.x, p3.y, p4.x, p4.y, 45);
    GeometricTransformation pVp08(p4.x, p3.y, p4.x, p4.y, 45);

    QList<QPoint> points1 = {QPoint(pVp05.getTransformationX(), pVp05.getTransformationY()), QPoint(pVp06.getTransformationX(), pVp06.getTransformationY()),
                            QPoint(pVp07.getTransformationX(), pVp07.getTransformationY()), QPoint(pVp08.getTransformationX(), pVp08.getTransformationY())};

    QList<QPoint> points2 = {QPoint(p1.x, p1.y), QPoint(p2.x, p2.y), QPoint(p3.x, p3.y), QPoint(p4.x, p4.y)};

    /*world definition in memory*/

    /*window definition*/
    int maxVPX = this->width();
    int maxVPY = this->height();

    Window window(maxVPX, maxVPY, xGlobal, xGlobal+SCALE, yGlobal, yGlobal+SCALE);
    /*window definition*/

    /*viewport definition*/
    QList<GenericObject *> displayFile;


    Rectangle rectVp(window.viewPortTransform(points));
    Rectangle rectVp1(window.viewPortTransform(points1));
    Rectangle rectNorm(window.viewPortTransform(points2));
    /*viewport definition*/

    displayFile.append(&rectVp);
    //displayFile.append(&rectVp1);
    displayFile.append(&rectNorm);

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
