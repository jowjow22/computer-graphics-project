#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "QList"
#include "QLine"
#include "line.h"
#include "point.h"
#include "genericobject.h"
#include <iostream>


class Rectangle: public QLine, public GenericObject
{
public:
    QList<QPoint> points;
    Rectangle(QList<QPoint> points);
    virtual void drawObject(QPainter *painter);
    virtual ~Rectangle()
    { }
};

#endif // RECTANGLE_H
