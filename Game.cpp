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
    SDL_RenderPresent(renderer);

}
//codigo funcional ahora por alguna razon
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
                    break;
                case SDLK_a:
                    player->moverLeft();
                    break;
                case SDLK_d:
                    player->moverRight();
                    break;
                case SDLK_s:
                    player->moverDown();
                    break;
            }
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
    //el jugador necesita moverse por la matriz de juego , esto para el
    //pathfinding de los fantasmas, como tambien las colisiones con la comida y
    //pared, el jugador debe de chekear colsiones arriba suyo, abajo suyo,
    //a su izquierda y a su derecha. estas verificaciones de colisiones
    //se deben de llamar en el event handler de movimientos
    //tipo me muevo a la derecha, primero verifique que no hay un obstaculo
    //si retorna false, muevase, si no , no se mueva
    //la pregunta ahora es , como le hago para que el jugador se mueva
    //implemente primero colisiones con pared, como pacman ignora el grid
    //debe checkear en el cuadrante
}
