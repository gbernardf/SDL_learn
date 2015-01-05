#include "TitleScreen.h"

TitleScreen::TitleScreen(int width, int height){
    screenWidth = width;
    screenHeight = height;
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
}

void TitleScreen::render(){
    toolbox->renderTexture(back,NULL,0,0);
    coin->idle();
    coin->render(1);
    toolbox->renderTexture(text,NULL,10,10);
    toolbox->renderTexture(clickToGoText,NULL,10,350);
}

bool TitleScreen::hit(){
    int x,y;
    SDL_GetMouseState(&x,&y);
    return coin->hit(x,y);
}
