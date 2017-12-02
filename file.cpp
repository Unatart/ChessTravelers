#include "file.h"

File::File(std::string init_full_path)  {
    boost::filesystem::path fp(init_full_path);
    this->full_path = fp;

    this->file_name = full_path.stem().string();
    this->extension = full_path.extension().string();
}

File::File(const File &other) {
    this->file_name = other.file_name;
    this->extension = other.extension;
    this->full_path = other.full_path;
}

File& File::operator =(const File &other) {
    if (this == &other) {
        return *this;
    }

    this->file_name = other.file_name;
    this->extension = other.extension;
    this->full_path = other.full_path;

    return *this;
}

void File::Set_file_name(std::string& init_file_name) {
    this->file_name = init_file_name;
}

void File::Set_extension(std::string& init_extension) {
    this->extension = init_extension;
}

void File::Set_full_path(std::string& init_full_path) {
    this->full_path = init_full_path;
}


std::string File::Get_file_name() const {
    return (this->file_name);
}

std::string File::Get_extension() const {
    return (this->extension);
}

std::string File::Get_full_path() const {
    return (this->full_path.relative_path().string());
}

void File::Show_file_name() const {
    std::cout << this->file_name;
}

void File::Show_extension() const {
    std::cout << this->extension;
}

void File::Show_full_path() const {
    std::cout << this->full_path.relative_path().string();
}

bool File::operator ==(const File& other) {
    if (this->full_path == other.full_path) {
        return true;
    }
    return false;
}

bool File::operator !=(const File& other) {
    if (this->full_path != other.full_path) {
        return true;
    }
    return false;
}

