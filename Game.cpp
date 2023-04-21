//
// Created by huevitoentorta on 18/03/23.
//

using namespace std;
#include "Game.h"
#include <iostream>
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
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        //esto dice dibujele color encima a renderer, los colores 250,255,255,255
        isRunning = true;
    }
    else{
        cout<<"no se creo bien la ventana de juego"<<endl;
        isRunning = false;
    }
    //player = new Player("../textures/a.png",renderer);
    Mapa = new Map(renderer);
    player = new Player("../Textures/player.png" , renderer);


}
void Game::update() {
    //aca deberia de meterle un metodo que sea handle arduino, entonces
    //deberia de checkear aca el arduino, si retorna algo diferente de -10
    //que se meta al if, y le haga player->updatePos
    //ACTUALIZA LA POSICION Y MOVIMIENTO DE IMAGENES.
    //cout<<"metodo update"<<endl;
    player->Update();
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
    Mapa->renderMap();
    player->renderAll();
    //Mapa->renderOne();
    //Fases->getFase().moveNrender();
    SDL_RenderPresent(renderer);
    /*aca debo de poner load balas a cada rato , ese metodo debe de checkear
     * la lista de cartuchos, agarrar una bala y usarla.*/
}
//codigo funcional ahora por alguna razon
void Game::eventHandler() { //no funciona de momento bien
    //funcion que maneja eventos
    SDL_Event evento ;
    //SDL_PollEvent(&evento); //investigar que hace esto
    while(SDL_PollEvent(&evento)){
        if(evento.type == SDL_QUIT || evento.type == SDL_WINDOWEVENT_CLOSE){
            isRunning = false;
        }
    }
    /*
    switch (evento.type) {
        //caso cuando le damos cerrar a la pestaña en la x, crea un evento
        //de tipo quit, si es quit, el siguiente loop del juego no va a ocurrir
        //y pone en falso running
        case SDL_QUIT: //si el evento es cerrar juego , corriendo es falso
            isRunning = false;
            cout<<"el evento es quit"<<endl;
            break;
        default:
            cout<<"no se hayo tipo de evento"<<endl;
            break;
    }*/
}
void Game::clean() {
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
void Game::verifyCollision(){
    /*
    int length = Fases->getFase().getSIze();
    enemyList enemigoxd = Fases->getFase();
    cout<<"el tamaño es "<<length<<endl;
    for(int a=1; a<=length;a++){
        cout<<"iteracion:"<<a<<endl;
        if(SDL_HasIntersection(player->getRect(), enemigoxd.search(a)->getRect())){
            cout << "hay colision papa" << endl;
            enemigoxd.deleteEnemy(a);
            break;
            //crep que por enemigoxd no ser pointer se jode.
        }
    }*/
   

}
