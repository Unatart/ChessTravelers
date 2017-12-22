#include "lvl_file_manager.h"

int main() {
    std::string path = "/home/neontears/test"; // надо добавить в общий конфиг

    // просто пример работы
    lvl_file_manager fm;
    fm.load_from_path(path);

    lvl_file f = fm.get_file(0);

    f.show_fullpath();
    return 0;
}
