#ifndef ROTATION3D_H
#define ROTATION3D_H
#include "point.h"

class Rotation3D
{
public:
    Rotation3D(float xOld, float yOld, float zOld, float angleX, float angleY, float angleZ);
    Rotation3D(Point point, float angleX, float angleY, float angleZ);

    float P[4][1];
    float PNew[4][1];
    float R[4][4];

    float xOld, yOld, zOld;
    float angleX, angleY, angleZ;

    float xNew, yNew, zNew;

    void allocatesP();
    void allocatesR();
    void allocatesPNew();
    void multiplicationMatrix();
    void clearAllMatrix();
    void doRotation();
    float getRotationX();
    float getRotationY();
    float getRotationZ();
};

#endif // ROTATION3D_H
