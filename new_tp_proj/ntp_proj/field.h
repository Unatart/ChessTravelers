#ifndef FIELD_H
#define FIELD_H

#include "utils.h"
#include "cell.h"
#include "winningmatrix.h"

class WinningMatrix;

class Field
{
public:
    Field (void);
    Field (int width, int height);
    ~Field (void);

    int width (void);
    int height (void);

    std::vector<Coordinates> winningPosition (void);
    bool isWinning (void);

    Cell* get (Coordinates crd);
    void set (Coordinates crd, Cell* cell);

    virtual void load (char* filename);
    virtual void fullprint (void);
    void smallprint (void);

protected :
    int _width;
    int _height;
    CellMatrix _cell_matrix;
    WinningMatrix _winning_matrix;

    void _allocate (int width, int height);
    void _free (void);
    void _resize (int width, int height);
};

#endif // FIELD_H
