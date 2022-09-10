#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "QRect"
#include "genericobject.h"
#include <iostream>


class Rectangle: public QRect, public GenericObject
{
    QRect rect;
public:
    int x, y, size;
    Rectangle(int x, int y, int size);
    virtual void drawObject(QPainter *painter);
    virtual ~Rectangle()
    { }
};

#endif // RECTANGLE_H
