//
// Created by huevitoentorta on 02/05/23.
//

#include "enemyHndlr.h"
enemyHndlr::enemyHndlr(SDL_Renderer *renders) {
    //ghost constructor
    this->render = renders;
    fantasmas[0]=new Enemy("../Textures/slimeazul.png",renders,1);
    fantasmas[0]->changeDirection(3);
    currentEnemies=1;
}

void enemyHndlr::renderallEnemies() {
    for(int i=0;i<currentEnemies;i++){
        fantasmas[i]->renderEnemy();
    }
}

void enemyHndlr::moveallEnemies() {
    for(int i=0;i<currentEnemies;i++){
        fantasmas[i]->move();
    }

}

void enemyHndlr::updateallEnemies() {
    for(int i=0;i<currentEnemies;i++){
        fantasmas[i]->Update();
    }

}

void enemyHndlr::lvlup(const char* texture) {//this function adds a ghost on screen on lvl up.
    currentEnemies+=1;
    fantasmas[currentEnemies-1]=new Enemy(texture,render,1);
    fantasmas[currentEnemies-1]->changeDirection(3);

}

int enemyHndlr::getCurrentEnemies() {
    return this->currentEnemies;
}
Enemy* enemyHndlr::getEnemy(int number){
    return fantasmas[number];
}

void enemyHndlr::spetialEmoves(bool flag) {
    for(int i=0;i<currentEnemies;i++){
        fantasmas[i]->setFLag(flag);
    }
}
//in these the x, y are the positions in the map where the power up spawned.
bool enemyHndlr::checkPowercollision(int x, int y) {
    for(int i=0;i<currentEnemies;i++){
        if(fantasmas[i]->getX()==y &&fantasmas[i]->getY()==x){
            return true;
        }
    }
    return false;
}
