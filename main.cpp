#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "functions.h"
#include "Sprite.h"
#include <sstream>
#include "Game.h"


const string IMG_PATH = "../FILES/imgs/";

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



    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Init error ! SDL_Error: %s\n", SDL_GetError());
    } else {

        SDL_Event event;
        window = toolbox.createWindow("SDL Game learn");
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0x00);
        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_ADD);
        toolbox.setRenderer(renderer);
        int imgFlags = IMG_INIT_PNG;

        SDL_Rect totalViewPort;
        totalViewPort.x = 0;
        totalViewPort.y = 0;
        totalViewPort.w = SCREEN_WIDTH;
        totalViewPort.h = SCREEN_HEIGHT;
        bool gameTitle = true;



        IMG_Init(imgFlags);
        TTF_Init();
        if (window == NULL) {
            printf("Window could not be created! SDL_Error:%s\n", SDL_GetError());
        } else {

            screenSurface = SDL_GetWindowSurface(window);
            toolbox.setScreenSurface(screenSurface);
            toolbox.setFont("/usr/share/cups/fonts/FreeMonoBold.ttf");

            Game game(SCREEN_WIDTH,SCREEN_HEIGHT);
            game.setRenderer(renderer);
            game.setToolbox(&toolbox);
            game.init();


            Sprite* coin = new Sprite(32,32,renderer);
            coin->updateTexture(toolbox.loadTexture(IMG_PATH + "anim_coin_colorKey.png"));
            coin->setIdleAnimation();
            coin->setPos((SCREEN_WIDTH/2 - coin->width()/2),(SCREEN_HEIGHT/2- coin->height()/2));

            SDL_Texture* back = toolbox.loadTexture(IMG_PATH + "back.png");
            Uint8 r = 255;
            Uint8 g = 1;
            Uint8 b = 1;
            SDL_Color textColor = {r,g,b,1};
            SDL_Texture* text = toolbox.loadTextureFromText("Coin Looter 1.0",textColor);
            SDL_Texture* clickToGoText = toolbox.loadTextureFromText("Clic coin to launch the game",textColor);

            bool run = true;
            Uint32 startTime = SDL_GetTicks();
            string timu = "Time since start: ";
            SDL_Texture* timeText = NULL;
            stringstream fullTimeString;
            do{
                SDL_RenderClear(renderer);
                SDL_RenderSetViewport(renderer,&totalViewPort);
                if(gameTitle){
                    while(SDL_PollEvent(&event) != 0){

                        if(event.type == SDL_QUIT){
                            run = false;
                        }else if(event.type == SDL_KEYDOWN){

                            switch(event.key.keysym.sym){
                            case SDLK_ESCAPE:
                                run = false;break;
                            }

                        }else if(event.type == SDL_MOUSEBUTTONDOWN){
                            int x,y;
                            SDL_GetMouseState(&x,&y);
                            if(coin->hit(x,y)){
                                gameTitle = false;
                            }

                        }
                    }
                }else{
                    game.handleEvent(&event);
                }
                toolbox.renderTexture(back,NULL,0,0);
                if(gameTitle){
                    coin->idle();
                    coin->render(1);
                    toolbox.renderTexture(text,NULL,10,10);
                    toolbox.renderTexture(clickToGoText,NULL,10,350);
                }else{
                    game.update();
                    game.render();
                    if(game.gameDone()){
                        gameTitle = true;
                        game.reset();
                    }
                }
//                fullTimeString.str("");
//                fullTimeString << timu << (SDL_GetTicks() - startTime);
//                timeText = toolbox.loadTextureFromText(fullTimeString.str().c_str(),textColor);
//                toolbox.renderTexture(timeText,NULL,10,350);
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
