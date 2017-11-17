TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

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
    utils.h
