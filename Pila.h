//
// Created by huevitoentorta on 09/05/23.
//

#ifndef PACMANMOBILE_PILA_H
#define PACMANMOBILE_PILA_H
#include "Pnode.h"
#include <iostream>
using namespace std;

class Pila {
private:
    Pnode * current;
    Pnode * head;
    int size;
public:
    Pila();
    int getX();
    int getY();
    void pop();
    void push(int x, int y);
    int getSize();
};


#endif //PACMANMOBILE_PILA_H
