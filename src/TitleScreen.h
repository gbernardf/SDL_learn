#ifndef TITLESCREEN_H
#define TITLESCREEN_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameState.h"
#include "Sprite.h"

const string IMG_PATH = "../files/png/";


class TitleScreen : public GameState
{
public:
    TitleScreen(int width, int height);
    ~TitleScreen();
    void init();
    bool update();
    void render();
    bool handleEvent(SDL_Event* event);
    bool hit();
private:
    SDL_Texture* back;
    Sprite* coin;
    SDL_Texture* text;
    SDL_Texture* clickToGoText;
    SDL_Texture* escToEsc;
    int screenWidth;
    int screenHeight;

};

#endif // TITLESCREEN_H
