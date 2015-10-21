#include "TitleScreen.h"

TitleScreen::TitleScreen(int width, int height):
  back(NULL),
  coin(NULL),
  text(NULL),
  clickToGoText(NULL),
  escToEsc(NULL),
  screenWidth(width),
  screenHeight(height)
{
}

TitleScreen::~TitleScreen(){
    delete coin;
}

void TitleScreen::init(){
    coin = new Sprite(32,32,renderer);
    coin->updateTexture(toolbox->loadTexture(IMG_PATH + "anim_coin_colorKey.png"));
    coin->setIdleAnimation();
    coin->setPos((screenWidth/2 - coin->width()/2),(screenHeight/2- coin->height()/2));

    back = toolbox->loadTexture(IMG_PATH + "back.png");
    Uint8 r = 255;
    Uint8 g = 1;
    Uint8 b = 1;
    SDL_Color textColor = {r,g,b,1};
    text = toolbox->loadTextureFromText("Coin Looter 1.0",textColor);
    clickToGoText = toolbox->loadTextureFromText("Clic coin to launch the game",textColor);
    escToEsc = toolbox->loadTextureFromText("ESCAPE to quit.",textColor);
}

bool TitleScreen::update(){
    coin->idle();
    return false;
}

void TitleScreen::render(){

    //toolbox->renderTexture(back,NULL,0,0);
    SDL_Rect fillRect = { 0, 0 ,screenWidth, screenHeight};
    SDL_SetRenderDrawColor( renderer, 50, 50, 50, 0xFF );
    SDL_RenderFillRect( renderer, &fillRect );
    coin->render(1);
    toolbox->renderTexture(text,NULL,10,10);
    toolbox->renderTexture(clickToGoText,NULL,10,325);
    toolbox->renderTexture(escToEsc,NULL,10,360);
}

bool TitleScreen::hit(){
    int x,y;
    SDL_GetMouseState(&x,&y);
    return coin->hit(x,y);
}

bool TitleScreen::handleEvent(SDL_Event* event){
    //const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(event) != 0){
        if(event->type == SDL_KEYDOWN){
            if(event->key.keysym.sym == SDLK_ESCAPE){
                states->clear();
            }
        }
        if(event->type == SDL_MOUSEBUTTONDOWN){
            if(hit()){
                states->pop_back();
            }
        }
    }
    return false;
}
