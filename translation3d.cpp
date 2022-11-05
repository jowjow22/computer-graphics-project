#include "translation3d.h"

Translation3D::Translation3D(float xOld, float yOld, float zOld, float dx, float dy, float dz) {
    this->xOld = xOld;
    this->yOld = yOld;
    this->zOld = zOld;
    this->dx = dx;
    this->dy = dy;
    this->dz = dz;
}

void Translation3D::allocatesP() {
    this->P[0][0] = this->xOld;
    this->P[1][0] = this->yOld;
    this->P[2][0] = this->zOld;
    this->P[3][0] = 1;
}

void Translation3D::allocatesT() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i==j) {
                this->T[i][j] = 1;
            } else if(j == 3 && i == 0) {
                this->T[i][j] = this->dx;
            } else if(j == 3 && i == 1) {
                this->T[i][j] = this->dy;
            } else if(j == 3 && i == 2) {
                this->T[i][j] = this->dz;
            } else {
                this->T[i][j] = 0;
            }
        }
    }
}

void Translation3D::allocatesPNew() {
    for(int i = 0; i < 4; i++) {
        PNew[i][0] = 0;
    }
}

void Translation3D::multiplicationMatrix() {
    //numero de linhas da matriz T
    for(int row = 0; row < 4; row++) {
        //numero de colunas da matriz P
        for (int col = 0; col < 1; col++) {
            //número de colunas de matriz T
            for (int inner = 0; inner < 4; inner++) {
                    this->PNew[row][col] += this->T[row][inner] * this->P[inner][col];
            }
        }
    }
}

void Translation3D::clearAllMatrix() {
    for(int i = 0; i < 4; i++) {
        this->P[i][0] = 0;
        this->PNew[i][0] = 0;
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            this->T[i][j] = 0;
        }
    }
}

void Translation3D::doTranslation() {
    allocatesP();
    allocatesT();
    allocatesPNew();
    multiplicationMatrix();
    this->xNew = this->PNew[0][0];
    this->yNew = this->PNew[1][0];
    this->zNew = this->PNew[2][0];
    clearAllMatrix();
}

float Translation3D::getTranslationX() {
    doTranslation();
    return this->xNew;
}

float Translation3D::getTranslationY() {
    doTranslation();
    return this->yNew;
}

float Translation3D::getTranslationZ() {
    doTranslation();
    return this->zNew;
}


