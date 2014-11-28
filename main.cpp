#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "functions.h"
#include "Sprite.h"


const string IMG_PATH = "../FILES/imgs/";

enum KeyPressSurfaces{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_TOTAL
};

int main(int argc, char* argv[]) {

    if(argc <= 1){
        std::cout<<"Arguments missing: WIDTH |  HEIGHT" <<std::endl;
    }

    const int SCREEN_WIDTH = atoi(argv[1]);
    const int SCREEN_HEIGHT = atoi(argv[2]);
    std::cout<< "SCREEN_WIDTH : " << SCREEN_WIDTH << std::endl;
    std::cout<< "SCREEN_HEIGHT: " << SCREEN_HEIGHT << std::endl;
    functions toolbox(SCREEN_WIDTH, SCREEN_HEIGHT);

    //Render window
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Surface* screenSurface = NULL;

    SDL_Rect totalViewPort;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Init error ! SDL_Error: %s\n", SDL_GetError());
    } else {

        SDL_Event event;

        totalViewPort.x = 0;
        totalViewPort.y = 0;
        totalViewPort.w = SCREEN_WIDTH;
        totalViewPort.h = SCREEN_HEIGHT;

        window = toolbox.createWindow("SDL Game learn");
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0x00);
        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_ADD);
        int imgFlags = IMG_INIT_PNG;

        IMG_Init(imgFlags);
        if (window == NULL) {
            printf("Window could not be created! SDL_Error:%s\n", SDL_GetError());
        } else {

            screenSurface = SDL_GetWindowSurface(window);
            toolbox.setScreenSurface(screenSurface);

            bool run = true;
            do{

                while(SDL_PollEvent(&event) != 0){
                    SDL_RenderClear(renderer);
                    SDL_RenderSetViewport(renderer,&totalViewPort);
                    if(event.type == SDL_QUIT){
                        run = false;
                    }else if(event.type == SDL_KEYDOWN){

                        switch(event.key.keysym.sym){
                            case SDLK_ESCAPE:
                            run = false;break;
                        }

                    }else{
                    }
                    SDL_RenderPresent(renderer);
                    SDL_Delay(40);
                }
                SDL_RenderPresent(renderer);
                SDL_Delay(40);

            }while(run);
        }

    }

    toolbox.cleanSurfaces();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}
