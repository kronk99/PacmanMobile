//
// Created by huevitoentorta on 12/04/23.
//

#include "Lista.h"
Lista::Lista() {
    size = 0;
}
void Lista::insertFirst(int x, int y, int F) {
    if(size != 0){ /**si el tamaño de la lista es diferente de 0*/
        Node *newnode = new Node(x,  y, F); /**cree un nuevo nodo, sobrecargando la operacion new*/
        newnode->setNext(head); //el nodo siguiente es el head
        head = newnode;//cambia el head
        size++;
    }
    else{ /**si no, cree un nuevo nodo y asigneselo al puntero head*/
        this->head =new Node(x,  y, F);
        this->last = head;
        size++;
    }
}
void Lista::insertLast(int x, int y, int F){
    if(size != 0){ /**si el tamaño de la lista es diferente de 0*/
        Node *newnode = new Node(x,  y, F); /**cree un nuevo nodo, sobrecargando la operacion new*/
        last->setNext(newnode);
        last = newnode;
        size++;
        cout<<"se creo un nuevo bullet"<<endl;
    }
    else{ /**si no, cree un nuevo nodo y asigneselo al puntero head*/
        this->head =new Node(x,  y, F);
        this->last = head;
        size++;
        cout<<"se creo un nuevo bullet"<<endl;
    }
}

void Lista::deleteFirst() { //ACA CUANDO HACE DELETE,
    //DEBE LLAMAR A CLOSE LIST e insertarle el nodo que borra.
    current = head;
    //head->getNext()!= NULL || size ==1
    if( size !=0){
        head = head->getNext();
        cout<<"se va a eliminar un nodo "<<endl;
        //totalmente o reciclarla.
        closeList->insertNode(current);
        cout<<"se pudo pasar el delete de la lista"<<endl;
        size--;
    }
    else{
        cout<<"lista vacia"<<endl;
    }
}


void Lista::printList() {
    Node *currente = head;
    for(int i=0;i<size;i++){
        cout<< "la bala  es:"<< currente<<endl;
        currente=currente->getNext();
    }
}

void Lista::insertCloseList(Lista *closelista) {
    this->closeList = closelista;
}

void Lista::insertNode(Node *nodo) {
    if(size != 0){ /**si el tamaño de la lista es diferente de 0*/
        Node *newnode = nodo; /**cree un nuevo nodo, sobrecargando la operacion new*/
        newnode->setNext(head); //el nodo siguiente es el head
        head = newnode;//cambia el head
        size++;
    }
    else{ /**si no, cree un nuevo nodo y asigneselo al puntero head*/
        this->head =nodo;
        this->last = head;
        size++;
    }
}
