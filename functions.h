#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <list>

using namespace std;

class functions {
public:
    functions(int width, int height);
    functions(const functions& orig);
    //virtual ~functions();

    SDL_Surface* loadImage(string imagePath);
    void applyImage(SDL_Surface* src, SDL_Surface* dest, int x, int y);
    void applyScaledImage(SDL_Surface* src, SDL_Surface* dest,SDL_Rect* stretchRect);
    SDL_Window* createWindow(string windowName);
    void setScreenSurface(SDL_Surface* screen);
    void cleanSurfaces();

private:
    int screenWidth;
    int screenHeight;
    SDL_Surface* screen;
    list<SDL_Surface*> loadedSurfaces;

};

#endif	/* FUNCTIONS_H */
