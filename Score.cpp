//
// Created by huevitoentorta on 30/04/23.
//

#include "Score.h"
//creo que tengo que hacer el score singleton
bool Score::is200() { //cambiar esto a modulo servira?
    if(countScore>=200){ //hacerlo mayor igual a 200 , para evaluar casos
        //donde el jugador consume a enemigos.
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
    destino.x = 128;
    destino.y= 0;
    destino.h = 32;
    destino.w = 32;
    //now for the power settings**************************************
    powerTexture = textureLoader::getTextureloader()->Loadtexture("../Textures/power.png",renders);
    //not getting right the texture. , mistake here.
    pDestino.h=32;
    pDestino.w=32;
    pDestino.x=32;
    pDestino.y=32;
    lvlDestino.x=32;
    lvlDestino.y=0;
    lvlDestino.h=32;
    lvlDestino.w=32;
    cout<<"la textura es"<<powerTexture<<endl;
    //pDestino.x=32;
    //pDestino.y=0;
    level=Map::getInstance()->getlvl();
    SDL_Surface *surface2 =TTF_RenderText_Solid(font ,to_string(level).c_str(), Color);
    lvlTexture =SDL_CreateTextureFromSurface(render,surface2);
    free(surface2);
    //el H y el w se deben de multiplicar por la cantidad de digitos
//que haya en el juego
}

void Score::renderSCore() {
    //to_string(currentScore).c_str()
    SDL_Surface *surface = TTF_RenderText_Solid(font ,to_string(currentScore).c_str(), Color);
    texture =SDL_CreateTextureFromSurface(render,surface);
    free(surface);
    SDL_RenderCopy(render,texture,nullptr,&destino);
    SDL_RenderCopy(render,lvlTexture,nullptr,&lvlDestino);
    //free(texture); este free daña el programa, espero que al no hacer free texture
    //no hayan memory leaks
}

void Score::scoreOne(int number) {
    currentScore+=number;
    countScore+=number;

}

void Score::spawnPower() { //this code needs to change.
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
    pDestino.x=powerY*32;
    pDestino.y=powerX*32;
}

int Score::getpowerX() {
    return powerX;
}

int Score::getpowerY() {
    return powerY;
}

void Score::renderAll() {
   renderSCore();
    if(ispowerAvailable==true){ //por que el render del poder lleva nullptr no tengo idea
        //verificar esto mas tarde, por alguna razon el screct es nulo aca.POSIBLE BUG.
        SDL_RenderCopy(render,powerTexture, nullptr,&pDestino);
        cout<<"existe poder"<<endl;
    }
}

void Score::setPowerstate(bool state) {
    this->ispowerAvailable = state;
}

void Score::setLevel() {
    level = Map::getInstance()->getlvl();
    SDL_Surface *surface2 =TTF_RenderText_Solid(font ,to_string(level).c_str(), Color);
    lvlTexture =SDL_CreateTextureFromSurface(render,surface2);
    free(surface2);
}