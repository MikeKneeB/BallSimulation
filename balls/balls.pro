#-------------------------------------------------
#
# Project created by QtCreator 2016-10-18T15:18:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = balls
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    twovector.cpp \
    ball.cpp \
    field.cpp \
    regularball.cpp \
    displaywindow.cpp

HEADERS  += mainwindow.h \
    twovector.h \
    ball.h \
    field.h \
    regularball.h \
    displaywindow.h

FORMS    += mainwindow.ui \
    displaywindow.ui
