//
// Created by huevitoentorta on 08/04/23.
//

#ifndef PROYECTO1_A_D2_PLAYER_H
#define PROYECTO1_A_D2_PLAYER_H
#include <SDL2/SDL.h>
#include "textureLoader.h"
#include <iostream>
#include <random>
#include "Map.h"

class Player {
private:
    int posx;
    int posy;
    SDL_Texture* playerSkin;
    SDL_Texture* playerpowerSkin;
    SDL_Rect origen , destino;
    SDL_Renderer* render;
    int posCounter;
    int posyCounter;
    Uint32 powerTimer ;


public:
    Player(const char* texture , SDL_Renderer* renders);
    void Update();
    void renderAll();
    SDL_Rect*  getRect();

    void moverRight();

    void moverLeft();

    void moverDown();

    void moverUp();

    int getY();
    int getX();
    void sumposCounter();
    bool checkCOunter();
    void sumposyCounter();
    bool checkyCounter();
    void setALlposfalse();
    void startimerCount();
    bool checktimerCount();
    void respawn();

};


#endif //PROYECTO1_A_D2_PLAYER_H
