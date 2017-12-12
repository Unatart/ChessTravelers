#include "mainwindow.h"
#include <QApplication>
#include "configuratinwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    ConfiguratonWindow conf;
    std::string filename =  "config.txt";
    conf.load_conf(filename);

    MainWindow w(0, conf);
    w.show();

    return a.exec();
}

