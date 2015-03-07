#-------------------------------------------------
#
# Project created by QtCreator 2014-09-13T00:31:57
#
#-------------------------------------------------

QT      += core gui
QT      += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NoteMaker
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/frmaddnote.cpp \
    src/dbmanager.cpp \
    src/frmtaskcalendar.cpp

HEADERS  += headers/mainwindow.h \
    headers/frmaddnote.h \
    headers/dbmanager.h \
    headers/constants.h \
    headers/frmtaskcalendar.h

FORMS    += ui/mainwindow.ui \
    ui/frmaddnote.ui \
    ui/frmtaskcalendar.ui

RESOURCES += \
    NoteMaker.qrc
