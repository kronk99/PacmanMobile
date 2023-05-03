//
// Created by huevitoentorta on 18/03/23.
//

using namespace std;
#include "Game.h"
#include <iostream>
#include <random>

SDL_Rect Origen ,DEST ;
SDL_Texture *textures;
SDL_Event Game::evento;
Game::Game() {
}
void Game::init(const char *title, int posx, int posy, int width, int lenght, bool fullscreen) {
    //este if asegura que sdl se inicie bien
    int flags = 0;
    if(fullscreen == true){
        flags = SDL_WINDOW_FULLSCREEN; //si se pide el juego en fullscreen se pone
    }
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){//tal vez este if me jode la progra
        cout<<"se inicio bien la libreria SDL"<<endl;
        //debo de cambiar pos x posy a centrado por si no da buena imagen
        window = SDL_CreateWindow(title , posx , posy ,width ,lenght , flags);
        cout<<"ventana creada exitosamente"<<endl;
        renderer = SDL_CreateRenderer(window , -1, 0);
        SDL_SetRenderDrawColor(renderer, 0,0,0,0);
        //esto dice dibujele color encima a renderer, los colores 250,255,255,255
        isRunning = true;
    }
    else{
        cout<<"no se creo bien la ventana de juego"<<endl;
        isRunning = false;
    }
    //player = new Player("../textures/a.png",renderer);
    Map::getInstance()->insertRender(renderer);
    player = new Player("../Textures/player.png" , renderer);
    //enemigo = new Enemy("../Textures/slimerojo.png",renderer,1);
    //enemigo->changeDirection(3);
    enemigos = new enemyHndlr(renderer);
    score=new Score(renderer);
    enemigos->lvlup("../Textures/slimerojo.png");
    enemigos->lvlup("../Textures/slimeverde.png");
    enemigos->lvlup("../Textures/slimenaranja.png");
}
void Game::update() {
    //aca deberia de meterle un metodo que sea handle arduino, entonces
    //deberia de checkear aca el arduino, si retorna algo diferente de -10
    //que se meta al if, y le haga player->updatePos
    //ACTUALIZA LA POSICION Y MOVIMIENTO DE IMAGENES.
    //cout<<"metodo update"<<endl;
    player->Update();
    enemigos->moveallEnemies();
    enemigos->updateallEnemies();
    //enemigo->move();
    //enemigo->Update();
    //PnEcollision();
    //playerMappos();
    //verifyCollision();
    //verifyCollision();
    //Mapa->loadMap() //esto mas adelante va a cambiar el arraytype;
}
void Game::render() {
    /* render, a lo que entiendo que hace, es como un tazon donde se añaden cosas
     * ese "tazon" de cosas para renderizar , las presenta como una imagen completa
     * por lo que entiendo no lo "redibuja " por encima, de ahi el render clear
     * limpia lo que tiene ese tazon y render present, presenta en pantalla lo que
     * contenga render*/
    //renderer es la ventana
    SDL_RenderClear(renderer);
    //donde lo quiero poner, que poner, rectangulo de la imagen(si usar un recorte
    // o la imagen completa), rectangulo donde
    //ponerlo en la pantala
    //SDL_RenderCopy(renderer,textures,NULL,NULL);
    //aca es cuando le ponemos cosas a render, para que renderize en pantalla,
    //player->renderAll();
    Map::getInstance()->renderMap();
    player->renderAll();
    enemigos->renderallEnemies();
    //enemigo->renderEnemy();
    score->renderSCore();
    //Mapa->renderOne();
    SDL_RenderPresent(renderer);

}
//codigo funcional ahora por alguna razon
//el codigo me dice cuando hay colision ,cuando ya esta dentro de la casilla
//no antes de colisionar, por lo que ese caso se debe de valorar
//pienso que lo mejor es que se mueva con el
void Game::eventHandler() { //no funciona de momento bien
    //funcion que maneja eventos
    //SDL_PollEvent(&evento); //investigar que hace esto
    while(SDL_PollEvent(&evento)){
        if(evento.type == SDL_QUIT || evento.type == SDL_WINDOWEVENT_CLOSE){
            isRunning = false;
        }
        /*el siguiente codigo es un tipo de approach creado por mi persona
         * el detalle esta en que no se si con colisiones servia, en el video
         * de ejemplos de manejador de ejemplos en vez de decirle que mueva 1 pixel
         * al jugador, el jugador siempre se mueve ,pero el codigo es multiplicado
         * por una velocidad, si la flecha se presiona la velocidad es x en una direccion
         * y si la tecla no esta hacia arriba (keyup) pone la velocidad en 0, probar ese
         * approach si el codigo no funciona con colisones.*/
        if(evento.type==SDL_KEYDOWN){
            switch (evento.key.keysym.sym) {
                case SDLK_w:
                    player->moverUp();
                    if(verifyCollision(player->getX() , player->getY())==true){
                        player->moverDown();
                        break;
                    }
                    if(verifyCollision(player->getX()+24 , player->getY())==true){
                        player->moverDown();
                        break;
                    }
                    player->sumposyCounter();
                    playerMappos();
                    break;
                case SDLK_a:
                    player->moverLeft();
                    if(verifyCollision(player->getX() , player->getY())==true){
                        player->moverRight();
                        break;
                    }
                    if(verifyCollision(player->getX() , player->getY()+24)==true){
                        player->moverRight();
                        break;
                    }
                    player->sumposCounter();
                    playerMappos();
                    break;
                case SDLK_d:
                    //CODIGO FUNCIONAL DE MOMENTO.
                    player->moverRight(); //no se por que es 16 el que sirve.
                    if(verifyCollision(player->getX()+24 , player->getY())==true){
                        player->moverLeft();
                        break;
                    }
                    if(verifyCollision(player->getX()+24 , player->getY()+24)==true){
                        player->moverLeft();
                        break;
                    }
                    player->sumposCounter();
                    playerMappos();
                    break;
                case SDLK_s:
                    //Codigo funcional
                    player->moverDown(); //modifique esto para colisiones abajo
                    if(verifyCollision(player->getX() , player->getY()+24)==true){
                        player->moverUp();
                        break;
                    }
                    if(verifyCollision(player->getX()+24 , player->getY()+24)==true){
                        player->moverUp();
                        break;
                    }
                    player->sumposyCounter();
                    playerMappos();
                    break;
            }
        }
    }
}
void Game::clean() { //limpia la screen , cuando el juego termina.
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout<<"el juego se ha limpiado"<<endl;
}
bool Game::running() {
    /*
    if(Fases->wincon() !=0){
        return isRunning;
    }
    else{
        return false;
    }*/
    return isRunning;
}
bool Game::verifyCollision(int x , int y){
    //this is wall collision with player;
    //hay que hacer un if para verificar que no sea una pared
    if(Map::getInstance()->getMapa(y/32,x/32)==2){
        cout<<"entre donde hay colision"<<endl;
        return true;
    }
    else{
        cout<<"no hay colision"<<endl;
        return false;
    }
}//this code is ok.
void Game::playerMappos() {
    if(player->checkCOunter()==true && player->checkyCounter()==true){
      cout<<"ESTOY en una casilla"<<endl;
      if(Map::getInstance()->getMapa(player->getY()/32,player->getX()/32)==1){
          score->scoreOne(10);
          Map::getInstance()->changeMap(player->getY()/32,player->getX()/32,0);
      }

      player->setALlposfalse();
    }
}//colision entre jugador y enemigos
//voy a documentar las colisiones por ahora, arreglarlo despues implementando
//colisiones para todos los enemigos.
/*
void Game::PnEcollision(){
    if(SDL_HasIntersection(player->getRect() , enemigo->getRect())){
        cout<<"EL FANTASMA SE COME AL JUGADOR"<<endl;
    }
}*/
