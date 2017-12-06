#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSound>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QtGui>
#include <QtCore>
#include "playingfield.h"


typedef std::pair<int, int> xy;
typedef std::vector<std::pair<int, int>> vect_xy;

const int INVALID_COORD = -1;

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
    explicit MainWindow(QWidget *parent = 0);
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
    QGraphicsScene  *scene;
    QPointF target;         //cursor point
    PlayingField* field;

    //size matrix scene
    int size_map_width;
    int size_map_height;

    //size one cube
    int size_cube_width;
    int size_cube_height;

    //size Canvas
    int size_canvas_width;
    int size_canvas_height;

    QString playerName;
    QEventLoop *myLoop;

    //draw
    void drawMap();
    void drawCube(QPoint cube, QPen pen, QColor clr_brush, float percent_offset);
    void drawCube(QPoint cube, int clr_pen, QColor clr_brush, float percent_offset);
    void drawClickedCube(QPoint cube, char clr);
    void drawPossibleMove(QPoint move_cube, char clr);
    void drawPossibleMoves(std::vector<QPoint> move_cubes, char clr);

    void loadData();

    bool change;

    void start();
    void runGame();
    void runMap();

    void toPage(TabPages page);

    //mouse click
    void ProcessClickMouseLeft(QPoint point);
    void ProcessClickMouseRight();
    void mousePressEvent(QMouseEvent *event);
    bool isClickedScene;
    int clrClickedCube;

    bool IsRunMap();

    QColor handleColor(int num_clr);
    QPoint getPosition(QPointF cursor);

    //convertations points for connection with base game
    QPoint ConvertToQPoint(Coordinates coord);
    Coordinates ConvertToCoordinates(QPoint point);
};

#endif // MAINWINDOW_H
