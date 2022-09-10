#include "line.h"

Line::Line(int xi, int yi, int xf, int yf)
{
    this->xi = xi;
    this->yi = yi;
    this->xf = xf;
    this->yf = yf;
    this->line = QLine(this->xi, this->yi, this->xf, this->yf);
}

void Line::drawObject(QPainter *painter){
    painter->drawLine(this->line);
}
