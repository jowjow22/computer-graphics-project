#include "readobj.h"

ReadObj::ReadObj()
{

}
//QList<QPoint>
void ReadObj::fileObjReader(char* filePath){

    fstream File;
    QList<QPoint> PointsRead;
    File.open(filePath, ios::in);
    if (!File){
        cout<<"Error while opening file";
    }
    else{
        cout<<"File found sucessfully";
    }

    char a;
    do{
        File >> a;
        cout << a;
    }while(a != 'v');

    float x, y, z;

    File >> x;
    File >> y;
    File >> z;

    File.close();
}
