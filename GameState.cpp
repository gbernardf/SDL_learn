#include "GameState.h"

GameState::GameState()
{
}

void GameState::setRenderer(SDL_Renderer *renderer){
    this->renderer = renderer;
}

void GameState::setToolbox(functions *toolbox){
    this->toolbox = toolbox;
}

void GameState::init(){
}
