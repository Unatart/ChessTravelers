#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// It's just a struct with public fields i, j
class CellCoordinates
{
public:

    int i;
    int j;

    CellCoordinates (void) :
        i(-1),
        j(-1)
    {

    }

    CellCoordinates (int _i, int _j) :
        i(_i),
        j(_j)
    {

    }

    CellCoordinates (const CellCoordinates &other) :
        i(other.i),
        j(other.j)
    {

    }
};

typedef struct
{
    CellCoordinates from;
    CellCoordinates to;
}
Move;

typedef char CellType;

#define EMPTY '#'   // gray
#define BLOCK '0'   // black
#define ONE '1'     // green
#define TWO '2'     // blue
#define THREE '3'   // yellow
#define FOUR '4'    // red

class Field
{
public:

    // ------ constructors, destructors ------- //

    Field (void)
    {
        _allocate(0, 0);
    }

    Field (int width, int height)
    {
        _allocate(width, height);
    }

    ~Field (void)
    {
        _free();
    }

    // ----------- getters, setters, info ---------- //

    CellType type (CellCoordinates cc)
    {
        return _matrix[cc.i][cc.j];
    }

    void set (CellCoordinates cc, CellType ct)
    {
        _matrix[cc.i][cc.j] = ct;
    }

    vector<CellCoordinates> winningPosition (void)
    {
        vector<CellCoordinates> winning_position;
        for (int i = 0; i < _height; ++i)
            for (int j = 0; j < _width; ++j)
                if (_winning_position[i][j])
                    winning_position.push_back(CellCoordinates(i, j));
    }

    bool isWinning (void)
    {
        for (int i = 0; i < _height; ++i)
            for (int j = 0; j < _width; ++j)
                if (_isFigure(CellCoordinates(i, j)))
                    if (!_winning_position[i][j])
                        return false;
        return true;
    }

    // ----------- input, output ------------ //

    // TODO: save

    // TODO: work with file with C++ functions, not with C FILE, fopen, fclose, fscanf
    virtual void load (char* filename)
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
                fscanf(f, "%c", &_matrix[i][j]);
            fscanf(f, "%c", &c); // one \n after matrix row
        }

        int i, j;
        while (!feof(f))
        {
            fscanf(f, "%d %d", &i, &j);
            _winning_position[i][j] = true;
        }

        fclose(f);
    }

    virtual void fullprint (void)
    {
        //cout << "width " << _width << " height " << _height << endl;
        //cout << "matrix" << endl;
        for (int i = 0; i < _height; ++i)
        {
            for (int j = 0; j < _width; ++j)
                cout << _matrix[i][j];
            cout << endl;
        }
        /*
        cout << "winning position" << endl;
        for (int i = 0; i < _height; ++i)
        {
            for (int j = 0; j < _width; ++j)
                cout << _winning_position[i][j];
            cout << endl;
        }
        */
    }

    void smallprint (void)
    {
        for (int i = 0; i < _height; ++i)
        {
            for (int j = 0; j < _width; ++j)
                cout << _matrix[i][j];
            cout << endl;
        }
    }

protected :

    int _width;
    int _height;
    CellType** _matrix;
    bool** _winning_position;

    // ----------------------- allocation ------------------ //

    virtual void _allocate (int width, int height)
    {
        _width = width;
        _height = height;
        _matrix = new CellType*[height];
        _winning_position = new bool*[height];
        for (int i = 0; i < height; ++i)
        {
            _matrix[i] = new CellType[width];
            _winning_position[i] = new bool[width];
            for (int j = 0; j < width; ++j)
            {
                _matrix[i][j] = EMPTY;
                _winning_position[i][j] = false;
            }
        }
    }

    virtual void _free (void)
    {
        for (int i = 0; i < _height; ++i)
        {
            delete [] _matrix[i];
            delete [] _winning_position[i];
        }
        delete [] _matrix;
        delete [] _winning_position;
    }

    virtual void _resize (int width, int height)
    {
        _free();
        _allocate(width, height);
    }

    // ------------------------- not public getters -------------------------------- //

    bool _isValid (CellCoordinates cc)
    {
        return (cc.i >= 0) && (cc.i < _height) && (cc.j >= 0) && (cc.j < _width);
    }

    bool _isBlock (CellCoordinates cc)
    {
        return _matrix[cc.i][cc.j] == BLOCK;
    }

    bool _isEmpty (CellCoordinates cc)
    {
        return _matrix[cc.i][cc.j] == EMPTY;
    }

    bool _isFigure (CellCoordinates cc)
    {
        return (_matrix[cc.i][cc.j] != EMPTY) && (_matrix[cc.i][cc.j] != BLOCK);
    }

};

