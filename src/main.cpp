#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "functions.h"
#include "GameStateManager.h"

int main(int argc, char* argv[]) {

    int SCREEN_WIDTH = 800;
    int SCREEN_HEIGHT = 600;

    if(argc > 1){
        const int SCREEN_WIDTH = atoi(argv[1]);
        const int SCREEN_HEIGHT = atoi(argv[2]);
        std::cout<< "SCREEN_WIDTH : " << SCREEN_WIDTH << std::endl;
        std::cout<< "SCREEN_HEIGHT: " << SCREEN_HEIGHT << std::endl;
    }


    functions toolbox(SCREEN_WIDTH, SCREEN_HEIGHT);

    //Render window
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;


    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Init error ! SDL_Error: %s\n", SDL_GetError());
    } else {

        window = toolbox.createWindow("SDL Game learn");
        if (window == NULL) {
            printf("Window could not be created! SDL_Error:%s\n", SDL_GetError());
        } else {
            int imgFlags = IMG_INIT_PNG;
            IMG_Init(imgFlags);
            TTF_Init();
            renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
            SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0x00);
            SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_ADD);
            toolbox.setRenderer(renderer);

            SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
            toolbox.setScreenSurface(screenSurface);
            toolbox.setFont("/usr/share/cups/fonts/FreeMonoBold.ttf");

            GameStateManager manager;
            manager.setUp(renderer,&toolbox);
            manager.setSizes(SCREEN_WIDTH,SCREEN_HEIGHT);

            manager.run();

        }

    }
    toolbox.cleanSurfaces();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}
