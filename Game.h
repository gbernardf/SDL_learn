#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameState.h"
#include <vector>
#include <sstream>
#include "functions.h"
#include "Sprite.h"

const string COINPATH = "../FILES/imgs/anim_coin_colorKey.png";
const string PALYERPATH = "../FILES/imgs/anim_colorKey.png";
const int COINS_NUMBER = 15;

class Game : public GameState
{
public:
    Game(int width, int height);
    void update();
    void render();
    void init();
    void handleEvent(SDL_Event *event);
    bool gameDone();
    void reset();
private:

    int screenWidth;
    int screenHeight;
    SDL_Renderer* renderer;
    vector<Sprite*> coins;
    Sprite* player;
    functions* toolbox;
    SDL_Texture* scoreText;

    int score;

    void renderScore();

    void initCoins();
    void initPlayer();

};

#endif // GAME_H
