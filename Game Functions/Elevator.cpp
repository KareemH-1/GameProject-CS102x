

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
	board[row][col + 3] = '_';
	board[row][col + 4] = '_';
	board[row][col + 5] = '_';
	board[row][col + 6] = '_';
	board[row][col + 7] = '_';
	board[row][col + 8] = '_';
	board[row][col + 9] = '_';
}

void drawAndMoveElevatorV(char board[100][1000], Elevator elevator[] , int i ) {
		drawElevator(board, elevator[i].row, elevator[i].col);
		moveElevatorVertically(elevator[i].row, elevator[i].startRow, elevator[i].endRow, elevator[i].direction);

}
void drawAndMoveElevatorH(char board[100][1000], Elevator elevator[] , int i) {
		drawElevator(board, elevator[i].row, elevator[i].col);
		moveElevatorHorizontally(elevator[i].col, elevator[i].startCol, elevator[i].endCol, elevator[i].direction);
}

void ElevatePlayer(int &pX, int &pY, Elevator elevator[], int nElevators) {
	for(int i = 0; i < nElevators; i++) {
		int check = 0;

		// Check if player is standing just above the elevator row
		if(pX == elevator[i].row - 1) {
			// Check if player's width overlaps the elevator platform
			if(pY + 3 <= elevator[i].col + 10 && pY + 9 >= elevator[i].col) {
				check = 1;
			}
		}

		// If player is on the elevator, move them accordingly
		if(check) {
			
			if(elevator[i].whichD == 1) { // vertical
				
				if(elevator[i].direction == 1) pX--;    // move up
				
				else if(elevator[i].direction == 2) pX++; // move down
			} 
			else { // horizontal
				
				if(elevator[i].direction == 1) pY++;    // move right
				
				else if(elevator[i].direction == 2) pY--; // move left
			}
			
		}
	}
}