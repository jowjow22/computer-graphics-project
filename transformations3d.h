#ifndef TRANSFORMATIONS3D_H
#define TRANSFORMATIONS3D_H
#include "translation3d.h"
#include "rotation3d.h"
#include "scale3d.h"
#include "line.h"
#include "point.h"
#include "readobj.h"


class Transformations3d
{
public:
    Transformations3d();
    static QList<QLine> getTransformations3d(ReadObj lines, int Angle, int scaleObject, int posX);
};

#endif // TRANSFORMATIONS3D_H
