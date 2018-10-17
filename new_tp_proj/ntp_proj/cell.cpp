#include "cell.h"
#include "figure.h"


// Cell - - - - - - - - - - - - - - - - - -

bool Cell::isEmpty (void) const
{
    return false;
}

bool Cell::isBlock (void) const
{
    return false;
}

bool Cell::isFigure (void) const
{
    return false;
}

std::vector<Coordinates> Cell::availableMoves (Coordinates crd, CellMatrix &matrix) const
{
    return std::vector<Coordinates>();
}

// EmptyCell - - - - - - - - - - - - - - - - - -

Cell* EmptyCell::clone (void) const
{
    return new EmptyCell;
}

bool EmptyCell::isEmpty (void) const
{
    return true;
}

char EmptyCell::charRepresentation (void) const
{
    return EMPTY;
}

QColor EmptyCell::colorRepresentation (void) const
{
    return EMPTYCOLOR;
}

// Block - - - - - - - - - - - - - - - - - - - -

Cell* Block::clone (void) const
{
    return new Block;
}

bool Block::isBlock (void) const
{
    return true;
}

char Block::charRepresentation (void) const
{
    return BLOCK;
}

QColor Block::colorRepresentation (void) const
{
    return BLOCKCOLOR;
}

Cell* CellFromChar (char chr)
{
    switch (chr)
    {
    case EMPTY:
        return new EmptyCell;
    case BLOCK:
        return new Block;
    case FIGURE1:
        return new Figure1;
    case FIGURE2:
        return new Figure2;
    case FIGURE3:
        return new Figure3;
    case FIGURE4:
        return new Figure4;
    }


}
