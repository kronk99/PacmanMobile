//
// Created by huevitoentorta on 06/05/23.
//

#include "pathfindingA.h"
/*this class will have 2 linked list, which are the open list
 * and the close list*/
pathfindingA* pathfindingA::pointer= nullptr;
pathfindingA::pathfindingA() {
    openList = new Lista();
    closeList= new Lista();
    openList->insertCloseList(closeList);
}
pathfindingA* pathfindingA::getInstance(){
    if(pointer== nullptr){
        cout<<"pathfinding estaba nullo"<<endl;
        pointer = new pathfindingA();
        return pointer;
    }
    else{
        return pointer;
    }
}

bool pathfindingA::validCell(int fila, int columna) {
    if (Map::getInstance()->getMapa(fila,columna)==2){
        return false;
    }
    else{
        return true;
    }
}
// A Utility Function to check whether given cell (row, col)
// is a valid cell or not.
bool pathfindingA:: isValid(int row, int col)
{
    // Returns true if row number and column number
    // is in range
    return (row >= 0) && (row < 20) && (col >= 0)
           && (col < 20);
}
bool pathfindingA::isDestination(int row, int col, int destx ,int desty)
{
    if (row == destx && col == desty){
        return (true);
    }
    else{
        return (false);
    }
}
//RECUERDE ROW = FILAS ->IMPLICA EL Y, COL =COLUMNAS->IMPLICA EL X
// A Utility Function to calculate the 'h' heuristics.
int pathfindingA:: calculateHValue(int row, int col, int destx,int desty)
{
    // Return using the distance formula
    return abs((row-destx)+(col-desty));
}
/*
 * CODIGO CON EL QUE SE VA A METER A LA PILA QUE EL ENEMYCLASS VA A TENER.
void tracePath(cell cellDetails[][COL], Pair dest)
{
    printf("\nThe Path is ");
    int row = dest.first;
    int col = dest.second;

    stack<Pair> Path;

    while (!(cellDetails[row][col].parent_i == row
             && cellDetails[row][col].parent_j == col)) {
        Path.push(make_pair(row, col));
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }

    Path.push(make_pair(row, col));
    while (!Path.empty()) {
        pair<int, int> p = Path.top();
        Path.pop();
        printf("-> (%d,%d) ", p.first, p.second);
    }

    return;
}*/
void pathfindingA::aStarSearch(int grid[20][20], int posx, int posy, int destx, int desty) {
    // If the source is out of range
    if (isValid(posx, posy) == false) {
        cout << "origen invalido" << endl;
        return;
    }

    // If the destination is out of range
    if (isValid(destx, desty) == false) {
        cout << "destino invalido" << endl;
        return;
    }
//CREO QUE EL CODIGO DE ABAJO ES INNECESARIO, YA QUE
//DEBO DE ASEGURARME QUE EL FANTASMA NO ESTE EN obstaculos y el objetivo tampoco
    // Either the source or the destination is blocked
    /*
    if (isUnBlocked(grid, src.first, src.second) == false
        || isUnBlocked(grid, dest.first, dest.second)
           == false) {
        printf("Source or the destination is blocked\n");
        return;
    }
*/
    // If the destination cell is the same as source cell
    if (isDestination(posx, posy, destx, desty) == true) {
        cout<<"se esta directamente en la posicion x y del objetivo"<<endl;
        return;
    }
    cell cellDetails[20][20];
    int i, j;
//initialize the struct
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            cellDetails[i][j].f = 99;
            cellDetails[i][j].g = 99;
            cellDetails[i][j].h = 99;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }
    // Initialising the parameters of the starting node
    i = posx, j = posy;
    cellDetails[i][j].f = 0;
    cellDetails[i][j].g = 0;
    cellDetails[i][j].h = 0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;

}