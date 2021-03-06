#-------------------------------------------------
#
# Project created by QtCreator 2019-04-27T21:31:51
#
#-------------------------------------------------


QT += multimedia multimediawidgets
QT       += core gui


#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = CPP_QT_Game_Tutorial
#TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    player.cpp \
    dialog.cpp \
    win.cpp \
    lose.cpp

HEADERS += \
    bullet.h \
    enemy.h \
    game.h \
    player.h \
    dialog.h \
    win.h \
    lose.h



RESOURCES += \
    res.qrc

FORMS += \
    dialog.ui \
    win.ui \
    lose.ui

DISTFILES += \
    images/lose.gif \
    sounds/lose.mp3

