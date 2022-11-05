#include "scale3d.h"

Scale3D::Scale3D(float xOld, float yOld, float zOld, float sx, float sy, float sz) {
    this->xOld = xOld;
    this->yOld = yOld;
    this->zOld = zOld;
    this->sx = sx;
    this->sy = sy;
    this->sz = sz;
}

void Scale3D::allocatesP() {
    this->P[0][0] = this->xOld;
    this->P[1][0] = this->yOld;
    this->P[2][0] = this->zOld;
    this->P[3][0] = 1;
}

void Scale3D::allocatesS() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i == j) {
                if(i == 0) {
                    this->S[i][j] = this->sx;
                } else if(i == 1) {
                    this->S[i][j] = this->sy;
                } else if(i == 2) {
                    this->S[i][j] = this->sz;
                } else {
                    this->S[i][j] = 1;
                }
            } else {
                this->S[i][j] = 0;
            }
        }
    }
}

void Scale3D::allocatesPNew() {
    for(int i = 0; i < 4; i++) {
        PNew[i][0] = 0;
    }
}

void Scale3D::multiplicationMatrix() {
    //numero de linhas da matriz S
    for(int row = 0; row < 4; row++) {
        //numero de colunas da matriz P
        for (int col = 0; col < 1; col++) {
            //número de colunas de matriz S
            for (int inner = 0; inner < 4; inner++) {
                    this->PNew[row][col] += this->S[row][inner] * this->P[inner][col];
            }
        }
    }
}

void Scale3D::clearAllMatrix() {
    for(int i = 0; i < 4; i++) {
        this->P[i][0] = 0;
        this->PNew[i][0] = 0;
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            this->S[i][j] = 0;
        }
    }
}

void Scale3D::doTranslation() {
    allocatesP();
    allocatesS();
    allocatesPNew();
    multiplicationMatrix();
    this->xNew = this->PNew[0][0];
    this->yNew = this->PNew[1][0];
    this->zNew = this->PNew[2][0];
    clearAllMatrix();
}

float Scale3D::getTranslationX() {
    doTranslation();
    return this->xNew;
}

float Scale3D::getTranslationY() {
    doTranslation();
    return this->yNew;
}

float Scale3D::getTranslationZ() {
    doTranslation();
    return this->zNew;
}
