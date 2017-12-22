#include "lvl_file_manager.h"

lvl_file_manager::lvl_file_manager() {
    amount_of_files = 0;
}

lvl_file_manager::lvl_file_manager(std::list<lvl_file>& init_files, int init_amount_of_files) :
files(init_files), amount_of_files(init_amount_of_files) {}

lvl_file_manager::lvl_file_manager(const lvl_file_manager& other) {
    this->files = other.files;
    this->amount_of_files = other.amount_of_files;
}

lvl_file_manager& lvl_file_manager::operator =(const lvl_file_manager& other) {
    if (this == &other) {
       return *this;
    }

    this->files = other.files;
    this->amount_of_files = other.amount_of_files;

    return *this;
}

void lvl_file_manager::load_from_path(std::string directory_path) {
    if (!directory_path.empty()) {
        fs::path apk_path(directory_path);
        fs::recursive_directory_iterator end;

        for (fs::recursive_directory_iterator i(apk_path); i != end; ++i) {
            const fs::path cp = (*i);
            lvl_file file(cp.string());
            files.push_back(file);
            amount_of_files++;
        }
    } else {
        throw common_exception("Directory is empty.");
    }
}

lvl_file& lvl_file_manager::get_file(int level) {
    if (level > this->amount_of_files)
        throw out_of_range_exception("Level can't be > amount of files in directory.");

    auto it = files.begin();
    std::advance(it, level);

    return *it;
}

int lvl_file_manager::get_amount_of_files() const {
    return (this->amount_of_files);
}

void lvl_file_manager::show_amount_of_files() const {
    std::cout << this->amount_of_files;
}

void lvl_file_manager::add_file(lvl_file &file) {
    this->files.push_back(file);
    this->amount_of_files++;
}

void lvl_file_manager::delete_file(lvl_file& file) {
    if (amount_of_files != 0) {
        this->files.remove(file);
        this->amount_of_files--;
    } else {
        throw out_of_range_exception("No more files in this file manager(lvl_filemanager)!");
    }

}

void lvl_file_manager::clean() {
    this->files.clear();
    this->amount_of_files = 0;
}
