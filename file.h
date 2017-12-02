#ifndef FILE_H
#define FILE_H

#include "utils.h"

class File {
public:
    File() = default;
    File(std::string init_full_path);
    ~File() = default;

    File(const File &other);
    File& operator =(const File &other);

    void Set_file_name(std::string& init_file_name);
    void Set_extension(std::string& init_extension);
    void Set_full_path(std::string& init_full_path);

    std::string Get_file_name() const;
    std::string Get_extension() const;
    std::string Get_full_path() const;

    void Show_file_name() const;
    void Show_extension() const;
    void Show_full_path() const;

    bool operator ==(const File& other);
    bool operator !=(const File& other);

    struct Finder{
        Finder(std::string const& n) : name(n) {}
        bool operator() (const File& elem) const {
            return elem.file_name == name;
        }
    private:
        std::string name;

    };

private:
    std::string file_name;
    std::string extension;

    boost::filesystem::path full_path;

};

#endif // FILE_H