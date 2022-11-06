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

        ifstream myfile(filePath);
        while(!myfile.eof()) {
            getline (myfile,line);
            std::istringstream iss( line );
            if(line[0] == 'v' && line[1] == ' ') {
                iss >> v >> valuesX>> valuesY>> valuesZ;
                this->readPoints.append(Point(std::stof(valuesX), std::stof(valuesY), std::stof(valuesZ)));
                cout << valuesX << "\t" << valuesY << "\t" << valuesZ << endl;
            }
        }

        myfile.close();
        this->FLAG = true;
    }
}
