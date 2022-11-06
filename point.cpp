#include "point.h"

Point::Point(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->point = QPoint(x, y);
}

void Point::drawObject(QPainter *painter){
    painter->drawPoint(this->point);
}
