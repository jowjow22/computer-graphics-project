#ifndef APPFRAME_H
#define APPFRAME_H

#include "QFrame"
#include <QPainter>
#include <iostream>
#include "window.h"
#include "genericobject.h"
#include "point.h"
#include "line.h"

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
    void plusObjectScale();
    void downObjectScale();
    void plusObjectAngleAroundX();
    void downObjectAngleAroundX();
    void plusObjectAngleAroundY();
    void downObjectAngleAroundY();
    void plusObjectAngleAroundZ();
    void downObjectAngleAroundZ();
    void plusObjectPosX();
    void downObjectPosX();
    void plusObjectPosY();
    void downObjectPosY();
    void plusObjectPosZ();
    void downObjectPosZ();
    QLine transformLineToQLine(Line line);
    QList<QLine> transformListOfLinesToListOfQLines(QList<Line> list);
public Q_SLOTS:
    void getSelectedObject(int);

};

#endif // APPFRAME_H
