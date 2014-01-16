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
    api/lpt/lptwindowsapi.cpp \
    api/lpt/lptunixapi.cpp \
    api/lpt/lptapi.cpp

HEADERS  += dashboard.h \
    api/lpt/lptwindowsapi.h \
    api/lpt/lptunixapi.h \
    api/portapifactory.h \
    api/portapi.h \
    api/lpt/lptapi.h

FORMS    += dashboard.ui
