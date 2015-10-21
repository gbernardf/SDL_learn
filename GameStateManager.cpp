#include "GameStateManager.h"

GameStateManager::GameStateManager():
renderer(NULL),
toolbox(NULL),
width(0),
height(0),
game(NULL),
titleScreen(NULL),
running(false),
states()
{
}

void GameStateManager::setUp(SDL_Renderer *renderer, functions *toolbox){
    this->renderer = renderer;
    this ->toolbox = toolbox;
}

GameStateManager::~GameStateManager(){
    delete game;
    delete titleScreen;
}

void GameStateManager::setSizes(int width, int height){
    this->width = width;
    this->height = height;
}

void GameStateManager::popBack(){
    states.pop_back();
}

void GameStateManager::run(){

    SDL_Event event;
    Uint32 time = SDL_GetTicks();

    running = true;
    game = new Game(width,height);
    game->setRenderer(renderer);
    game->setToolbox(toolbox);
    game->setStatesVector(&states);
    game->init();

    titleScreen = new TitleScreen(width,height);
    titleScreen->setRenderer(renderer);
    titleScreen->setToolbox(toolbox);
    titleScreen->setStatesVector(&states);
    titleScreen->init();

    game->setTitleScren(titleScreen);

    states.push_back(game);
    states.push_back(titleScreen);

    bool pop = false;
    GameState* currentState;
    while(running && !states.empty()){
        pop = false;
        SDL_RenderClear(renderer);
        currentState = states.back();
        currentState->handleEvent(&event);
        currentState->update();
        currentState->render();
        SDL_RenderPresent(renderer);
        SDL_Delay(40);
    }

}
