#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include <QList>
#include <QPoint>

class Window
{
public:
    QList<int> worldMid = {0,0};
    int vpMaxX, vpMaxY;
    float wXMax, wYMax, wXMin, wYMin;
    Window(int vpMaxX, int vpMaxY, float wXMin, float wXMax, float wYMin, float wYMax);
    void changeWindowState(float wXMax, float wYMax, float wXMin, float wYMin);

    float gVPX(float x);
    float gVPY(float y);
    float getWindowX(float x);
    float getWindowY(float y);
    float gNormalizedX(float x);
    float gNormalizedY(float y);
    float setWindow();
    QList<QPoint> viewPortTransform(QList<QPoint> points);
};

#endif // WINDOW_H
