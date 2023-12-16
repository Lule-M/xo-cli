#include <stdio.h>

/*

	1.	123
	2.	123
	3.	123

		 1   2   3
	1	   |   |
		---+---+---
	2	   |   |
		---+---+---
	3	   |   |

*/

int turnNumber = 0;

char *board[3] = {"   ", "   ", "   "};

void DrawGrid()
{
	printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
	printf("---+---+---\n");
	printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
	printf("---+---+---\n");
	printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int CheckLegality(int X, int Y)
{
	if (board[Y][X] == ' ')
		return 1;
	else
		return 0;
}

int WritePlayerChoice(int X, int Y, char currentPlayer)
{
	X--;
	Y--;

	if (CheckLegality(X, Y) == 1)
	{
		board[Y][X] = currentPlayer;
		return 1;
	}
	else
	{
		return 0;
	}
}

void GetPlayerChoice(int* coordinateX, int* coordinateY, char currentPlayer)
{
	int x = 0;
	int y = 0;

	while(scanf("%d %d", &x, &y) != 2)
	{
		while((getchar())!='\n');

		printf("Incorrect coordinate format.\n");
		printf("\nPlayer %c is on the move.\nEnter coordinates: ", currentPlayer);
	}

	*coordinateX = x;
	*coordinateY = y;

	printf("============================= pozz sa rafa===============================");
}

int main()
{
	int coordinateX;				
	int coordinateY;			
	
	do
	{
		char currentPlayer = (turnNumber % 2 == 0)? 'X' : 'O';
	
		printf("\nTurn %d\n\n", turnNumber + 1);
		DrawGrid();

		printf("\nPlayer %c is on the move.\nEnter coordinates: ", currentPlayer);
		
		GetPlayerChoice(&coordinateX, &coordinateY, currentPlayer);

		while (WritePlayerChoice(coordinateX, coordinateY, currentPlayer) == 0)
		{
			GetPlayerChoice(&coordinateX, &coordinateY, currentPlayer);
		}


		printf("X: %d\tY: %d\n", coordinateX, coordinateY);

		getchar();	// equivalent to system("pause")
		turnNumber++;

	}while (1);
	
	return 0;
}