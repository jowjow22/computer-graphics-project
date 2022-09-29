#include "rectangle.h"

Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4) {
    this->line1 = QLine(p1.x, p1.y, p2.x, p2.y);
    this->line2 = QLine(p1.x, p1.y, p3.x, p3.y);
    this->line3 = QLine(p3.x, p3.y, p4.x, p4.y);
    this->line4 = QLine(p4.x, p4.y, p2.x, p2.y);
    this->rect.append(line1);
    this->rect.append(line2);
    this->rect.append(line3);
    this->rect.append(line4);
}

Rectangle::Rectangle(Point bottomLeft, Point topRight) {
    this->line1 = QLine(bottomLeft.x, topRight.y, topRight.x, topRight.y);
    this->line2 = QLine(bottomLeft.x, topRight.y, bottomLeft.x, bottomLeft.y);
    this->line3 = QLine(bottomLeft.x, bottomLeft.y, topRight.x, bottomLeft.y);
    this->line4 = QLine(topRight.x, bottomLeft.y, topRight.x, topRight.y);
    this->rect.append(line1);
    this->rect.append(line2);
    this->rect.append(line3);
    this->rect.append(line4);
}

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

Rectangle::Rectangle(Point centerPoint, int sizeWidth, int sizeHeight) {
    this->line1 = QLine((centerPoint.x)-sizeWidth/2, (centerPoint.y)+sizeHeight/2, (centerPoint.x)+sizeWidth/2, (centerPoint.y)+sizeHeight/2);
    this->line2 = QLine((centerPoint.x)-sizeWidth/2, (centerPoint.y)+sizeHeight/2, (centerPoint.x)-sizeWidth/2, (centerPoint.y)-sizeHeight/2);
    this->line3 = QLine((centerPoint.x)-sizeWidth/2, (centerPoint.y)-sizeHeight/2, (centerPoint.x)+sizeWidth/2, (centerPoint.y)-sizeHeight/2);
    this->line4 = QLine((centerPoint.x)+sizeWidth/2, (centerPoint.y)-sizeHeight/2, (centerPoint.x)+sizeWidth/2, (centerPoint.y)+sizeHeight/2);
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
