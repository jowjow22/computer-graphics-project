#include "readobj.h"
#include "point.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <QFile>
#include <regex>
#include <QString>
#include <QTextStream>
#include "mainwindow.h"
#include <math.h>
#include "transformations3d.h"

ReadObj::ReadObj(QString fileName, QColor objColor, int x)
{
    this->FLAG = false;
    this->fileName = fileName;
    this->objectColor = objColor;
    this->x = x;
}
void ReadObj::fileObjReader(){
    if(!this->FLAG){
    QString line;
    QFile objFile("../computer-graphics-project/"+this->fileName+".obj");
    regex vertexReg("[v]( ([-]?[0-9]*.[0-9]*))+");
    regex facesReg("[f]( [0-9]*/[0-9]*/[0-9]*)+");
    if(!objFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
    QTextStream in(&objFile);

    do{
        line = in.readLine().trimmed();
        if(regex_match(line.toStdString(), vertexReg)){
            auto vertex = line.split(u' ');
            this->readPoints.append(Point(vertex[1].toDouble(), vertex[2].toDouble(), vertex[3].toDouble()));
        }
    } while(!line.isNull());
    objFile.close();

    if(!objFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
    QTextStream in2(&objFile);
    QString line2;
    do{
        line2 = in2.readLine().trimmed();
        if(regex_match(line2.toStdString(), facesReg)){
            auto faces = line2.split(u' ');
            for(int i = 1; i <= faces.length()-2; i++){
                int currentPoint = faces[i].split(u'/')[0].toInt() - 1;
                int nextPoint = faces[i+1].split(u'/')[0].toInt() - 1;
                int firstPoint = faces[1].split(u'/')[0].toInt() - 1;
                this->readLines.append(Line(this->readPoints.at(currentPoint), this->readPoints.at(nextPoint)));
                if(i == faces.length()-2){
                    this->readLines.append(Line(this->readPoints.at(nextPoint), this->readPoints.at(firstPoint)));
                }

            }
        }
    }while(!line2.isNull());
    objFile.close();
    this->FLAG = true;
    }
}

string ReadObj::getVertexOfPlane(string value) {
    for(unsigned long i = 0; i < value.length(); i++) {
        if(value[i] == '/') {
            return value.substr(0, i);
        }
    }
    return value;
}


QList<QLine> ReadObj::transformObjectData(Window *window, Clipping *frame, int scaleObject, int angleX, int angleY, int angleZ, int posX, int posY, int posZ){
    this->x += posX;
    this->y += posY;
    this->z += posZ;
    this->size += scaleObject;
    this->angleX = angleX;
    this->angleY = angleY;
    this->angleZ = angleZ;
    return frame->listClipping(window->viewPortTransformLine(Transformations3d::getTransformations3d(*this, this->size, this->angleX, this->angleY, this->angleZ, this->x, this->y, this->z)));
}

QList<QLine> ReadObj::draw(Window *window, Clipping *frame){
    return frame->listClipping(window->viewPortTransformLine(Transformations3d::getTransformations3d(*this, this->size, this->angleX, this->angleY, this->angleZ, this->x, this->y, this->z)));
}

void ReadObj::clearValues(string values[]) {
    for(unsigned long i = 0; i < values->length(); i++) {
        values[i].clear();
    }
}
