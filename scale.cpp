#include "scale.h"

Scale::Scale(float xOld, float yOld, float sx, float sy)
{
    this->xOld = xOld;
    this->yOld = yOld;
    this->sx = sx;
    this->sy = sy;
}

void Scale::allocatesP(){
    this->P[0][0] = xOld;
    this->P[1][0] = yOld;
    this->P[2][0] = 1;
}

void Scale::allocatesS() {
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

void Scale::allocatesPNew() {
    this->PNew[0][0] = 0;
    this->PNew[1][0] = 0;
    this->PNew[2][0] = 0;
}

void Scale::multiplicationMatrix() {
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

void Scale::doScale() {
    allocatesP();
    allocatesS();
    allocatesPNew();
    multiplicationMatrix();
}

float Scale::getScaleX() {
    doScale();
    return this->PNew[0][0];
}

float Scale::getScaleY() {
    doScale();
    return this->PNew[1][0];
}
