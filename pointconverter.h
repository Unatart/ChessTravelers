#ifndef POINTCONVERTER_H
#define POINTCONVERTER_H

#include <QPoint>
#include "utils.h"

QPoint ConvertToQPoint(Coordinates coord);
Coordinates ConvertToCoordinates(QPoint point);

#endif // POINTCONVERTER_H
