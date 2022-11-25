#include "transformations3d.h"

Transformations3d::Transformations3d()
{

}

QList<QLine> Transformations3d::getTransformations3d(ReadObj lines, float scaleObject, float angleX, float angleY, float angleZ, float posX, float posY, float posZ){
    QList<Line> aux, aux2, aux3;
    QList<QLine> QAux;
    for(const Line &line : lines.readLines) {
        aux.append(Line(Rotation3D(Point(line.x1, line.y1, line.z1), angleX, angleY, angleZ).getRotationX(),
                        Rotation3D(Point(line.x1, line.y1, line.z1), angleX, angleY, angleZ).getRotationY(),
                        Rotation3D(Point(line.x1, line.y1, line.z1), angleX, angleY, angleZ).getRotationZ(),
                        Rotation3D(Point(line.x2, line.y2, line.z2), angleX, angleY, angleZ).getRotationX(),
                        Rotation3D(Point(line.x2, line.y2, line.z2), angleX, angleY, angleZ).getRotationY(),
                        Rotation3D(Point(line.x2, line.y2, line.z2), angleX, angleY, angleZ).getRotationZ()));
    }

    for(const Line &line : aux) {
        aux2.append(Line(Scale3D(Point(line.x1, line.y1, line.z1), 1+scaleObject).getScaleX(),
                         Scale3D(Point(line.x1, line.y1, line.z1), 1+scaleObject).getScaleY(),
                         Scale3D(Point(line.x1, line.y1, line.z1), 1+scaleObject).getScaleZ(),
                         Scale3D(Point(line.x2, line.y2, line.z2), 1+scaleObject).getScaleX(),
                         Scale3D(Point(line.x2, line.y2, line.z2), 1+scaleObject).getScaleY(),
                         Scale3D(Point(line.x2, line.y2, line.z2), 1+scaleObject).getScaleZ()));
    }

    for(const Line &line : aux2) {
        aux3.append(Line(Translation3D(Point(line.x1, line.y1, line.z1), 0-posX, 0+posY, 0-posZ).getTranslationX(),
                          Translation3D(Point(line.x1, line.y1, line.z1), 0-posX, 0+posY, 0-posZ).getTranslationY(),
                          Translation3D(Point(line.x1, line.y1, line.z1), 0-posX, 0+posY, 0-posZ).getTranslationZ(),
                          Translation3D(Point(line.x2, line.y2, line.z2), 0-posX, 0+posY, 0-posZ).getTranslationX(),
                          Translation3D(Point(line.x2, line.y2, line.z2), 0-posX, 0+posY, 0-posZ).getTranslationY(),
                          Translation3D(Point(line.x2, line.y2, line.z2), 0-posX, 0+posY, 0-posZ).getTranslationZ()));
    }

    for(const Line &line: aux3) {
        QAux.append(QLine(line.x1, line.y1, line.x2, line.y2));
    }

    return QAux;
}
