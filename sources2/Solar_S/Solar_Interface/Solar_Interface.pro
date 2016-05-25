#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T12:20:18
#
#-------------------------------------------------

QT       += widgets

TARGET = Solar_Interface
TEMPLATE = lib
CONFIG += staticlib

SOURCES += solar_interface.cpp \
    coordinates.cpp \
    functions.cpp \
    main.cpp \
    planets.cpp \
    solars.cpp \
    spaceobject.cpp \
    star.cpp

HEADERS += solar_interface.h \
    coordinates.h \
    functions.h \
    planets.h \
    solars.h \
    spaceobject.h \
    star.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
