#include "rectangle.h"


Rectangle::Rectangle(Point centerPoint, int size) {
        this->line1 = QLine((centerPoint.x)-size/2, (centerPoint.y)+size/2, (centerPoint.x)+size/2, (centerPoint.y)+size/2);
        this->line2 = QLine((centerPoint.x)-size/2, (centerPoint.y)+size/2, (centerPoint.x)-size/2, (centerPoint.y)-size/2);
        this->line3 = QLine((centerPoint.x)-size/2, (centerPoint.y)-size/2, (centerPoint.x)+size/2, (centerPoint.y)-size/2);
        this->line4 = QLine((centerPoint.x)+size/2, (centerPoint.y)-size/2, (centerPoint.x)+size/2, (centerPoint.y)+size/2);
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
