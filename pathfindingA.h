//
// Created by huevitoentorta on 06/05/23.
//

#ifndef PACMANMOBILE_PATHFINDINGA_H
#define PACMANMOBILE_PATHFINDINGA_H
#include "Lista.h"
#include <iostream>
#include "Map.h"
class pathfindingA {//had to do the struct as global , could not implement it
    //as a private attribute of this class.
    struct cell {
        // Row and Column index of its parent
        // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
        int parent_i, parent_j;
        // f = g + h
        int f, g, h;
    };
private:
    static pathfindingA* pointer;
    Lista *openList;
    Lista *closeList;
public:
    pathfindingA();
    pathfindingA *getInstance();
    bool validCell(int x, int y);

    bool isValid(int row, int col);

    bool isDestination(int row, int col, int destx, int desty);

    int calculateHValue(int row, int col, int destx, int desty);
    void aStarSearch(int [20][20] , int posx, int posy , int destx ,int desty);
};


#endif //PACMANMOBILE_PATHFINDINGA_H
