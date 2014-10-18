#-------------------------------------------------
#
# Project created by QtCreator 2014-10-04T22:19:18
#
#-------------------------------------------------

QT       += core gui widgets network

TARGET = servidor
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    train.cpp \
    mainwindow.cpp \
    controller.cpp \
    server.cpp

HEADERS += \
    train.h \
    mainwindow.h \
    controller.h \
    server.h

FORMS += \
    mainwindow.ui
