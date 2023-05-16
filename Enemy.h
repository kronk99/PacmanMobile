//
// Created by huevitoentorta on 27/04/23.
//

#ifndef PACMANMOBILE_ENEMY_H
#define PACMANMOBILE_ENEMY_H
#include <SDL2/SDL.h>
#include "textureLoader.h"
#include <iostream>
#include "Map.h"
#include "pathfindingA.h"
class Enemy {
private:
    int posx;
    int posy;
    SDL_Texture* enemySkin;
    SDL_Rect origen , destino;
    SDL_Renderer* render;
    int direction; //vector director , auxiliar que define en que sentido de movimiento
    //el enemigo debe de ir
    int velocity; //
    int countx; //contador x para verificar si esta dentro de una casilla
    int county; //contador y para verificar si esta dentro de una casilla
    int paths;
    int route[3]; //areglo de seleccion de rutas aleatorias
    Pila *pila; //pila cuando
    bool flag; //bandera que le indica al enemigo cuando puede moverse por pathfinding
    int type; //tipo de movimiento, backtracking o pathfinding.
    int number; //tamaño de la pila del movimiento por pathfinding
    //es un verificador que me dice si la pila es 0,muevase normal, si hay algo
    //en la pila muevase por pathfinding.
    Uint32 respawnTimer ; //contador del timer de espera;

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
    void setFLag(bool flag); //seteador de bandera para pathfinding.
    void deletePila();
    void specialMove(int x, int y); //movimiento por pathfinding
//DOWN BELOW IS WHEN THE ENEMY HAS BEEN EATEN BY THE PLAYER...
    void startimerCount(int number);
    bool checktimerCount();
    void respawn();

};


#endif //PACMANMOBILE_ENEMY_H
