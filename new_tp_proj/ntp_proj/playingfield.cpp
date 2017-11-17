#include "playingfield.h"

// PlayingField

PlayingField::PlayingField (void) : Field()
{
    _deselect();
}

PlayingField::PlayingField (int width, int height) : Field(width, height)
{
    _deselect();
}

Coordinates PlayingField::selectedCell (void)
{
    return _selected_cell;
}

std::vector<Coordinates> PlayingField::availableMoves (void)
{
    return _available_moves;
}

int PlayingField::movesDone (void)
{
    return _stack.capacity();
}

void PlayingField::pressCell (Coordinates crd)
{
    if (_cell_matrix.isValid(crd))
    {
        if (_isSelected())
        {
            _tryMove(crd);
            _deselect();
        }
        else
            _trySelect(crd);
    }
}

void PlayingField::load (std::string filename)
{
    Field::load(filename);
    _deselect();
}

void PlayingField::fullprint (void)
{
    Field::fullprint();
    std::cout << "selected cell: " << _selected_cell.i << ' ' << _selected_cell.j << std::endl;
    std::cout << "available moves:" << std::endl;
    std::vector<Coordinates> available_moves = availableMoves();
    for (Coordinates &temp : available_moves)
    {
        std::cout << temp.i << ' ' << temp.j << std::endl;
    }
}

void PlayingField::undo (void)
{
    if (!_stack.empty())
    {
        _undo();
    }
}

bool PlayingField::_isSelected (void)
{
    return _selected_cell.isValid();
}

void PlayingField::_trySelect (Coordinates crd)
{
    if (_cell_matrix.isFigure(crd))
        _select(crd);
}

void PlayingField::_select (Coordinates crd)
{
    _selected_cell = Coordinates(crd);
    _findAvailableMoves();
}

void PlayingField::_deselect (void)
{
    _selected_cell = Coordinates();
    _available_moves.clear();
}

void PlayingField::_tryMove (Coordinates crd)
{
    for (Coordinates &temp : _available_moves)
    {
        if ((temp.i == crd.i) && (temp.j == crd.j))
        {
            _move(_selected_cell, crd);
            _storeMove(_selected_cell, crd);
            break;
        }
    }
}

void PlayingField::_move (Coordinates from, Coordinates to)
{
    set(to, get(from));
    try {
        Cell* temp = new EmptyCell;
    } catch(std::bad_alloc& exception) {
        throw bad_alloc_exception(" in / PlayingField::_move / : can't allocate memory.");
    }
    set(from, temp);
    delete temp;
}

void PlayingField::_storeMove (Coordinates from, Coordinates to)
{
    Move move;
    move.from = from;
    move.to = to;
    _stack.push_back(move);
}

void PlayingField::_undo (void)
{
    Move move = _stack.back();
    _stack.pop_back();
    _move(move.to, move.from);
}

void PlayingField::_findAvailableMoves (void)
{
    _available_moves = get(_selected_cell)->availableMoves(_selected_cell, _cell_matrix);
}
