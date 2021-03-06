#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <list>

using namespace std;

class functions {
public:
    functions(int width, int height);
    functions(const functions& orig);
    void setRenderer(SDL_Renderer* renderer);
    void setFont(string fontPath);
    //virtual ~functions();

    SDL_Surface* loadImage(string imagePath);
    SDL_Texture* loadTexture(string imagePath);
    SDL_Texture* loadTextureFromText(string text, SDL_Color textColor);
    void applyImage(SDL_Surface* src, SDL_Surface* dest, int x, int y);
    void applyScaledImage(SDL_Surface* src, SDL_Surface* dest,SDL_Rect* stretchRect);
    SDL_Window* createWindow(string windowName);
    void setScreenSurface(SDL_Surface* screen);
    void renderTexture(SDL_Texture* texture, SDL_Rect *srcPortion, int x, int y);
    void changeAlpha(SDL_Texture* texture, Uint8 newAlpha);
    void cleanSurfaces();

private:
    int screenWidth;
    int screenHeight;
    SDL_Surface* screen;
    SDL_Renderer* renderer;
    list<SDL_Surface*> loadedSurfaces;
    list<SDL_Texture*> loadedTextures;
    TTF_Font* _font;

};

#endif	/* FUNCTIONS_H */
