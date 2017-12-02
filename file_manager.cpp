#include "file_manager.h"
#include "file.h"
#include "utils.h"

FileManager::FileManager(std::list<File>& init_files, int init_amount_of_files) :
files(init_files), amount_of_files(init_amount_of_files) {}

FileManager::FileManager(const FileManager& other) {
    this->files = other.files;
    this->amount_of_files = other.amount_of_files;

}

FileManager& FileManager::operator =(const FileManager& other) {
    if (this == &other) {
       return *this;
    }

    this->files = other.files;
    this->amount_of_files = other.amount_of_files;

    return *this;
}

void FileManager::CreateFileManager(std::string &directory_path) {
    if (!directory_path.empty()) {
        boost::filesystem::path apk_path(directory_path);
        boost::filesystem::recursive_directory_iterator end;

        for (boost::filesystem::recursive_directory_iterator i(apk_path); i != end; ++i) {
            const boost::filesystem::path cp = (*i);
            File file(cp.string());
            files.push_back(file);
            amount_of_files++;
        }
    }
}

File& FileManager::getFile(std::string file_name) {
    auto it = std::find_if(files.begin(), files.end(), File::Finder(file_name));

    return *it; // Не могу понять что здесь не так. Необходимо вернуть файл из листа проверив его по имени.
}

int FileManager::getAmount_of_files() const {
    return (this->amount_of_files);
}

void FileManager::showAmount_of_files() const {
    std::cout << this->amount_of_files;
}

void FileManager::addFile(File& file) {
    this->files.push_back(file);
    this->amount_of_files++;
}

 void FileManager::deleteFile(File& file) {
    this->files.remove(file);
    this->amount_of_files--;
}

void FileManager::cleanFileManager() {
    this->files.clear();
    this->amount_of_files = 0;
}