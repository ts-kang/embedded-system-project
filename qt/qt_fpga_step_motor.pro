#-------------------------------------------------
#
# Project created by QtCreator 2018-04-05T15:10:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_fpga_step_motor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        #dip.c \
   # step.c

HEADERS  += mainwindow.h \
   # dip.h \
   # step.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
