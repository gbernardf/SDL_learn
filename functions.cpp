#include "functions.h"

#include <string>

using namespace std;

functions::functions(int width, int height) {
    screenWidth = width;
    screenHeight = height;
}

//load an image file into a SDL_Surface pointer and returns it
//can return a NULL pointer if the path is wrong.
SDL_Surface* loadImage(string imagePath){
    SDL_Surface* loadedImage = SDL_LoadBMP(imagePath.c_str());
    //SDL_Surface* optimizedImage = NULL;
    if(loadedImage == NULL){
        cout<<"Cant load image: " + imagePath + ".\n";
    }

    return loadedImage;
}
