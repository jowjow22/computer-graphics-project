#ifndef ROTATION3D_H
#define ROTATION3D_H


class Rotation3D
{
public:
    Rotation3D(float xOld, float yOld, float zOld, float angle);

    float P[4][1];
    float PNew[4][1];
    float RAroundX[4][4];
    float RAroundY[4][4];
    float RAroundZ[4][4];

    float xOld, yOld, zOld;
    float angle;

    float xNew, yNew, zNew;

    void allocatesP();
    void allocatesRAroundX();
    void allocatesRAroundY();
    void allocatesRAroundZ();
    void allocatesPNew();
    void multiplicationMatrixAroundX();
    void multiplicationMatrixAroundY();
    void multiplicationMatrixAroundZ();
    void clearAllMatrix();
    void doRotationAroundX();
    void doRotationAroundY();
    void doRotationAroundZ();
    float getRotationXAroundX();
    float getRotationYAroundX();
    float getRotationZAroundX();
    float getRotationXAroundY();
    float getRotationYAroundY();
    float getRotationZAroundY();
    float getRotationXAroundZ();
    float getRotationYAroundZ();
    float getRotationZAroundZ();
};

#endif // ROTATION3D_H
