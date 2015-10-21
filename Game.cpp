#include "Game.h"
#include <stdlib.h>



Game::Game(int width, int height):
screenWidth(width),
screenHeight(height),
coins(),
player(NULL),
scoreText(NULL),
titleScreen(NULL),
score(0),
won(false)
{
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
        x = rand()%(screenWidth-coinX->width());
        y = rand()%(screenHeight-coinX->height());
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
            SDL_Keycode key = event->key.keysym.sym;
            if( key == SDLK_ESCAPE){
                states->push_back(titleScreen);
                return true;
            }
            if(won){
                if(key == SDLK_n){
                    states->push_back(titleScreen);
                    return true;
                }
                if(key == SDLK_y){
                    reset();
                    return true;
                }
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
    if(gameDone())won = true;
    int playerX = 32;
    int playerY = 32;
    player->getPos(&playerX,&playerY);
    vector<Sprite*> updatedCoins;
    for(int i = 0;i<coins.size();i++){
        if(coins.at(i)->hit(playerX,playerY)){
            score++;
            continue;
        }
        coins.at(i)->idle();
        updatedCoins.push_back(coins.at(i));
    }
    coins.clear();
    coins = updatedCoins;
    return false;
}
void Game::render(){
    SDL_RenderClear(renderer);
    SDL_Rect fillRect = { 0, 0 ,screenWidth, screenHeight};
    SDL_SetRenderDrawColor( renderer, 50, 50, 50, 0xFF );
    SDL_RenderFillRect( renderer, &fillRect );
    if(won){
        renderWon();
    }else{
        renderScore();
    }
    std::vector<Sprite*>::const_iterator it = coins.begin();
    std::vector<Sprite*>::const_iterator end = coins.end();
    while(it!=end){
        (*it)->render(1);
        it++;
    }
    player->render(1);
}


void Game::renderScore(){
    SDL_Color textColor = {255,255,255,1};
    stringstream scoreString;
    scoreString.str("");
    scoreString << "Score: "<< COINS_NUMBER - coins.size();
    scoreText = toolbox->loadTextureFromText(scoreString.str().c_str(),textColor);
    toolbox->renderTexture(scoreText,NULL,10,10);
}

void Game::renderWon(){
    SDL_Color textColor = {255,0,0,1};
    string youWin = "You win !!!     RESET ?   y/n";
    scoreText = toolbox->loadTextureFromText(youWin,textColor);
    toolbox->renderTexture(scoreText,NULL,10,10);

}

void Game::reset(){
    player->setPos(screenWidth/2 - player->width()/2, screenHeight/2 - player->height()/2);
    won = false;
    SDL_Texture* coin = toolbox->loadTexture(COINPATH);
    for(int i=0; i< COINS_NUMBER; i++){
        Sprite* coinX = new Sprite(32,32,renderer);
        int x = rand()%(screenWidth-coinX->width());
        int y = rand()%(screenHeight-coinX->height());
        coinX->updateTexture(coin);
        coinX->setIdleAnimation();
        coinX->setPos(x,y);
        coins.push_back(coinX);
    }
}
