#include "perspectiveprojection.h"

PerspectiveProjection::PerspectiveProjection(float x, float y, float z, float distance)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->distance = distance;
}

PerspectiveProjection::PerspectiveProjection(Point point, float distance)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
    this->distance = distance;
}

Point PerspectiveProjection::newPerspectivePoints() {
    return Point((this->x/(this->z/this->distance)), (this->y/(this->z/this->distance)), this->distance);
}
