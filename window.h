#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include <QList>
#include "line.h"
#include <QLine>

class Window
{
public:
    QList<int> worldMid = {0,0};
    int vpMaxX, vpMaxY, vpMaxZ;
    float wXMax, wYMax, wZMax, wXMin, wYMin, wZMin;
    Window(int vpMaxX, int vpMaxY, int vpMaxZ, float wXMin, float wXMax, float wYMin, float wYMax, float wZMin, float wZMax);
    void changeWindowState(float wXMax, float wYMax, float wXMin, float wYMin);

    float gVPX(float x);
    float gVPY(float y);
    float gVPZ(float z);
    Line gVPLine(Line line);
    float getWindowX(float x);
    float getWindowY(float y);
    float getWindowZ(float z);
    float gNormalizedX(float x);
    float gNormalizedY(float y);
    float gNormalizedZ(float z);
    float setWindow();
    QList<Point> viewPortTransformPoint(QList<Point> points);
    QList<Line> viewPortTransformLine(QList<Line> lines, int windowScale, int windowAngleX, int windowAngleY, int windowAngleZ, int windowPosX, int windowPosY, int windowPosZ);
};

#endif // WINDOW_H
