#include "transformations3d.h"

Transformations3d::Transformations3d()
{

}

QList<Line> Transformations3d::getTransformations3d(ReadObj lines, float scaleObject, float angleX, float angleY, float angleZ, float posX, float posY, float posZ){
    QList<Line> aux, aux2;
    QList<Line> QAux;
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
        QAux.append(Line(Translation3D(Point(line.x1, line.y1, line.z1), 0-posX, 0+posY, 0-posZ).getTranslationX(),
                          Translation3D(Point(line.x1, line.y1, line.z1), 0-posX, 0+posY, 0-posZ).getTranslationY(),
                          Translation3D(Point(line.x1, line.y1, line.z1), 0-posX, 0+posY, 0-posZ).getTranslationZ(),
                          Translation3D(Point(line.x2, line.y2, line.z2), 0-posX, 0+posY, 0-posZ).getTranslationX(),
                          Translation3D(Point(line.x2, line.y2, line.z2), 0-posX, 0+posY, 0-posZ).getTranslationY(),
                          Translation3D(Point(line.x2, line.y2, line.z2), 0-posX, 0+posY, 0-posZ).getTranslationZ()));
    }
    return QAux;
}

Line Transformations3d::getWindowTransformations3d(Line line, float scaleObject, float angleX, float angleY, float angleZ, float posX, float posY, float posZ){
    Line aux, aux2;
    Line QAux;
    aux = Line(Rotation3D(Point(line.x1, line.y1, line.z1), angleX, angleY, angleZ).getRotationX(),
               Rotation3D(Point(line.x1, line.y1, line.z1), angleX, angleY, angleZ).getRotationY(),
               Rotation3D(Point(line.x1, line.y1, line.z1), angleX, angleY, angleZ).getRotationZ(),
               Rotation3D(Point(line.x2, line.y2, line.z2), angleX, angleY, angleZ).getRotationX(),
               Rotation3D(Point(line.x2, line.y2, line.z2), angleX, angleY, angleZ).getRotationY(),
               Rotation3D(Point(line.x2, line.y2, line.z2), angleX, angleY, angleZ).getRotationZ());

    aux2 = Line(Scale3D(Point(aux.x1, aux.y1, aux.z1), 1+scaleObject).getScaleX(),
                Scale3D(Point(aux.x1, aux.y1, aux.z1), 1+scaleObject).getScaleY(),
                Scale3D(Point(aux.x1, aux.y1, aux.z1), 1+scaleObject).getScaleZ(),
                Scale3D(Point(aux.x2, aux.y2, aux.z2), 1+scaleObject).getScaleX(),
                Scale3D(Point(aux.x2, aux.y2, aux.z2), 1+scaleObject).getScaleY(),
                Scale3D(Point(aux.x2, aux.y2, aux.z2), 1+scaleObject).getScaleZ());

    QAux = Line(Translation3D(Point(aux2.x1, aux2.y1, aux2.z1), 0-posX, 0+posY, 0-posZ).getTranslationX(),
                Translation3D(Point(aux2.x1, aux2.y1, aux2.z1), 0-posX, 0+posY, 0-posZ).getTranslationY(),
                Translation3D(Point(aux2.x1, aux2.y1, aux2.z1), 0-posX, 0+posY, 0-posZ).getTranslationZ(),
                Translation3D(Point(aux2.x2, aux2.y2, aux2.z2), 0-posX, 0+posY, 0-posZ).getTranslationX(),
                Translation3D(Point(aux2.x2, aux2.y2, aux2.z2), 0-posX, 0+posY, 0-posZ).getTranslationY(),
                Translation3D(Point(aux2.x2, aux2.y2, aux2.z2), 0-posX, 0+posY, 0-posZ).getTranslationZ());

    return QAux;
}
