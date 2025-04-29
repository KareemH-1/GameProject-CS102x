

void moveElevatorVertically(int& row, int startRow, int endRow, int& direction) {
	if (row == endRow) direction = 2;
	else if (row == startRow) direction = 1;

	if (direction == 1) row--;
	else row++;
}

void moveElevatorHorizontally(int& col, int startCol, int endCol, int& direction) {
	if (col == endCol) direction = 2;
	else if (col == startCol) direction = 1;

	if (direction == 1) col++;
	else col--;
}
void drawElevator(char board[100][1000], int row, int col) {
	board[row][col] = '_';
	board[row][col + 1] = '_';
	board[row][col + 2] = '_';
	board[row][col + 4] = '_';
	board[row][col + 5] = '_';
	board[row][col + 6] = '_';
	board[row][col + 7] = '_';
	board[row][col + 8] = '_';
	board[row][col + 9] = '_';
	board[row][col + 10] = '_';
}

void drawAndMoveElevatorV(char board[100][1000], Elevator elevator[] , int i ) {
		drawElevator(board, elevator[i].row, elevator[i].col);
		moveElevatorVertically(elevator[i].row, elevator[i].startRow, elevator[i].endRow, elevator[i].direction);

}
void drawAndMoveElevatorH(char board[100][1000], Elevator elevator[] , int i) {
		drawElevator(board, elevator[i].row, elevator[i].col);
		moveElevatorHorizontally(elevator[i].col, elevator[i].startCol, elevator[i].endCol, elevator[i].direction);
}

void ElevatePlayer(int &pX , int & pY , Elevator elevator[] , int nElevators) {
	
	for(int i =0 ; i< nElevators ; i++){
		int check =0 , subcheck =0;

		if(pX == elevator[i].row-1)subcheck = 1;
		if(pY+9 >= elevator[i].col && pY+3 <= elevator[i].col+ 10 && subcheck) check =1; 
	
		if(check){
			if(elevator[i].whichD == 1){
				if(elevator[i].direction ==1) pX--;
				else if(elevator[i].direction == 2) pX++;
			}
			else {
				if(elevator[i].direction ==1) pY++;
				else if(elevator[i].direction == 2) pY--;
			}
		}
	}
}

