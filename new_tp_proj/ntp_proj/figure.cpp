#include "figure.h"

bool Figure::isFigure (void) const
{
    return true;
}

// Figure1

Cell* Figure1::clone (void) const
{
    return new Figure1;
}

char Figure1::charRepresentation (void) const
{
    return FIGURE1;
}

QColor Figure1::colorRepresentation (void) const
{
    return FIGURE1COLOR;
}

std::vector<Coordinates> Figure1::availableMoves (Coordinates crd, CellMatrix &matrix) const
{
    std::vector<Coordinates> available_moves = std::vector<Coordinates>();
    std::vector<Coordinates> neighbours = matrix.getLineNeighbours(crd);
    for (Coordinates &crd : neighbours)
        if (matrix.isEmpty(crd))
            if (matrix.figuresInLineNeighbours(crd) > 1)
                available_moves.push_back(crd);
    neighbours.clear();
    neighbours = matrix.getDiagonalNeighbours(crd);
    for (Coordinates &crd : neighbours)
        if (matrix.isEmpty(crd))
            if (matrix.figuresInLineNeighbours(crd) > 0)
                 available_moves.push_back(crd);
    return available_moves;
}

// Figure2

Cell* Figure2::clone (void) const
{
    return new Figure2;
}

char Figure2::charRepresentation (void) const
{
    return FIGURE2;
}

QColor Figure2::colorRepresentation (void) const
{
    return FIGURE2COLOR;
}

std::vector<Coordinates> Figure2::availableMoves (Coordinates crd, CellMatrix &matrix) const
{
    std::vector<Coordinates> available_moves = std::vector<Coordinates>();
    for (int di = -1; di < 2; ++di)
        for (int dj = -1; dj < 2; ++dj)
            if ((di != 0) || (dj != 0))
            {
                int len = matrix.checkDirection(crd, di, dj);
                if (len > 1)
                {
                    Coordinates crd = Coordinates(crd.i + di * len, crd.j + dj * len);
                    available_moves.push_back(crd);
                }
            }
    return available_moves;
}

// Figure3

Cell* Figure3::clone (void) const
{
    return new Figure3;
}

char Figure3::charRepresentation (void) const
{
    return FIGURE3;
}

QColor Figure3::colorRepresentation (void) const
{
    return FIGURE3COLOR;
}

std::vector<Coordinates> Figure3::availableMoves (Coordinates crd, CellMatrix &matrix) const
{
    std::vector<Coordinates> available_moves = std::vector<Coordinates>();
    std::vector<Coordinates> neighbours = matrix.getLineNeighbours(crd);
    for (Coordinates &crd : neighbours)
        if (matrix.isEmpty(crd))
            if (matrix.figuresInLineNeighbours(crd) > 2)
                available_moves.push_back(crd);
    neighbours.clear();
    neighbours = matrix.getDiagonalNeighbours(crd);
    for (Coordinates &crd : neighbours)
        if (matrix.isEmpty(crd))
            if (matrix.figuresInLineNeighbours(crd) > 1)
                 available_moves.push_back(crd);
    return available_moves;
}

// Figure4

Cell* Figure4::clone (void) const
{
    return new Figure4;
}

QColor Figure4::colorRepresentation (void) const
{
    return FIGURE4COLOR;
}

std::vector<Coordinates> Figure4::availableMoves (Coordinates crd, CellMatrix &matrix) const
{
    std::vector<Coordinates> available_moves = std::vector<Coordinates>();
    for (int di = -1; di < 2; ++di)
        for (int dj = -1; dj < 2; ++dj)
            if ((di != 0) || (dj != 0))
            {
                int len = matrix.checkDirection(crd, di, dj);
                if (len > 2)
                {
                    Coordinates crd = Coordinates(crd.i + di * len, crd.j + dj * len);
                    available_moves.push_back(crd);
                }
            }
    return available_moves;
}
