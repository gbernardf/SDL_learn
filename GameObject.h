#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Sprite.h"

class GameObject
{
public:
    GameObject();

private:
    Sprite sprite;
    int _posX;
    int _posY;
};

#endif // GAMEOBJECT_H
