#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int size)
{
    this->x = x;
    this->y = y;
    this->size = size;
    this->rect = QRect(this->x, this->y, this->size, this->size);
}

void Rectangle::drawObject(QPainter *painter){
    painter->drawRect(this->rect);
}
