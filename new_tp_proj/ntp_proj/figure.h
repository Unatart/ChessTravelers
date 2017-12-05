#ifndef FIGURE_H
#define FIGURE_H

#include "utils.h"
#include "cell.h"

class Figure : public Cell
{
public:
    virtual bool isFigure (void) const override;
};

class Figure1 : public Figure
{
public:
    virtual Cell* clone (void) const override;
    virtual char charRepresentation (void) const override;
    virtual QColor colorRepresentation (void) const override;
    virtual std::vector<Coordinates> availableMoves (Coordinates crd, CellMatrix &matrix) const override;
};

class Figure2 : public Figure
{
public:
    virtual Cell* clone (void) const override;
    virtual char charRepresentation (void) const override;
    virtual QColor colorRepresentation (void) const override;
    virtual std::vector<Coordinates> availableMoves (Coordinates crd, CellMatrix &matrix) const override;
};

class Figure3 : public Figure
{
public:
    virtual Cell* clone (void) const override;
    virtual char charRepresentation (void) const override;
    virtual QColor colorRepresentation (void) const override;
    virtual std::vector<Coordinates> availableMoves (Coordinates crd, CellMatrix &matrix) const override;
};

class Figure4 : public Figure
{
public:
    virtual Cell* clone (void) const override;
    virtual char charRepresentation (void) const override;
    virtual QColor colorRepresentation (void) const override;
    virtual std::vector<Coordinates> availableMoves (Coordinates crd, CellMatrix &matrix) const override;
};

#endif // FIGURE_H
