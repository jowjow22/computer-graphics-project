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

    Translation pVp05(p1.x, p1.y, -100, -100);
    Translation pVp06(p2.x, p2.y, -100, -100);
    Translation pVp07(p3.x, p3.y, -100, -100);
    Translation pVp08(p4.x, p4.y, -100, -100);

    Rotation pVp09(pVp05.getTranslationX(), pVp05.getTranslationY(), 60+Angle);
    Rotation pVp10(pVp06.getTranslationX(), pVp06.getTranslationY(), 60+Angle);
    Rotation pVp11(pVp07.getTranslationX(), pVp07.getTranslationY(), 60+Angle);
    Rotation pVp12(pVp08.getTranslationX(), pVp08.getTranslationY(), 60+Angle);

    Translation pVp13(pVp09.getRotationX(), pVp09.getRotationY(), 100, 100);
    Translation pVp14(pVp10.getRotationX(), pVp10.getRotationY(), 100, 100);
    Translation pVp15(pVp11.getRotationX(), pVp11.getRotationY(), 100, 100);
    Translation pVp16(pVp12.getRotationX(), pVp12.getRotationY(), 100, 100);

    QList<QPoint> points1 = {QPoint(pVp13.getTranslationX(), pVp13.getTranslationY()), QPoint(pVp14.getTranslationX(), pVp14.getTranslationY()),
                             QPoint(pVp15.getTranslationX(), pVp15.getTranslationY()), QPoint(pVp16.getTranslationX(), pVp16.getTranslationY())};

    Translation pVp17(p1.x, p1.y, -150, -150);
    Translation pVp18(p2.x, p2.y, -150, -150);
    Translation pVp19(p3.x, p3.y, -150, -150);
    Translation pVp20(p4.x, p4.y, -150, -150);

    Scale pVp21(pVp17.getTranslationX(), pVp17.getTranslationY(), 1+scaleObject, 1+scaleObject);
    Scale pVp22(pVp18.getTranslationX(), pVp18.getTranslationY(), 1+scaleObject, 1+scaleObject);
    Scale pVp23(pVp19.getTranslationX(), pVp19.getTranslationY(), 1+scaleObject, 1+scaleObject);
    Scale pVp24(pVp20.getTranslationX(), pVp20.getTranslationY(), 1+scaleObject, 1+scaleObject);

    Translation pVp25(pVp21.getScaleX(), pVp21.getScaleY(), 150, 150);
    Translation pVp26(pVp22.getScaleX(), pVp22.getScaleY(), 150, 150);
    Translation pVp27(pVp23.getScaleX(), pVp23.getScaleY(), 150, 150);
    Translation pVp28(pVp24.getScaleX(), pVp24.getScaleY(), 150, 150);

    QList<QPoint> points2 = {QPoint(pVp25.getTranslationX(), pVp25.getTranslationY()), QPoint(pVp26.getTranslationX(), pVp26.getTranslationY()),
                             QPoint(pVp27.getTranslationX(), pVp27.getTranslationY()), QPoint(pVp28.getTranslationX(), pVp28.getTranslationY())};

    QList<QPoint> pointsNorm = {QPoint(p1.x, p1.y), QPoint(p2.x, p2.y), QPoint(p3.x, p3.y), QPoint(p4.x, p4.y)};

    /*world definition in memory*/

    /*window definition*/
    int maxVPX = this->width();
    int maxVPY = this->height();

    Window window(maxVPX, maxVPY, xGlobal, xGlobal+SCALE, yGlobal, yGlobal+SCALE);
    /*window definition*/

    /*viewport definition*/
    QList<GenericObject *> displayFile;

    Rectangle rectVp1(window.viewPortTransform(points1));
    Rectangle rectVp2(window.viewPortTransform(points2));
    Rectangle rectNorm(window.viewPortTransform(pointsNorm));

    displayFile.append(&rectVp1);
    displayFile.append(&rectVp2);
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

void AppFrame::changEscale() {
    scaleObject += 1;
}
