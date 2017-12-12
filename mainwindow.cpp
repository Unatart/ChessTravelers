#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, const ConfiguratonWindow& conf):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    canvas(new CustomCanvas()),
    sound(new CustomSound(conf.Sounds)),
    Maps(conf.Maps)
{
    ui->setupUi(this);
    ui->label_ver->setText(QString::fromStdString(conf.version_program));

    //gameLoop
    gameLoop = std::move(std::unique_ptr<QEventLoop>(new QEventLoop(ui->graphicsView)));

    //init canvas
    ui->graphicsView->setScene(canvas.get());
    canvas->setCanvas(conf.width_canvas, conf.height_canvas);

    //init table result
    ui->tableBestPlayers->setHorizontalHeaderLabels(QStringList() << "Player" << "Score");

    //sound
    sound->playInMenu();
}

MainWindow::~MainWindow() {
    delete ui;
}

QPoint MainWindow::getPosition(QPointF &cursor, int size_cube_width, int size_cube_height) {
    int i = (int) (cursor.x()) / size_cube_width;
    int j = (int) (cursor.y()) / size_cube_height;
    if (i >= 0 && i < size_map_width && j >= 0 && j < size_map_height) {
        return QPoint(j, i);
    }
    return QPoint(INVALID_COORD, INVALID_COORD);
}

void MainWindow::drawGrid() {
    canvas->drawGrid(size_map_width, size_map_height);
}

void MainWindow::drawMapCube() {
    for (int i = 0; i < size_map_height; ++i) {
        for (int j = 0; j < size_map_width; ++j) {
            QPoint point_cube(i, j);
            QColor clr = field->get(ConvertToCoordinates(point_cube))->colorRepresentation();
            canvas->drawCube(point_cube, QPen(Qt::black, 1), clr, 0);
        }
    }
}

void MainWindow::drawPossibleCube() {
    std::vector<Coordinates> possible_points = field->availableMoves();
    if (possible_points.size() != 0) {
        QColor clr = field->get(field->selectedCell())->colorRepresentation();
        for (size_t i = 0; i < possible_points.size(); ++i) {
            canvas->drawCube(ConvertToQPoint(possible_points[i]), QPen(Qt::black, 1), clr, 0.6);
        }
        canvas->drawCube(ConvertToQPoint(field->selectedCell()), QPen(Qt::red, 3), clr, 0);
    }
}

void MainWindow::drawFinishCube()  {
    std::vector<Coordinates> win_points = field->winningPosition();
    for (size_t i = 0; i < win_points.size(); ++i) {
        canvas->drawCube(ConvertToQPoint(win_points[i]), QPen(Qt::black, 1), Qt::cyan, 0.3);
    }
}

void MainWindow::drawMap() {
    //draw maps (lines)
    drawGrid();
    //draw player and other cubs
    drawMapCube();
    //draw cube finish mission
    drawFinishCube();
    //copy and convert coord into field
    drawPossibleCube();
}

void MainWindow::loadData(std::string map) {
    //LOADS AND SAVE FILES IN FILEMANAGER
    field = std::move(std::unique_ptr<PlayingField>(new PlayingField()));
    std::string filename = Maps + map;
    field->load(filename);

    size_map_width = field->width();
    size_map_height = field->height();

    canvas->setSizeCube(canvas->getWidth() / size_map_width, canvas->getHeight() / size_map_height);
}

bool MainWindow::IsRunMap() {
    return field->isWinning() ? false : true;
}

void MainWindow::runMap() {
    drawMap();
    canvas->setActive(true);
    while (IsRunMap()) {
        gameLoop.get()->exec();
        drawMap();
    }
    canvas->setActive(false);
}

void MainWindow::runGame() {
    //GETS AND SAVE MAP IN FILEMANAGER
    std::vector<std::string> map = {"1.txt"}; //this example
    for (size_t i = 0; i < map.size(); ++i) {
        loadData(map[i]);
        runMap();
        getCongratulationMesBox(map[i], 0);
    }
}

void MainWindow::start(){
    sound->playInGame();
    runGame();
}

//handle event click mouse
void MainWindow::ProcessClickMouseRight() {
    field->undo();
}

void MainWindow::ProcessClickMouseLeft(QPoint point) {
    if (point.x() == INVALID_COORD){
        return;
    }
    sound->SoundClick();
    field->pressCell(ConvertToCoordinates(point));
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        if (canvas->getActive() == true) {
            QPointF cursor = ui->graphicsView->mapToScene(ui->graphicsView->mapFromGlobal(event->globalPos()));
            QPoint i_j = getPosition(cursor, canvas->getWidthCube(), canvas->getHeightCube());
            ProcessClickMouseLeft(i_j);
        }
    }
    if(event->button() == Qt::RightButton) {
        if (canvas->getActive() == true) {
            ProcessClickMouseRight();
        }
    }
    gameLoop.get()->quit();
}

void MainWindow::toPage(TabPages page) {
    ui->tabGame->setCurrentIndex(page);
}

void MainWindow::on_SelectGame_clicked() {
    toPage(SELECT);
}

void MainWindow::on_Exit_clicked() {
    exit(1);
}

void MainWindow::on_About_clicked() {
    toPage(ABOUT);
}

void MainWindow::on_Statistic_clicked() {
    toPage(STATISTIC);
    ui->tableBestPlayers->horizontalHeader()->resizeSection(0,
            ui->tableBestPlayers->horizontalHeader()->size().rwidth() * 2/3),
    ui->tableBestPlayers->horizontalHeader()->resizeSection(1,
            ui->tableBestPlayers->horizontalHeader()->size().rwidth() * 1/3);
    //LOADS RESULT PLAYERS FROM FILEMANAGER
}

void MainWindow::on_BackOutSelect_clicked() {
    toPage(MENU);
}

void MainWindow::on_BackOutStatistic_clicked() {
    toPage(MENU);
}

void MainWindow::on_BackOutAbout_clicked() {
    ui->TextAbout->setText("Информация об игре");
    toPage(MENU);
}

void MainWindow::getErrMesBox() {
    QMessageBox messageBox;
    messageBox.critical(0, "Error", "Enter your UserName!");
    messageBox.setFixedSize(width() / 2, height() / 2);
}

void MainWindow::getCongratulationMesBox(std::string message, int score) {
    QMessageBox messageBox;
    messageBox.information(0, "Сongratulation!",
                           "You complete mission"
                           + QString::fromStdString(message)
                           + "\n"
                           + "Your score: "
                           + QString::number(score)
                           );
    messageBox.setFixedSize(width() / 2, height() / 2);
}

void MainWindow::on_Start_clicked() {
    playerName = ui->NamelineEdit->text();
    if (playerName.size() == 0) {
        getErrMesBox();
        return;
    }
    ui->playerName_label->setText(playerName);
    toPage(START);
    start();
    toPage(MENU);
}

void MainWindow::on_newGame_clicked() {
    toPage(ENTER_NAME);
}

void MainWindow::on_backSelect_clicked() {
    toPage(MENU);
}
