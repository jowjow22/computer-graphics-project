#ifndef READOBJ_H
#define READOBJ_H

#include <QPoint>
#include <QList>
#include<iostream>
#include<fstream>
#include <string>

using namespace std;

class ReadObj
{
public:
    ReadObj();
    void fileObjReader(char* filePath);
};

#endif // READOBJ_H
