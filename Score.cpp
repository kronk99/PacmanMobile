//
// Created by huevitoentorta on 30/04/23.
//

#include "Score.h"
//creo que tengo que hacer el score singleton
bool Score::is200() {
    if(countScore==200){
        cout<<"es 200!!"<<endl;
        countScore=0;
        return true;
    }else{
        return false;
    }

}

Score::Score(SDL_Renderer *renders) {
    TTF_Init();
    font = TTF_OpenFont("../assets/Pixeltype.ttf" ,30);
    //TTF_Quit(); //Usar esto cuando se cierra el juego. no aca
    this->render = renders;
    this->currentScore =0;
    countScore=0;
    Color = {255,255,255,255};
    Color2 = {0,0,0,0};
    destino.x = 128;
    destino.y= 0;
    destino.h = 32;
    destino.w = 32;
//el H y el w se deben de multiplicar por la cantidad de digitos
//que haya en el juego
}

void Score::renderSCore() {
    //to_string(currentScore).c_str()
    SDL_Surface *surface = TTF_RenderText_Solid(font ,to_string(currentScore).c_str(), Color);
    texture =SDL_CreateTextureFromSurface(render,surface);
    free(surface);
    SDL_RenderCopy(render,texture,nullptr,&destino);
    //free(texture); este free daña el programa, espero que al no hacer free texture
    //no hayan memory leaks
}

void Score::scoreOne(int number) {
    currentScore+=number;
    countScore+=number;

}

void Score::spawnPower() {
    //optimizar es poniendo en un array a la hora de crear el gamemap
    //las casillas que no sean obstaculos y aca, con un random de el poder.
    bool spawngood = false;
    while(spawngood ==false){
        random_device rd, dd;
        std::uniform_int_distribution<int> randomx(0, 21);
        std::uniform_int_distribution<int> randomy(0, 21);
        int randomNum = randomx(rd);
        int randomNum2 = randomy(dd);
        if(Map::getInstance()->getMapa(randomNum,randomNum2)!=2 &&Map::getInstance()->getMapa(randomNum,randomNum2)!=3){
            spawngood =true;
            powerX = randomNum;
            powerY=randomNum2;
            Map::getInstance()->setpowerpos(randomNum,randomNum2);
        }
    }
    cout<<"EL X DEL SCORE es "<<powerX<<endl;
    cout<<"EL Y DEL SCORE es"<<powerY<<endl;
}

int Score::getpowerX() {
    return powerX;
}

int Score::getpowerY() {
    return powerY;
}
