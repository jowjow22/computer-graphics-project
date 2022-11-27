#ifndef TRANSFORMATIONS3D_H
#define TRANSFORMATIONS3D_H
#include "translation3d.h"
#include "rotation3d.h"
#include "scale3d.h"
#include "line.h"
#include "perspectiveprojection.h"
#include "point.h"
#include "readobj.h"


class Transformations3d
{
public:
    Transformations3d();
    static QList<Line> getTransformations3d(ReadObj lines, float scaleObject, float angleX, float angleY, float angleZ, float posX, float posY, float posZ);
};

#endif // TRANSFORMATIONS3D_H
