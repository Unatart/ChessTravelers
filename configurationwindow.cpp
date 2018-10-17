#include "configuratinwindow.h"

ConfiguratonWindow::ConfiguratonWindow() {

}

ConfiguratonWindow::~ConfiguratonWindow() {

}


void ConfiguratonWindow::load_conf(std::string &filename) {
    std::ifstream fconfig(filename);
    fconfig >> width_window >> height_window;
    fconfig >> width_canvas >> height_canvas;

    std::getline(fconfig, Maps);
    std::getline(fconfig, Maps);
    std::getline(fconfig, Sounds);
    std::getline(fconfig, AboutProgram);
    std::getline(fconfig, version_program);

    fconfig.close();
}
