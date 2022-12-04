#include "perspectiveprojection.h"

PerspectiveProjection::PerspectiveProjection()
{

}

Point PerspectiveProjection::newPerspectivePoints(float x, float y, float z, float distance) {
    return Point((x/(z/distance)), (y/(z/distance)), distance);
}

QList<Line> PerspectiveProjection::newListOfPerspectivePoints(QList<Line> list, float distance) {
    QList<Line> returnedList;
    for(const Line &line : list) {
        returnedList.append(Line(newPerspectivePoints(line.x1, line.y1, line.z1, distance), newPerspectivePoints(line.x2, line.y2, line.z2, distance)));
    }
    return returnedList;
}
