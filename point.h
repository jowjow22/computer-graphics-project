#ifndef POINT_H
#define POINT_H
#include "QPoint"
#include "genericobject.h"


class Point: public GenericObject, public QPoint
{
    QPoint point;
public:
    int x, y, z;
    Point(float x, float y, float z);
    virtual void drawObject(QPainter *painter);
    virtual ~Point()
    { }
};

#endif // POINT_H
