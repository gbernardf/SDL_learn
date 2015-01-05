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
    Sprite(int animWidth, int animHeight, SDL_Renderer* renderer);
    int width();
    int height();
    SDL_Texture* getText();
    SDL_Rect* currentFrame();
    void updateTexture(SDL_Texture* newTexture);
    void loadAnimations();
    void setIdleAnimation();
    void render(double scale);
    void setPos(int x, int y);
    void idle();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool hit(int x, int y);
    void setBoundaries(int w, int h);
    void getPos(int*x,int*y);
    ~Sprite();
private:
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    int _width;
    int _height;
    int moveDistance;
    int frameNumber;
    int animationFrameWidth;
    int animationFrameHeight;
    int posX;
    int posY;
    int screenHeight;
    int screenWidth;

    SDL_Rect* moveDownAnimation[ANIMATION_FRAMES];
    SDL_Rect* moveLeftAnimation[ANIMATION_FRAMES];
    SDL_Rect* moveRightAnimation[ANIMATION_FRAMES];
    SDL_Rect* moveUpAnimation[ANIMATION_FRAMES];
    SDL_Rect* idleAnimation[8];

    SDL_Rect* _currentAnimFrame;


};

#endif // SPRITE_H
