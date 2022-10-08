        #include "rectangle.h"

Rectangle::Rectangle(QList<QPoint> points) {
    for(QPoint point : points){
        this->points.append(point);
    }
}

void Rectangle::drawObject(QPainter *painter){
    for(int i = 0; i < this->points.length(); i++){
        if(i == this->points.length() - 1){
            QLine line(this->points[i], this->points[0]);
            painter->drawLine(line);
        }
        else{
            QLine line(this->points[i], this->points[i+1]);
            painter->drawLine(line);
        }
    }
}
