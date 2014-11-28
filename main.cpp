#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "functions.h"
#include "Sprite.h"
#include <sstream>

const string IMG_PATH = "../FILES/imgs/";

enum KeyPressSurfaces{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_TOTAL
};

void updateColors(int& r, int& g, int& b){
    if(r == 255 && g == 1 && b< 255){
        if(b+10 > 255){
            b=255;
        }else{
            b+=10;
        }

    }else if(b==255 && g == 1 && r >1){
        if(r-10 > 1){
            r = 1;
        }else{
            r-=10;
        }
    }else if(r == 1 && b == 255 && g < 255){
        if(g+10 > 255){
            g = 255;
        }else{
            g+=10;
        }
    }else if(r == 1 && g == 255 && b > 1){
        if(b-10<1){
            b = 1;
        }else{
            b-=10;
        }
    }else if(b == 1 && g == 255 && r < 255){
        if(r+10>255){
            r = 255;
        }else{
            r+=10;
        }
    }else if(r==255 && b ==1 && g > 1){
        if(g-10 < 1){
            g = 1;
        }else{
            g-=10;
        }
    }

}

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



        IMG_Init(imgFlags);
        TTF_Init();
        if (window == NULL) {
            printf("Window could not be created! SDL_Error:%s\n", SDL_GetError());
        } else {

            screenSurface = SDL_GetWindowSurface(window);
            toolbox.setScreenSurface(screenSurface);
            toolbox.setFont("/usr/share/cups/fonts/FreeMonoBold.ttf");
            Sprite* coin = new Sprite(32,32,renderer);
            coin->updateTexture(toolbox.loadTexture(IMG_PATH + "anim_coin_colorKey.png"));
            coin->setIdleAnimation();

            SDL_Texture* back = toolbox.loadTexture(IMG_PATH + "back.png");
            int r = 255;
            int g = 1;
            int b = 1;
            SDL_Color textColor = {0,0,0};
            SDL_Texture* text = toolbox.loadTextureFromText("Spin spin ! You devil coin from hell !!!",textColor);

            bool run = true;
            Uint32 startTime = SDL_GetTicks();
            string timu = "Time since start: ";
            SDL_Texture* timeText = NULL;
            stringstream fullTimeString;
            do{
                SDL_RenderClear(renderer);
                SDL_RenderSetViewport(renderer,&totalViewPort);
                while(SDL_PollEvent(&event) != 0){

                    if(event.type == SDL_QUIT){
                        run = false;
                    }else if(event.type == SDL_KEYDOWN){

                        switch(event.key.keysym.sym){
                            case SDLK_ESCAPE:
                            run = false;break;
                        }

                    }else{
                    }
                }
                toolbox.renderTexture(back,NULL,0,0);
                coin->idle();
                coin->render((SCREEN_WIDTH/2 - coin->width()),(SCREEN_HEIGHT/2- coin->height()),1);
                toolbox.renderTexture(text,NULL,10,10);
                fullTimeString.str("");
                fullTimeString << timu << (SDL_GetTicks() - startTime);
                timeText = toolbox.loadTextureFromText(fullTimeString.str().c_str(),textColor);
                toolbox.renderTexture(timeText,NULL,10,350);
//                updateColors(r,g,b);
//                textColor = {r,g,b};
//                text = toolbox.loadTextureFromText("Spin spin ! You devil coin from hell !!!",textColor);
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
