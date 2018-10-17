#ifndef FILE_H
#define FILE_H

#include <string>
#include <iostream>
#include "exceptions.h"

class file {
public:
    virtual void set_filename(std::string& init_filename) = 0;
    virtual void set_extension(std::string& init_extension) = 0;
    virtual void set_fullpath(std::string& init_fullpath) = 0;

    virtual std::string get_filename() const = 0;
    virtual std::string get_extensions() const = 0;
    virtual std::string get_fullpath() const = 0;

    virtual void show_filename() const = 0;
    virtual void show_extensions() const = 0;
    virtual void show_fullpath() const = 0;
};

#endif // FILE_H
