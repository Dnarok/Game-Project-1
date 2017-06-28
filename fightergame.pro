#-------------------------------------------------
#
# Project created by QtCreator 2016-12-15T16:19:38
#
#-------------------------------------------------

QT       += core gui\
            multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fightergame
TEMPLATE = app


SOURCES += main.cpp \
    myrect.cpp \
    pillar.cpp \
    game.cpp \
    bullet.cpp

HEADERS  += \
    myrect.h \
    pillar.h \
    game.h \
    bullet.h

FORMS    +=

RESOURCES += \
    rsc.qrc
