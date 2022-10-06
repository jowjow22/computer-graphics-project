#include "translation.h"

Translation::Translation(float xOld, float yOld, float dx, float dy)
{
    this->xOld = xOld;
    this->yOld = yOld;
    this->dx = dx;
    this->dy = dy;
}

void Translation::allocatesP() {
    this->P[0][0] = xOld;
    this->P[1][0] = yOld;
    this->P[2][0] = 1;
}

void Translation::allocatesT() {
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

void Translation::allocatesPNew() {
    this->PNew[0][0] = 0;
    this->PNew[1][0] = 0;
    this->PNew[2][0] = 0;
}

void Translation::multiplicationMatrix() {
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

void Translation::doTranslation() {
    allocatesP();
    allocatesT();
    allocatesPNew();
    multiplicationMatrix();
}

float Translation::getTranslationX() {
    doTranslation();
    return this->PNew[0][0];
}

float Translation::getTranslationY() {
    doTranslation();
    return this->PNew[1][0];
}
