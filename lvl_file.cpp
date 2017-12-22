#include "lvl_file.h"

lvl_file::lvl_file(const std::string& init_fullpath) {
    fs::path fp(init_fullpath);

    fullpath = fp;
    filename = fp.filename();
    extension = fp.extension();
}

lvl_file::lvl_file(const lvl_file& other) {
    fullpath = other.fullpath;
    filename = other.filename;
    extension = other.extension;
}

lvl_file& lvl_file::operator= (const lvl_file& other) {
    if (this == &other) {
        return *this;
    }
    fullpath = other.fullpath;
    filename = other.filename;
    extension = other.extension;

    return *this;
}

void lvl_file::set_filename(std::string& init_filename) {
    filename = init_filename;
}

void lvl_file::set_extension(std::string& init_extension) {
    extension = init_extension;
}

void lvl_file::set_fullpath(std::string& init_fullpath) {
    fullpath = init_fullpath;
}

std::string lvl_file::get_filename() const {
    return filename;
}

std::string lvl_file::get_extensions() const {
    return extension;
}

std::string lvl_file::get_fullpath() const {
    return fullpath;
}

void lvl_file::show_filename() const {
    std::cout << this->get_filename() << std::endl;
}

void lvl_file::show_extensions() const {
    std::cout << this->get_extensions() << std::endl;
}

void lvl_file::show_fullpath() const {
    std::cout << this->get_fullpath() << std::endl;
}

bool lvl_file::operator ==(const lvl_file& other) {
    if (fullpath == other.fullpath) {
        return true;
    }
    return false;
}

bool lvl_file::operator !=(const lvl_file& other) {
    if (!(this == &other)) {
        return true;
    }
    return false;
}
