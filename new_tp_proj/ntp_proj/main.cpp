#include "utils.h"
#include "cell.h"
#include "playingfield.h"

int main (void)
{
    PlayingField field = PlayingField();
    field.load((char*)"field1.txt");

    while (!field.isWinning())
    {
        field.fullprint();
        Coordinates temp;
        std::cout << "press cell:" << std::endl;
        std::cin >> temp.i >> temp.j;
        if ((temp.i == -1) && (temp.j == -1))
            field.undo();
        else
            field.pressCell(temp);
    }
    field.fullprint();
    std::cout << "you win!" << std::endl;

    return 0;
}
