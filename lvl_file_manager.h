#ifndef LVL_FILE_MANAGER_H
#define LVL_FILE_MANAGER_H

#include "file_manager.h"

class lvl_file_manager : public file_manager {
public:
    lvl_file_manager();
    lvl_file_manager(std::list<lvl_file>& init_files, int init_amount_of_files);

    lvl_file_manager(const lvl_file_manager& other);
    lvl_file_manager& operator =(const lvl_file_manager& other);

    void load_from_path(std::string directory_path);

    lvl_file& get_file(int level);

    int get_amount_of_files() const;
    void show_amount_of_files() const;

    void add_file(lvl_file& file);
    void delete_file(lvl_file& file);

    void clean();

private:
    std::list<lvl_file> files;
    int amount_of_files;
};

#endif // lvl_file_MANAGER_H
