#ifndef SCALE3D_H
#define SCALE3D_H
#include "point.h"

class Scale3D
{
public:
    Scale3D(float xOld, float yOld, float zOld, float sx, float sy, float sz);
    Scale3D(Point point, float sx, float sy, float sz);
    Scale3D(Point point, float s);

    float P[4][1];
    float S[4][4];
    float PNew[4][1];

    float xOld, yOld, zOld;
    float sx, sy, sz;

    float xNew, yNew, zNew;

    void allocatesP();
    void allocatesS();
    void allocatesPNew();
    void multiplicationMatrix();
    void clearAllMatrix();
    void doScale();
    float getScaleX();
    float getScaleY();
    float getScaleZ();
};

#endif // SCALE3D_H
