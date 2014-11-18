#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL2/SDL_image.h>
#include <list>

using namespace std;

class Sprite
{
public:
    Sprite();
    int width();
    int height();
    void updateTexture(SDL_Texture* newTexture);
    ~Sprite();
private:
    SDL_Texture* texture;
    int _width;
    int _height;
    SDL_Rect idleAnimation[4];
    SDL_Rect moveAnimation[4];


};

#endif // SPRITE_H
