//
// Created by huevitoentorta on 06/05/23.
//

#include "Node.h"

Node::Node(int posxi, int posyi, int Fi) {
    this->posx =posxi;
    this->posy=posyi;
    this->F =Fi;
}

Node *Node::getNext() {
    return this->next;
}

void Node::setNext(Node *nexti) {
    this->next = nexti;
}

int Node::getx() {
    return this->posx;
}

int Node::gety() {
    return posy;
}

int Node::getF() {
    return F;
}
