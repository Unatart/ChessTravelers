#ifndef CELLMATRIX_H
#define CELLMATRIX_H

#include "utils.h"
#include "cell.h"

class Cell;

class CellMatrix
{
public:
    CellMatrix (void);
    CellMatrix (int width, int height);
    ~CellMatrix (void);

    void allocate (int width, int height);
    void resize (int width, int height);
    void free (void);

    Cell* get (Coordinates crd);
    void set (Coordinates crd, Cell* cell);
    void set (Coordinates crd, char chr);

    bool isValid (Coordinates crd);
    bool isEmpty (Coordinates crd);
    bool isBlock (Coordinates crd);
    bool isFigure (Coordinates crd);

    std::vector<Coordinates> getLineNeighbours (Coordinates crd);
    std::vector<Coordinates> getDiagonalNeighbours (Coordinates crd);
    int figuresInLineNeighbours (Coordinates crd);
    int checkDirection (Coordinates crd, int di, int dj);

private:
    int _width;
    int _height;
    Cell*** _matrix;
};

#endif // CELLMATRIX_H
