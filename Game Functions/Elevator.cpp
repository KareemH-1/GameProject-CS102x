#include <iostream>
#include <conio.h>

using namespace std;

void moveElevatorVertically (int& row , int startRow , int endRow  , int &direction){
	if(row == endRow) direction = 2;
	else if(row == startRow) direction =1;
	
	if (direction == 1) row--;
	else row++;
}

void moveElevatorHorizontally(int & col , int startCol , int endCol , int & direction){
	if(col == endCol) direction = 2;
	else if(col == startCol) direction =1;
	
	if (direction == 1) col++;
	else col--;
}
void drawElevator(char board[100][1000] , int row , int col){
	board[row][col] = '_' ;
	board[row][col+1] = '_' ;
	board[row][col+2] = '_' ;
	board[row][col+4] = '_' ;
	board[row][col+5] = '_' ;
	board[row][col+6] = '_' ;
	board[row][col+7] = '_' ;
	board[row][col+8] = '_' ;
	board[row][col+9] = '_' ;
	board[row][col+10] = '_' ;
}
