#ifndef SCALE3D_H
#define SCALE3D_H


class Scale3D
{
public:
    Scale3D(float xOld, float yOld, float zOld, float sx, float sy, float sz);

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
    void doTranslation();
    float getTranslationX();
    float getTranslationY();
    float getTranslationZ();
};

#endif // SCALE3D_H
