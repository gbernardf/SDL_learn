TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/include/SDL2
LIBS += -lSDL2

SOURCES += main.cpp \
    functions.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    functions.h




