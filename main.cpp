#include <SDL2/SDL.h>
#include <stdio.h>
#include "functions.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 400;
const string IMG_PATH = "../FILES/imgs/";

int main(int argc, char* argv[]) {

    functions toolbox(SCREEN_WIDTH, SCREEN_HEIGHT);

    //Render window
    SDL_Window* window = NULL;

    //the surface contained by the window
    SDL_Surface* screenSurface = NULL;
    SDL_Surface* background = NULL;
    SDL_Surface* player = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Init error ! SDL_Error: %s\n", SDL_GetError());
    } else {
        SDL_Event event;
        //create window
        window = toolbox.createWindow("SDL Game learn");
        if (window == NULL) {
            printf("Window could not be created! SDL_Error:%s\n", SDL_GetError());
        } else {

            string backPath = IMG_PATH + "back.bmp";
            string playerPath = IMG_PATH + "_carreGob.bmp";

            //background = SDL_LoadBMP(path.c_str());
            player = toolbox.loadImage(playerPath);
            background = toolbox.loadImage(backPath);
            if(background == NULL)
                std::cout<<"SDL_LoadBMP failed." <<std::endl;
            //get window surface
            screenSurface = SDL_GetWindowSurface(window);
            toolbox.applyImage(background,screenSurface,0,0);
            toolbox.applyImage(player,screenSurface,304,160);

            SDL_UpdateWindowSurface(window);
            bool run = true;
            do{
                while(SDL_PollEvent(&event)){
                    if(event.type == SDL_QUIT)
                        run = false;
                }
            }while(run);
        }

    }

    //destroy window
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
