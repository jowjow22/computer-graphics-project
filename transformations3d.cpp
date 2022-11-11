#include "transformations3d.h"

Transformations3d::Transformations3d()
{

}

QList<QLine> Transformations3d::getTransformations3d(ReadObj lines, int scaleObject, int angleX, int angleY, int angleZ, int posX, int posY, int posZ){
    QList<Line> aux, aux2, aux3, aux4, aux5;
    QList<QLine> QAux;
    for(const Line &line : lines.readLines) {
        aux.append(Line(Rotation3D(Point(line.x1, line.y1, line.z1), angleX).getRotationXAroundX(),
                        Rotation3D(Point(line.x1, line.y1, line.z1), angleX).getRotationYAroundX(),
                        Rotation3D(Point(line.x1, line.y1, line.z1), angleX).getRotationZAroundX(),
                        Rotation3D(Point(line.x2, line.y2, line.z2), angleX).getRotationXAroundX(),
                        Rotation3D(Point(line.x2, line.y2, line.z2), angleX).getRotationYAroundX(),
                        Rotation3D(Point(line.x1, line.y1, line.z1), angleX).getRotationZAroundX()));
    }

    for(const Line &line : aux) {
        aux2.append(Line(Rotation3D(Point(line.x1, line.y1, line.z1), angleY).getRotationXAroundY(),
                         Rotation3D(Point(line.x1, line.y1, line.z1), angleY).getRotationYAroundY(),
                         Rotation3D(Point(line.x1, line.y1, line.z1), angleY).getRotationZAroundY(),
                         Rotation3D(Point(line.x2, line.y2, line.z2), angleY).getRotationXAroundY(),
                         Rotation3D(Point(line.x2, line.y2, line.z2), angleY).getRotationYAroundY(),
                         Rotation3D(Point(line.x1, line.y1, line.z1), angleY).getRotationZAroundY()));
    }

    for(const Line &line : aux2) {
        aux3.append(Line(Rotation3D(Point(line.x1, line.y1, line.z1), angleZ).getRotationXAroundZ(),
                         Rotation3D(Point(line.x1, line.y1, line.z1), angleZ).getRotationYAroundZ(),
                         Rotation3D(Point(line.x1, line.y1, line.z1), angleZ).getRotationZAroundZ(),
                         Rotation3D(Point(line.x2, line.y2, line.z2), angleZ).getRotationXAroundZ(),
                         Rotation3D(Point(line.x2, line.y2, line.z2), angleZ).getRotationYAroundZ(),
                         Rotation3D(Point(line.x1, line.y1, line.z1), angleZ).getRotationZAroundZ()));
    }

    for(const Line &line : aux3) {
        aux4.append(Line(Scale3D(Point(line.x1, line.y1, line.z1), 1+scaleObject).getScaleX(),
                         Scale3D(Point(line.x1, line.y1, line.z1), 1+scaleObject).getScaleY(),
                         Scale3D(Point(line.x1, line.y1, line.z1), 1+scaleObject).getScaleZ(),
                         Scale3D(Point(line.x2, line.y2, line.z2), 1+scaleObject).getScaleX(),
                         Scale3D(Point(line.x2, line.y2, line.z2), 1+scaleObject).getScaleY(),
                         Scale3D(Point(line.x1, line.y1, line.z1), 1+scaleObject).getScaleZ()));
    }

    for(const Line &line : aux4) {
        aux5.append(Line(Translation3D(Point(line.x1, line.y1, line.z1), 0-posX, 0+posY, 0-posZ).getTranslationX(),
                          Translation3D(Point(line.x1, line.y1, line.z1), 0-posX, 0+posY, 0-posZ).getTranslationY(),
                          Translation3D(Point(line.x1, line.y1, line.z1), 0-posX, 0+posY, 0-posZ).getTranslationZ(),
                          Translation3D(Point(line.x2, line.y2, line.z2), 0-posX, 0+posY, 0-posZ).getTranslationX(),
                          Translation3D(Point(line.x2, line.y2, line.z2), 0-posX, 0+posY, 0-posZ).getTranslationY(),
                          Translation3D(Point(line.x1, line.y1, line.z1), 0-posX, 0+posY, 0-posZ).getTranslationZ()));
    }

    for(const Line &line: aux5) {
        QAux.append(QLine(line.x1, line.y1, line.x2, line.y2));
    }

    return QAux;
}
