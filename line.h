#ifndef LINE_H
#define LINE_H
#include "QLine"
#include "point.h"
#include "genericobject.h"


class Line: public QLine, public QPoint, public GenericObject
{
    QLine line;
public:
    float xi, yi, xf, yf;
    Line(float xi, float yi, float xf, float yf);
    Line(Point point1, Point point2);
    virtual void drawObject(QPainter *painter);
    virtual ~Line()
    { }
};

#endif // LINE_H
