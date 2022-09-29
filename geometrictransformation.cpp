#include "geometrictransformation.h"
#include <math.h>
#define PI 3.14159265

GeometricTransformation::GeometricTransformation(float xOld, float yOld, float dx, float dy, float angulo)
{
    this->xOld = xOld;
    this->yOld = yOld;
    this->dx = dx;
    this->dy = dy;
    this->angulo = angulo;
}

void GeometricTransformation::allocateP() {
    this->P[0][0] = xOld;
    this->P[1][0] = yOld;
    this->P[2][0] = 1;
}

void GeometricTransformation::allocateM() {
    this->M[0][0] = cos(angulo*(PI/180));
    M[1][0] = sin(angulo*(PI/180));
    M[2][0] = 0;
    M[0][1] = -sin(angulo*(PI/180));
    M[1][1] = cos(angulo*(PI/180));
    M[2][1] = 0;
    M[0][2] = dx*(1 - cos(angulo*(PI/180)))+dy*sin(angulo*(PI/180));
    M[1][2] = dy*(1 - cos(angulo*(PI/180)))+dx*sin(angulo*(PI/180));
    M[2][2] = 1;
}

void GeometricTransformation::allocatePNew() {
    PNew[0][0] = 0;
    PNew[1][0] = 0;
    PNew[2][0] = 0;
}

void GeometricTransformation::multiplicationMatrix() {
    //numero de linhas da matriz R
    for(int row = 0; row < 3; row++) {
        //numero de colunas da matriz P
        for (int col = 0; col < 1; col++) {
            //número de colunas de matriz R
            for (int inner = 0; inner < 3; inner++) {
                    this->PNew[row][col] += this->M[row][inner] * this->P[inner][col];
            }
        }
    }
}

void GeometricTransformation::doTransformation() {
    allocateP();
    allocateM();
    allocatePNew();
    multiplicationMatrix();
}

float GeometricTransformation::getTransformationX() {
    doTransformation();
    return PNew[0][0];
}

float GeometricTransformation::getTransformationY() {
    doTransformation();
    return PNew[1][0];
}
