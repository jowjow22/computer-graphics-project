#ifndef SCALE_H
#define SCALE_H
#include <iostream>


class Scale
{
public:
    Scale(float xOld, float yOld, float sx, float sy);

    float PNew[3][1];
    float S[3][3];
    float P[3][1];

    float xOld, yOld, sx, sy;
    float xNew, yNew;

    void allocatesP();
    void allocatesS();
    void allocatesPNew();
    void multiplicationMatrix();
    void doScale();
    float getScaleX();
    float getScaleY();
};

#endif // SCALE_H
