//
// Created by huevitoentorta on 09/05/23.
//

#include "Pila.h"
//these are peak but for the data
int Pila::getX() {
    return head->getx();
}
//peak for ydata
int Pila::getY() {
    return head->gety();
}

void Pila::pop() {
//DEBE LLAMAR A CLOSE LIST e insertarle el nodo que borra.
    current = head;
    //head->getNext()!= NULL || size ==1
    if( size !=0){
        head = head->getNext();
        delete current;
        size--;
    }
    else{
        cout<<"lista vacia"<<endl;
    }
}

void Pila::push(int x , int y) {
    if(size != 0){ /**si el tamaño de la lista es diferente de 0*/
        Pnode *newnode = new Pnode(x,  y); /**cree un nuevo nodo, sobrecargando la operacion new*/
        newnode->setNext(head); //el nodo siguiente es el head
        head = newnode;//cambia el head
        size++;
    }
    else{ /**si no, cree un nuevo nodo y asigneselo al puntero head*/
        this->head =new Pnode(x,  y);
        size++;
    }
}

int Pila::getSize() {
    return this->size;
}

Pila::Pila() {
    this->size = 0;

}
