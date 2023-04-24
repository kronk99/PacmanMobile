#include <iostream>
#include "Game.h"
int main() {
    int a=184;
    int b=32;
    cout<<"el numero es"<<a/b<<endl;
    const int fps=60;
    const int frameDelay = 1000/fps;
    Uint32 frameStart;
    int frametime;
    Game *game = new Game();
    //hice el init como el verdadero constructor de la ventana de juegoxd.
    game->init("juego1" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED ,960 ,720,false);
    while(game->running()){
        frameStart=SDL_GetTicks();
        game->eventHandler();
        game->update();
        game->render();
        frametime = SDL_GetTicks()-frameStart;
        if(frameDelay>frametime){
            //este delay debe de ser ajustado para la velocidad del juego
            //o las balas.
            SDL_Delay(frameDelay-frametime);
        }
    }

    return 0;
}
