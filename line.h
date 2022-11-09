#ifndef LINE_H
#define LINE_H
#include "QLine"
#include "point.h"
#include "genericobject.h"


class Line: public QLine, public QPoint, public GenericObject
{
    QLine line;
public:
    float x1, y1, z1, x2, y2, z2;
    Line(float x1, float y1, float z1, float x2, float y2, float z2);
    Line(Point point1, Point point2);
    virtual void drawObject(QPainter *painter);
    virtual ~Line()
    { }
};

#endif // LINE_H
