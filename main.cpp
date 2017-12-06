#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.setPalette(QPalette(QColor(Qt::red), QPalette::Background));
    w.show();

    return a.exec();
}

