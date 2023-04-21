//
// Created by huevitoentorta on 20/04/23.
//

#include "Map.h"
//esto de abajo es el gamemap, desde aca se crea el mapa, con 1 como comida, 2 como obstaculo
//0 como celda vacia sin nada
//ESTE MAPA ES UN MAPA GLOBAL, AKA VARIABLE GLOBAL.
int lvl1[20][20]={
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,0,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
};//constructor de la clase , solicita a texture loader las texturas correspondientes
//de esta clase.
Map::Map(SDL_Renderer *renderers) {
    renderer = renderers;
    comida=textureLoader::getTextureloader()->Loadtexture("../Textures/food.png", renderer);
    pared =textureLoader::getTextureloader()->Loadtexture("../Textures/wall.png", renderer);
//aca deberia de haber un switch que me diga
//ok level 3, misma funcionalidad, entonces meta mapa lvl1.
    loadMap(lvl1);
    origen.x=0;
    origen.y=0;
    origen.h=139;
    origen.w=153;
    origen2.x=0;
    origen2.y=0;
    destino.x=0;
    destino.y=0;
    destino.h=16;//height
    destino.w=16;//width
    origen2.h=186;
    origen2.w=173;
    destino2.x=0;
    destino2.y=0;
    destino2.h=32;//height
    destino2.w=32;//width
    //si no sirve tengo que hacer 2 rectangulos uno para comida y otro para pared
    //para asi poder decirles el height y el weight.
}

void Map::loadMap(int array[20][20]) {
    for(int row=0;row < 20;row++){
        for(int colum=0;colum<20;colum++){
            mapa[row][colum]=array[row][colum];
        }
    }
    cout<<"la posicion 1 es:"<<mapa[0][0]<<endl;
}
void Map::changeMap(int fila,int col, int valtoChange){
    mapa[fila][col] =valtoChange;
}

void Map::renderMap() {
    int type=0;
    for(int row=0;row < 20;row++){
        for(int colum=0;colum<20;colum++){
            type = mapa[row][colum];
            destino.x=colum*32;
            destino.y=row*32;
            destino2.x=colum*32;
            destino2.y=row*32;
            switch (type) {
                case 0:
                    break;
                case 1:
                    SDL_RenderCopy(renderer,comida,&origen,&destino);
                    break;
                case 2:
                    SDL_RenderCopy(renderer,pared,&origen2,&destino2);
                    break;
                default:
                    break;
            }
        }
    }
    cout<<"se renderiza el mapa0"<<endl;
}
void Map::renderOne(){
    SDL_RenderCopy(renderer,pared,&origen,&destino);
}
