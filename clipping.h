#ifndef CLIPPING_H
#define CLIPPING_H
#include "QList"
#include "QLine"
#include <QPoint>
#include <QList>
#include <QPainter>

class Clipping
{
public:
    QList<QPoint> framePoints;
    int rightX, leftX, topY, bottomY;
    Clipping(QList<QPoint> framePoints);
    virtual void drawFrame(QPainter *painter);
    void defineFramePoints();
    void defineRegionCode(QPoint point, int regionCode[4]);
    float lineEquationLeft(QPoint p1, QPoint p2);
    float lineEquationRight(QPoint p1, QPoint p2);
    float lineEquationTop(QPoint p1, QPoint p2);
    float lineEquationBottom(QPoint p1, QPoint p2);
    QList<QLine> doClipping(QList<QLine> list);
    virtual ~Clipping()
    { }
};

#endif // CLIPPING_H
