//
// Created by huevitoentorta on 02/05/23.
//

#ifndef PACMANMOBILE_ENEMYHNDLR_H
#define PACMANMOBILE_ENEMYHNDLR_H
#include "Enemy.h"

class enemyHndlr {
private:
    Enemy *fantasmas[4];
    int currentEnemies;
    SDL_Renderer *render;
public:
    enemyHndlr(SDL_Renderer *render);
    void renderallEnemies(); //renders all the current enemies.
    void moveallEnemies(); //moves all enemies.
    void updateallEnemies(); //updates all enemies.
    void lvlup(const char* texture);
    int getCurrentEnemies();

    Enemy* getEnemy(int number);
};


#endif //PACMANMOBILE_ENEMYHNDLR_H
