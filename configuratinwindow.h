#ifndef CONFIGURATINWINDOW_H
#define CONFIGURATINWINDOW_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

typedef std::string Path;

class ConfiguratonWindow {
    public:
        ConfiguratonWindow();
        ~ConfiguratonWindow();

        unsigned height_window, width_window;
        unsigned height_canvas, width_canvas;

        Path Maps;
        Path Sounds;
        Path AboutProgram;

        std::string version_program;

        void load_conf(std::string& filename);
};

#endif // CONFIGURATINWINDOW_H
