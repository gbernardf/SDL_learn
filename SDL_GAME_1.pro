TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/include/SDL2
LIBS += -lSDL2
LIBS += -lSDL2_image
LIBS += -lSDL2_ttf

SOURCES += main.cpp \
    functions.cpp \
    Sprite.cpp \
    Game.cpp \
    GameState.cpp \
    TitleScreen.cpp

HEADERS += \
    functions.h \
    Sprite.h \
    Game.h \
    GameState.h \
    TitleScreen.h