class PlayingField : public Field
{
public :

    PlayingField (void) : Field()
    {
        _deselect();
    }

    PlayingField (int width, int height) : Field(width, height)
    {
        _deselect();
    }

    CellCoordinates selectedCell (void)
    {
        return _selected_cell;
    }

    vector<CellCoordinates> availableMoves (void)
    {
        return _available_moves;
    }

    int movesDone (void)
    {
        return _stack.capacity();
    }

    void pressCell (CellCoordinates cc)
    {
        if (_isValid(cc))
        {
            if (_isSelected())
            {
                _tryMove(cc);
                _deselect();
            }
            else
                _trySelect(cc);
        }
    }

    virtual void load (char *filename)
    {
        Field::load(filename);
        _deselect();
    }

    virtual void fullprint (void)
    {
        Field::fullprint();
        cout << "selected cell: " << _selected_cell.i << ' ' << _selected_cell.j << endl;
        //cout << "moves done: " << _stack.capacity() << endl;
        cout << "available moves:" << endl;
        vector<CellCoordinates> available_moves = availableMoves();
        for (CellCoordinates &temp : available_moves)
        {
            cout << temp.i << ' ' << temp.j << endl;
        }
    }

    void undo (void)
    {
        if (!_stack.empty())
        {
            _undo();
        }
    }

protected :

    CellCoordinates _selected_cell;
    vector<CellCoordinates> _available_moves;
    vector<Move> _stack;

    // ------------- select ----------------- //

    bool _isSelected (void)
    {
        return _selected_cell.i != -1;
    }

    void _trySelect (CellCoordinates cc)
    {
        if (_isFigure(cc))
            _select(cc);
    }

    void _select (CellCoordinates cc)
    {
        _selected_cell = CellCoordinates(cc);
        _findAvailableMoves();
    }

    void _deselect (void)
    {
        _selected_cell = CellCoordinates();
        _available_moves.clear();
    }

    // ------------------- move, undo ---------------------- //

    void _tryMove (CellCoordinates cc)
    {
        for (CellCoordinates &temp : _available_moves)
        {
            if ((temp.i == cc.i) && (temp.j == cc.j))
            {
                _move(_selected_cell, cc);
                _storeMove(_selected_cell, cc);
                break;
            }
        }
    }

    void _move (CellCoordinates from, CellCoordinates to)
    {
        set(to, type(from));
        set(from, EMPTY);
    }

    void _storeMove (CellCoordinates from, CellCoordinates to)
    {
        Move move;
        move.from = from;
        move.to = to;
        _stack.push_back(move);
    }

    void _undo (void)
    {
        Move move = _stack.back();
        _stack.pop_back();
        _move(move.to, move.from);
    }

    // ------------------------ available moves ------------------------ //

    void _findAvailableMoves (void)
    {
        switch (type(_selected_cell))
        {
        case ONE :
            _findAvailableMovesONE();
            break;
        case TWO:
            _findAvailableMovesTWO();
            break;
        case THREE:
            _findAvailableMovesTHREE();
            break;
        case FOUR:
            _findAvailableMovesFOUR();
            break;
        }
    }

