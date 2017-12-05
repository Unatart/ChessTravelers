#ifndef CELL_H
#define CELL_H

#include "utils.h"
#include "cellmatrix.h"

class CellMatrix;

// Cells

class Cell {
public:
    virtual Cell* clone (void) const = 0;
    virtual bool isEmpty (void) const;
    virtual bool isBlock (void) const;
    virtual bool isFigure (void) const;
    virtual char charRepresentation (void) const = 0;
    virtual QColor colorRepresentation (void) const = 0;
    virtual std::vector<Coordinates> availableMoves (Coordinates crd, CellMatrix &matrix) const;

};

class EmptyCell : public Cell {
public:
    virtual Cell* clone (void) const override;
    virtual bool isEmpty (void) const override;
    virtual char charRepresentation (void) const override;
    virtual QColor colorRepresentation (void) const override;
};

class Block : public Cell {
public:
    virtual Cell* clone (void) const override;
    virtual bool isBlock (void) const override;
    virtual char charRepresentation (void) const override;
    virtual QColor colorRepresentation (void) const override;
};

Cell* CellFromChar (char chr);

#endif // CELL_H
