#include "perspectiveprojection.h"

PerspectiveProjection::PerspectiveProjection()
{

}

QPoint PerspectiveProjection::newPerspectivePoints(float x, float y, float z, float distance) {
    return QPoint((x/(z/distance)), (y/(z/distance)));
}

QList<QLine> PerspectiveProjection::newListOfPerspectivePoints(QList<Line> list, float distance) {
    QList<QLine> returnedList;
    for(const Line &line : list) {
        returnedList.append(QLine(newPerspectivePoints(line.x1, line.y1, line.z1, distance), newPerspectivePoints(line.x2, line.y2, line.z2, distance)));
    }
    return returnedList;
}
