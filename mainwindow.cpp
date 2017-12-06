#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "utils.h"
#include "cell.h"
#include "playingfield.h"
#include "datagame.h"

#include <string>

enum COLOR_ID {
    WHITE = '#',
    BLACK = '0',
    GREEN = 2,
    BLUE  = '1',
    RED   = 4
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_ver->setText("v0.2");

    size_map_width = 1;
    size_map_height = 1;

    size_canvas_width = 400;
    size_canvas_height = 400;
    scene = new QGraphicsScene();
    myLoop = new QEventLoop (ui->graphicsView);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(0, 0, size_canvas_width, size_canvas_height);

    change = true;

    isClickedScene = false;
    clrClickedCube = WHITE;
    ui->graphicsView->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QColor MainWindow::handleColor(int num_clr) {
    QColor color;
    switch(num_clr) {
        case WHITE:
            color = Qt::white;
            break;
        case BLUE:
            color = Qt::blue;
            break;
        case RED:
            color = Qt::red;
            break;
        case BLACK:
            color = Qt::black;
            break;
        case GREEN:
            color = Qt::green;
            break;
    }
    return color;
}

QPoint MainWindow::getPosition(QPointF cursor) {
    for (int i = 0; i < size_map_height; ++i) {
        for (int j = 0; j < size_map_width; ++j) {
            if (cursor.x() >= j * size_cube_width
                    && cursor.y() >= i * size_cube_height
                        && cursor.x() < j * size_cube_width + size_cube_width
                            && cursor.y() < i * size_cube_height + size_cube_height)
            {
                QPoint i_j(i, j);
                return i_j;
            }
        }
    }
    QPoint err(INVALID_COORD, INVALID_COORD);
    return err;
}

void MainWindow::drawCube(QPoint cube, QPen pen, QColor clr_brush, float percent_offset) {
    if (cube.x() != INVALID_COORD) {
        int x = cube.y(), y = cube.x();
        int offset_width = (int) size_cube_width * percent_offset;
        int offset_height = (int) size_cube_height * percent_offset;

        QBrush brush(clr_brush);

        scene->addRect(x * size_cube_width + offset_width,  y * size_cube_height + offset_height,
                size_cube_width - 2 * offset_width,
                    size_cube_height - 2 * offset_height,  pen, brush);
    }
}

void MainWindow::drawCube(QPoint cube, int clr_pen, QColor clr_brush, float percent_offset) {
    if (cube.x() != INVALID_COORD) {
        int x = cube.y(), y = cube.x();
        int offset_width = (int) size_cube_width * percent_offset;
        int offset_height = (int) size_cube_height * percent_offset;

        QPen pen(handleColor(clr_pen));
        QBrush brush(clr_brush);

        scene->addRect(x * size_cube_width + offset_width,  y * size_cube_height + offset_height,
                size_cube_width - 2 * offset_width,
                    size_cube_height - 2 * offset_height,  pen, brush);
    }
}

void MainWindow::drawClickedCube(QPoint cube, char clr){
    //clean this cube place
    drawCube(cube, BLACK, WHITE, 0);
    //small clicked cube and green pen
    drawCube(cube, GREEN, clr, 3);
}

void MainWindow::drawPossibleMoves(std::vector<QPoint> move_cubes, char clr) {
    //draw some possible cubs
    for (size_t i = 0; i < move_cubes.size(); ++i) {
        drawPossibleMove(move_cubes[i], clr);
    }
}

void MainWindow::drawPossibleMove(QPoint move_cube, char clr) {
    //possible move cube
    drawCube(move_cube, clr, GREEN, 5);
}

QPoint MainWindow::ConvertToQPoint(Coordinates coord) {
    QPoint point(coord.i, coord.j);
    return point;
}

Coordinates MainWindow::ConvertToCoordinates(QPoint point) {
    Coordinates coordinates(point.x(), point.y());
    return coordinates;
}

void MainWindow::drawMap() {
    //draw maps (lines)
    //cols map
    for (int col = 1; col < size_map_height; ++col){
        scene->addLine(col * size_cube_height , 0, col * size_cube_height, size_canvas_height);
    }
    //rows map
    for (int row = 0; row < size_map_width; ++row){
        scene->addLine(0, row * size_cube_width, size_canvas_width, row * size_cube_width);
    }

    //draw player and other cubs
    for (int i = 0; i < size_map_height; ++i) {
        for (int j = 0; j < size_map_width; ++j) {
            QPoint point_cube(i, j);
            QColor clr = field->get(ConvertToCoordinates(point_cube))->colorRepresentation();
            drawCube(point_cube, BLACK, clr, 0);
        }
    }
    //draw cube finish mission
    std::vector<Coordinates> win_points = field->winningPosition();// ConvertToQPoint(field->winningPosition());
    for (size_t i = 0; i < win_points.size(); ++i) {
        drawCube(ConvertToQPoint(win_points[i]), BLACK, Qt::cyan, 0.3);
    }


    //copy and convert coord into field
    std::vector<Coordinates> possible_points = field->availableMoves();
    std::cout << possible_points.size() << std::endl;
    if (possible_points.size() != 0) {
        QColor clr = field->get(field->selectedCell())->colorRepresentation();
        for (size_t i = 0; i < possible_points.size(); ++i) {
            drawCube(ConvertToQPoint(possible_points[i]), BLACK, clr, 0.6);
        }
        drawCube(ConvertToQPoint(field->selectedCell()), QPen(Qt::red, 3), clr, 0);
    }
}

void MainWindow::loadData() {
    //there are methods don`t work (rewrite in FileManager)
    field = new PlayingField();
    std::string filename = "maps/1.txt";
    field->load(filename);

    size_map_width = field->width();
    size_map_height = field->height();

    size_cube_width = size_canvas_width / size_map_width;
    size_cube_height = size_canvas_height / size_map_height;
}

bool MainWindow::IsRunMap() {
    if (field->isWinning()) {
        return false;
    }
    return true;
}

void MainWindow::runGame() {
    isClickedScene = true;
    drawMap();
    while (IsRunMap()) {
        myLoop->exec();
        drawMap();
    }
}

void MainWindow::start(){
    //#########for fun#############
    QSound sound("sound/background.wav");
    sound.setLoops(5);
    sound.play();

    //#############################
    loadData();
    runGame();
}

//handle event click mouse
void MainWindow::ProcessClickMouseRight() {
    field->undo();
    isClickedScene = true;
    //drawMap();
}

void MainWindow::ProcessClickMouseLeft(QPoint point) {
    if (point.x() == INVALID_COORD){
        isClickedScene = true;
        return;
    }

    field->pressCell(ConvertToCoordinates(point));
    isClickedScene = true;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        if (isClickedScene == true) {
            QPointF scenePos = ui->graphicsView->mapToScene(ui->graphicsView->mapFromGlobal(event->globalPos()));
            //QPointF scenePos = ui->graphicsView->mapFromGlobal(QCursor::pos());
            std::cout << scenePos.x() << " " << scenePos.y() << std::endl;
            QPoint i_j = getPosition(scenePos);

            ProcessClickMouseLeft(i_j);
            //getPosition MouseClick in canvas (i, j) for debug
            //ui->label_3->setText(QString::number(i_j.x()) + " " + QString::number(i_j.y()));
        }
        myLoop->quit();
    }
    if(event->button() == Qt::RightButton) {
        //isClickedScene = false;
        ProcessClickMouseRight();
        myLoop->quit();
    }
}

