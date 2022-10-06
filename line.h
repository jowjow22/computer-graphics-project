#ifndef LINE_H
#define LINE_H
#include "QLine"
#include "point.h"
#include "genericobject.h"


class Line: public QLine, public QPoint, public GenericObject
{
    QLine line;
public:
    int xi, yi, xf, yf;
    Line(int xi, int yi, int xf, int yf);
    Line(Point point1, Point point2);
    virtual void drawObject(QPainter *painter);
    virtual ~Line()
    { }
};

#endif // LINE_H
