#ifndef APPFRAME_H
#define APPFRAME_H

#include "QFrame"
#include <QPainter>
#include <iostream>
#include "window.h"
#include "genericobject.h"
#include "point.h"

class AppFrame: public QFrame
{
public:
    AppFrame(QWidget *parent = nullptr);
    QList<QList<QLine>> worldObjectList;
    virtual void paintEvent(QPaintEvent *event);
    void coordsWindowToViewport(QList<GenericObject *> *displayFile, Window window, Point *p);
    void addPointToDisplayFile(QList<GenericObject *> *displayFile, Point *p);
    void plusWindowsX();
    void minusWindowsX();
    void plusWindowsY();
    void minusWindowsY();
    void plusWindowsScale();
    void downWindowsScale();
    void plusObjectAngle();
    void downObjectAngle();
    void plusObjectScale();
    void downObjectScale();

};

#endif // APPFRAME_H
