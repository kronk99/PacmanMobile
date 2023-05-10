//
// Created by huevitoentorta on 09/05/23.
//

#ifndef PACMANMOBILE_PNODE_H
#define PACMANMOBILE_PNODE_H


class Pnode {
private:
    int posx;
    int posy;
    Pnode *next;
public:
    Pnode(int posxi,int posyi );
    Pnode* getNext();
    void setNext(Pnode* next);
    int getx();
    int gety();
};


#endif //PACMANMOBILE_PNODE_H
