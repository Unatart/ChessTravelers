#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <list>
#include <iterator>
#include "file.h"

class File;

class FileManager {
public:
    FileManager() = default;
    FileManager(std::list<File>& init_files, int init_amount_of_files);
    ~FileManager() = default;

    FileManager(const FileManager& other);
    FileManager& operator =(const FileManager& other);

    void CreateFileManager(std::string& directory_path);

    File& getFile(std::string file_name);

    int getAmount_of_files() const;
    void showAmount_of_files() const;

    void addFile(File& file);
    void deleteFile(File& file);

    void cleanFileManager();

private:
    std::list<File> files;
    int amount_of_files;
};

#endif // FILE_MANAGER_H