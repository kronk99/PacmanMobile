//
// Created by huevitoentorta on 03/05/23.
//

#ifndef PACMANMOBILE_VIDA_H
#define PACMANMOBILE_VIDA_H
#include <SDL2/SDL.h>
#include "textureLoader.h"
class Vida {
private:
    short vida;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Rect Origen,destino;
public:
    Vida(SDL_Renderer *renderer);
    short getVida();
    void reduceVida();
    void renderAll();
    void setvida(); //para la endgamescreen.
};


#endif //PACMANMOBILE_VIDA_H
