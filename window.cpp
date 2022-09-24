#include "window.h"
#include <QRect>

Window::Window(int vpMaxX, int vpMaxY, float wXMin, float wXMax, float wYMin, float wYMax)
{
    //window definitions
    this->wXMax = wXMax;
    this->wXMin = wXMin;
    this->wYMax = wYMax;
    this->wYMin = wYMin;
    //window definitions

    //viewport info
    this->vpMaxX = vpMaxX;
    this->vpMaxY = vpMaxY;
    //viewport info
}

float Window::getWindowX(float x){
   float windowMidX = (this->wXMax+this->wXMin)/2;
   return (this->worldMid[0]+windowMidX + x);
}

float Window::getWindowY(float y){
    float windowMidY = (this->wYMax+this->wYMin)/2;
    return (this->worldMid[0]+windowMidY + y);
}

float Window::gNormalizedX(float x){
    float windowX = (this->getWindowX(x)-this->wXMin)/ (this->wXMax - this->wXMin);
    return windowX;
}


float Window::gNormalizedY(float y){
    float windowY = 1 - (this->getWindowY(y) - this->wYMin) / (this->wYMax - this->wYMin);
    return windowY;
}

float Window::gVPX(float x){
    return this->gNormalizedX(x)*this->vpMaxX;
}

float Window::gVPY(float y){
    return this->gNormalizedY(y)*this->vpMaxY;
}
