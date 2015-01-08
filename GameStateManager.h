#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <SDL2/SDL.h>
#include "functions.h"
#include "GameState.h"
#include "Game.h"
#include "TitleScreen.h"

class GameStateManager
{
public:
    GameStateManager();
    ~GameStateManager();
    void run();
    void setUp(SDL_Renderer* renderer,functions* toolbox);
    void setSizes(int width, int height);
    void popBack();
private:
    SDL_Renderer* renderer;
    functions* toolbox;

    int width;
    int height;

    Game *game;
    TitleScreen *titleScreen;
    bool running;

    std::vector<GameState*> states;
};

#endif // GAMESTATEMANAGER_H
