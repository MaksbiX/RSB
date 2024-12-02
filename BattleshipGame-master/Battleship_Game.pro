
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Battleship_Game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cpu.cpp \
    battleshipgame.cpp \
    displayships.cpp \
    selectship.cpp \
    boardsquare.cpp \
    player.cpp \
    human.cpp \
    gameships.cpp \
    cpuships.cpp \
    blast.cpp

HEADERS  += mainwindow.h \
    cpu.h \
    battleshipgame.h \
    displayships.h \
    selectship.h \
    boardsquare.h \
    player.h \
    human.h \
    gameships.h \
    cpuships.h \
    blast.h \
    vars.h \
    vars2.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    TODO.txt

DISTFILES += \
    JonsNotecs.txt \
    FromSFMLToQt.txt \
    BSGVariables.txt
