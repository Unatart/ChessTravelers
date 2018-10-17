#include "winningmatrix.h"

// WinningMatrix

WinningMatrix::WinningMatrix (void)
{
    allocate(0, 0);
}

WinningMatrix::WinningMatrix (int width, int height)
{
    allocate(width, height);
}

WinningMatrix::~WinningMatrix (void)
{
    free();
}

void WinningMatrix::allocate (int width, int height)
{
    _width = width;
    _height = height;
    try {
        _matrix = new bool*[height];
        for (int i = 0; i < height; ++i)
        {
            _matrix[i] = new bool[width];
            for (int j = 0; j < height; ++j)
                _matrix[i][j] = false;
        }
    } catch(std::bad_alloc& exception) {
        throw bad_alloc_exception(" in / WinningMatrix::allocate / : can't allocate memory.");
    }
}

void WinningMatrix::resize (int width, int height)
{
    free();
    allocate(width, height);
}

void WinningMatrix::free (void)
{
    for (int i = 0; i < _height; ++i)
        delete [] _matrix[i];
    delete [] _matrix;
}

bool WinningMatrix::get (Coordinates crd)
{
    return _matrix[crd.i][crd.j];
}

void WinningMatrix::set (Coordinates crd, bool b)
{
    _matrix[crd.i][crd.j] = b;
}

bool WinningMatrix::isWinning (Coordinates crd)
{
    return _matrix[crd.i][crd.j];
}