void MainWindow::toPage(TabPages page) {
    ui->tabGame->setCurrentIndex(page);
}

void MainWindow::on_SelectGame_clicked()
{
    toPage(SELECT);
}

void MainWindow::on_Exit_clicked()
{
    exit(1);
}

void MainWindow::on_About_clicked()
{
    toPage(ABOUT);
}

void MainWindow::on_Statistic_clicked()
{
    toPage(STATISTIC);
    ui->tableBestPlayers->setRowCount(50);
    ui->tableBestPlayers->setColumnCount(2);

    int table_size = ui->tableBestPlayers->horizontalHeader()->size().rwidth();
    int offset = ui->tableBestPlayers->verticalHeader()->size().rwidth();
    ui->tableBestPlayers->horizontalHeader()->resizeSection(0, table_size * 2/3);
    ui->tableBestPlayers->horizontalHeader()->resizeSection(1, table_size * 1/3 - offset);
    ui->tableBestPlayers->setHorizontalHeaderLabels(QStringList() << "Player" << "Score");

    //load out file && set all players
}

void MainWindow::on_BackOutSelect_clicked()
{
    toPage(MENU);
}

void MainWindow::on_BackOutStatistic_clicked()
{
    toPage(MENU);
}

void MainWindow::on_BackOutAbout_clicked()
{
    toPage(MENU);
    ui->TextAbout->setText("Информация об игре");
}

void MainWindow::on_Start_clicked()
{
    playerName = ui->NamelineEdit->text();
    if (playerName.size() == 0) {
        return;
    }
    ui->playerName_label->setText(playerName);
    toPage(START);
    start();
}

void MainWindow::on_newGame_clicked()
{
    toPage(ENTER_NAME);
}

void MainWindow::on_backSelect_clicked()
{
    toPage(MENU);
}
