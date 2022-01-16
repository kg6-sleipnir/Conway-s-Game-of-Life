#include "Board Controller.h"

void SetCell(int x, int y, bool state, Board* board)
{
	if (state == ALIVE)
	{
		board->cells[y][x] = '*';
	}
	else
	{
		board->cells[y][x] = ' ';
	}
}

bool GetCell(int x, int y, Board* board)
{

	if (board->cells[y][x] == '*')
	{
		return ALIVE;
	}
	else
	{
		return DEAD;
	}
}

Board CreateBoard()
{
	Board board;

	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			SetCell(x, y, DEAD, &board);
		}
	}

	return board;
}

void PrintBoard(Board* board)
{
	printf("\033[H\033[J"); //set cursor to home position and clear console
	
	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			printf("%c", board->cells[y][x]);
		}

		printf("\n");
	}
}
