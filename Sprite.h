#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL2/SDL_image.h>
#include <list>

using namespace std;

const int ANIMATION_FRAMES = 4;

class Sprite
{
public:
    Sprite();
    Sprite(int animWidth, int animHeight);
    int width();
    int height();
    void updateTexture(SDL_Texture* newTexture);
    void loadAnimations();
    void setIdleAnimation();
    void render( SDL_Renderer* renderer, int posX, int posY);
    void idle();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    ~Sprite();
private:
    SDL_Texture* texture;
    int _width;
    int _height;
    int frameNumber;
    int animationFrameWidth;
    int animationFrameHeight;

    //By convention we'll build sprite sheets like this:
    // move down row
    // move left row
    // move right row
    // move up row
    // no idle animation for now
    SDL_Rect* moveDownAnimation[ANIMATION_FRAMES];
    SDL_Rect* moveLeftAnimation[ANIMATION_FRAMES];
    SDL_Rect* moveRightAnimation[ANIMATION_FRAMES];
    SDL_Rect* moveUpAnimation[ANIMATION_FRAMES];
    SDL_Rect* idleAnimation[8];

    SDL_Rect* _currentAnimFrame;


};

#endif // SPRITE_H
