//
// Created by huevitoentorta on 16/05/23.
//

#include "Backtracking.h"
Backtracking *Backtracking::pointer= nullptr;
Backtracking *Backtracking::getInstance() { //constructor de la clase backtracking.
    if(pointer== nullptr){
        //cout<<"pathfinding estaba nullo"<<endl;
        pointer = new Backtracking();
        return pointer;
    }
    else{
        return pointer;
    }
}
Backtracking::Backtracking() {
//ACA DEBO DE CREAR LA COLA.
}

void Backtracking::findpath() {

}

void Backtracking::visit(int x, int y) {
// Caso base - alcanza la posicion de destino
    if(x == end[0] && y == end[1]){

        // actualiza la ruta - marca true si hay una posible ruta
        hasPath=true;

        // Almacena el minimo de la ruta
        if(length < shortLength)
            shortLength= length;

        // Realiza el bactracking para explorar más ruta
        return;
    }

    // Marca la posicion actual como visitada
    visited[x][y] = 1;

    // incremente la ruta actual +1
    length++;

    // Right
    if(canVisit(x+1, y)){ //
        visit(x+1, y);
        std::cout << "Right " << " " << x << " " << y << std::endl;
        // Agregar la cola acá para que agregue la posicion
    }

    // Down
    if(canVisit(x, y+1)){
        visit(x, y+1);
        std::cout << "Down" << " " << x << " " << y << std::endl;
        // Agregar la cola acá para que agregue la posicion
    }

    // Left
    if(canVisit(x-1, y)){
        visit(x-1, y);
        std::cout << "Left " << " " <<  x << " " << y << std::endl;
        // Agregar la cola acá para que agregue la posicion
    }

    // Up
    if(canVisit(x, y-1)){
        visit(x, y-1);
        std::cout << "Up " << " " << x << " " << y << std::endl;
        // Agregar la cola acá para que agregue la posicion
    }

    //Backtrack by unvisiting the current cell and
    //decrementing the value of current path length
    visited[x][y] = 0;
    length--;
}

bool Backtracking::canVisit(int x, int y) {
    // Columnas en la matriz
    int m =22; //sizeof(matrix[0]) / sizeof(matrix[0][0]);
    // Filas en la matriz
    int n =22; //sizeof(matrix) / sizeof(matrix[0]);
    // Analiza los extremos de la matriz
    if(x<0 || y<0 || x>=m || y>=n){
        return false;
    }
    // Analiza si la posicion ya fue visitada o si es un obstaculo (2)
    if(matrix[x][y]==2 || visited[x][y]==1){
        return false;
    }

    return true;
}
//esto de abajo debe de usarse hasta cambiar de mapaaaa.
void Backtracking::insertMapa(int mapas [22][22]) {
    for(int i=0;i<22;i++){
        for(int j=0;j<22;j++){
            matrix[i][j] = mapas[i][j];
        }
    }
}//metodo que debe de usarse para dejar la lista de visitados limpia.
void Backtracking::resetAll() {
    for(int i=0;i<22;i++){
        for(int j=0;j<22;j++){
            visited[i][j] = 0;
        }
    }
    length=0;
}

void Backtracking::insertStart(int *inicio, int *final) {
    start= inicio;
    end=final;
}

int Backtracking::getshortlenght() {
    return shortLength;
}

int Backtracking::gethaspath() {
    return hasPath;
}

