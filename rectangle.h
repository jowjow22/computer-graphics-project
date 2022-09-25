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
    Rectangle(Point p1, Point p2, Point p3, Point p4);
    Rectangle(Point bottomLeft, Point topRight);
    Rectangle(Point centerPoint, int size);
    Rectangle(Point centerPoint, int sizeWidth, int sizeHeight);
    virtual void drawObject(QPainter *painter);
    virtual ~Rectangle()
    { }
};

#endif // RECTANGLE_H
