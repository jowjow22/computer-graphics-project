#include "line.h"

Line::Line(int xi, int yi, int xf, int yf)
{
    this->xi = xi;
    this->yi = yi;
    this->xf = xf;
    this->yf = yf;
    this->line = QLine(this->xi, this->yi, this->xf, this->yf);
}

Line::Line(Point point1, Point point2)
{
    this->xi = point1.x;
    this->yi = point1.y;
    this->xf = point2.x;
    this->yf = point2.y;
    this->line = QLine(this->xi, this->yi, this->xf, this->yf);
}

void Line::drawObject(QPainter *painter){
    painter->drawLine(this->line);
}
