#include "clipping.h"

Clipping::Clipping(int xMin, int yMin, int xMax, int yMax)
{
    this->xMin = xMin;
    this->yMin = yMin;
    this->xMax = xMax;
    this->yMax = yMax;


}

void Clipping::calculateRegionCode(QList<QPoint*> *points){
    for(int i = 0; i < points->length(); i++){
        if(i == points->length() - 1){
            if(points->at(i)->y() > this->yMax){
                rc0[0] = 1;
            }
            if(points->at(i)->y() < this->yMin ){
                rc0[1] = 1;
            }
            if(points->at(i)->x() > this->xMax ){
                rc0[2] = 1;
            }
            if(points->at(i)->x() < this->xMin){
                rc0[3] = 1;
            }
            if(points->at(i+1)->y() > this->yMax){
                rc1[0] = 1;
            }
            if(points->at(i+1)->y() < this->yMin ){
                rc1[1] = 1;
            }
            if(points->at(i+1)->x() > this->xMax ){
                rc1[2] = 1;
            }
            if(points->at(i+1)->x() < this->xMin){
                rc1[3] = 1;
            }
            m = (points->at(i)->x()-points->at(i+1)->x())/(points->at(i)->x()-points->at(i+1)->x());
            if(rc0[0] == 1){
                points->at(i)->setX(points->at(i)->x() + 1/m*(yMax - points->at(i)->y()));
                    // topo: X = X1 + 1/m*(Yt - Y1)
            }
            if(rc0[1] == 1){
                points->at(i)->setX(points->at(i)->x() + 1/m*(yMin - points->at(i)->y()));
                    // base: X = X1 + 1/m*(Yf - Y1)
            }
            if(rc0[2] == 1){
                points->at(i)->setY(m*(xMax - points->at(i)->x()) + points->at(i)->y());
                    // direita: Y = m*(Xd - X1) + Y1
            }
            if(rc0[3] == 1){
                points->at(i)->setY(m*(xMin - points->at(i)->x()) + points->at(i)->y());
                   // esquerda: Y = m*(Xe - X1) + Y1
            }
            if(rc1[0] == 1){
                points->at(i+1)->setX(points->at(i+1)->x() + 1/m*(yMax - points->at(i+1)->y()));
                    // topo: X = X1 + 1/m*(Yt - Y1)
            }
            if(rc1[1] == 1){
                points->at(i+1)->setX(points->at(i+1)->x() + 1/m*(yMin - points->at(i+1)->y()));
                    // base: X = X1 + 1/m*(Yf - Y1)
            }
            if(rc1[2] == 1){
                points->at(i+1)->setY(m*(xMax - points->at(i+1)->x()) + points->at(i+1)->y());
                    //->direita: Y = m*(Xd - X1) + Y1
            }
            if(rc1[3] == 1){
                points->at(i+1)->setY(m*(xMin - points->at(i+1)->x()) + points->at(i+1)->y());
                   // esquerda: Y = m*(Xe - X1) + Y1
            }
        }
        else{
            if(points->at(i)->y() > this->yMax){
                rc0[0] = 1;
            }
            if(points->at(i)->y() < this->yMin ){
                rc0[1] = 1;
            }
            if(points->at(i)->x() > this->xMax ){
                rc0[2] = 1;
            }
            if(points->at(i)->x() < this->xMin){
                rc0[3] = 1;
            }
            if(points->at(1)->y() > this->yMax){
                rc1[0] = 1;
            }
            if(points->at(1)->y() < this->yMin){
                rc1[1] = 1;
            }
            if(points->at(1)->x() > this->xMax ){
                rc1[2] = 1;
            }
            if(points->at(1)->x() < this->xMin){
                rc1[3] = 1;
            }
            m = (points->at(i)->x()-points->at(i+1)->x())/(points->at(i)->x()-points->at(i+1)->x());
            if(rc0[0] == 1){
                points->at(i)->setX(points->at(i)->x() + 1/m*(yMax - points->at(i)->y()));
                    // topo: X = X1 + 1/m*(Yt - Y1)
            }
            if(rc0[1] == 1){
                points->at(i)->setX(points->at(i)->x() + 1/m*(yMin - points->at(i)->y()));
                    // base: X = X1 + 1/m*(Yf - Y1)
            }
            if(rc0[2] == 1){
                points->at(i)->setY(m*(xMax - points->at(i)->x()) + points->at(i)->y());
                    // direita: Y = m*(Xd - X1) + Y1
            }
            if(rc0[3] == 1){
                points->at(i)->setY(m*(xMin - points->at(i)->x()) + points->at(i)->y());
                   // esquerda: Y = m*(Xe - X1) + Y1
            }
            if(rc1[0] == 1){
                points->at(1)->setX(points->at(1)->x() + 1/m*(yMax - points->at(1)->y()));
                    // topo: X = X1 + 1/m*(Yt - Y1)
            }
            if(rc1[1] == 1){
                points->at(1)->setX(points->at(1)->x() + 1/m*(yMin - points->at(1)->y()));
                    // base: X = X1 + 1/m*(Yf - Y1)
            }
            if(rc1[2] == 1){
                points->at(1)->setY(m*(xMax - points->at(1)->x()) + points->at(1)->y());
                    // direita: Y = m*(Xd - X1) + Y1
            }
            if(rc1[3] == 1){
                points->at(1)->setY(m*(xMin - points->at(1)->x()) + points->at(1)->y());
                   // esquerda: Y = m*(Xe - X1) + Y1
            }
        }
    }
}

