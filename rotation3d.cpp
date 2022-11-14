#include "rotation3d.h"
#include <math.h>
#define PI 3.14159265

Rotation3D::Rotation3D(float xOld, float yOld, float zOld, float angle) {
    this->xOld = xOld;
    this->yOld = yOld;
    this->zOld = zOld;
    this->angle = angle;
}

Rotation3D::Rotation3D(Point point, float angle) {
    this->xOld = point.x;
    this->yOld = point.y;
    this->zOld = point.z;
    this->angle = angle;
}

void Rotation3D::allocatesP() {
    this->P[0][0] = this->xOld;
    this->P[1][0] = this->yOld;
    this->P[2][0] = this->zOld;
    this->P[3][0] = 1;
}

void Rotation3D::allocatesRAroundX() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i == j) {
                if((i == 0 && j == 0) || (i == 3 && j == 3)) {
                    this->RAroundX[i][j] = 1;
                } else {
                    this->RAroundX[i][j] = cos(this->angle*(PI/180));
                }
            } else if(i == 2 && j == 1) {
                this->RAroundX[i][j] = sin(this->angle*(PI/180));
            } else if(i == 1 && j == 2) {
                this->RAroundX[i][j] = - sin(this->angle*(PI/180));
            } else {
                this->RAroundX[i][j] = 0;
            }
        }
    }
}

void Rotation3D::allocatesRAroundY() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i == j) {
                if((i == 1 && j == 1) || (i == 3 && j == 3)) {
                    this->RAroundY[i][j] = 1;
                } else {
                    this->RAroundY[i][j] = cos(this->angle*(PI/180));
                }
            } else if(i == 2 && j == 0) {
                this->RAroundY[i][j] = - sin(this->angle*(PI/180));
            } else if(i == 0 && j == 2) {
                this->RAroundY[i][j] = sin(this->angle*(PI/180));
            } else {
                this->RAroundY[i][j] = 0;
            }
        }
    }
}

void Rotation3D::allocatesRAroundZ() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i == j) {
                if((i == 2 && j == 2) || (i == 3 && j == 3)) {
                    this->RAroundZ[i][j] = 1;
                } else {
                    this->RAroundZ[i][j] = cos(this->angle*(PI/180));
                }
            } else if(i == 1 && j == 0) {
                this->RAroundZ[i][j] = sin(this->angle*(PI/180));
            } else if(i == 0 && j == 1) {
                this->RAroundZ[i][j] = sin(this->angle*(PI/180));
            } else {
                this->RAroundZ[i][j] = 0;
            }
        }
    }
}

void Rotation3D::allocatesPNew() {
    for(int i = 0; i < 4; i++) {
        PNew[i][0] = 0;
    }
}

void Rotation3D::multiplicationMatrixAroundX() {
    //numero de linhas da matriz RAroundX
    for(int row = 0; row < 4; row++) {
        //numero de colunas da matriz P
        for (int col = 0; col < 1; col++) {
            //número de colunas de matriz RAroundX
            for (int inner = 0; inner < 4; inner++) {
                    this->PNew[row][col] += this->RAroundX[row][inner] * this->P[inner][col];
            }
        }
    }
}

void Rotation3D::multiplicationMatrixAroundY() {
    //numero de linhas da matriz RAroundY
    for(int row = 0; row < 4; row++) {
        //numero de colunas da matriz P
        for (int col = 0; col < 1; col++) {
            //número de colunas de matriz RAroundY
            for (int inner = 0; inner < 4; inner++) {
                    this->PNew[row][col] += this->RAroundY[row][inner] * this->P[inner][col];
            }
        }
    }
}

void Rotation3D::multiplicationMatrixAroundZ() {
    //numero de linhas da matriz RAroundZ
    for(int row = 0; row < 4; row++) {
        //numero de colunas da matriz P
        for (int col = 0; col < 1; col++) {
            //número de colunas de matriz RAroundZ
            for (int inner = 0; inner < 4; inner++) {
                    this->PNew[row][col] += this->RAroundZ[row][inner] * this->P[inner][col];
            }
        }
    }
}

void Rotation3D::clearAllMatrix() {
    for(int i = 0; i < 4; i++) {
        this->P[i][0] = 0;
        this->PNew[i][0] = 0;
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            this->RAroundX[i][j] = 0;
            this->RAroundY[i][j] = 0;
            this->RAroundZ[i][j] = 0;
        }
    }
}

void Rotation3D::doRotationAroundX() {
    allocatesP();
    allocatesRAroundX();
    allocatesPNew();
    multiplicationMatrixAroundX();
    this->xNew = this->PNew[0][0];
    this->yNew = this->PNew[1][0];
    this->zNew = this->PNew[2][0];
    clearAllMatrix();
}

void Rotation3D::doRotationAroundY() {
    allocatesP();
    allocatesRAroundY();
    allocatesPNew();
    multiplicationMatrixAroundY();
    this->xNew = this->PNew[0][0];
    this->yNew = this->PNew[1][0];
    this->zNew = this->PNew[2][0];
    clearAllMatrix();
}

void Rotation3D::doRotationAroundZ() {
    allocatesP();
    allocatesRAroundZ();
    allocatesPNew();
    multiplicationMatrixAroundZ();
    this->xNew = this->PNew[0][0];
    this->yNew = this->PNew[1][0];
    this->zNew = this->PNew[2][0];
    clearAllMatrix();
}

float Rotation3D::getRotationXAroundX() {
    doRotationAroundX();
    return this->xNew;
}

float Rotation3D::getRotationYAroundX() {
    doRotationAroundX();
    return this->yNew;
}

float Rotation3D::getRotationZAroundX() {
    doRotationAroundX();
    return this->zNew;
}

float Rotation3D::getRotationXAroundY() {
    doRotationAroundY();
    return this->xNew;
}

float Rotation3D::getRotationYAroundY() {
    doRotationAroundY();
    return this->yNew;
}

float Rotation3D::getRotationZAroundY() {
    doRotationAroundY();
    return this->zNew;
}

float Rotation3D::getRotationXAroundZ() {
    doRotationAroundZ();
    return this->xNew;
}

float Rotation3D::getRotationYAroundZ() {
    doRotationAroundZ();
    return this->yNew;
}

float Rotation3D::getRotationZAroundZ() {
    doRotationAroundZ();
    return this->zNew;
}
