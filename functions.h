#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

using namespace std;

class functions {
public:
    functions(int width, int height);
    functions(const functions& orig);
    //virtual ~functions();

    SDL_Surface* loadImage(string imagePath);
    void applyImage(SDL_Surface* src, SDL_Surface* dest, int x, int y);
    SDL_Window* createWindow(string windowName);

private:
    int screenWidth;
    int screenHeight;

};

#endif	/* FUNCTIONS_H */
