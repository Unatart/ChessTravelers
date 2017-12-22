#ifndef LVL_FILE_H
#define LVL_FILE_H

#include <experimental/filesystem>
#include "file.h"

namespace fs = std::experimental::filesystem::v1;

class file;

class lvl_file : public file {
public:
    lvl_file() = default;
    lvl_file(const std::string& init_fullpath);
    ~lvl_file() = default;

    lvl_file(const lvl_file& other);
    lvl_file& operator= (const lvl_file& other);

    void set_filename(std::string& init_filename);
    void set_extension(std::string& init_extension);
    void set_fullpath(std::string& init_fullpath);

    std::string get_filename() const;
    std::string get_extensions() const;
    std::string get_fullpath() const;

    void show_filename() const;
    void show_extensions() const;
    void show_fullpath() const;

    bool operator ==(const lvl_file& other);
    bool operator !=(const lvl_file& other);

private:
    std::string extension;
    std::string filename;
    std::string fullpath;
};

#endif // LVL_FILE_H
