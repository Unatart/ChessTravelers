#ifndef UTILS_H
#define UTILS_H

#include <Qt>
#include <QColor>

#include <stdio.h>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <vector>
#include <string>

#include "exceptions.h"

#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>

// defines

#define EMPTY       '#'
#define BLOCK       '0'
#define FIGURE1     '1'
#define FIGURE2     '2'
#define FIGURE3     '3'
#define FIGURE4     '4'

#define EMPTYCOLOR              Qt::white
#define BLOCKCOLOR              Qt::black
#define FIGURE1COLOR            Qt::green
#define FIGURE2COLOR            Qt::blue
#define FIGURE3COLOR            Qt::yellow
#define FIGURE4COLOR            Qt::red
#define SELECTEDCOLOR           Qt::magenta
#define AVAILABLEMOVESCOLOR     Qt::cyan

class Coordinates;
class Move;
class Cell;
class CellMatrix;
class WinningMatrix;
class Field;

class Coordinates
{
public:
    int i;
    int j;

    Coordinates (void);
    Coordinates (int _i, int _j);
    Coordinates (const Coordinates &other);

    bool isValid (void);
};

class Move
{
public:
    Coordinates from;
    Coordinates to;
};


#endif // UTILS_H
