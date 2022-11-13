#ifndef READOBJ_H
#define READOBJ_H

#include <QList>
#include "point.h"
#include "line.h"
#include <QLine>
#include<iostream>
#include<fstream>
#include <string>
#include "window.h"
#include "clipping.h"

using namespace std;

class ReadObj
{
public:
    QString fileName;
    QColor objectColor;

    double x, y, z, angleX = 0, angleY=0, angleZ=0, size = 5;

    ReadObj(QString fileName, QColor objColor, int x);
    QList<Point> readPoints;
    QList<Line> readLines;
    QList<QLine> draw(Window *window, Clipping *frame);
    QList<QLine> transformObjectData(Window *window, Clipping *frame, int scaleObject, int angleX, int angleY, int angleZ, int posX, int posY, int posZ);
    void fileObjReader();
    string getVertexOfPlane(string value);
    void clearValues(string values[]);
private:
    bool FLAG;
};

#endif // READOBJ_H
