#-------------------------------------------------
#
# Project created by QtCreator 2016-11-28T22:36:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CenterOfMass
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    workspace.cpp \
    mygraphicviewer.cpp

HEADERS  += mainwindow.h \
    workspace.h \
    mygraphicviewer.h

FORMS    += mainwindow.ui

DISTFILES += \
    README.md
