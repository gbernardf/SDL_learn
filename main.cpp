#include <SDL2/SDL.h>
#include <stdio.h>
#include "functions.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 400;

int main(int argc, char* argv[]) {

    functions toolbox(SCREEN_WIDTH, SCREEN_HEIGHT);

    //Render window
    SDL_Window* window = NULL;

    //the surface contained by the window
    SDL_Surface* screenSurface = NULL;
    SDL_Surface* background = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Init error ! SDL_Error: %s\n", SDL_GetError());
    } else {

        //create window
        window = SDL_CreateWindow("SDL tut 01",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN
                                  );
        if (window == NULL) {
            printf("Window could not be created! SDL_Error:%s\n", SDL_GetError());
        } else {

            string path = "/home/gui/CODE/SDL/SDL_GAME_1/FILES/imgs/back.bmp";
            background = SDL_LoadBMP(path.c_str());

            background = toolbox.loadImage(path);
            if(background == NULL)
                std::cout<<"SDL_LoadBMP failed." <<std::endl;
            //get window surface
            screenSurface = SDL_GetWindowSurface(window);
            SDL_BlitSurface(background, NULL, screenSurface, NULL);

            SDL_UpdateWindowSurface(window);

            SDL_Delay(2000);
        }

    }

    //destroy window
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
