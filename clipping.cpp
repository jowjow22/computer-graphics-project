#include "clipping.h"
#include <iostream>

Clipping::Clipping(QList<QPoint> points) {
    for(QPoint point : points){
        this->framePoints.append(point);
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
    float m = (p2.y() - p1.y())/(p2.x() - p1.x());
    float newY = m * (this->leftX - p2.x()) + p2.y();
    return newY;
}

float Clipping::lineEquationRight(QPoint p1, QPoint p2) {
    float m = (p2.y() - p1.y())/(p2.x() - p1.x());
    float newY = m * (this->rightX - p2.x()) + p2.y();
    return newY;
}

float Clipping::lineEquationTop(QPoint p1, QPoint p2) {
    float m = (p2.y() - p1.y())/(p2.x() - p1.x());
    float newX = p1.x() + 1/m * (this->topY - p1.y());
    return newX;
}

float Clipping::lineEquationBottom(QPoint p1, QPoint p2) {
    float m = (p2.y() - p1.y())/(p2.x() - p1.x());
    float newX = p1.x() + 1/m * (this->bottomY - p1.y());
    return newX;
}

QList<QLine> Clipping::doClipping(QList<QLine> list) {
    defineFramePoints();
    QList<QLine> clippingList;
    for(int i = 0; i < list.length(); i++) {
        int regionCode[4], regionCode1[4];
        QPoint p1 = list.at(i).p1();
        QPoint p2 = list.at(i).p2();
        defineRegionCode(p1, regionCode);
        defineRegionCode(p2, regionCode1);
        std::cout << "p1" << std::endl;
        for(int i = 0; i < 4; i ++) {
            std::cout << regionCode[i] << std::endl;
        }
        std::cout << "p2" << std::endl;
        for(int i = 0; i < 4; i ++) {
            std::cout << regionCode1[i] << std::endl;
        }
        //base case
        if(regionCode[0] == 0 && regionCode[1] == 0 && regionCode[2] == 0 && regionCode[3] == 0) {
            //base case
            if(regionCode1[0] == 0 && regionCode1[1] == 0 && regionCode1[2] == 0 && regionCode1[3] == 0) {
                clippingList.append(QLine(p1, p2));
                break;
            }
            //normal cases
            //Top
            if(regionCode1[0] == 1 && regionCode1[1] == 0 && regionCode1[2] == 0 && regionCode1[3] == 0) {
                float newXP2 = lineEquationTop(p1, p2);
                clippingList.append(QLine(p1.x(), p1.y(), newXP2, this->topY));
                break;
            }
            //Right
            if(regionCode1[0] == 0 && regionCode1[1] == 0 && regionCode1[2] == 1 && regionCode1[3] == 0) {
                float newYP2 = lineEquationRight(p1, p2);
                clippingList.append(QLine(p1.x(), p1.y(), this->rightX, newYP2));
                break;
            }
            //Bottom
            if(regionCode1[0] == 0 && regionCode1[1] == 1 && regionCode1[2] == 0 && regionCode1[3] == 0) {
                float newXP2 = lineEquationBottom(p1, p2);
                clippingList.append(QLine(p1.x(), p1.y(), newXP2, this->bottomY));
                break;
            }
            //Left
            if(regionCode1[0] == 0 && regionCode1[1] == 0 && regionCode1[2] == 0 && regionCode1[3] == 1) {
                float newYP2 = lineEquationLeft(p1, p2);
                clippingList.append(QLine(p1.x(), p1.y(), this->leftX, newYP2));
                break;
            }

            //special cases
            //Top Left
            if(regionCode1[0] == 1 && regionCode1[1] == 0 && regionCode1[2] == 0 && regionCode1[3] == 1) {
                break;
            }
            //Top Right
            if(regionCode1[0] == 1 && regionCode1[1] == 0 && regionCode1[2] == 1 && regionCode1[3] == 0) {
                break;
            }
            //Bottom Right
            if(regionCode1[0] == 0 && regionCode1[1] == 1 && regionCode1[2] == 1 && regionCode1[3] == 0) {
                break;
            }
            //Bottom Left
            if(regionCode1[0] == 0 && regionCode1[1] == 1 && regionCode1[2] == 0 && regionCode1[3] == 1) {
                break;
            }
        }

        if(regionCode1[0] == 0 && regionCode1[1] == 0 && regionCode1[2] == 0 && regionCode1[3] == 0) {
            //normal cases
            //Top
            if(regionCode[0] == 1 && regionCode[1] == 0 && regionCode[2] == 0 && regionCode[3] == 0) {
                float newXP1 = lineEquationTop(p1, p2);
                clippingList.append(QLine(newXP1, this->topY, p2.x(), p2.y()));
                break;
            }
            //Right
            if(regionCode[0] == 0 && regionCode[1] == 0 && regionCode[2] == 1 && regionCode[3] == 0) {
                float newYP1 = lineEquationRight(p2, p1);
                clippingList.append(QLine(this->rightX, newYP1, p2.x(), p2.y()));
                break;
            }
            //Bottom
            if(regionCode[0] == 0 && regionCode[1] == 1 && regionCode[2] == 0 && regionCode[3] == 0) {
                float newXP1 = lineEquationBottom(p1, p2);
                clippingList.append(QLine(newXP1, this->bottomY, p2.x(), p2.y()));
                break;
            }
            //Left
            if(regionCode[0] == 0 && regionCode[1] == 0 && regionCode[2] == 0 && regionCode[3] == 1) {
                float newYP1 = lineEquationLeft(p2, p1);
                clippingList.append(QLine(this->leftX, newYP1, p2.x(), p2.y()));
                break;
            }

            //special cases
            //Top Left
            if(regionCode[0] == 1 && regionCode[1] == 0 && regionCode[2] == 0 && regionCode[3] == 1) {
                break;
            }
            //Top Right
            if(regionCode[0] == 1 && regionCode[1] == 0 && regionCode[2] == 1 && regionCode[3] == 0) {
                break;
            }
            //Bottom Right
            if(regionCode[0] == 0 && regionCode[1] == 1 && regionCode[2] == 1 && regionCode[3] == 0) {
                break;
            }
            //Bottom Left
            if(regionCode[0] == 0 && regionCode[1] == 1 && regionCode[2] == 0 && regionCode[3] == 1) {
                break;
            }
        }
    }
    return clippingList;
}
