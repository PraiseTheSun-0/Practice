include(gtest_dependency.pri)
INCLUDEPATH += ToTest/

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        ToTest/IKeypad.h \
        ToTest/ILatch.h \
        ToTest/lockcontroller.h \
        tst_testdivisionbyzero.h

SOURCES += \
        ToTest/lockcontroller.cpp \
        main.cpp
