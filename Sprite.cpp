#include "Sprite.h"
#include "functions.h"

Sprite::Sprite()
{
    _width = 0;
    _height = 0;
    texture = NULL;
    _currentAnimFrame = NULL;
    frameNumber = 0;
}

Sprite::Sprite(int animWidth, int animHeight, SDL_Renderer *renderer){
    _width = 0;
    _height = 0;
    texture = NULL;
    animationFrameHeight = animHeight;
    animationFrameWidth = animWidth;
    this->renderer = renderer;
    _currentAnimFrame = NULL;
    frameNumber = 0;
}

int Sprite::width(){
    return animationFrameWidth;
}

int Sprite::height(){
    return animationFrameHeight;
}

void Sprite::updateTexture(SDL_Texture* newTexture){
    texture = newTexture;
}

void Sprite::setIdleAnimation(){
    int i = 0;
    do{
        idleAnimation[i] = new SDL_Rect;
        idleAnimation[i]->x = i*animationFrameWidth;
        idleAnimation[i]->y = 0;
        idleAnimation[i]->w = animationFrameWidth;
        idleAnimation[i]->h = animationFrameHeight;
        i++;
    }while(i<8);
    _currentAnimFrame = idleAnimation[0];
}

void Sprite::loadAnimations(){
    int i = 0;
    do{
        moveDownAnimation[i] = new SDL_Rect;
        moveDownAnimation[i]->x = i*animationFrameWidth;
        moveDownAnimation[i]->y = 0;
        moveDownAnimation[i]->w = animationFrameWidth;
        moveDownAnimation[i]->h = animationFrameHeight;

        moveLeftAnimation[i] = new SDL_Rect;
        moveLeftAnimation[i]->x = i*animationFrameWidth;
        moveLeftAnimation[i]->y = animationFrameHeight;
        moveLeftAnimation[i]->w = animationFrameWidth;
        moveLeftAnimation[i]->h = animationFrameHeight;

        moveRightAnimation[i] = new SDL_Rect;
        moveRightAnimation[i]->x = i*animationFrameWidth;
        moveRightAnimation[i]->y = animationFrameHeight * 2;
        moveRightAnimation[i]->w = animationFrameWidth;
        moveRightAnimation[i]->h = animationFrameHeight;

        moveUpAnimation[i] = new SDL_Rect;
        moveUpAnimation[i]->x = i*animationFrameWidth;
        moveUpAnimation[i]->y = animationFrameHeight * 3;
        moveUpAnimation[i]->w = animationFrameWidth;
        moveUpAnimation[i]->h = animationFrameHeight;
        i++;
    }while(i<4);
    _currentAnimFrame = moveDownAnimation[0];
}

void Sprite::idle(){
    _currentAnimFrame = idleAnimation[frameNumber%8];
    frameNumber++;
    if(frameNumber > 40)frameNumber = 0;
}

void Sprite::moveUp(){
    _currentAnimFrame = moveUpAnimation[frameNumber%4];
    frameNumber++;
    if(frameNumber > 40)frameNumber = 0;
}

void Sprite::moveDown(){
    _currentAnimFrame = moveDownAnimation[frameNumber%4];
    frameNumber++;
    if(frameNumber > 40)frameNumber = 0;
}

void Sprite::moveLeft(){
    _currentAnimFrame = moveLeftAnimation[frameNumber%4];
    frameNumber++;
    if(frameNumber > 40)frameNumber = 0;
}

void Sprite::moveRight(){
    _currentAnimFrame = moveRightAnimation[frameNumber%4];
    frameNumber++;
    if(frameNumber > 40)frameNumber = 0;
}

void Sprite::render(int posX, int posY, double scale){
    SDL_Rect destRect;
    destRect.x = posX;
    destRect.y = posY;
    destRect.w = animationFrameWidth*scale;
    destRect.h = animationFrameHeight*scale;
    if(animationFrameWidth == 0 || animationFrameHeight == 0){
        SDL_QueryTexture(texture,NULL,NULL,&destRect.w,&destRect.h);
    }
    SDL_RenderCopy(renderer,texture,_currentAnimFrame,&destRect);
}

SDL_Texture* Sprite::getText(){
    return texture;
}

SDL_Rect* Sprite::currentFrame(){
    return _currentAnimFrame;
}
