#include "functions.h"

#include <string>

using namespace std;

functions::functions(int width, int height) {
    screenWidth = width;
    screenHeight = height;
}

//load an image file into a SDL_Surface pointer and returns it
//can return a NULL pointer if the path is wrong.
SDL_Surface* functions::loadImage(string imagePath){
    SDL_Surface* loadedImage = SDL_LoadBMP(imagePath.c_str());
    //SDL_Surface* optimizedImage = NULL;
    if(loadedImage == NULL){
        cout<<"Cant load image: " + imagePath + ".\n";
    }

    return loadedImage;
}


SDL_Window *functions::createWindow(string windowName){
    return SDL_CreateWindow(windowName.c_str(),
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            screenWidth,
                            screenHeight,
                            SDL_WINDOW_SHOWN
                            );
}

void functions::applyImage(SDL_Surface* src, SDL_Surface* dest, int x, int y){
    SDL_Rect position;
    position.x = x;
    position.y = y;
    SDL_BlitSurface(src,NULL,dest,&position);
}
