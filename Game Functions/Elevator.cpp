
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

void drawAndMoveElevatorV(char board[100][1000], int& row , int col, int startRow, int endRow , int& direction) {
	
	drawElevator(board, row, col);
	moveElevatorVertically(row, startRow, endRow, direction);
}

void drawAndMoveElevatorH(char board[100][1000], int row, int &col, int startCol, int endCol, int& direction) {

	drawElevator(board, row, col);
	moveElevatorVertically(row, startCol, endCol, direction);
}

void moveplayervertically(int& row, int startRow, int endRow, int& direction) {
	if (row == endRow) direction = 2;
	else if (row == startRow+1) direction = 1;

	if (direction == 1) row--;
	else row++;
}


void moveplayerhorizontally(int& col, int startCol, int endCol, int& direction) {
	if (col == endCol) direction = 2;
	else if (col == startCol) direction = 1;

	if (direction == 1) col++;
	else col--;
}

void playerElevate (char board[100][1000], &pX, &pY,int row, int &col,int& direction){

}