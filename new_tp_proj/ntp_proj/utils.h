#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <iostream>
#include <vector>

// defines

#define EMPTY       '#'
#define BLOCK       '0'
#define FIGURE1     '1'
#define FIGURE2     '2'
#define FIGURE3     '3'
#define FIGURE4     '4'


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
