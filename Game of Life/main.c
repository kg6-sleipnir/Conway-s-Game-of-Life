#include <stdio.h>
#include <Windows.h>

#include "Board Controller.h"
#include "Conway's Controller.h"

int main()
{

	Board board = CreateBoard();

	SetCell(2, 1, ALIVE, &board);
	SetCell(2, 2, ALIVE, &board);
	SetCell(2, 3, ALIVE, &board);
	SetCell(1, 3, ALIVE, &board);
	SetCell(0, 2, ALIVE, &board);

	PrintBoard(&board);

	for (int i = 0; i < 1000; i++)
	{
		IterateCells(&board);
		Sleep(100);
		PrintBoard(&board);
	}

}