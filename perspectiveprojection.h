#ifndef PERSPECTIVEPROJECTION_H
#define PERSPECTIVEPROJECTION_H
#include "point.h"
#include "line.h"

class PerspectiveProjection
{
public:
    PerspectiveProjection();

    static Point newPerspectivePoints(float x, float y, float z, float distance);
    static QList<Line> newListOfPerspectivePoints(QList<Line> list, float distance);
};

#endif // PERSPECTIVEPROJECTION_H
