#include <iostream>
#include "Game.h"
#include "Lista.h"
#include "pathfindingA.h"
int main() {
    /*
    int x1 = 1;
    int x2=2;
    int x3=3;
    int F1 =3;
    int F2 = 5;
    Lista *openlist = new Lista();
    Lista *closeLIst = new Lista();
    openlist->insertCloseList(closeLIst);
    openlist->insertFirst(x1,x2,F1);
    openlist->insertLast(x2,x1,F2);
    openlist->printList();
    cout<<"el f mayor es:"<< openlist->minorF()<<endl;
    cout<<"el f2 mayor es:"<< openlist->minorF()<<endl;
    cout<<"el xd mayor es:"<< openlist->minorF()<<endl;
    closeLIst->printList();
    closeLIst->trueDelete();
    closeLIst->printList();*/
    int lvl1[22][22]={
            //significado de los numeros:
            // 0 implica que no hay comida ni objetos(pacman paso por ahi)
            //1 implica que hay comida
            //2 implica que hay obstaculo:
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
            {2,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,2},
            {2,1,2,2,1,2,2,2,1,2,1,2,2,2,1,2,2,1,2,2,1,2},
            {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
            {2,1,2,2,1,2,1,2,2,2,2,2,1,2,1,2,2,1,2,2,1,2},
            {2,1,1,1,1,2,1,1,1,2,1,1,1,2,1,1,1,1,1,1,1,2},
            {2,2,2,2,1,2,2,2,1,2,1,2,2,2,2,1,2,1,2,2,2,2},
            {0,0,0,2,1,2,1,1,1,1,1,1,1,1,2,1,2,1,2,0,0,2},
            {2,2,2,2,1,2,1,2,2,2,2,2,2,1,2,1,2,1,2,2,2,2},
            {2,1,1,1,1,1,1,2,1,1,1,1,2,1,1,1,1,1,1,1,1,2},
            {2,1,2,2,1,2,1,2,2,2,2,2,2,1,2,1,2,2,2,2,1,2},
            {2,1,2,2,1,2,1,1,1,1,1,1,1,1,2,1,1,1,1,2,1,2},
            {2,1,1,1,1,2,1,2,2,2,2,2,1,2,2,1,2,2,1,2,1,2},
            {2,1,2,2,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,2},
            {2,1,1,1,1,2,2,2,1,2,1,2,2,2,2,1,2,2,1,2,1,2},
            {2,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2},
            {2,1,1,1,1,2,2,2,2,1,2,1,2,2,2,1,2,2,1,2,1,2},
            {2,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,2,1,2},
            {2,1,2,2,2,1,2,1,2,2,2,2,2,1,2,2,2,2,2,2,1,2},
            {2,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
            {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    };
    pathfindingA::getInstance()->aStarSearch(lvl1,2,1,20,12);

    /*
    int a=184;
    int b=32;
    cout<<"el numero es"<<a/b<<endl;
    const int fps=60;
    const int frameDelay = 1000/fps;
    Uint32 frameStart;
    int frametime;
    Game *game = new Game();
    //hice el init como el verdadero constructor de la ventana de juegoxd.
    game->init("juego1" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED ,704,704,false);
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
*/
    return 0;
}
