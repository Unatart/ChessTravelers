#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QMessageBox>

#include <memory>

#include "playingfield.h"
#include "configuratinwindow.h"
#include "pointconverter.h"
#include "interfaceerrors.h"
#include "customcanvas.h"
#include "customsound.h"

enum TabPages {
    MENU = 0,
    SELECT = 1,
    START = 2,
    STATISTIC = 3,
    ABOUT = 4,
    ENTER_NAME = 5
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0,  const ConfiguratonWindow &conf = ConfiguratonWindow());
    ~MainWindow();

//buttons
private slots:
    //menu pages
    void on_SelectGame_clicked();
    void on_Exit_clicked();
    void on_About_clicked();
    void on_Statistic_clicked();
    //back out page
    void on_BackOutSelect_clicked();
    void on_BackOutStatistic_clicked();
    void on_BackOutAbout_clicked();
    void on_Start_clicked();

    void on_newGame_clicked();
    void on_backSelect_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<CustomCanvas> canvas;
    std::unique_ptr<CustomSound> sound;
    std::unique_ptr<PlayingField> field;

    //size matrix scene
    int size_map_width;
    int size_map_height;

    QString playerName;
    std::unique_ptr<QEventLoop> gameLoop;

    //Paths
    Path Maps;

    //draw
    void drawMap();
    void drawGrid();
    void drawMapCube();
    void drawPossibleCube();
    void drawFinishCube();

    void loadData(std::string map);
    void start();
    void runGame();
    void runMap();
    bool IsRunMap();

    void getCongratulationMesBox(std::string message, int score);
    void getErrMesBox();
    void toPage(TabPages page);

    //mouse click
    void ProcessClickMouseLeft(QPoint point);
    void ProcessClickMouseRight();
    void mousePressEvent(QMouseEvent *event); 

    QPoint getPosition(QPointF &cursor, int size_cube_width, int size_cube_height);
};

#endif // MAINWINDOW_H
