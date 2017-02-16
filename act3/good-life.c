/// http://www.dreamincode.net/forums/topic/55572-conways-game-of-life/
/// downloaded by copy-paste on 8/19/matrixdim15 and modified to use an infinite loop.
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

#define _BSD_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "display.h"

#define MATRIX 20
#define ROW 20
#define COL 20
#define LOOP 100

void header(void) /*function for program header*/
{
	printf("\n\t..Welcome to the Game of life..\n");
}

// find the rule of the game. 
void rule(int size, char life[][size], int row, int col)
{
	// temp array to store data and confused with same information
	int l[size][size];
	for (int i = 0 ; i < ROW; i++){
		for (int j = 0; j< COL; j++){
			l[i][j] = life[i][j];
		}
	}
	
	//find number of neighbors
	int neighbors = 0;
	if(life[(row - 1)% ROW][(col - 1)% COL] == '*')
		neighbors++;
	if(life[(row - 1)% ROW][(col)%COL] == '*')
		neighbors++;
	if(life[(row - 1)%ROW][(col + 1)% COL] == '*')
		neighbors++;
	if(life[row% ROW][(col - 1)% COL] == '*')
		neighbors++;
	if(life[row% ROW][(col + 1)%COL] == '*')
		neighbors++;
	if(life[(row + 1)% ROW][(col - 1)% COL] == '*')
		neighbors++;
	if(life[(row + 1)% ROW][col% COL] == '*')
		neighbors++;
	if(life[(row + 1)% ROW][(col + 1)% COL] == '*')
		neighbors++;
	//RULES
	//survival rules
	if( life[row][col] == '*'){
		if ( neighbors < 2 || neighbors > 3 ){
			l[row][col] = ' ';
		}else if (neighbors == 2 || neighbors == 3 ){
			l[row][col] = '*';
		}
	}
	// birth rule
	if ( life[row][col] == ' '){
		if  (neighbors == 3){ 
			l[row][col] ='*';	
		}
	}	
	//Death rule
//	if (neighbors< 2 || neighbors> 3){
//		l[row][col]= ' ';
//	}	
	//Survive
//	if (neighbors ==2){
//		if (life[row][col] =='*'){
//			l[row][col]= '*';
//		}else{
//			l[row][col] = ' ';
//		}
//	}
	
	//Birth rule
//	if(neighbors ==3){
//		l[row][col] ='*';
//	}

	//deep compy again
	for (int i = 0 ; i < ROW; i++){
		for (int j = 0; j< COL; j++){
			life[i][j] = l[i][j];
		}
	}

	return;
}


int main(void)
{
	char life[ROW][COL];
	int orgs;//, gens;
	int i, row, col;
	int count = 0;
	// int x = 19;
	// int y = 19;
	//  char ans;

	header();

	printf("\nPlease enter the initial number of organisms: ");
	scanf("%i", &orgs);

	srand( 31 );

	for(i = 0; i<orgs; i++)
	{
		row = rand();
		row %= ROW;
		col = rand();
		col %= COL;
		life[row][col] = '*';
	}

	for(row = 0; row<ROW; row++)
	{
		for(col = 0; col<COL; col++)
		{
			if(life[row][col] != '*')
				life[row][col] = ' ';
		}
	}

	for(row = 0; row<ROW; row++)
	{
		for(col = 0; col<COL; col++)
		{
			printf("%c", life[row][col]);
		}
		puts(" ");
	}

	while ( 1 ) 
	{
		clear();
		set_cur_pos(1,1);
		for(row = 0; row<ROW; row++)
		{
			for(col = 0; col<COL; col++)
			{
				rule(MATRIX, life, row,col);
			//	printf("%c",life[row][col]);
				put(life[row][col]);					
			}

			puts(" ");
		}
		printf("\ngeneration: %d\n", count);
		usleep( 81000 );
		count++;
	}
	return 0;
}

