#ifndef GEOMETRICTRANSFORMATION_H
#define GEOMETRICTRANSFORMATION_H
#include <iostream>
#include <cmath>
using namespace std;


class GeometricTransformation
{
public:
    GeometricTransformation(float xOld, float yOld, float dx, float dy, float sx, float sy, float angulo);
    float P[3][1];
    float R[3][3];
    float T[3][3];
    float S[3][3];
    float PNew[3][1];

    float xOld, yOld, xNew, yNew;
    float dx, dy, sx, sy, angulo;

    void allocatesP();
    void allocatesR();
    void allocatesT();
    void allocatesS();
    void allocatesPNew();
    void multiplicationMatrixR();
    void multiplicationMatrixT();
    void multiplicationMatrixS();
    void updateValuesOfP();
    void doTransformation();
    float getTransformationX();
    float getTransformationY();
};

#endif // GEOMETRICTRANSFORMATION_H
