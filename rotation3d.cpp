#include "rotation3d.h"
#include <math.h>
#define PI 3.14159265

Rotation3D::Rotation3D(float xOld, float yOld, float zOld, float angleX, float angleY, float angleZ) {
    this->xOld = xOld;
    this->yOld = yOld;
    this->zOld = zOld;
    this->angleX = angleX*(PI/180);
    this->angleY= angleY*(PI/180);
    this->angleZ = angleZ*(PI/180);
}

Rotation3D::Rotation3D(Point point, float angleX, float angleY, float angleZ) {
    this->xOld = point.x;
    this->yOld = point.y;
    this->zOld = point.z;
    this->angleX = angleX*(PI/180);
    this->angleY = angleY*(PI/180);
    this->angleZ = angleZ*(PI/180);
}

void Rotation3D::allocatesP() {
    this->P[0][0] = this->xOld;
    this->P[1][0] = this->yOld;
    this->P[2][0] = this->zOld;
    this->P[3][0] = 1;
}

void Rotation3D::allocatesR() {
    this->R[0][0] = cos(this->angleY)*cos(this->angleZ);
    this->R[0][1] = -cos(this->angleY)*sin(this->angleZ);
    this->R[0][2] = sin(this->angleY);
    this->R[0][3] = 0;
    this->R[1][0] = (sin(this->angleX)*sin(this->angleY)*cos(this->angleZ)) + (cos(this->angleX)*sin(this->angleZ));
    this->R[1][1] = (cos(this->angleX)*cos(this->angleZ)) - (sin(this->angleX)*sin(this->angleY)*sin(this->angleZ));
    this->R[1][2] = -sin(this->angleX)*cos(this->angleY);
    this->R[1][3] = 0;
    this->R[2][0] = (sin(this->angleX)*sin(this->angleZ)) - (cos(this->angleX)*sin(this->angleY)*cos(this->angleZ));
    this->R[2][1] = (cos(this->angleX)*sin(this->angleY)*sin(this->angleZ)) + (sin(this->angleX)*cos(this->angleZ));
    this->R[2][2] = cos(this->angleX)*cos(this->angleY);
    this->R[2][3] = 0;
    this->R[3][0] = 0;
    this->R[3][1] = 0;
    this->R[3][2] = 0;
    this->R[3][3] = 1;
}

void Rotation3D::allocatesPNew() {
    for(int i = 0; i < 4; i++) {
        PNew[i][0] = 0;
    }
}

void Rotation3D::multiplicationMatrix() {
    //numero de linhas da matriz R
    for(int row = 0; row < 4; row++) {
        //numero de colunas da matriz P
        for (int col = 0; col < 1; col++) {
            //número de colunas de matriz R
            for (int inner = 0; inner < 4; inner++) {
                    this->PNew[row][col] += this->R[row][inner] * this->P[inner][col];
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
            this->R[i][j] = 0;
        }
    }
}

void Rotation3D::doRotation() {
    allocatesP();
    allocatesR();
    allocatesPNew();
    multiplicationMatrix();
    this->xNew = this->PNew[0][0];
    this->yNew = this->PNew[1][0];
    this->zNew = this->PNew[2][0];
    clearAllMatrix();
}

float Rotation3D::getRotationX() {
    doRotation();
    return this->xNew;
}

float Rotation3D::getRotationY() {
    doRotation();
    return this->yNew;
}

float Rotation3D::getRotationZ() {
    doRotation();
    return this->zNew;
}
