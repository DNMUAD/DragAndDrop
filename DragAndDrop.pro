#-------------------------------------------------
#
# Project created by QtCreator 2023-10-27T09:27:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DragAndDrop
TEMPLATE = app

CONFIG += -static
QMAKE_LFLAGS += -static

SOURCES += main.cpp\
    dropwidget.cpp \
    dragwidgetlineedit.cpp \
    dragwidgetpushbutton.cpp \
    listlabel.cpp \
    dragtestwidget.cpp \
    mainwindow.cpp \
    tablewidget.cpp

HEADERS  += \
    dragwidgetlineedit.h \
    dragwidgetpushbutton.h \
    dropwidget.h \
    listlabel.h \
    dragtestwidget.h \
    mainwindow.h \
    tablewidget.h

FORMS    += \
    mainwindow.ui

RESOURCES += \
    DAD.qrc
