#include "functions.h"

#include <string>

using namespace std;

functions::functions(int width, int height):
  screenWidth(width),
  screenHeight(height),
  screen(NULL),
  renderer(NULL),
  loadedSurfaces(),
  loadedTextures(),
  _font(NULL)
{
}

void functions::setScreenSurface(SDL_Surface* screen){
    this->screen = screen;
}

void functions::setRenderer(SDL_Renderer* renderer){
    this->renderer = renderer;
}

void functions::setFont(string fontPath){
    _font = TTF_OpenFont( fontPath.c_str(), 40 );
}//#include <SDL2/SDL_image.h>

SDL_Surface* functions::loadImage(string imagePath){
    SDL_Surface* loadedImage = IMG_Load(imagePath.c_str());
    SDL_Surface* optimizedImage = NULL;
    if(loadedImage == NULL){
        cout<<"Cant load image: " + imagePath + ".\n";
    }else{
        optimizedImage = SDL_ConvertSurface(loadedImage,screen->format,0);//NULL
        SDL_SetColorKey( optimizedImage, SDL_TRUE, SDL_MapRGB( optimizedImage->format, 0xFF, 0x00, 0xFF ) );
        SDL_FreeSurface(loadedImage);
    }
    loadedSurfaces.push_back(optimizedImage);
    return optimizedImage;
}

SDL_Texture* functions::loadTexture(string imagePath){
    SDL_Surface* loadedImage = loadImage(imagePath);
    SDL_Texture* loadedTexture = SDL_CreateTextureFromSurface(renderer,loadedImage);
    loadedTextures.push_back(loadedTexture);
    return loadedTexture;
}

SDL_Texture* functions::loadTextureFromText(string text, SDL_Color textColor){
    SDL_Surface* textSurface = TTF_RenderText_Solid( _font, text.c_str(), textColor );
    SDL_Texture* loadedTexture = SDL_CreateTextureFromSurface(renderer,textSurface);
    SDL_FreeSurface( textSurface );
    loadedTextures.push_back(loadedTexture);
    return loadedTexture;
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

void functions::applyScaledImage(SDL_Surface *src, SDL_Surface *dest, SDL_Rect *stretchRect){
    SDL_BlitScaled(src,NULL,dest,stretchRect);
}

void functions::renderTexture(SDL_Texture *texture, SDL_Rect* srcPortion, int x, int y){
    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    SDL_QueryTexture(texture,NULL,NULL,&destRect.w,&destRect.h);
    while(destRect.w+destRect.x > screenWidth){
        destRect.w = destRect.w -10;
    }

    SDL_RenderCopy(renderer,texture,srcPortion,&destRect);
}

void functions::changeAlpha(SDL_Texture* texture, Uint8 newAlpha){
    SDL_SetTextureAlphaMod( texture, newAlpha );
}

void functions::cleanSurfaces(){
    while(!loadedSurfaces.empty()){
        SDL_FreeSurface(loadedSurfaces.front());
        loadedSurfaces.pop_front();
    }
    while(!loadedTextures.empty()){
        SDL_DestroyTexture(loadedTextures.front());
        loadedTextures.pop_front();
    }
}
