#ifndef TITLESCREEN_H
#define TITLESCREEN_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameState.h"
#include "Sprite.h"

const string IMG_PATH = "../FILES/imgs/";


class TitleScreen : public GameState
{
public:
    TitleScreen(int width, int height);
    void init();
    void update();
    void render();
    bool hit();
private:
    SDL_Texture* back;
    Sprite* coin;
    SDL_Texture* text;
    SDL_Texture* clickToGoText;
    int screenWidth;
    int screenHeight;

};

#endif // TITLESCREEN_H
