#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL2/SDL_image.h>

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

};

#endif // SPRITE_H
