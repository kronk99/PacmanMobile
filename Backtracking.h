//
// Created by huevitoentorta on 16/05/23.
//

#ifndef PACMANMOBILE_BACKTRACKING_H
#define PACMANMOBILE_BACKTRACKING_H
#include <iostream>
#include <limits.h>

class Backtracking {
private:
    int *start; // inicio
    int *end; //final
    int visited[22][22];
    int matrix[22][22];
    int shortLength = INT_MAX; // la ruta más corta - contador
    int length=0; // contador
    bool hasPath = false; // verifica si hay ruta o no
    static Backtracking* pointer;
public:
    Backtracking();
    static Backtracking *getInstance();
    void findpath();
    void visit(int x,int y);
    bool canVisit(int x, int y);


    //añadidos por mi persona
    void insertStart(int inicio[2] , int final[2]); //esto le inserta
    //las posiciones actuales de mi enemigo.

    void deletepositions(); //delete positions.

    void insertMapa(int mapas [22][22]);

    void resetAll(); //resetea todos los valores
    //el lenght , elvisited matrix
    int getshortlenght();
    int gethaspath();




};


#endif //PACMANMOBILE_BACKTRACKING_H
