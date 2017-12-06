/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabGame;
    QWidget *tab;
    QPushButton *SelectGame;
    QPushButton *Statistic;
    QPushButton *About;
    QLabel *label;
    QPushButton *Exit;
    QWidget *tab_5;
    QPushButton *newGame;
    QPushButton *Load;
    QPushButton *BackOutSelect;
    QLabel *GameLabel;
    QWidget *tab_3;
    QPushButton *Menu;
    QGraphicsView *graphicsView;
    QLabel *playerName_label;
    QLabel *label_3;
    QWidget *tab_2;
    QPushButton *BackOutStatistic;
    QTableWidget *tableBestPlayers;
    QLabel *label_4;
    QWidget *tab_4;
    QPushButton *BackOutAbout;
    QTextEdit *TextAbout;
    QWidget *tab_6;
    QPushButton *Start;
    QLabel *EnterNameLabel;
    QPushButton *backSelect;
    QLineEdit *NamelineEdit;
    QLabel *label_ver;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(509, 564);
        MainWindow->setAutoFillBackground(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabGame = new QTabWidget(centralWidget);
        tabGame->setObjectName(QStringLiteral("tabGame"));
        tabGame->setGeometry(QRect(0, 0, 511, 501));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        SelectGame = new QPushButton(tab);
        SelectGame->setObjectName(QStringLiteral("SelectGame"));
        SelectGame->setGeometry(QRect(140, 110, 191, 51));
        Statistic = new QPushButton(tab);
        Statistic->setObjectName(QStringLiteral("Statistic"));
        Statistic->setGeometry(QRect(140, 190, 191, 51));
        About = new QPushButton(tab);
        About->setObjectName(QStringLiteral("About"));
        About->setGeometry(QRect(140, 280, 191, 51));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 50, 180, 31));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        Exit = new QPushButton(tab);
        Exit->setObjectName(QStringLiteral("Exit"));
        Exit->setGeometry(QRect(140, 370, 191, 51));
        tabGame->addTab(tab, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        newGame = new QPushButton(tab_5);
        newGame->setObjectName(QStringLiteral("newGame"));
        newGame->setGeometry(QRect(130, 110, 191, 51));
        Load = new QPushButton(tab_5);
        Load->setObjectName(QStringLiteral("Load"));
        Load->setGeometry(QRect(130, 210, 191, 51));
        BackOutSelect = new QPushButton(tab_5);
        BackOutSelect->setObjectName(QStringLiteral("BackOutSelect"));
        BackOutSelect->setGeometry(QRect(130, 310, 191, 51));
        GameLabel = new QLabel(tab_5);
        GameLabel->setObjectName(QStringLiteral("GameLabel"));
        GameLabel->setGeometry(QRect(190, 40, 81, 31));
        GameLabel->setFont(font);
        tabGame->addTab(tab_5, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        Menu = new QPushButton(tab_3);
        Menu->setObjectName(QStringLiteral("Menu"));
        Menu->setGeometry(QRect(120, 410, 191, 51));
        graphicsView = new QGraphicsView(tab_3);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(5, 1, 405, 405));
        playerName_label = new QLabel(tab_3);
        playerName_label->setObjectName(QStringLiteral("playerName_label"));
        playerName_label->setGeometry(QRect(420, 20, 81, 16));
        QPalette palette;
        QBrush brush(QColor(124, 101, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        playerName_label->setPalette(palette);
        QFont font1;
        font1.setPointSize(12);
        playerName_label->setFont(font1);
        playerName_label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(430, 60, 50, 13));
        tabGame->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        BackOutStatistic = new QPushButton(tab_2);
        BackOutStatistic->setObjectName(QStringLiteral("BackOutStatistic"));
        BackOutStatistic->setGeometry(QRect(150, 420, 191, 51));
        tableBestPlayers = new QTableWidget(tab_2);
        tableBestPlayers->setObjectName(QStringLiteral("tableBestPlayers"));
        tableBestPlayers->setEnabled(true);
        tableBestPlayers->setGeometry(QRect(0, 30, 501, 361));
        tableBestPlayers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableBestPlayers->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableBestPlayers->setColumnCount(0);
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 0, 151, 31));
        label_4->setFont(font);
        tabGame->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        BackOutAbout = new QPushButton(tab_4);
        BackOutAbout->setObjectName(QStringLiteral("BackOutAbout"));
        BackOutAbout->setGeometry(QRect(150, 400, 191, 51));
        TextAbout = new QTextEdit(tab_4);
        TextAbout->setObjectName(QStringLiteral("TextAbout"));
        TextAbout->setGeometry(QRect(-7, 0, 521, 381));
        TextAbout->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        tabGame->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        Start = new QPushButton(tab_6);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setGeometry(QRect(150, 210, 191, 51));
        EnterNameLabel = new QLabel(tab_6);
        EnterNameLabel->setObjectName(QStringLiteral("EnterNameLabel"));
        EnterNameLabel->setGeometry(QRect(150, 20, 221, 31));
        EnterNameLabel->setFont(font);
        backSelect = new QPushButton(tab_6);
        backSelect->setObjectName(QStringLiteral("backSelect"));
        backSelect->setGeometry(QRect(150, 300, 191, 51));
        NamelineEdit = new QLineEdit(tab_6);
        NamelineEdit->setObjectName(QStringLiteral("NamelineEdit"));
        NamelineEdit->setGeometry(QRect(40, 80, 411, 91));
        QPalette palette1;
        QBrush brush2(QColor(6, 106, 200, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        NamelineEdit->setPalette(palette1);
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setPointSize(48);
        font2.setBold(true);
        font2.setWeight(75);
        NamelineEdit->setFont(font2);
        NamelineEdit->setAlignment(Qt::AlignCenter);
        tabGame->addTab(tab_6, QString());
        label_ver = new QLabel(centralWidget);
        label_ver->setObjectName(QStringLiteral("label_ver"));
        label_ver->setGeometry(QRect(460, 500, 47, 13));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 509, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabGame->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ChessTravelers", 0));
        SelectGame->setText(QApplication::translate("MainWindow", "Start", 0));
        Statistic->setText(QApplication::translate("MainWindow", "Statistic", 0));
        About->setText(QApplication::translate("MainWindow", "About", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>ChessTravelers</p></body></html>", 0));
        Exit->setText(QApplication::translate("MainWindow", "Exit", 0));
        tabGame->setTabText(tabGame->indexOf(tab), QApplication::translate("MainWindow", "Menu", 0));
        newGame->setText(QApplication::translate("MainWindow", "New Game", 0));
        Load->setText(QApplication::translate("MainWindow", "Continue", 0));
        BackOutSelect->setText(QApplication::translate("MainWindow", "Back", 0));
        GameLabel->setText(QApplication::translate("MainWindow", "Game", 0));
        tabGame->setTabText(tabGame->indexOf(tab_5), QApplication::translate("MainWindow", "SelectGame", 0));
        Menu->setText(QApplication::translate("MainWindow", "Back", 0));
        playerName_label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        tabGame->setTabText(tabGame->indexOf(tab_3), QApplication::translate("MainWindow", "Game", 0));
        BackOutStatistic->setText(QApplication::translate("MainWindow", "Back", 0));
        label_4->setText(QApplication::translate("MainWindow", "Best players", 0));
        tabGame->setTabText(tabGame->indexOf(tab_2), QApplication::translate("MainWindow", "Statistics", 0));
        BackOutAbout->setText(QApplication::translate("MainWindow", "Back", 0));
        tabGame->setTabText(tabGame->indexOf(tab_4), QApplication::translate("MainWindow", "About", 0));
        Start->setText(QApplication::translate("MainWindow", "Start", 0));
        EnterNameLabel->setText(QApplication::translate("MainWindow", "Enter your name", 0));
        backSelect->setText(QApplication::translate("MainWindow", "Back", 0));
        NamelineEdit->setText(QString());
        tabGame->setTabText(tabGame->indexOf(tab_6), QApplication::translate("MainWindow", "EnterName", 0));
        label_ver->setText(QApplication::translate("MainWindow", "GameVersion", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
