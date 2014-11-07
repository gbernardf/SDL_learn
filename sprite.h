#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL2/SDL_image.h>

using namespace std;

class sprite
{
public:
    sprite(string filepath);
    int width();
    int height();
    void updateTexture(string filepath);
    ~sprite();
private:
    SDL_Texture* texture;
    int _width;
    int _height;
};

#endif // SPRITE_H
