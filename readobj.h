#ifndef READOBJ_H
#define READOBJ_H

#include <QList>
#include "point.h"
#include<iostream>
#include<fstream>
#include <string>

using namespace std;

class ReadObj
{
public:
    ReadObj();
    QList<Point> readPoints;
    bool FLAG;
    void fileObjReader(char* filePath);
};

#endif // READOBJ_H
