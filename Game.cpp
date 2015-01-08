#include "Game.h"
#include <stdlib.h>



Game::Game(int width, int height){
    screenWidth = width;
    screenHeight = height;
    score = 0;
}

Game::~Game(){
    delete player;
}

void Game::init(){
    initCoins();
    initPlayer();
}

void Game::initCoins(){
    SDL_Texture* coin = toolbox->loadTexture(COINPATH);
    int x,y;
    for(int i=0; i< COINS_NUMBER; i++){
        Sprite* coinX = new Sprite(32,32,renderer);
        x = rand()%screenWidth;
        y = rand()%screenHeight;
        coinX->updateTexture(coin);
        coinX->setIdleAnimation();
        coinX->setPos(x,y);
        coins.push_back(coinX);
    }
}

void Game::initPlayer(){
    SDL_Texture* playerText = toolbox->loadTexture(PALYERPATH);
    player = new Sprite(64,64, renderer);
    player->setBoundaries(screenWidth, screenHeight);
    player->updateTexture(playerText);
    player->loadAnimations();
    player->setPos(screenWidth/2 - player->width()/2, screenHeight/2 - player->height()/2);

}

bool Game::handleEvent(SDL_Event* event){
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(event) != 0){
        if(event->type == SDL_KEYDOWN){
            if(event->key.keysym.sym == SDLK_ESCAPE){
                states->push_back(titleScreen);
                return true;
            }
        }
    }
    if(currentKeyStates[SDL_SCANCODE_W]){
        player->moveUp();
    }else if(currentKeyStates[SDL_SCANCODE_S]){
        player->moveDown();
    }else if(currentKeyStates[SDL_SCANCODE_A]){
        player->moveLeft();
    }else if(currentKeyStates[SDL_SCANCODE_D]){
        player->moveRight();
    }
    return false;
}

bool Game::gameDone(){
    return coins.empty();
}

void Game::setTitleScren(TitleScreen *screen){
    titleScreen = screen;
}

bool Game::update(){
    int playerX = 32;
    int playerY = 32;
    player->getPos(&playerX,&playerY);
    vector<Sprite*> updatedCoins;
    for(int i = 0;i<coins.size();i++){
        if(coins.at(i)->hit(playerX,playerY)){
            //delete coins.at(i);
            score++;
            continue;
        }
        coins.at(i)->idle();
        updatedCoins.push_back(coins.at(i));
    }

    coins = updatedCoins;
    return false;
}
void Game::render(){
    SDL_RenderClear(renderer);
    renderScore();
    player->render(1);
    std::vector<Sprite*>::const_iterator it = coins.begin();
    std::vector<Sprite*>::const_iterator end = coins.end();
    while(it!=end){
        (*it)->render(1);
        it++;
    }
}

void Game::renderScore(){
    SDL_Color textColor = {255,255,255,1};
    stringstream scoreString;
    scoreString.str("");
    scoreString << "Score: "<< COINS_NUMBER - coins.size();
    scoreText = toolbox->loadTextureFromText(scoreString.str().c_str(),textColor);
    toolbox->renderTexture(scoreText,NULL,10,10);
}

void Game::reset(){
    player->setPos(screenWidth/2 - player->width()/2, screenHeight/2 - player->height()/2);
    SDL_Texture* coin = toolbox->loadTexture(COINPATH);
    for(int i=0; i< COINS_NUMBER; i++){
        Sprite* coinX = new Sprite(32,32,renderer);
        int x = rand()%screenWidth;
        int y = rand()%screenHeight;
        coinX->updateTexture(coin);
        coinX->setIdleAnimation();
        coinX->setPos(x,y);
        coins.push_back(coinX);
    }
}
