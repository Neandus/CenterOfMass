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
    README.md \
    resources/arrow-top.svg \
    resources/brush.svg \
    resources/data-transfer-download.svg \
    resources/folder.svg \
    resources/pencil.svg \
    resources/sun.svg \
    resources/target.svg \
    resources/trash.svg
