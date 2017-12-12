#include "pointconverter.h"

QPoint ConvertToQPoint(Coordinates coord) {
    return QPoint(coord.i, coord.j);
}

Coordinates ConvertToCoordinates(QPoint point) {
    return Coordinates(point.x(), point.y());
}
