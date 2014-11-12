#include "Sprite.h"
#include "functions.h"

Sprite::Sprite()
{
    _width = 0;
    _height = 0;
    texture = NULL;
}

int Sprite::width(){
	return _width;
}

int Sprite::height(){
	return _height;
}
