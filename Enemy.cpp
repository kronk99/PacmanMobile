//
// Created by huevitoentorta on 27/04/23.
//

#include "Enemy.h"

Enemy::Enemy(const char* texture,SDL_Renderer *renders , int velocidad) {
    this->render =renders;
    enemySkin=textureLoader::getTextureloader()->Loadtexture(texture , render);
    //SDL_Surface* p= IMG_Load(texture);
    //playerSkin= SDL_CreateTextureFromSurface(render , p);
    //SDL_FreeSurface(p); CAMBIE all this
    posx=552;
    posy=288;
    velocity = velocidad;

}
void Enemy::Update(){
    //aca habria que hacer un if, por si las imagenes de los 4 fantasmas distintos
    //son de pixeles distintos

    //posx+=1; //esto es lo que debe de cambiarse al leer el arduino
    //posy+=1;//esto es lo que debe de cambiarse al leer el arduino
    origen.x=0; //centro de la imagen
    origen.y=0;//centro de la imagen
    origen.h=63; //tamaño y de la imagen
    origen.w=79; //tamaño x de la imagen
//las imagenes empiezan ancho x alto , tener cuidado con esto
    destino.x=posx; //esto deberia ser igual a la posx posy , el height y w se mantienen
    destino.y=posy;//hasta donde mover la imagen
    destino.h=24;//reescalado de la imagen(la disminuye a 64 pixeles)
    destino.w=24;

}
void Enemy::renderEnemy() {
    SDL_RenderCopy(render,enemySkin,&origen,&destino);
}

void Enemy::moveEnemy() {
    switch (direction) {
        case 1:
            moverUp();
            break;
        case 2:
            moverDown();
            break;
        case 3:
            moverLeft();
            break;
        case 4:
            moverRight();
            break;
        default:
           cout<<"no me quiero mover"<<endl;
           break;
    }
}

void Enemy::moverRight() {
    posx+=velocity;
}

void Enemy::moverLeft() {
    posx-=velocity;
}

void Enemy::moverUp() {
    posy-=velocity;
}

void Enemy::moverDown() {
    posy+=velocity;
}

void Enemy::changeDirection(int number) {
    this->direction = number;
}
int Enemy::getY(){
    return posy;
}
int Enemy::getX(){
    return posx;
}
int Enemy::getDirection(){
    return this->direction;
}
