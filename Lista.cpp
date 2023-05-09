//
// Created by huevitoentorta on 12/04/23.
//
//DOUBLE LINKED LIST
#include "Lista.h"
Lista::Lista() {
    size = 0;
    Fmenor=0;
}
void Lista::insertFirst(int x, int y, int F) {
    if(size != 0){ /**si el tamaño de la lista es diferente de 0*/
        Node *newnode = new Node(x,  y, F); /**cree un nuevo nodo, sobrecargando la operacion new*/
        newnode->setNext(head); //el nodo siguiente es el head
        head->setPrevious(newnode);
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
        newnode->setPrevious(last);
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
        //head->setNext(nullptr);
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

void Lista::insertNode(Node *nodo) { //insercion para la close list.
    if(size != 0){ /**si el tamaño de la lista es diferente de 0*/
        Node *newnode = nodo; /**cree un nuevo nodo, sobrecargando la operacion new*/
        newnode->setNext(head); //el nodo siguiente es el head
        head->setPrevious(newnode);
        head = newnode;//cambia el head
        size++;
    }
    else{ /**si no, cree un nuevo nodo y asigneselo al puntero head*/
        this->head =nodo;
        this->last = head;
        size++;
    }
}

void Lista::trueDelete() {
    current = head;
    while(size!=0){
        head = head->getNext();
        delete current;
        current=head;
        size--;
    }

}

Node *Lista::minorF() { //metodo para la open list
    current = head;
    for(int i=0;i<size;i++){
        if(Fmenor <= current->getF()){
            Fmenor = current->getF();
        }
        current2=current;
        current = current->getNext();
    }

    current = current2;

    deleteNode(current2);

    //delete current; this is the node that ill be deleting from the list.
    return current;
}

void Lista::deleteNode(Node *nodo) {
    cout<<"legue aca"<<endl;
    //LLEGUE ACA , EL CURRENT 2 SI LO AGARRA, VER SI EL QUE IMPRIME ES EL CORRECTO.
    
    //casos :
    if(size >1){
        current2 = nodo->getPrevious();
        if(nodo ==head){
            cout<<"entre al metodo 2"<<endl;
            closeList->insertNode(nodo);
            head = nodo->getNext();
            head->setPrevious(nullptr);
            cout<<"el nodo es head"<<endl;

        }
        else if(nodo ==last){
            cout<<"entre al metodo 2"<<endl;
            current2->setNext(nullptr);
            cout<<"entre al metodo x"<<endl;
            last = current2;
            closeList->insertNode(nodo);
            cout<<"el nodo es la cola"<<endl;
        }
        else{
            cout<<"el nodo no es ni la cabeza ni la cola"<<endl;
            //caso estoy en el medio de 2 nodos  y caso donde pueden ser 3.
            current2->setNext(nodo->getNext());
            if(nodo->getNext() != nullptr){
                nodo->getNext()->setPrevious(current2);
            }
            closeList->insertNode(nodo);
        }
        size--;
    }
    else if (size==1){
        current2 = nodo->getPrevious();
        cout<<"la lista solo tiene 1 nodo"<<endl;
        closeList->insertNode(nodo);
        head= nullptr;
        last= nullptr;
        size--;
    }
    else{
        cout<<"lista vacia"<<endl;
    }
}

int Lista::getSIze() {
    return size;
}

bool Lista::isincloseL(int xi ,int yi) {
    current = head;
    for(int i=0;i<size;i++){
        if(current->getx() ==xi && current->gety()==yi){
            return true;
        }
        current=current->getNext();
    }
    return false;
}
