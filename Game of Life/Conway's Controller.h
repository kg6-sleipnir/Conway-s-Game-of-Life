#ifndef CONWAY
#define CONWAY


#include <stdbool.h>


#include "Board Controller.h"

//check neighbors of cell to determine next state of a cell
bool CheckNeighbors(int x, int y, Board* board);

//iterate every cell in board
void IterateCells(Board* board);

#endif