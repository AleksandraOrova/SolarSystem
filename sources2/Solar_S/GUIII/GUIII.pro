#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T23:43:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIII
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    planetview.cpp \
    satelliteview.cpp \
    systemdrawer.cpp

HEADERS  += mainwindow.h \
    planetview.h \
    satelliteview.h \
    systemdrawer.h

RESOURCES += \
    resources/resources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Core/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Core/debug/ -lCore
else:unix: LIBS += -L$$OUT_PWD/../Core/ -lCore

INCLUDEPATH += $$PWD/../Core
DEPENDPATH += $$PWD/../Core

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/release/libCore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/debug/libCore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/release/Core.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/debug/Core.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Core/libCore.a


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Solar_Interface/release/ -lSolar_Interface
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Solar_Interface/debug/ -lSolar_Interface
else:unix: LIBS += -L$$OUT_PWD/../Solar_Interface/ -lSolar_Interface

INCLUDEPATH += $$PWD/../Solar_Interface
DEPENDPATH += $$PWD/../Solar_Interface

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Solar_Interface/release/libSolar_Interface.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Solar_Interface/debug/libSolar_Interface.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Solar_Interface/release/Solar_Interface.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Solar_Interface/debug/Solar_Interface.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Solar_Interface/libSolar_Interface.a
