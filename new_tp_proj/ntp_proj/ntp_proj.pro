TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += C:\Users\Unatart\Desktop\Project\new_tp_proj\boost_1_65_1

SOURCES += main.cpp \
    cell.cpp \
    figure.cpp \
    cellmatrix.cpp \
    field.cpp \
    playingfield.cpp \
    winningmatrix.cpp \
    utils.cpp

HEADERS += \
    cell.h \
    figure.h \
    cellmatrix.h \
    winningmatrix.h \
    field.h \
    playingfield.h \
    utils.h \
    exceptions.h
