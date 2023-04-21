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
public:
    Map(SDL_Renderer *renderer);
//falta un deconstructor
    void loadMap(int array[20][20]);
    void renderMap();
    int mapa[20][20];

    void changeMap(int fila, int col, int valtoChange);

    void renderOne();
};


#endif //PACMANMOBILE_MAP_H
