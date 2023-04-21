//
// Created by huevitoentorta on 08/04/23.
//

#ifndef PROYECTO1_A_D2_TEXTURELOADER_H
#define PROYECTO1_A_D2_TEXTURELOADER_H
#include <SDL2/SDL_image.h>

using namespace std;
class textureLoader {
private:
    SDL_Surface *tempo;
    static textureLoader* pointer;
public:
    SDL_Texture *Loadtexture(const char* filename,SDL_Renderer *render);
    static textureLoader* getTextureloader();
    textureLoader();
};


#endif //PROYECTO1_A_D2_TEXTURELOADER_H
