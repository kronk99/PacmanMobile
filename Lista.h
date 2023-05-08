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
    Node *current2;
    int size;
    Lista *closeList;
    int Fmenor;
public:
    Lista();
    void insertFirst(int x , int y, int F);
    void insertLast(int x , int y, int F);
    void deleteFirst();
    void printList();
    void insertCloseList(Lista *closelist);
    void insertNode(Node* nodo);
    void trueDelete();
    Node* minorF();
    void deleteNode(Node *nodo);
    int getSIze();



};


#endif //PROYECTO1_A_D2_LISTA_H
