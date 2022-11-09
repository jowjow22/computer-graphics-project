#include "point.h"

Point::Point(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->point = QPoint(x, y);
}

Point::Point(float x, float y) {
    this->x = x;
    this->y = y;
    this->z = 0;
    this->point = QPoint(x, y);
}

QPoint Point::transformPointToQPoint(Point point) {
    return QPoint(point.x, point.y);
}

QList<QPoint> Point::transformPointToQPoint(QList<Point> list) {
    QList<QPoint> newList;
    for(Point point : list) {
        newList.append(transformPointToQPoint(point));
    }
    return newList;
}

void Point::drawObject(QPainter *painter){
    painter->drawPoint(this->point);
}
