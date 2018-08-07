#-------------------------------------------------
#
# Project created by QtCreator 2018-05-12T18:54:46
#
#-------------------------------------------------

QT       += core gui
QT       += charts
QT       += axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Ploting_and_Visualization
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    polynomial.cpp \
    visualization.cpp \
    readfile.cpp \
    qcustomplot.cpp \
    cosine.cpp \
    logarithm.cpp \
    sine.cpp

HEADERS += \
        mainwindow.h \
    polynomial.h \
    visualization.h \
    readfile.h \
    qcustomplot.h \
    cosine.h \
    logarithm.h \
    sine.h

FORMS += \
        mainwindow.ui
