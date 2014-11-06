#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "functions.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 400;
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

    functions toolbox(SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Surface* keySurfaces[KEY_PRESS_SURFACE_TOTAL];

    //Render window
    SDL_Window* window = NULL;

    //the surface contained by the window
    SDL_Surface* screenSurface = NULL;
    SDL_Surface* background = NULL;
    SDL_Surface* player = NULL;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
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
            string upPath = IMG_PATH + "up.png";
            string lftPath = IMG_PATH + "lft.png";
            string riPath = IMG_PATH + "ri.png";
            string dwPath = IMG_PATH + "dw.png";


            //get window surface
            screenSurface = SDL_GetWindowSurface(window);
            toolbox.setScreenSurface(screenSurface);

            player = toolbox.loadImage(playerPath);
            background = toolbox.loadImage(backPath);
            keySurfaces[KEY_PRESS_SURFACE_UP] = toolbox.loadImage(upPath);
            keySurfaces[KEY_PRESS_SURFACE_LEFT] = toolbox.loadImage(lftPath);
            keySurfaces[KEY_PRESS_SURFACE_RIGHT] = toolbox.loadImage(riPath);
            keySurfaces[KEY_PRESS_SURFACE_DOWN] = toolbox.loadImage(dwPath);



            bool run = true;
            do{
                while(SDL_PollEvent(&event) != 0){
                    toolbox.applyImage(background,screenSurface,0,0);
                    toolbox.applyImage(player,screenSurface,304,160);
                    if(event.type == SDL_QUIT){
                        run = false;
                    }else if(event.type == SDL_KEYDOWN){

                        switch(event.key.keysym.sym){
                            case SDLK_UP:
                            toolbox.applyImage(keySurfaces[KEY_PRESS_SURFACE_UP],screenSurface,304,110);break;

                            case SDLK_DOWN:
                            toolbox.applyImage(keySurfaces[KEY_PRESS_SURFACE_DOWN],screenSurface,304,200);break;

                            case SDLK_LEFT:
                            toolbox.applyImage(keySurfaces[KEY_PRESS_SURFACE_LEFT],screenSurface,254,160);break;

                            case SDLK_RIGHT:
                            toolbox.applyImage(keySurfaces[KEY_PRESS_SURFACE_RIGHT],screenSurface,354,160);break;

                        }

                    }
                    SDL_UpdateWindowSurface(window);
                }
            }while(run);
        }

    }

    toolbox.cleanSurfaces();
    //destroy window
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
