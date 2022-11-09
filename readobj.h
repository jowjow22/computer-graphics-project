#ifndef READOBJ_H
#define READOBJ_H

#include <QList>
#include "point.h"
#include "line.h"
#include <QLine>
#include<iostream>
#include<fstream>
#include <string>

using namespace std;

class ReadObj
{
public:
    ReadObj();
    QList<Point> readPoints;
    QList<Line> readLines;
    bool FLAG;
    void fileObjReader(char* filePath);
    string getVertexOfPlane(string value);
    void clearValues(string values[]);
};

#endif // READOBJ_H
