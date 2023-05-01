//
// Created by huevitoentorta on 27/04/23.
//

#ifndef PACMANMOBILE_ENEMY_H
#define PACMANMOBILE_ENEMY_H
#include <SDL2/SDL.h>
#include "textureLoader.h"
#include <iostream>
#include "Map.h"

class Enemy {
private:
    int posx;
    int posy;
    SDL_Texture* enemySkin;
    SDL_Rect origen , destino;
    SDL_Renderer* render;
    int direction;
    int velocity;
    int countx;
    int county;
    int paths;
    int route[3];
public:
    Enemy(const char* texture,SDL_Renderer* renders ,int velocidad);
    void renderEnemy();
    void moveEnemy();
    void moverRight();

    void moverLeft();

    void moverDown();

    void moverUp();
    void changeDirection(int number);

    void Update();

    int getY();

    int getX();

    int getDirection();
    void move();

    bool checkCounterx();

    bool checkCountery();

    void checkSurround();
    SDL_Rect* getRect();
};


#endif //PACMANMOBILE_ENEMY_H
