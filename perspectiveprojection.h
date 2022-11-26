#ifndef PERSPECTIVEPROJECTION_H
#define PERSPECTIVEPROJECTION_H
#include "point.h"

class PerspectiveProjection
{
public:
    PerspectiveProjection(float xOld, float yOld, float zOld, float distance);
    PerspectiveProjection(Point point, float distance);
    float x, y, z;
    float distance;

    Point newPerspectivePoints();
};

#endif // PERSPECTIVEPROJECTION_H
