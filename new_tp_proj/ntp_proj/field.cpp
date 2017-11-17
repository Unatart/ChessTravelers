#include "field.h"

// Field

Field::Field (void)
{
    _allocate(0, 0);
}

Field::Field (int width, int height)
{
    _allocate(width, height);
}

Field::~Field (void)
{
    _free();
}

int Field::width (void)
{
    return _width;
}

int Field::height (void)
{
    return _height;
}

Cell* Field::get (Coordinates crd)
{
    return _cell_matrix.get(crd);
}

void Field::set (Coordinates crd, Cell* cell)
{
    _cell_matrix.set(crd, cell);
}

std::vector<Coordinates> Field::winningPosition (void)
{
    std::vector<Coordinates> winning_position;
    for (int i = 0; i < _height; ++i)
        for (int j = 0; j < _width; ++j)
        {
            Coordinates crd = Coordinates(i, j);
            if (_winning_matrix.isWinning(crd))
                winning_position.push_back(crd);
        }
}

bool Field::isWinning (void)
{
    for (int i = 0; i < _height; ++i)
        for (int j = 0; j < _width; ++j)
        {
            Coordinates crd = Coordinates(i, j);
            if (_cell_matrix.isFigure(crd))
                if (!_winning_matrix.isWinning(crd))
                    return false;
        }
    return true;
}

void Field::load (char* filename)
{
    FILE *f = fopen(filename, "r");

    int width, height;
    fscanf(f, "%d %d", &width, &height);
    _resize(width, height);

    char c;
    for (int i = 0; i < 2; ++i)
        fscanf(f, "%c", &c); // two \n before matrix

    for (int i = 0; i < _height; ++i)
    {
        for (int j = 0; j < _width; ++j)
        {
            fscanf(f, "%c", &c);
            _cell_matrix.set(Coordinates(i, j), c);
        }
        fscanf(f, "%c", &c); // one \n after matrix row
    }

    int i, j;
    while (!feof(f))
    {
        fscanf(f, "%d %d", &i, &j);
        _winning_matrix.set(Coordinates(i, j), true);
    }

    fclose(f);
}

void Field::fullprint (void)
{
    std::cout << "width " << _width << " height " << _height << std::endl;
    std::cout << "matrix" << std::endl;
    for (int i = 0; i < _height; ++i)
    {
        for (int j = 0; j < _width; ++j)
            std::cout << _cell_matrix.get(Coordinates(i, j))->charRepresentation();
        std::cout << std::endl;
    }
}

void Field::smallprint (void)
{
    for (int i = 0; i < _height; ++i)
    {
        for (int j = 0; j < _width; ++j)
            std::cout << _cell_matrix.get(Coordinates(i, j))->charRepresentation();
        std::cout << std::endl;
    }
}

void Field::_allocate (int width, int height)
{
    _cell_matrix.allocate(width, height);
    _winning_matrix.allocate(width, height);
    _width = width;
    _height = height;
}

void Field::_free (void)
{
    _winning_matrix.free();
    _cell_matrix.free();
}

void Field::_resize (int width, int height)
{
    _free();
    _allocate(width, height);
}
