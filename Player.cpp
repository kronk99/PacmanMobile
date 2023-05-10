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
    posx=64;
    posy=64;
    posCounter=0;
    posyCounter=0;
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
    //la imagen la agarra desde la esquina superior izquierda , es decir x=0,y=0
    //a eso se le suman 32 para hacer el ancho y largo
}
void Player::renderAll() {
    SDL_RenderCopy(render,playerSkin,&origen,&destino);
}
void Player::moverRight(){
    posx+=16;
    cout<<posx<<endl;
}
void Player::moverLeft(){
    posx-=16; //esto debe ser un multiplo o submultiplo del valor al que se
    //reescalan las imagenes , para este caso 24, ese multiplo o submultiplo es la
    //velocidad, en el checkeador de colisiones , la cantidad que suma es el doble
    //de la velocidad, si no, es un valor fijo encontrado de manera a prueba y error
    //asumo que tendra alguna relacion con el re-escalado de la imagen , para este caso
    //re-escalado 24- suma en colisiones =16
    //confirmado , probe con 8 4 y 12 como velocidades , por lo tanto esto es util
    //para el movimiento de los fantasmas, velocidades disponibles entonces ; 4,8,12
}
void Player::moverUp(){
    posy-=16;
}
void Player::moverDown(){
    posy+=16;
    cout<<posy<<endl;
}
SDL_Rect*  Player::getRect(){
    return &destino;
}
int Player::getX(){
    //cout<<"el X es"<<posx<<endl;
    return this->posx;
}
int Player::getY(){
    return this->posy;
}

void Player::sumposCounter() {
    posCounter++;
    //cout<<"se sumo posx"<<endl;
}
bool Player::checkCOunter() {
    if(posCounter%2==0){ //esto es 2 por que el jugador se mueve 12 pixeles, 12+12 24
        //2 veces 24, entonces el contador es 2 para decir que ya esta dentro de una
        //celda y no por encima.
        return true;

    }
    else{
        return false;
    }
}
void Player::sumposyCounter() {
    posyCounter++;
    //cout<<"se sumo posy"<<endl;
}
bool Player::checkyCounter() {
    if(posyCounter %2 ==0){ //esto es 2 por que el jugador se mueve 12 pixeles, 12+12 24
        //2 veces 24, entonces el contador es 2 para decir que ya esta dentro de una
        //celda y no por encima.
        return true;
    }
    else{
        return false;
    }
}

void Player::setALlposfalse() {
    posCounter=0;
    posyCounter=0;
}
