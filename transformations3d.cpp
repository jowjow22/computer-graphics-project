#include "transformations3d.h"

Transformations3d::Transformations3d()
{

}

QList<QLine> Transformations3d::getTransformations3d(ReadObj lines, int Angle, int scaleObject, int posX){
    QList<Line> aux, aux2;
    QList<QLine> QAux;
    for(Line line : lines.readLines) {
        aux.append(Line(Rotation3D(Point(line.x1, line.y1, line.z1), 40+Angle).getRotationXAroundY(),
                           Rotation3D(Point(line.x1, line.y1, line.z1), 40+Angle).getRotationYAroundY(),
                           Rotation3D(Point(line.x2, line.y2, line.z2), 40+Angle).getRotationXAroundY(),
                           Rotation3D(Point(line.x2, line.y2, line.z2), 40+Angle).getRotationYAroundY()));
    }

    for(Line line : aux) {
        aux2.append(Line(Scale3D(Point(line.x1, line.y1, line.z1), 1+scaleObject).getScaleX(),
                           Scale3D(Point(line.x1, line.y1, line.z1), 1+scaleObject).getScaleY(),
                           Scale3D(Point(line.x2, line.y2, line.z2), 1+scaleObject).getScaleX(),
                           Scale3D(Point(line.x2, line.y2, line.z2), 1+scaleObject).getScaleY()));
    }

    for(Line line : aux2) {
        QAux.append(QLine(Translation3D(Point(line.x1, line.y1, line.z1), 0-posX, 0, 0).getTranslationX(),
                           Translation3D(Point(line.x1, line.y1, line.z1), 0-posX, 0, 0).getTranslationY(),
                           Translation3D(Point(line.x2, line.y2, line.z2), 0-posX, 0, 0).getTranslationX(),
                           Translation3D(Point(line.x2, line.y2, line.z2), 0-posX, 0, 0).getTranslationY()));
    }

    return QAux;
}
