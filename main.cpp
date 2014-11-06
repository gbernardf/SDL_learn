#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
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
    SDL_Surface* sol = NULL;
    SDL_Surface* up = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Init error ! SDL_Error: %s\n", SDL_GetError());
    } else {
        SDL_Event event;
        //create window
        window = toolbox.createWindow("SDL Game learn");
        int imgFlags = IMG_INIT_PNG;
        IMG_Init(imgFlags);
        if (window == NULL) {
            printf("Window could not be created! SDL_Error:%s\n", SDL_GetError());
        } else {

            string backPath = IMG_PATH + "back.bmp";
            string playerPath = IMG_PATH + "_carreGob.bmp";
            string solPath = IMG_PATH + "sol.bmp";


            //get window surface
            screenSurface = SDL_GetWindowSurface(window);
            toolbox.setScreenSurface(screenSurface);

            player = toolbox.loadImage(playerPath);
            background = toolbox.loadImage(backPath);
            sol = toolbox.loadImage(solPath);
            up = toolbox.loadImage(IMG_PATH + "up.png");

            toolbox.applyImage(background,screenSurface,0,0);
            toolbox.applyImage(sol,screenSurface,0,0);
            toolbox.applyImage(player,screenSurface,304,160);
            toolbox.applyImage(up,screenSurface,304,110);

            SDL_UpdateWindowSurface(window);
            bool run = true;
            do{
                while(SDL_PollEvent(&event) != 0){
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
