#ifndef PERSPECTIVEPROJECTION_H
#define PERSPECTIVEPROJECTION_H
#include "point.h"
#include "line.h"

class PerspectiveProjection
{
public:
    PerspectiveProjection();

    static QPoint newPerspectivePoints(float x, float y, float z, float distance);
    static QList<QLine> newListOfPerspectivePoints(QList<Line> list, float distance);
};

#endif // PERSPECTIVEPROJECTION_H
