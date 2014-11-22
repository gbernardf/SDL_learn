#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Sprite.h"

class GameObject
{
public:
    GameObject();
    void render();

private:
    SDL_Renderer* renderer;
    Sprite* sprite;
    int _posX;
    int _posY;
    Uint8 alpha;
    bool isColider;
};

#endif // GAMEOBJECT_H
