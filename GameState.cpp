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

void GameState::setStatesVector(std::vector<GameState*> *states){
    this->states = states;
}

void GameState::render(){

}

bool GameState::update(){

}

bool GameState::handleEvent(SDL_Event *event){

}
