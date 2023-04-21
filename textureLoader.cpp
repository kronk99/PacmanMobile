//
// Created by huevitoentorta on 08/04/23.
//

#include "textureLoader.h"
textureLoader* textureLoader::pointer= nullptr;
textureLoader::textureLoader() {
}

textureLoader *textureLoader::getTextureloader() {
    if (pointer == nullptr) {
        pointer = new textureLoader();
        return pointer;
    } else {
        return pointer;
    }
}
SDL_Texture* textureLoader::Loadtexture(const char *filename, SDL_Renderer *render) {
   /* string image = "../textures/a.png";
    string image2 = "../textures/Spaceship.png";
    SDL_Surface* temp= IMG_Load(image2.c_str());
    SDL_Surface* p= IMG_Load(image.c_str());
    texture = SDL_CreateTextureFromSurface(renderer , temp);
    textures = SDL_CreateTextureFromSurface(renderer , p);
    SDL_FreeSurface(temp);
    SDL_FreeSurface(p);*/
    tempo= IMG_Load(filename);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(render,tempo);
    SDL_FreeSurface(tempo);
    return texture;
}