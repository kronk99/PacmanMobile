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
    return (row >= 0) && (row < 22) && (col >= 0)
           && (col < 22);
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
 * CODIGO CON EL QUE SE VA A METER A LA PILA QUE EL ENEMYCLASS VA A TENER.*/
void pathfindingA::tracePath(cell cellDetails[22][22], int destx ,int desty ,int origenx ,int origeny)
{
    printf("\nThe Path is ");
    int row = destx;
    int col = desty;
    newPila = new Pila();
    newPila->push(row ,col);
//me hace falta una pila para este codigo.
   // stack<Pair> Path;
    //!(cellDetails[row][col].parent_i == destx && cellDetails[row][col].parent_j == desty
    //ANTES DE ESTE CICLO AÑADIRLE A LA PILA EL DESTX Y EL DESTY.
    while (cellDetails[row][col].parent_i != origenx or cellDetails[row][col].parent_j != origeny) {
//cambiar el && por un or
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        cout<<"la ruta x es:"<<temp_row<<endl;
        cout<<"la ruta y es:"<<temp_col<<endl;
        newPila->push(temp_row ,temp_col);
        row = temp_row;
        col = temp_col;
        //basicamente tengo que añadir en la pila los temp_rows NO LOS ROW COL,añadiendo inicialmente
        //la destx y la desty .
    }
/*
    Path.push(make_pair(row, col));
    while (!Path.empty()) {
        pair<int, int> p = Path.top();
        Path.pop();
        printf("-> (%d,%d) ", p.first, p.second);
    }

    return;*/
}
void pathfindingA::aStarSearch(int grid[22][22], int posx, int posy, int destx, int desty) {
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
    cell cellDetails[22][22];
    int i, j;
//initialize the struct
    for (i = 0; i < 22; i++) {
        for (j = 0; j < 22; j++) {
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
    openList->insertFirst(posx,posy,0);
    bool foundDest = false;
    Node *current;
    int gNew, hNew, fNew;

    while(openList->getSIze()!=0){
        current = openList->minorF();
        i = current->getx();
        j = current->gety();
        cout<<"mi x ahora es"<<i<<endl;
        cout<<"mi y ahora es:"<<j<<endl;
        //now we will genenerate the succesors.
        //int g, h, f; //for storing these values of the 8 succesors.
        //********************First succesor (North)********************
        // Only process this cell if this is a valid one
        if (isValid(i - 1, j) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i - 1, j, destx, desty) == true) {
                // Set the Parent of the destination cell
                cellDetails[i - 1][j].parent_i = i;
                cellDetails[i - 1][j].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, destx,desty , posx ,posy);
                foundDest = true;
                return;
            }
                // If the successor is already on the closed
                // list or if it is blocked, then ignore it.
                // Else do the following
                //si no esta en la close list y la celda no es un obstaculo calcule
                //los valores de g h f
            else if (closeList->isincloseL(i-1 ,j)==false && validCell(i-1,j)==true){
                gNew = cellDetails[i][j].g + 10;
                hNew = calculateHValue(i - 1, j, destx,desty);
                fNew = gNew+hNew;
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i - 1][j].f == 99 || cellDetails[i - 1][j].f > fNew) {
                    openList->insertFirst(i-1,j,fNew);

                    // Update the details of this cell
                    cellDetails[i - 1][j].f = fNew;
                    cellDetails[i - 1][j].g = gNew;
                    cellDetails[i - 1][j].h = hNew;
                    cellDetails[i - 1][j].parent_i = i;
                    cellDetails[i - 1][j].parent_j = j;
                    cout<<"el sucesor escogido es el norte"<<endl;
                }
            }
        }
        //**here starts the second successor SOUTH:*****************
        if (isValid(i + 1, j) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i + 1, j, destx, desty) == true) {
                // Set the Parent of the destination cell
                cellDetails[i + 1][j].parent_i = i;
                cellDetails[i + 1][j].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, destx,desty ,posx, posy);
                foundDest = true;
                return;
            }
                // If the successor is already on the closed
                // list or if it is blocked, then ignore it.
                // Else do the following
                //si no esta en la close list y la celda no es un obstaculo calcule
                //los valores de g h f
            else if (closeList->isincloseL(i+1 ,j)==false && validCell(i+1,j)==true){
                gNew = cellDetails[i][j].g + 10;
                hNew = calculateHValue(i + 1, j, destx,desty);
                fNew = gNew+hNew;
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i + 1][j].f == 99 || cellDetails[i + 1][j].f > fNew) {
                    openList->insertFirst(i+1,j,fNew);

                    // Update the details of this cell
                    cellDetails[i + 1][j].f = fNew;
                    cellDetails[i + 1][j].g = gNew;
                    cellDetails[i + 1][j].h = hNew;
                    cellDetails[i + 1][j].parent_i = i;
                    cellDetails[i + 1][j].parent_j = j;
                    cout<<"el sucesor escogido es el sur"<<endl;
                }
            }
        }
        //***here where the third succesor starts (EAST/Este)*************
        if (isValid(i , j+1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i , j+1, destx, desty) == true) {
                // Set the Parent of the destination cell
                cellDetails[i][j+1].parent_i = i;
                cellDetails[i][j+1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, destx,desty,posx, posy);
                foundDest = true;
                return;
            }
                // If the successor is already on the closed
                // list or if it is blocked, then ignore it.
                // Else do the following
                //si no esta en la close list y la celda no es un obstaculo calcule
                //los valores de g h f
            else if (closeList->isincloseL(i ,j+1)==false && validCell(i,j+1)==true){
                gNew = cellDetails[i][j].g + 10;
                hNew = calculateHValue(i , j+1, destx,desty);
                fNew = gNew+hNew;
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i ][j+1].f == 99 || cellDetails[i ][j+1].f > fNew) {
                    openList->insertFirst(i,j+1,fNew);

                    // Update the details of this cell
                    cellDetails[i ][j+1].f = fNew;
                    cellDetails[i ][j+1].g = gNew;
                    cellDetails[i ][j+1].h = hNew;
                    cellDetails[i ][j+1].parent_i = i;
                    cellDetails[i ][j+1].parent_j = j;
                    cout<<"el sucesor escogido es el este"<<endl;
                }
            }
        }
        //****west case (OESTE)
        if (isValid(i , j-1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i , j-1, destx, desty) == true) {
                // Set the Parent of the destination cell
                cellDetails[i][j-1].parent_i = i;
                cellDetails[i][j-1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, destx,desty ,posx ,posy);
                foundDest = true;
                return;
            }
                // If the successor is already on the closed
                // list or if it is blocked, then ignore it.
                // Else do the following
                //si no esta en la close list y la celda no es un obstaculo calcule
                //los valores de g h f
            else if (closeList->isincloseL(i ,j-1)==false && validCell(i,j-1)==true){
                gNew = cellDetails[i][j].g + 10;
                hNew = calculateHValue(i , j-1, destx,desty);
                fNew = gNew+hNew;
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i ][j-1].f == 99 || cellDetails[i ][j-1].f > fNew) {
                    openList->insertFirst(i,j-1,fNew);

                    // Update the details of this cell
                    cellDetails[i ][j-1].f = fNew;
                    cellDetails[i ][j-1].g = gNew;
                    cellDetails[i ][j-1].h = hNew;
                    cellDetails[i ][j-1].parent_i = i;
                    cellDetails[i ][j-1].parent_j = j;
                    cout<<"el sucesor escogido es el Oeste"<<endl;
                }
            }
        }
        //caso NORESTE********************* REVISAR CASO POR CASO, NO ESTAN SIRVIENDO A PARTIR DE ESTE PARA ABAJO
        if (isValid(i-1 , j+1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i-1 , j+1, destx, desty) == true) {
                // Set the Parent of the destination cell
                cellDetails[i-1][j+1].parent_i = i;
                cellDetails[i-1][j+1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, destx,desty,posx,posy);
                foundDest = true;
                return;
            }
                // If the successor is already on the closed
                // list or if it is blocked, then ignore it.
                // Else do the following
                //si no esta en la close list y la celda no es un obstaculo calcule
                //los valores de g h f
            else if (closeList->isincloseL(i-1 ,j+1)==false && validCell(i-1,j+1)==true){
                gNew = cellDetails[i][j].g + 14;
                hNew = calculateHValue(i-1 , j+1, destx,desty);
                fNew = gNew+hNew;
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i-1][j+1].f == 99 || cellDetails[i -1][j+1].f > fNew) {
                    openList->insertFirst(i-1,j+1,fNew);

                    // Update the details of this cell
                    cellDetails[i-1 ][j+1].f = fNew;
                    cellDetails[i-1][j+1].g = gNew;
                    cellDetails[i-1][j+1].h = hNew;
                    cellDetails[i-1][j+1].parent_i = i;
                    cellDetails[i-1][j+1].parent_j = j;
                    cout<<"el sucesor escogido es el NOreste"<<endl;
                }
            }
        }
        //caso NOROESTE*****************
        if (isValid(i-1 , j-1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i-1 , j-1, destx, desty) == true) {
                // Set the Parent of the destination cell
                cellDetails[i-1][j-1].parent_i = i;
                cellDetails[i-1][j-1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, destx,desty,posx,posy);
                foundDest = true;
                return;
            }
                // If the successor is already on the closed
                // list or if it is blocked, then ignore it.
                // Else do the following
                //si no esta en la close list y la celda no es un obstaculo calcule
                //los valores de g h f
            else if(closeList->isincloseL(i-1 ,j-1)==false && validCell(i-1,j-1)==true){
                cout<<"entre aca con un valid cell de"<<i-1<<"y"<<j-1<<"para un valid cell de "<<validCell(i-1,j-1)<<endl;
                gNew = cellDetails[i][j].g + 14;
                hNew = calculateHValue(i-1 , j-1, destx,desty);
                fNew = gNew+hNew;
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i-1 ][j-1].f == 99 || cellDetails[i -1][j-1].f > fNew) {
                    openList->insertFirst(i-1,j-1,fNew);

                    // Update the details of this cell
                    cellDetails[i-1 ][j-1].f = fNew;
                    cellDetails[i-1][j-1].g = gNew;
                    cellDetails[i-1][j-1].h = hNew;
                    cellDetails[i-1][j-1].parent_i = i;
                    cellDetails[i-1][j-1].parent_j = j;
                    cout<<"el sucesor escogido es el NOrOeste"<<endl;
                }
            }
        }
        //caso 7 SURESTE.
        if (isValid(i+1 , j+1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i+1 , j+1, destx, desty) == true) {
                // Set the Parent of the destination cell
                cellDetails[i+1][j+1].parent_i = i;
                cellDetails[i+1][j+1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, destx,desty,posx,posy);
                foundDest = true;
                return;
            }
                // If the successor is already on the closed
                // list or if it is blocked, then ignore it.
                // Else do the following
                //si no esta en la close list y la celda no es un obstaculo calcule
                //los valores de g h f
            else if (closeList->isincloseL(i+1 ,j+1)==false && validCell(i+1,j+1)==true){
                cout<<"entre aca con un valid cell de"<<i-1<<"y"<<j-1<<"para un valid cell de "<<validCell(i-1,j-1)<<endl;
                gNew = cellDetails[i][j].g + 14;
                hNew = calculateHValue(i+1 , j+1, destx,desty);
                fNew = gNew+hNew;
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i+1 ][j+1].f == 99 || cellDetails[i +1][j+1].f > fNew) {
                    openList->insertFirst(i+1,j+1,fNew);

                    // Update the details of this cell
                    cellDetails[i+1 ][j+1].f = fNew;
                    cellDetails[i+1][j+1].g = gNew;
                    cellDetails[i+1][j+1].h = hNew;
                    cellDetails[i+1][j+1].parent_i = i;
                    cout<<"mi J es"<<j<<endl;
                    cellDetails[i+1][j+1].parent_j = j;
                    cout<<"el sucesor escogido es el sureste"<<endl;
                    cout<<"EL VALOR DE J EN LA MATRIZ AHORA ES"<<cellDetails[i+1][j+1].parent_j<<endl;
                }
            }
        }
        //caso 8 SUROESTE
        if (isValid(i+1 , j-1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i+1 , j-1, destx, desty) == true) {
                // Set the Parent of the destination cell
                cellDetails[i+1][j-1].parent_i = i;
                cellDetails[i+1][j-1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, destx,desty,posx,posy);
                foundDest = true;
                return;
            }
                // If the successor is already on the closed
                // list or if it is blocked, then ignore it.
                // Else do the following
                //si no esta en la close list y la celda no es un obstaculo calcule
                //los valores de g h f
            else if (closeList->isincloseL(i+1 ,j-1)==false && validCell(i+1,j-1)==true){
                gNew = cellDetails[i][j].g + 14;
                hNew = calculateHValue(i+1 , j-1, destx,desty);
                fNew = gNew+hNew;
                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i+1 ][j-1].f == 99 || cellDetails[i +1][j-1].f > fNew) {
                    openList->insertFirst(i+1,j-1,fNew);

                    // Update the details of this cell
                    cellDetails[i+1 ][j-1].f = fNew;
                    cellDetails[i+1][j-1].g = gNew;
                    cellDetails[i+1][j-1].h = hNew;
                    cellDetails[i+1][j-1].parent_i = i;
                    cellDetails[i+1][j-1].parent_j = j;
                    cout<<"el sucesor escogido es el suroeste"<<endl;
                }
            }
        }
    }
    // When the destination cell is not found and the open
    // list is empty, then we conclude that we failed to
    // reach the destination cell. This may happen when the
    // there is no way to destination cell (due to
    // blockages)
    if (foundDest == false)
        printf("Failed to find the Destination Cell\n");

    return;
}

Pila *pathfindingA::getpila() {
    return this->newPila;
}
