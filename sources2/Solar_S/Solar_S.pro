TEMPLATE = subdirs
QMAKE_CXXFLAGS += -std=c++11

App.depends = Core
Test.depends = Core

SUBDIRS += \
    App \
    Core \
    Test \
    GUII
