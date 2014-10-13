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


SOURCES += main.cpp\
        mainwindow.cpp \
    frmaddnote.cpp \
    dbmanager.cpp

HEADERS  += mainwindow.h \
    frmaddnote.h \
    dbmanager.h \
    constants.h

FORMS    += mainwindow.ui \
    frmaddnote.ui

RESOURCES += \
    NoteMaker.qrc
