/// http://www.dreamincode.net/forums/topic/55572-conways-game-of-life/
/// downloaded by copy-paste on 8/19/mdim15 and modified to use an infinite loop.
///
/// This code needs serious work in these areas:
/// <ol>
/// <li>  syntax: there are a number of warnings that cause errors.
/// </li>
/// <li>  semantics: the game algorithm implementation is incorrect.
/// </li>
/// <li>  design: the implementation needs function and value refactoring.
/// </li>
/// <li>  style: formatting is poor; e.g. mix of TAB and spaces indentation
/// </li>
/// <li>  documentation: documentation is non-existent except for this block.
/// </li>
/// </ol>
///

#include <stdio.h>
#include <stdlib.h>

void header(void) /*function for program header*/
{
	printf("\n\t..Welcome to the Game of life..\n");
}

void survivalRule(int rowsize, int colsize, int size, char life[][size])
{
	int row, col;
	int neighbors = 0;
	for(row = 0; row<rowsize; row++)
	{
		for(col = 0; col<colsize; col++)
		{
			if(life[row][col] == '*')
			{
				if(life[row - 1][col - 1] == '*')
					++neighbors;
				if(life[row - 1][col] == '*')
					++neighbors;
				if(life[row - 1][col + 1] == '*')
					++neighbors;
				if(life[row][col - 1] == '*')
					++neighbors;
				if(life[row][col + 1] == '*')
					++neighbors;
				if(life[row + 1][col - 1] == '*')
					++neighbors;
				if(life[row + 1][col] == '*')
					++neighbors;
				if(life[row + 1][col + 1] == '*')
					++neighbors;
				if(neighbors == 2 || neighbors == 3)
				{
					life[row][col] = '*';
				}
			}
		}
	}
	return;
}

void birthRule(int rowsize, int colsize, int size, char life[][size])
{
	int row, col;
	int neighbors = 0;
	for(row = 0; row<rowsize; row++)
	{
		for(col = 0; col<colsize; col++)
		{
			if(life[row][col]== ' ')
			{
				if(life[row - 1][col - 1] == '*')
					neighbors++;
				if(life[row - 1][col] == '*')
					neighbors++;
				if(life[row - 1][col + 1] == '*')
					neighbors++;
				if(life[row][col - 1] == '*')
					neighbors++;
				if(life[row][col + 1] == '*')
					neighbors++;
				if(life[row + 1][col - 1] == '*')
					neighbors++;
				if(life[row + 1][col] == '*')
					neighbors++;
				if(life[row + 1][col + 1] == '*')
					neighbors++;
				if(neighbors == 3)
				{
					life[row][col] = '*';
				}
			}
		}
	}

	return;
}

void deathRule(int rowsize, int colsize, int size, char life[][size])
{
	int row , col;
	int neighbors = 0;
	for(row = 0; row<rowsize; row++)
	{
		for(col = 0; col<colsize; col++)
		{
			if(life[row][col] == '*')
			{
				if(life[row - 1][col - 1] == '*')
					neighbors++;
				if(life[row - 1][col] == '*')
					neighbors++;
				if(life[row - 1][col + 1] == '*')
					neighbors++;
				if(life[row][col - 1] == '*')
					neighbors++;
				if(life[row][col + 1] == '*')
					neighbors++;
				if(life[row + 1][col - 1] == '*')
					neighbors++;
				if(life[row + 1][col] == '*')
					neighbors++;
				if(life[row + 1][col + 1] == '*')
					neighbors++;
				if(neighbors < 2 || neighbors > 4)
				{
					life[row][col] = ' ';
				}
			}
		}
	}
	return;
}


int main(void)
{
	int mdim = 20;
	char life[mdim][10];
	int orgs;//, gens;
	int i,row, col; // a, b
	int count = 0;
//	int x = 19;
//	int y = 19;
//	char ans;

	header();

	printf("\nPlease enter the initial number of organisms: ");
	scanf("%i", &orgs);

	srand( 31 );

	for(i = 0; i<orgs; i++)
	{
		row = rand();
		row %= mdim;
		col = rand();
		col %= mdim;
		life[row][col] = '*';
	}

	for(row = 0; row<mdim; row++)
	{
		for(col = 0; col<mdim; col++)
		{
			if(life[row][col] != '*')
				life[row][col] = ' ';
		}
	}

	for(row = 0; row<mdim; row++)
	{
		for(col = 0; col<mdim; col++)
		{
			printf("%c", life[row][col]);
		}
		puts(" ");
	}

	while ( count<=10 ) {
		birthRule(20, 10,mdim, life);
		survivalRule(20,10,mdim,life);
		deathRule(20,10,mdim,life);
		for(row = 0; row<mdim; row++)
		{
			for(col = 0; col<mdim; col++)
			{
				printf("%c", life[row][col]);
			}
			puts(" ");
		}
		printf("\ngeneration: %d\n", count);
		count++;
	}
	return 0;
}

