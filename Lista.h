//
// Created by huevitoentorta on 12/04/23.
//

#ifndef PROYECTO1_A_D2_LISTA_H
#define PROYECTO1_A_D2_LISTA_H
#include <iostream>
#include "Node.h"
using namespace std;

class Lista {
private:
    /**aca deberia de tener una instancia de garbage colector*/
    Node *head;
    Node *last;
    Node *current;
    int size;
    Lista *closeList;
public:
    Lista();
    void insertFirst(int x , int y, int F);
    void insertLast(int x , int y, int F);
    void deleteFirst();
    void printList();
    void insertCloseList(Lista *closelist);
    void insertNode(Node* nodo);


};


#endif //PROYECTO1_A_D2_LISTA_H
