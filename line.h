#ifndef LINE_H
#define LINE_H
#include "QLine"
#include "genericobject.h"


class Line: public QLine, public GenericObject
{
    QLine line;
public:
    int xi, yi, xf, yf;
    Line(int xi, int yi, int xf, int yf);
    virtual void drawObject(QPainter *painter);
    virtual ~Line()
    { }
};

#endif // LINE_H
