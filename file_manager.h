#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <list>
#include <string>
#include "lvl_file.h"

class file_manager {
public:
    virtual void load_from_path(std::string path) = 0;
};

#endif // FILE_MANAGER_H
