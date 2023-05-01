//
// Created by huevitoentorta on 30/04/23.
//

#ifndef PACMANMOBILE_SCORE_H
#define PACMANMOBILE_SCORE_H
#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"
#include "textureLoader.h"
#include <string>
using namespace std;

class Score {
private :
    int currentScore;
    SDL_Renderer *render;
    SDL_Color Color;
    SDL_Color Color2;
    TTF_Font *font;
    SDL_Texture *texture;
    SDL_Rect destino;

public :
    Score(SDL_Renderer *render);
    bool is200();
    void renderSCore();
    void scoreOne(int number);
};


#endif //PACMANMOBILE_SCORE_H