    void _findAvailableMovesONE (void)
    {
        vector<CellCoordinates> neighbours = _getLineNeighbours(_selected_cell);
        for (CellCoordinates &cc : neighbours)
            if (_isEmpty(cc))
                if (_figuresInLineNeighbours(cc) > 1)
                    _available_moves.push_back(cc);
        neighbours.clear();
        neighbours = _getDiagonalNeighbours(_selected_cell);
        for (CellCoordinates &cc : neighbours)
            if (_isEmpty(cc))
                if (_figuresInLineNeighbours(cc) > 0)
                     _available_moves.push_back(cc);
    }

    void _findAvailableMovesTWO (void)
    {
        for (int di = -1; di < 2; ++di)
            for (int dj = -1; dj < 2; ++dj)
                if ((di != 0) || (dj != 0))
                {
                    int len = _checkDirection(di, dj);
                    if (len > 1)
                    {
                        cout << _selected_cell.i << ' ' << _selected_cell.j << ' ' << di << ' ' << dj << ' ' << len;
                        CellCoordinates cc = CellCoordinates(_selected_cell.i + di * len, _selected_cell.j + dj * len);
                        _available_moves.push_back(cc);
                    }
                }
    }

    void _findAvailableMovesTHREE (void)
    {
        vector<CellCoordinates> neighbours = _getLineNeighbours(_selected_cell);
        for (CellCoordinates &cc : neighbours)
            if (_isEmpty(cc))
                if (_figuresInLineNeighbours(cc) > 2)
                    _available_moves.push_back(cc);
        neighbours.clear();
        neighbours = _getDiagonalNeighbours(_selected_cell);
        for (CellCoordinates &cc : neighbours)
            if (_isEmpty(cc))
                if (_figuresInLineNeighbours(cc) > 1)
                     _available_moves.push_back(cc);
    }

    void _findAvailableMovesFOUR (void)
    {
        for (int di = -1; di < 2; ++di)
            for (int dj = -1; dj < 2; ++dj)
                if ((di != 0) || (dj != 0))
                {
                    int len = _checkDirection(di, dj);
                    if (len > 2)
                    {
                        CellCoordinates cc = CellCoordinates(_selected_cell.i + di * len, _selected_cell.j + dj * len);
                        _available_moves.push_back(cc);
                    }
                }
    }

    int _checkDirection (int di, int dj)
    {
        int len = 0;
        CellCoordinates cc = CellCoordinates(_selected_cell);
        while (true)
        {
            ++len;
            cc.i += di;
            cc.j += dj;
            if (!_isValid(cc))
                return 0;
            if (_isBlock(cc))
                return 0;
            if (_isEmpty(cc))
                return len;
        }
        return 0;
    }

    vector<CellCoordinates> _getLineNeighbours (CellCoordinates cc)
    {
        vector<CellCoordinates> neighbours;
        for (int di = -1; di < 2; ++di)
            for (int dj = -1; dj < 2; ++dj)
                if (abs(di + dj) == 1)
                {
                    CellCoordinates temp;
                    temp.i = cc.i + di;
                    temp.j = cc.j + dj;
                    if (_isValid(temp))
                        neighbours.push_back(temp);
                }
        return neighbours;
    }

    vector<CellCoordinates> _getDiagonalNeighbours (CellCoordinates cc)
    {
        vector<CellCoordinates> neighbours;
        for (int di = -1; di < 2; di += 2)
            for (int dj = -1; dj < 2; dj += 2)
            {
                CellCoordinates temp;
                temp.i = cc.i + di;
                temp.j = cc.j + dj;
                if (_isValid(temp))
                    neighbours.push_back(temp);
            }
        return neighbours;
    }

    int _figuresInLineNeighbours (CellCoordinates cc)
    {
        vector<CellCoordinates> neighbours = _getLineNeighbours(cc);
        int count = 0;
        for (CellCoordinates &temp : neighbours)
            if (_isFigure(temp))
                ++count;
        return count;
    }
};

int main (void)
{
    PlayingField field = PlayingField();
    field.load((char*)"field1.txt");
    while (!field.isWinning())
    {
        field.fullprint();
        CellCoordinates temp;
        cin >> temp.i >> temp.j;
        field.pressCell(temp);
    }
    field.fullprint();
    cout << "you win!" << endl;
    return 0;
}
