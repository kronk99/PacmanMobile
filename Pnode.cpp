//
// Created by huevitoentorta on 09/05/23.
//

#include "Pnode.h"
Pnode::Pnode(int posxi, int posyi) {
    this->posx =posxi;
    this->posy=posyi;
}

Pnode *Pnode::getNext() {
    return this->next;
}

void Pnode::setNext(Pnode *nexti) {
    this->next = nexti;
}

int Pnode::getx() {
    return this->posx;
}

int Pnode::gety() {
    return posy;
}
