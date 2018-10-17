#ifndef WINNINGMATRIX_H
#define WINNINGMATRIX_H

#include "utils.h"

class WinningMatrix
{
public:
    WinningMatrix (void);
    WinningMatrix (int width, int height);
    ~WinningMatrix (void);

    void allocate (int width, int height);
    void resize (int width, int height);
    void free (void);

    bool get (Coordinates crd);
    void set (Coordinates crd, bool b);

    bool isWinning (Coordinates crd);

private:
    int _width;
    int _height;
    bool** _matrix;
};


#endif // WINNINGMATRIX_H
