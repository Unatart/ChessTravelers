#ifndef PLAYINGFIELD_H
#define PLAYINGFIELD_H

#include "utils.h"
#include "field.h"

class PlayingField : public Field
{
public :
    PlayingField (void);
    PlayingField (int width, int height);

    virtual void load (char *filename);
    virtual void fullprint (void);

    Coordinates selectedCell (void);
    std::vector<Coordinates> availableMoves (void);
    int movesDone (void);

    void pressCell (Coordinates crd);
    void undo (void);

protected :
    Coordinates _selected_cell;
    std::vector<Coordinates> _available_moves;
    std::vector<Move> _stack;

    bool _isSelected (void);
    void _trySelect (Coordinates crd);
    void _select (Coordinates crd);
    void _deselect (void);

    void _tryMove (Coordinates crd);
    void _move (Coordinates from, Coordinates to);
    void _storeMove (Coordinates from, Coordinates to);
    void _undo (void);

    void _findAvailableMoves (void);
};

#endif // PLAYINGFIELD_H
