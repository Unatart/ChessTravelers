int main (void)
{
    PlayingField field = PlayingField();
    std::string path = "/home/neontears/test";
    FileManager manager;
    manager.CreateFileManager(path);
    field.load(manager, "test.txt");

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

void Field::load (FileManager& manager, std::string& file_name)
{
    File f = manager.getFile(file_name);
    std::ifstream file(f.Get_full_path(), std::ios::in);

    int width, height;
    if (file.is_open()) {
        file >> width;
        file >> height;
    } else {
        throw common_exception(" in / Field::load / : can't open file.");
    }
    _resize(width, height);

    char c;
    for (int i = 0; i < 2; ++i) {
        file >> c; // two \n before matrix
    }

    for (int i = 0; i < _height; ++i)
    {
        for (int j = 0; j < _width; ++j)
        {
            file >> c;
            _cell_matrix.set(Coordinates(i, j), c);
        }
        file >> c; // one \n after matrix row
    }

    int i, j;
    while (!file.eof())
    {
        file >> i >> j;
        _winning_matrix.set(Coordinates(i,j), true);
    }

    file.close();
}