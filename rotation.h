#ifndef ROTATION_H
#define ROTATION_H
#include <iostream>
#include <cmath>
using namespace std;


class Rotation
{
public:
    Rotation(float oldX, float oldY, float graus);
    float PNew[3][1];
    float R[3][3];
    float P[3][1];

    float xOld, yOld, angulo;
    float xNew, yNew;

    void allocatesP();
    void allocatesR();
    void allocatesPNew();
    void multiplicationMatrix();
    void doRotation();
    float getRotationX();
    float getRotationY();
};

#endif // ROTATION_H
