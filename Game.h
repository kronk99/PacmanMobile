//
// Created by huevitoentorta on 18/03/23.
//

#ifndef PROYECTO1_A_D2_GAME_H
#define PROYECTO1_A_D2_GAME_H
//#include <SDL2/SDL.h> lo quito por que ya player.h lo incluye.

#include <SDL2/SDL.h>
//#include "Enemigos/enemyList.h"
#include "Map.h"
#include "Player.h"
//#include "Enemy.h"
#include "Score.h"
#include "enemyHndlr.h"
#include "Vida.h";
class Game {
private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Map *Mapa;
    Player *player;
    //Enemy *enemigo;
    Score *score;
    enemyHndlr *enemigos;
    Vida *vida;
    bool LOCK;

    //enemyList* pruebaenemigo;
public:
    Game();
    void init(const char *title ,int posx , int posy , int width , int lenght ,bool fullscreen);
    void update();
    void render();
    void clean();
    void eventHandler();
    bool running();
    void playerMappos();
    static SDL_Event evento;
    bool verifyCollision(int a, int b);
    void PnEcollision();
    void checkScore();
    void checkPcolision();
    void tolvlUp();
};


#endif //PROYECTO1_A_D2_GAME_H
