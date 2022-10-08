#ifndef CLIPPING_H
#define CLIPPING_H

#include <QList>
#include <QPoint>

class Clipping
{
public:
    Clipping(int xMin, int yMin, int xMax, int yMax);
    void calculateRegionCode(QList<QPoint* > *points);
    int rc0[4];
    int rc1[4];
    int xMin, yMin, xMax, yMax, m, x0, x1, y0, y1;

};

#endif // CLIPPING_H
