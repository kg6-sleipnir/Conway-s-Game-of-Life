#include "Conway's Controller.h"

bool CheckNeighbors(int x, int y, Board* board)
{

	int aliveNeighbors = 0; //number of alive neighbors not including self


	/*
	we want to make sure we only check cells that are within the bounds
	of the console

	to do this we assume that all cells out of bounds are considered dead

	since dead cells don't add to the aliveNeighbors counter, we don't
	check the cells out of bounds to avoid checking junk data outside
	of the cells array of the board struct
	*/


	//       check only y pos below 0          check only y pos above Height  
	//   [-------------------------------]  [---------------------------------]
	for (int yPos = ((y == 0) ? y : y - 1); yPos <= ((y == Height) ? y : y + 1); yPos++)
	{
		//        check only x right of 0          check only x left of Width  
		//   [-------------------------------]  [------------------------------]  
		for (int xPos = ((x == 0) ? x : x - 1); xPos <= ((x == Width) ? x : x + 1); xPos++)
		{
			if (xPos == x && yPos == y)
			{
				continue;
			}

			if (GetCell(xPos, yPos, board) == ALIVE)
			{
				aliveNeighbors++;
			}
		}
	}


	/*
	Rules for Conway's Game of Life:

	1. A dead cell with exactly 3 neighbors will become alive
	2. An alive cell with 2 or 3 neighbors will remain alive
	3. An alive cell with 1 or less neighbors will die
	4. An alive cell with 4 or more neighbors will die
	*/
	
	if ((aliveNeighbors == 2 && GetCell(x, y, board) == ALIVE) || aliveNeighbors == 3) //check every condition where a cell will become or stay alive
	{
		return ALIVE;
	}
	else
	{
		return DEAD;
	}

}

void IterateCells(Board* board)
{

	Board newBoard = CreateBoard();

	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			SetCell(x, y, CheckNeighbors(x, y, board), &newBoard);
		}
	}

	*board = newBoard;
}
