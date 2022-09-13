#include "rectangle.h"

Rectangle::Rectangle(Point point1, Point point2, Point point3, Point point4)
{
    this->line1 = QLine(point1.x, point1.y, point2.x, point2.y);
    this->line2 = QLine(point1.x, point1.y, point3.x, point3.y);
    this->line3 = QLine(point3.x, point3.y, point4.x, point4.y);
    this->line4 = QLine(point4.x, point4.y, point2.x, point2.y);
    this->rect.append(line1);
    this->rect.append(line2);
    this->rect.append(line3);
    this->rect.append(line4);
}

void Rectangle::drawObject(QPainter *painter){
    for(int i = 0; i < this->rect.size(); i++) {
        painter->drawLine(this->rect.at(i));
    }
}
