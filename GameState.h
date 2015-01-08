#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SDL2/SDL.h>
#include "functions.h"
#include <vector>

class GameState
{
public:
    GameState();
    void setRenderer(SDL_Renderer* renderer);
    void setToolbox(functions* toolbox);
    void setStatesVector(std::vector<GameState*> *states);
    void init();
    virtual void render();
    virtual bool update();
    virtual bool handleEvent(SDL_Event* event);
protected:
    SDL_Renderer* renderer;
    functions* toolbox;
    std::vector<GameState*> *states;
};

#endif // GAMESTATE_H
