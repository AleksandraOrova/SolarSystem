#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T12:20:18
#
#-------------------------------------------------

QT       += widgets

TARGET = Solar_Interface
TEMPLATE = lib
CONFIG += staticlib

SOURCES += solar_interface.cpp

HEADERS += solar_interface.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
