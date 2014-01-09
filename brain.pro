#-------------------------------------------------
#
# Project created by QtCreator 2013-12-29T15:54:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = brain
TEMPLATE = app


SOURCES += main.cpp\
        dashboard.cpp \
    api/lptwindowsapi.cpp \
    api/lptunixapi.cpp

HEADERS  += dashboard.h \
    api/lptwindowsapi.h \
    api/lptunixapi.h \
    api/portapifactory.h \
    api/portapi.h \
    api/lpt/lptapi.h

FORMS    += dashboard.ui
