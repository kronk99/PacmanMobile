//
// Created by huevitoentorta on 20/04/23.
//

#ifndef PACMANMOBILE_MAP_H
#define PACMANMOBILE_MAP_H
#include <SDL2/SDL.h>
#include "textureLoader.h"
#include <iostream>

class Map {
private:
    SDL_Renderer *renderer;
    SDL_Rect origen,destino;
    SDL_Rect origen2,destino2;
    SDL_Texture *pared;
    SDL_Texture *comida;
    int mapa[30][40];
public:
    Map(SDL_Renderer *renderer);
//falta un deconstructor
    void loadMap(int array[30][40]);
    void renderMap();
    //int mapa[20][20];

    void changeMap(int fila, int col, int valtoChange);

    void renderOne();

    SDL_Rect* getRect2();

    void setX(int a, int b);

    int getMapa(int a, int b);
};


#endif //PACMANMOBILE_MAP_H