//Segunda ideia
/*
 * #include "clipping.h"

Clipping::Clipping(int xMin, int yMin, int xMax, int yMax)
{
    this->xMin = xMin;
    this->yMin = yMin;
    this->xMax = xMax;
    this->yMax = yMax;


}

void Clipping::calculateRegionCode(QList<QPoint> *points){
            if(points->at(0).y() > this->yMax){
                rc0[0] = 1;
            }
            if(points->at(0).y() < this->yMin ){
                rc0[1] = 1;
            }
            if(points->at(0).x() > this->xMax ){
                rc0[2] = 1;
            }
            if(points->at(0).x() < this->xMin){
                rc0[3] = 1;
            }
            if(points->at(1).y() > this->yMax){
                rc1[0] = 1;
            }
            if(points->at(1).y() < this->yMin ){
                rc1[1] = 1;
            }
            if(points->at(1).x() > this->xMax ){
                rc1[2] = 1;
            }
            if(points->at(1).x() < this->xMin){
                rc1[3] = 1;
            }
            m = (points->at(0).x()-points->at(1).x())/(points->at(0).x()-points->at(1).x());
            if(rc0[0] == 1){
                this->x0 = points->at(0).x() + 1/m*(yMax - points->at(0).y());
                    // topo: X = X1 + 1/m*(Yt - Y1)
            }
            if(rc0[1] == 1){
                x0 = points->at(0).x() + 1/m*(yMin - points->at(0).y());
                    // base: X = X1 + 1/m*(Yf - Y1)
            }
            if(rc0[2] == 1){
                y0 = m*(xMax - points->at(0).x()) + points->at(0).y();
                    // direita: Y = m*(Xd - X1) + Y1
            }
            if(rc0[3] == 1){
                y0 = m*(xMin - points->at(0).x()) + points->at(0).y();
                   // esquerda: Y = m*(Xe - X1) + Y1
            }
            if(rc1[0] == 1){
                x1 = points->at(1).x() + 1/m*(yMax - points->at(1).y());
                    // topo: X = X1 + 1/m*(Yt - Y1)
            }
            if(rc1[1] == 1){
                x1 = points->at(1).x() + 1/m*(yMin - points->at(1).y());
                    // base: X = X1 + 1/m*(Yf - Y1)
            }
            if(rc1[2] == 1){
                y1 = m*(xMax - points->at(1).x()) + points->at(1).y();
                    //->direita: Y = m*(Xd - X1) + Y1
            }
            if(rc1[3] == 1){
                y1 = m*(xMin - points->at(1).x()) + points->at(1).y();
                   // esquerda: Y = m*(Xe - X1) + Y1
        }
}




void Clipping::preRegionCode(QList<QPoint*> *points, QList<QPoint> *newPoints){
    for(int i = 0; i < points->length(); i++){
        if(i == points->length() - 1){
            calculateRegionCode(points);
            QPoint *newP = (QPoint*)malloc(sizeof(QPoint));
            newP->setX(x0);
            newP->setX(y0);
            newPoints->append(*newP);
        }
        else{
            calculateRegionCode({points->at(i), points->at(1)});
            QPoint *newP = (QPoint*)malloc(sizeof(QPoint));
            newP->setX(x0);
            newP->setX(y0);
            newPoints->append(*newP);
        }
    }
}

#ifndef CLIPPING_H
#define CLIPPING_H

#include <QList>
#include <QPoint>

class Clipping
{
public:
    Clipping(int xMin, int yMin, int xMax, int yMax);
    void calculateRegionCode(QList<QPoint* > *points);
    void preRegionCode(QList<QPoint> *points, QList<QPoint> *newPoints);
    int rc0[4];
    int rc1[4];
    int xMin, yMin, xMax, yMax, m, x0, x1, y0, y1;

};

#endif // CLIPPING_H




 * */
