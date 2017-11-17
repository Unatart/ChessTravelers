#include "utils.h"

Coordinates::Coordinates (void)
{
    i = -1;
    j = -1;
}

Coordinates::Coordinates (int _i, int _j)
{
    i = _i;
    j = _j;
}

Coordinates::Coordinates (const Coordinates &other)
{
    i = other.i;
    j = other.j;
}

bool Coordinates::isValid (void)
{
    return (i != -1) && (j != -1);
}
