#ifndef TRANSLATION_H
#define TRANSLATION_H
#include <iostream>


class Translation
{
public:
    Translation(float xOld, float yOld, float dx, float dy);

    float PNew[3][1];
    float T[3][3];
    float P[3][1];

    float xOld, yOld, dx, dy;
    float xNew, yNew;

    void allocatesP();
    void allocatesT();
    void allocatesPNew();
    void multiplicationMatrix();
    void doTranslation();
    float getTranslationX();
    float getTranslationY();

};

#endif // TRANSLATION_H
