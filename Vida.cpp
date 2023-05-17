//
// Created by huevitoentorta on 03/05/23.
//

#include "Vida.h"

Vida::Vida(SDL_Renderer *renderers) { //x = 192
    this->renderer = renderers;
    texture = textureLoader::getTextureloader()->Loadtexture("../Textures/vida.png",renderer);
    vida=3;
    Origen.x=0;
    Origen.y=0;
    Origen.h=152;
    Origen.w=173;
    destino.x=0;
    destino.y=0;
    destino.h=32;
    destino.w=32;
}

short Vida::getVida() {
    return this->vida;
}

void Vida::reduceVida() {
    if (vida<0){
        vida = 0;
    }
    else{
        vida--;
    }
}

void Vida::renderAll() {
    for(int i=0;i<vida;i++){
        destino.x = 192 + (i*32);
        SDL_RenderCopy(renderer ,texture, &Origen,&destino);
    }
}

void Vida::setvida() {
    vida++;
}

