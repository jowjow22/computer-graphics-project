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

    float x, y, z, angleX = 0, angleY = 0, angleZ = 0, size = 5;
    static int focalDistance;

    ReadObj(QString fileName, QColor objColor, int x);
    QList<Point> readPoints;
    QList<Line> readLines;
    QList<QLine> draw(Window *window, Clipping *frame, int focalDistance);
    QList<QLine> transformObjectData(Window *window, Clipping *frame, float scaleObject, float angleX, float angleY, float angleZ, float posX, float posY, float posZ);
    void fileObjReader();
    string getVertexOfPlane(string value);
    void clearValues(string values[]);
private:
    bool FLAG;
};

#endif // READOBJ_H
