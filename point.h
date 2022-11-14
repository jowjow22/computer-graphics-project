#ifndef POINT_H
#define POINT_H
#include <QPoint>
#include <QList>
#include "genericobject.h"


class Point: public GenericObject, public QPoint
{
    QPoint point;
public:
    float x, y, z;
    Point(float x, float y, float z);
    Point(float x, float y);
    QPoint transformPointToQPoint(Point point);
    QList<QPoint> transformPointToQPoint(QList<Point> list);
    virtual void drawObject(QPainter *painter);
    virtual ~Point()
    { }
};

#endif // POINT_H
