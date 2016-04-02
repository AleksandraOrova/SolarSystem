TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    consoleapp.cpp \
    planetinfo.cpp \
    vector3.cpp \
    solarsystem.cpp

HEADERS += \
    consoleapp.h \
    planetinfo.h \
    vector3.h \
    solarsystem.h
