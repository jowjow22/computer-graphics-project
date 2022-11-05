#ifndef TRANSLATION3D_H
#define TRANSLATION3D_H


class Translation3D
{
public:
    Translation3D(float xOld, float yOld, float zOld, float dx, float dy, float dz);

    float P[4][1];
    float T[4][4];
    float PNew[4][1];

    float xOld, yOld, zOld;
    float dx, dy, dz;

    float xNew, yNew, zNew;

    void allocatesP();
    void allocatesT();
    void allocatesPNew();
    void multiplicationMatrix();
    void doTranslation();
    void clearAllMatrix();
    float getTranslationX();
    float getTranslationY();
    float getTranslationZ();
};

#endif // TRANSLATION3D_H
