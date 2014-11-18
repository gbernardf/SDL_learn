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
    SDL_Texture* keyTextures[KEY_PRESS_SURFACE_TOTAL];

    Uint8 alpha = 0;

    //Render window
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_Surface* screenSurface = NULL;
    SDL_Texture* playerTex = NULL;

    SDL_Rect topRightViewPort;
    SDL_Rect topLeftViewPort;
    SDL_Rect bottomViewPort;
    SDL_Rect totalViewPort;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Init error ! SDL_Error: %s\n", SDL_GetError());
    } else {
        SDL_Event event;

        topLeftViewPort.x = 0;
        topLeftViewPort.y = 0;
        topLeftViewPort.w = SCREEN_WIDTH / 2;
        topLeftViewPort.h = 100;

        topRightViewPort.x = SCREEN_WIDTH / 2;
        topRightViewPort.y = 0;
        topRightViewPort.w = SCREEN_WIDTH / 2;
        topRightViewPort.h = 100;

        bottomViewPort.x = 0;
        bottomViewPort.y = 100;
        bottomViewPort.w = SCREEN_WIDTH;
        bottomViewPort.h = SCREEN_HEIGHT - 100;

        totalViewPort.x = 0;
        totalViewPort.y = 0;
        totalViewPort.w = SCREEN_WIDTH;
        totalViewPort.h = SCREEN_HEIGHT;

        window = toolbox.createWindow("SDL Game learn");
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0x00);
        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_ADD);
        int imgFlags = IMG_INIT_PNG;
        IMG_Init(imgFlags);
        if (window == NULL) {
            printf("Window could not be created! SDL_Error:%s\n", SDL_GetError());
        } else {

            string backPath = IMG_PATH + "back.png";
            string playerPath = IMG_PATH + "_carreGob.png";
            string upPath = IMG_PATH + "up_colorKey.png";
            string lftPath = IMG_PATH + "lft_colorKey.png";
            string riPath = IMG_PATH + "ri_colorKey.png";
            string dwPath = IMG_PATH + "dw_colorKey.png";

            screenSurface = SDL_GetWindowSurface(window);
            toolbox.setScreenSurface(screenSurface);

            playerTex = toolbox.loadTexture(playerPath,renderer);

            keyTextures[KEY_PRESS_SURFACE_DEFAULT] = toolbox.loadTexture(backPath,renderer);
            keyTextures[KEY_PRESS_SURFACE_UP] = toolbox.loadTexture(upPath,renderer);
            keyTextures[KEY_PRESS_SURFACE_LEFT] = toolbox.loadTexture(lftPath,renderer);
            keyTextures[KEY_PRESS_SURFACE_RIGHT] = toolbox.loadTexture(riPath,renderer);
            keyTextures[KEY_PRESS_SURFACE_DOWN] = toolbox.loadTexture(dwPath,renderer);


            bool run = true;
            do{
                while(SDL_PollEvent(&event) != 0){
                    SDL_RenderClear(renderer);
                    SDL_RenderSetViewport(renderer,&totalViewPort);

                    toolbox.renderTexture(keyTextures[KEY_PRESS_SURFACE_DEFAULT],renderer,0,0);

                    int playerX = 304;
                    int playerY = 50;
                    if(event.type == SDL_QUIT){
                        run = false;
                    }
                    else if(event.type == SDL_KEYDOWN){
                        if(event.key.keysym.sym == SDLK_a){
                            if(alpha - 32 <0){
                                alpha =0;
                            }else{
                                alpha -= 32;
                            }
                        }
                        if(event.key.keysym.sym == SDLK_q){
                            if(alpha + 32 > 255){
                                alpha =255;
                            }else{
                                alpha += 32;
                            }
                        }
                        SDL_SetTextureAlphaMod( playerTex, alpha );
                        SDL_RenderSetViewport(renderer,&topRightViewPort);
                        switch(event.key.keysym.sym){

                            case SDLK_UP:
                            toolbox.renderTexture(keyTextures[KEY_PRESS_SURFACE_UP],renderer,150,25);
                            SDL_RenderSetViewport(renderer,&bottomViewPort);
                            toolbox.renderTexture(playerTex,renderer,playerX ,playerY - 10);break;

                            case SDLK_DOWN:
                            toolbox.renderTexture(keyTextures[KEY_PRESS_SURFACE_DOWN],renderer,150,25);
                            SDL_RenderSetViewport(renderer,&bottomViewPort);
                            toolbox.renderTexture(playerTex,renderer,playerX,playerY + 10);break;

                            case SDLK_LEFT:
                            toolbox.renderTexture(keyTextures[KEY_PRESS_SURFACE_LEFT],renderer,150,25);
                            SDL_RenderSetViewport(renderer,&bottomViewPort);
                            toolbox.renderTexture(playerTex,renderer,playerX - 10,playerY);break;

                            case SDLK_RIGHT:
                            toolbox.renderTexture(keyTextures[KEY_PRESS_SURFACE_RIGHT],renderer,150,25);
                            SDL_RenderSetViewport(renderer,&bottomViewPort);
                            toolbox.renderTexture(playerTex,renderer,playerX + 10,playerY);break;

                        }

                    }else{
                        SDL_RenderSetViewport(renderer,&bottomViewPort);
                        toolbox.renderTexture(playerTex,renderer,playerX,playerY);

                    }
                    SDL_RenderPresent(renderer);
                }
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
