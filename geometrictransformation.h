#ifndef GEOMETRICTRANSFORMATION_H
#define GEOMETRICTRANSFORMATION_H
#include <iostream>
#include <cmath>
using namespace std;


class GeometricTransformation
{
public:
    GeometricTransformation(float xOld, float yOld, float dx, float dy, float angulo);
    float P[3][1];
    float M[3][3];
    float PNew[3][1];

    float xOld, yOld, xNew, yNew;
    float dx, dy, angulo;

    void allocateP();
    void allocateM();
    void allocatePNew();
    void multiplicationMatrix();
    void doTransformation();
    float getTransformationX();
    float getTransformationY();
};

#endif // GEOMETRICTRANSFORMATION_H
