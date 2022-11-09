#include "readobj.h"
#include "point.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

ReadObj::ReadObj()
{
    this->FLAG = false;
}
//QList<QPoint>
void ReadObj::fileObjReader(char* filePath){
    if(this->FLAG == false) {
        string line;
        string v, valuesX, valuesY, valuesZ;
        string f, value1, value2, value3, value4;

        ifstream myfile(filePath);
        while(!myfile.eof()) {
            getline (myfile,line);
            std::istringstream iss( line );
            if(line[0] == 'v' && line[1] == ' ') {
                iss >> v >> valuesX >> valuesY >> valuesZ;
                this->readPoints.append(Point(std::stof(valuesX), std::stof(valuesY), std::stof(valuesZ)));
                //cout << valuesX << "\t" << valuesY << "\t" << valuesZ << endl;
            }
            if(line[0] == 'f') {
                iss >> f >> value1 >> value2 >> value3 >> value4;
                value1 = getVertexOfPlane(value1);
                value2 = getVertexOfPlane(value2);
                value3 = getVertexOfPlane(value3);
                value4 = getVertexOfPlane(value4);
                if(value4.empty()) {
                    this->readLines.append(Line(this->readPoints.at(std::stoi(value1) - 1), this->readPoints.at(std::stoi(value2) - 1)));
                    this->readLines.append(Line(this->readPoints.at(std::stoi(value2) - 1), this->readPoints.at(std::stoi(value3) - 1)));
                    this->readLines.append(Line(this->readPoints.at(std::stoi(value3) - 1), this->readPoints.at(std::stoi(value1) - 1)));
                } else {
                    this->readLines.append(Line(this->readPoints.at(std::stoi(value1) - 1), this->readPoints.at(std::stoi(value2) - 1)));
                    this->readLines.append(Line(this->readPoints.at(std::stoi(value2) - 1), this->readPoints.at(std::stoi(value3) - 1)));
                    this->readLines.append(Line(this->readPoints.at(std::stoi(value3) - 1), this->readPoints.at(std::stoi(value1) - 1)));
                    this->readLines.append(Line(this->readPoints.at(std::stoi(value4) - 1), this->readPoints.at(std::stoi(value1) - 1)));
                }
                //cout << value1 << "\t" << value2 << "\t" << value3 << "\t" << value4 << endl;
                value1.clear();
                value2.clear();
                value3.clear();
                value4.clear();
            }
        }
        std::cout << this->readPoints.length() << std::endl;
        std::cout << this->readLines.length() << std::endl;
        myfile.close();
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
