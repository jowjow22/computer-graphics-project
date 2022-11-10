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
#include <math.h>

ReadObj::ReadObj()
{
    this->FLAG = false;
}
//QList<QPoint>
void ReadObj::fileObjReader(QString filePath){
    if(!this->FLAG){
    QString line;
    QFile objFile(filePath);
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

//Implementar essa função em fileObjReader
void ReadObj::clearValues(string values[]) {
    for(unsigned long i = 0; i < values->length(); i++) {
        values[i].clear();
    }
}
