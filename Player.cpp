//
// Created by huevitoentorta on 08/04/23.
//

#include "Player.h"
Player::Player(const char* texture , SDL_Renderer* renders) {
    render = renders;
    playerSkin=textureLoader::getTextureloader()->Loadtexture(texture , render);
    //SDL_Surface* p= IMG_Load(texture);
    //playerSkin= SDL_CreateTextureFromSurface(render , p);
    //SDL_FreeSurface(p); CAMBIE all this
    posx=96;
    posy=96;
//EL JUGADOR DEBE DE MOVERSE EN MULTIPLOS DE 32 PIXELES
}
void Player::Update() {
    //posx+=1; //esto es lo que debe de cambiarse al leer el arduino
    //posy+=1;//esto es lo que debe de cambiarse al leer el arduino
    origen.x=0; //centro de la imagen
    origen.y=0;//centro de la imagen
    origen.h=290; //tamaño y de la imagen
    origen.w=193; //tamaño x de la imagen
//las imagenes empiezan ancho x alto , tener cuidado con esto
    destino.x=posx; //esto deberia ser igual a la posx posy , el height y w se mantienen
    destino.y=posy;//hasta donde mover la imagen
    destino.h=32;//reescalado de la imagen(la disminuye a 64 pixeles)
    destino.w=32;
}
void Player::renderAll() {
    SDL_RenderCopy(render,playerSkin,&origen,&destino);
}
SDL_Rect*  Player::getRect(){
    return &destino;
}