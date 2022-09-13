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
    QList<QLine> rect;
public:
    QLine line1, line2, line3, line4;
    Rectangle(Point point1, Point point2, Point point3, Point point4);
    virtual void drawObject(QPainter *painter);
    virtual ~Rectangle()
    { }
};

#endif // RECTANGLE_H
