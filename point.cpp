#include "point.h"

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
    this->point = QPoint(x, y);
}

void Point::drawObject(QPainter *painter){
    painter->drawPoint(this->point);
}
