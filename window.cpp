#include "window.h"
#include <QRect>
#include "rotation3d.h"
#include "transformations3d.h"

Window::Window(int vpMaxX, int vpMaxY, int vpMaxZ, float wXMin, float wXMax, float wYMin, float wYMax, float wZMin, float wZMax)
{
    //window definitions
    this->wXMax = wXMax;
    this->wXMin = wXMin;
    this->wYMax = wYMax;
    this->wYMin = wYMin;
    this->wZMax = wZMax;
    this->wZMin = wZMin;
    //window definitions

    //viewport info
    this->vpMaxX = vpMaxX;
    this->vpMaxY = vpMaxY;
    this->vpMaxZ = vpMaxZ;
    //viewport info
}

float Window::getWindowX(float x){
   float windowMidX = (this->wXMax-this->wXMin)/2;
   return (this->worldMid[0] + windowMidX + x);
}

float Window::getWindowY(float y){
    float windowMidY = (this->wYMax-this->wYMin)/2;
    return (this->worldMid[0] + windowMidY + y);
}

float Window::getWindowZ(float z){
    float windowMidZ = (this->wZMax-this->wZMin)/2;
    return (this->worldMid[0] + windowMidZ + z);
}

float Window::gNormalizedX(float x){
    float windowX = (this->getWindowX(x)-this->wXMin)/ (this->wXMax - this->wXMin);
    return windowX;
}

float Window::gNormalizedY(float y){
    float windowY = 1 - (this->getWindowY(y) - this->wYMin) / (this->wYMax - this->wYMin);
    return windowY;
}

float Window::gNormalizedZ(float z){
    float windowZ = 1 - (this->getWindowZ(z) - this->wZMin) / (this->wZMax - this->wZMin);
    return windowZ;
}

float Window::gVPX(float x){
    return this->gNormalizedX(x)*this->vpMaxX;
}

float Window::gVPY(float y){
    return this->gNormalizedY(y)*this->vpMaxY;
}

float Window::gVPZ(float z){
    return this->gNormalizedZ(z)*this->vpMaxZ;
}

Line Window::gVPLine(Line line) {
    return Line(this->gVPX(line.x1), this->gVPY(line.y1), this->gVPZ(line.z1),
                this->gVPX(line.x2), this->gVPY(line.y2), this->gVPZ(line.z2));
}

QList<Point> Window::viewPortTransformPoint(QList<Point> points){
    QList<Point> viewPortPoints;
    for(const Point &point : points){
        viewPortPoints.append(Point(this->gVPX(point.x), this->gVPY(point.y), this->gVPZ(point.z)));
    }
    return viewPortPoints;
}

QList<Line> Window::viewPortTransformLine(QList<Line> lines, int windowScale, int windowAngleX, int windowAngleY, int windowAngleZ, int windowPosX, int windowPosY, int windowPosZ){
    QList<Line> viewPortLines;
    for(const Line &line : lines){
        viewPortLines.append(this->gVPLine(Transformations3d::getWindowTransformations3d(line, windowScale, windowAngleX, windowAngleY, windowAngleZ, windowPosX, windowPosY, windowPosZ)));
    }
    return viewPortLines;
}
