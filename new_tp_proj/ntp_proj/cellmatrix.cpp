#include "cellmatrix.h"

// CellMatrix

CellMatrix::CellMatrix (void)
{
    allocate(0, 0);
}

CellMatrix::CellMatrix (int width, int height)
{
    allocate(width, height);
}

CellMatrix::~CellMatrix (void)
{
    free();
}

void CellMatrix::allocate (int width, int height)
{
    _width = width;
    _height = height;
    try {
        _matrix = new Cell**[height];
        for (int i = 0; i < height; ++i)
        {
            _matrix[i] = new Cell*[width];
            for (int j = 0; j < height; ++j)
                _matrix[i][j] = nullptr;
        }
    } catch(std::bad_alloc& exception) {
        throw bad_alloc_exception(" in / CellMatrix::allocate / : can't allocate memory.");
    }
}

void CellMatrix::resize (int width, int height)
{
    free();
    allocate(width, height);
}

void CellMatrix::free (void)
{
    for (int i = 0; i < _height; ++i)
    {
        for (int j = 0; j < _width; ++j)
            delete _matrix[i][j];
        delete [] _matrix[i];
    }
    delete [] _matrix;
}

Cell* CellMatrix::get (Coordinates crd)
{
    return _matrix[crd.i][crd.j];
}

void CellMatrix::set (Coordinates crd, Cell* cell)
{

    delete _matrix[crd.i][crd.j];
    _matrix[crd.i][crd.j] = cell->clone();
}

void CellMatrix::set (Coordinates crd, char chr)
{
    if (_matrix[crd.i][crd.j] != nullptr)
    {
        delete _matrix[crd.i][crd.j];
    }
    _matrix[crd.i][crd.j] = CellFromChar(chr);
}

bool CellMatrix::isValid (Coordinates crd)
{
    return (crd.i >= 0) && (crd.i < _height) && (crd.j >= 0) && (crd.j < _width);
}

bool CellMatrix::isEmpty (Coordinates crd)
{
    return _matrix[crd.i][crd.j]->isEmpty();
}

bool CellMatrix::isBlock (Coordinates crd)
{
    return _matrix[crd.i][crd.j]->isBlock();
}

bool CellMatrix::isFigure (Coordinates crd)
{
    return _matrix[crd.i][crd.j]->isFigure();
}

std::vector<Coordinates> CellMatrix::getLineNeighbours (Coordinates crd)
{
    std::vector<Coordinates> neighbours;
    for (int di = -1; di < 2; ++di)
        for (int dj = -1; dj < 2; ++dj)
            if (abs(di + dj) == 1)
            {
                Coordinates temp = Coordinates(crd.i + di, crd.j + dj);
                if (isValid(temp))
                    neighbours.push_back(temp);
            }
    return neighbours;
}

std::vector<Coordinates> CellMatrix::getDiagonalNeighbours (Coordinates crd)
{
    std::vector<Coordinates> neighbours;
    for (int di = -1; di < 2; di += 2)
        for (int dj = -1; dj < 2; dj += 2)
        {
            Coordinates temp = Coordinates(crd.i + di, crd.j + dj);
            if (isValid(temp))
                neighbours.push_back(temp);
        }
    return neighbours;
}

int CellMatrix::figuresInLineNeighbours (Coordinates crd)
{
    std::vector<Coordinates> neighbours = getLineNeighbours(crd);
    int count = 0;
    for (Coordinates &temp : neighbours)
        if (isFigure(temp))
            ++count;
    return count;
}

int CellMatrix::checkDirection (Coordinates crd, int di, int dj)
{
    int len = 0;
    while (true)
    {
        ++len;
        crd.i += di;
        crd.j += dj;
        if (!isValid(crd))
            return 0;
        if (isBlock(crd))
            return 0;
        if (isEmpty(crd))
            return len;
    }
    return 0;
}
