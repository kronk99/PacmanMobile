//
// Created by huevitoentorta on 30/04/23.
//

#ifndef PACMANMOBILE_SCORE_H
#define PACMANMOBILE_SCORE_H
#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"
#include "textureLoader.h"
#include <string>
#include <random>
#include "Map.h"
using namespace std;

class Score {
private :
    int currentScore;
    int countScore;
    SDL_Renderer *render;
    SDL_Color Color;
    SDL_Color Color2;
    TTF_Font *font;
    SDL_Texture *texture;
    SDL_Rect destino;
    int powerX;
    int powerY;

public :
    Score(SDL_Renderer *render);
    bool is200();
    void renderSCore();
    void scoreOne(int number);
    void spawnPower();
    int getpowerX();
    int getpowerY();
};


#endif //PACMANMOBILE_SCORE_H
