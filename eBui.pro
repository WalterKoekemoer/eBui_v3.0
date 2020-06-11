#-------------------------------------------------
#
# Project created by QtCreator 2020-05-31T13:43:59
#
#-------------------------------------------------

QT       += core gui
QT       += core
QT       += widgets
QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = eBui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    addcomponent.cpp \
    subcomponetsscene.cpp \
    resistor.cpp \
    inductor.cpp \
    capacitor.cpp \
    depcurrentsrc.cpp \
    depvoltagesrc.cpp \
    definecomponent.cpp \
    widget.cpp \
    wire.cpp \
    mainscene.cpp \
    voltagesource.cpp

HEADERS  += widget.h \
    addcomponent.h \
    subcomponetsscene.h \
    resistor.h \
    inductor.h \
    capacitor.h \
    depcurrentsrc.h \
    depvoltagesrc.h \
    definecomponent.h \
    component.h \
    wire.h \
    connections.h \
    mainscene.h \
    voltagesource.h

FORMS    += widget.ui \
    addcomponent.ui \
    definecomponent.ui

RESOURCES += \
    icons.qrc
