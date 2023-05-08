//
// Created by huevitoentorta on 06/05/23.
//

#ifndef PACMANMOBILE_NODE_H
#define PACMANMOBILE_NODE_H


class Node {
private:
    int posx;
    int posy;
    int F;
    Node *next;
    Node *previous;
public:
        Node(int posxi,int posyi , int F );
        Node* getNext();
        void setNext(Node* next);
        int getx();
        int gety();
        int getF();
        Node* getPrevious();
        void setPrevious(Node* previus);

};


#endif //PACMANMOBILE_NODE_H
