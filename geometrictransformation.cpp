#include "geometrictransformation.h"
#include <math.h>
#define PI 3.14159265
#include <QList>
#include <QPoint>

GeometricTransformation::GeometricTransformation(float dx, float dy, float sx, float sy,float angulo)
{
    this->dx = -dx;
    this->dy = -dy;
    this->sx = sx;
    this->sy = sy;
    this->angulo = angulo;
}

void GeometricTransformation::allocatesP() {
    this->P[0][0] = xOld;
    this->P[1][0] = yOld;
    this->P[2][0] = 1;
}

void GeometricTransformation::allocatesR() {
    this->R[0][0] = cos(angulo*(PI/180));
    this->R[1][0] = sin(angulo*(PI/180));
    this->R[2][0] = 0;
    this->R[0][1] = -sin(angulo*(PI/180));
    this->R[1][1] = cos(angulo*(PI/180));
    this->R[2][1] = 0;
    this->R[0][2] = 0;
    this->R[1][2] = 0;
    this->R[2][2] = 1;
}

void GeometricTransformation::allocatesT() {
    this->T[0][0] = 1;
    this->T[1][0] = 0;
    this->T[2][0] = 0;
    this->T[0][1] = 0;
    this->T[1][1] = 1;
    this->T[2][1] = 0;
    this->T[0][2] = dx;
    this->T[1][2] = dy;
    this->T[2][2] = 1;
}

void GeometricTransformation::allocatesS() {
    this->S[0][0] = sx;
    this->S[1][0] = 0;
    this->S[2][0] = 0;
    this->S[0][1] = 0;
    this->S[1][1] = sy;
    this->S[2][1] = 0;
    this->S[0][2] = 0;
    this->S[1][2] = 0;
    this->S[2][2] = 1;
}

void GeometricTransformation::allocatesPNew() {
    for(int i = 0; i < 3; i++) {
        this->PNew[i][0] = 0;
    }
}

void GeometricTransformation::multiplicationMatrixR() {
    //numero de linhas da matriz R
    for(int row = 0; row < 3; row++) {
        //numero de colunas da matriz P
        for (int col = 0; col < 1; col++) {
            //número de colunas de matriz R
            for (int inner = 0; inner < 3; inner++) {
                    this->PNew[row][col] += this->R[row][inner] * this->P[inner][col];
            }
        }
    }
}

void GeometricTransformation::multiplicationMatrixT() {
    //numero de linhas da matriz T
    for(int row = 0; row < 3; row++) {
        //numero de colunas da matriz P
        for (int col = 0; col < 1; col++) {
            //número de colunas de matriz T
            for (int inner = 0; inner < 3; inner++) {
                    this->PNew[row][col] += this->T[row][inner] * this->P[inner][col];
            }
        }
    }
}

void GeometricTransformation::multiplicationMatrixS() {
    //numero de linhas da matriz S
    for(int row = 0; row < 3; row++) {
        //numero de colunas da matriz P
        for (int col = 0; col < 1; col++) {
            //número de colunas de matriz S
            for (int inner = 0; inner < 3; inner++) {
                    this->PNew[row][col] += this->S[row][inner] * this->P[inner][col];
            }
        }
    }
}

void GeometricTransformation::updateValuesOfP() {
    for(int i = 0; i < 3; i++) {
        this->P[i][0] = PNew[i][0];
    }
}


void GeometricTransformation::doTransformation() {
    //allocation
    allocatesP();
    allocatesR();
    allocatesT();
    allocatesS();
    allocatesPNew();

    //go to origin
    multiplicationMatrixT();
    updateValuesOfP();
    allocatesPNew();

    //do Rotation
    multiplicationMatrixR();
    updateValuesOfP();
    allocatesPNew();

    //do Scale
    multiplicationMatrixS();
    updateValuesOfP();
    allocatesPNew();

    //return object
    this->T[0][2] = -1*dx;
    this->T[1][2] = -1*dy;
    multiplicationMatrixT();
}

float GeometricTransformation::getTransformationX() {
    doTransformation();
    return this->PNew[0][0];
}

float GeometricTransformation::getTransformationY() {
    doTransformation();
    return this->PNew[1][0];
}

QList<QPoint> GeometricTransformation::getGeometricTransformation(QList<QPoint> list) {
    for(int i = 0; i < list.length(); i++) {
        this->xOld = list.at(i).x();
        this->yOld = list.at(i).y();
        this->xNew = getTransformationX();
        this->yNew = getTransformationY();
        this->listPoints.append(QPoint(this->xNew, this->yNew));
    }
    return this->listPoints;
}
