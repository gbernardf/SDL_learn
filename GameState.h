#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SDL2/SDL.h>
#include "functions.h"

class GameState
{
public:
    GameState();
    void init();
    void render();
    void update();

    void setRenderer(SDL_Renderer* renderer);
    void setToolbox(functions* toolbox);
protected:
    SDL_Renderer* renderer;
    functions* toolbox;

};

#endif // GAMESTATE_H
