#ifndef BOARD
#define BOARD

#include <stdbool.h>
#include <stdio.h>


#define ALIVE true
#define DEAD false

#define Width 119
#define Height 29

typedef struct Board
{

	//array of cells for the board
	//NOTE: x y coordinates are swapped to cells[y][x]
	char cells[Height][Width];

} Board;


void SetCell(int x, int y, bool state, Board* board);

bool GetCell(int x, int y, Board* board);

//create initialized board
Board CreateBoard();

void PrintBoard(Board* board);

#endif