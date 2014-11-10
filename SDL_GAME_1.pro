TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/include/SDL2
LIBS += -lSDL2
LIBS += -lSDL2_image

SOURCES += main.cpp \
    functions.cpp \
    sprite.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    functions.h \
    sprite.h




