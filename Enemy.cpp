//
// Created by huevitoentorta on 27/04/23.
//

#include <random>
#include "Enemy.h"

Enemy::Enemy(const char* texture,SDL_Renderer *renders , int velocidad) {
    this->render =renders;
    enemySkin=textureLoader::getTextureloader()->Loadtexture(texture , render);
    //SDL_Surface* p= IMG_Load(texture);
    //playerSkin= SDL_CreateTextureFromSurface(render , p);
    //SDL_FreeSurface(p); CAMBIE all this
    posx=288;
    posy=256;
    velocity = velocidad;
    county=0;
    countx=0;

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
            county++;
            break;
        case 2:
            moverDown();
            county++;
            break;
        case 3:
            moverLeft();
            countx++;
            break;
        case 4:
            moverRight();
            county++;
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

void Enemy::move() { //mueve al jugador , debo de poner siempreel direction a la izquierda

    //si no esta encima de una casilla , sigase moviendo.
    if(checkCounterx() == true || checkCountery() == true){
        //cout<<"no estoy moviendome"<<endl;
        checkSurround();
        countx =0;
        county=0;
        random_device rd;
        std::uniform_int_distribution<int> randomx(0, paths-1);
        int randomNum = randomx(rd);
        direction = route[randomNum];
    }
    else{ //si esta encima de una casilla..
        moveEnemy();
    }
}
void Enemy::checkSurround(){ //checkea casillas al rededor;
    //aca hace aritmetica con x /32 y/32 para agarrar la casilla
    //luego verifica si x-1,y no es pared
    //el switch case debe de ser con direction , y debe de ser si la direccion
    //es 1 , 1 es muevase hacia arriba, entonces chekee todos excepto la casilla de
    //abajo., asi me aseguro que no se devuelva el fantasma, si o si devolver un
    //array de espacios disponibles.
    //usar un array estatico , si solo puedo poner 1 posicion ponga las demas como
    //dicha posicion , si no ponga el resto
    paths = 0;
    switch (direction) {
        case 1: //caso subi, vengo de abajo
            if(Map::getInstance()->getMapa(posy/32,(posx-32)/32)!=2){//move left
                route[paths] = 3;
                paths++;
            }
            if(Map::getInstance()->getMapa(posy/32,(posx+32)/32)!=2){//move right
                route[paths] = 4;
                paths++;
            }
            if(Map::getInstance()->getMapa((posy-32)/32,posx/32)!=2){//move up
                route[paths] = 1;
                paths++;
            }
            break;
        case 2: //caso vengo de arriba CODE OK
            if(Map::getInstance()->getMapa(posy/32,(posx-32)/32)!=2){//move left
                route[paths] = 3;
                paths++;
            }
            if(Map::getInstance()->getMapa(posy/32,(posx+32)/32)!=2){//move right
                route[paths] = 4;
                paths++;
            }
            if(Map::getInstance()->getMapa((posy+32)/32,posx/32)!=2){//move up
                route[paths] = 2;
                paths++;
            }
            break;
        case 3: //vengo de la derecha
            if(Map::getInstance()->getMapa((posy-32)/32,posx/32)!=2){//move up
                route[paths] = 1;
                paths++;
            }
            if(Map::getInstance()->getMapa(posy/32,(posx-32)/32)!=2){//move right
                route[paths] = 3;
                paths++;
            }
            if(Map::getInstance()->getMapa((posy+32)/32,posx/32)!=2){//move up
                route[paths] = 2;
                paths++;
            }
            break;
        case 4://vengo de la izquierda
            if(Map::getInstance()->getMapa(posy/32,(posx+32)/32)!=2){//move left
                route[paths] = 4;
                paths++;
            }
            if(Map::getInstance()->getMapa((posy-32)/32,posx/32)!=2){//move right
                route[paths] = 1;
                paths++;
            }
            if(Map::getInstance()->getMapa((posy+32)/32,posx/32)!=2){//move up
                route[paths] = 2;
                paths++;
            }

            break;
        default:
            cout<<"no me quiero mover"<<endl;
            break;
    }
}
bool Enemy::checkCounterx() {
    if(countx ==32){ //esto es 2 por que el jugador se mueve 12 pixeles, 12+12 24
        //2 veces 24, entonces el contador es 2 para decir que ya esta dentro de una
        //celda y no por encima.
        return true;

    }
    else{ //haga los counters 0
        return false;
    }
}
bool Enemy::checkCountery() {
    if(county ==32){ //esto es 2 por que el jugador se mueve 12 pixeles, 12+12 24
        //2 veces 24, entonces el contador es 2 para decir que ya esta dentro de una
        //celda y no por encima.
        return true;

    }
    else{
        return false;
    }
}

