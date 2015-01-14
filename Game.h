#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameState.h"
#include <vector>
#include <sstream>
#include "functions.h"
#include "Sprite.h"
#include "TitleScreen.h"

const string COINPATH = "../FILES/imgs/anim_coin_colorKey.png";
const string PALYERPATH = "../FILES/imgs/anim_colorKey.png";
const int COINS_NUMBER = 40;

class Game : public GameState
{
public:
    Game(int width, int height);
    ~Game();
    bool update();
    void render();
    void init();
    bool handleEvent(SDL_Event *event);
    void setTitleScren(TitleScreen* screen);
    bool gameDone();
    void reset();
private:

    int screenWidth;
    int screenHeight;
    vector<Sprite*> coins;
    Sprite* player;
    SDL_Texture* scoreText;
    TitleScreen* titleScreen;

    int score;
    bool won;

    void renderScore();
    void renderWon();

    void initCoins();
    void initPlayer();


};

#endif // GAME_H
