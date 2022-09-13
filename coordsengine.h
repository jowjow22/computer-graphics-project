#ifndef COORDSENGINE_H
#define COORDSENGINE_H
#include "mainwindow.h"


class CoordsEngine: public MainWindow
{
public:
    CoordsEngine();
    int getWindowWidth();
    int getWindowHeight();
};

#endif // COORDSENGINE_H
