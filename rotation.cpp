#include "rotation.h"
#include <math.h>
#define PI 3.14159265

Rotation::Rotation(float oldX, float oldY, float angulo)
{
    this->xOld = oldX;
    this->yOld = oldY;
    this->angulo = angulo;
}

void Rotation::allocatesP() {
    this->P[0][0] = xOld;
    this->P[1][0] = yOld;
    this->P[2][0] = 1;
}

void Rotation::allocatesR() {
    this->R[0][0] = cos(angulo*(PI/180));
    this->R[1][0] = sin(angulo*(PI/180));
    this->R[2][0] = 0;
    this->R[0][1] = -sin(angulo*(PI/180));
    this->R[1][1] = cos(angulo*(PI/180));
    this->R[2][1] = 0;
    this->R[2][0] = 0;
    this->R[2][1] = 0;
    this->R[2][2] = 1;
}

void Rotation::allocatesPNew() {
    this->PNew[0][0] = 0;
    this->PNew[1][0] = 0;
    this->PNew[2][0] = 0;
}

void Rotation::multiplicationMatrix() {
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

void Rotation::doRotation() {
    allocatesP();
    allocatesR();
    allocatesPNew();
    multiplicationMatrix();
}

float Rotation::getRotationX() {
    doRotation();
    return this->PNew[0][0];
}

float Rotation::getRotationY() {
    doRotation();
    return this->PNew[1][0];
}
