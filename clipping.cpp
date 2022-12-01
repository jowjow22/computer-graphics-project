#include "clipping.h"
#include <iostream>

Clipping::Clipping(QList<Point> points) {
    for(const Point &point : points){
        this->framePoints.append(point.point);
    }
}

void Clipping::drawFrame(QPainter *painter){
    for(int i = 0; i < this->framePoints.length(); i++){
        if(i == this->framePoints.length() - 1){
            QLine line(this->framePoints[i], this->framePoints[0]);
            painter->drawLine(line);
        }
        else{
            QLine line(this->framePoints[i], this->framePoints[i+1]);
            painter->drawLine(line);
        }
    }
}

void Clipping::defineFramePoints() {
    this->leftX = framePoints.at(3).x();
    this->rightX = framePoints.at(2).x();
    this->bottomY = framePoints.at(1).y();
    this->topY = framePoints.at(2).y();
}

void Clipping::defineRegionCode(QPoint point, int regionCode[4]) {
    //Top
    if(point.y() > this->topY) {
        regionCode[0] = 1;
    } else {
        regionCode[0] = 0;
    }
    //Bottom
    if(point.y() < this->bottomY) {
        regionCode[1] = 1;
    } else {
        regionCode[1] = 0;
    }
    //Right
    if(point.x() > this->rightX) {
        regionCode[2] = 1;
    } else {
        regionCode[2] = 0;
    }
    //Left
    if(point.x() < this->leftX) {
        regionCode[3] = 1;
    } else {
        regionCode[3] = 0;
    }
}

float Clipping::lineEquationLeft(QPoint p1, QPoint p2) {
    float m = (float) (p2.y() - p1.y())/(p2.x() - p1.x());
    float newY = m*(this->leftX - p1.x()) + p1.y();
    return newY;
}

float Clipping::lineEquationRight(QPoint p1, QPoint p2) {
    float m = (float) (p2.y() - p1.y())/(p2.x() - p1.x());
    float newY = m*(this->rightX - p1.x()) + p1.y();
    return newY;
}

float Clipping::lineEquationTop(QPoint p1, QPoint p2) {
    float m = (float) (p2.y() - p1.y())/(p2.x() - p1.x());
    float newX = p1.x() + (this->topY - p1.y())/m;
    return newX;
}

float Clipping::lineEquationBottom(QPoint p1, QPoint p2) {
    float m = (float) (p2.y() - p1.y())/(p2.x() - p1.x());
    float newX = p1.x() + (this->bottomY - p1.y())/m;
    return newX;
}

QLine Clipping::doClipping(QLine line) {
    int regionCodeP1[4], regionCodeP2[4];
    QPoint p1(line.p1().x(), line.p1().y());
    QPoint p2(line.p2().x(), line.p2().y());
    defineRegionCode(p1, regionCodeP1);
    defineRegionCode(p2, regionCodeP2);
    //base case
    if(regionCodeP2[0] == 0 && regionCodeP2[1] == 0 && regionCodeP2[2] == 0 && regionCodeP2[3] == 0) {
        if(regionCodeP1[0] == 1) {
            float newP1X = lineEquationTop(p1, p2);
            p1.setX(newP1X);
            p1.setY(this->topY);
        }
        if(regionCodeP1[1] == 1) {
            float newP1X = lineEquationBottom(p1, p2);
            p1.setX(newP1X);
            p1.setY(this->bottomY);
        }
        if(regionCodeP1[2] == 1) {
            float newP1Y = lineEquationRight(p1, p2);
            p1.setX(this->rightX);
            p1.setY(newP1Y);
        }
        if(regionCodeP1[3] == 1) {
            float newP1Y = lineEquationLeft(p1, p2);
            p1.setX(this->leftX);
            p1.setY(newP1Y);
        }
        return QLine(p1, p2);
    }

    if(regionCodeP1[0] == 0 && regionCodeP1[1] == 0 && regionCodeP1[2] == 0 && regionCodeP1[3] == 0) {
        if(regionCodeP2[0] == 1) {
            float newP2X = lineEquationTop(p1, p2);
            p2.setX(newP2X);
            p2.setY(this->topY);
        }
        if(regionCodeP2[1] == 1) {
            float newP2X = lineEquationBottom(p1, p2);
            p2.setX(newP2X);
            p2.setY(this->bottomY);
        }
        if(regionCodeP2[2] == 1) {
            float newP2Y = lineEquationRight(p1, p2);
            p2.setX(this->rightX);
            p2.setY(newP2Y);
        }
        if(regionCodeP2[3] == 1) {
            float newP2Y = lineEquationLeft(p1, p2);
            p2.setX(this->leftX);
            p2.setY(newP2Y);
        }
        return QLine(p1, p2);
    }
    return QLine();
}

QList<QLine> Clipping::listClipping(QList<Line> list) {
    defineFramePoints();
    QList<QLine> returnedList;
    for(int i = 0; i < list.length(); i++) {
        returnedList.append(doClipping(list.at(i).line));
    }
    return returnedList;
}
