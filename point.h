#ifndef POINT_H
#define POINT_H
#include "QPoint"
#include "genericobject.h"


class Point: public GenericObject, public QPoint
{
    QPoint point;
public:
    int x, y;
    Point(int x, int y);
    virtual void drawObject(QPainter *painter);
    virtual ~Point()
    { }
};

#endif // POINT_H
