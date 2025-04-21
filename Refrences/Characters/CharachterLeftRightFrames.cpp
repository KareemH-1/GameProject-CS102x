void DrawPlayerLeftFrame2(char board[24][80], int R, int C, int& shootingR, int& shootingC) {

    //Left arm
    board[R-4][C] = '\\';
    board[R-4][C+1] = '|';
    board[R-4][C+2] = '-';
    board[R-4][C+3] = '-';
    board[R-4][C+4] = '-';
    shootingR = R-4;
    shootingC = C-1;
    board[R-5][C] = '/';
    board[R-5][C+1] = '|';
    board[R-5][C+2] = '-';
    board[R-5][C+3] = '-';
    board[R-5][C+4] = '-';


    //Right arm

    board[R-5][C+12] = '\\';
    board[R-4][C+13] = '\\';
    board[R-3][C+14] = '\\';

    //Left leg

    board[R][C+4] = '/';
    board[R][C+5] = '_';
    board[R][C+6] = '/';
    board[R-1][C+5] = '/';
    board[R-1][C+7] = '/';

    //Right leg
    board[R][C+10] = '\\';
    board[R][C+11] = '_';
    board[R][C+12] = '\\';
    board[R-1][C+9] = '|';
    board[R-1][C+11] = '|';

    //Body
    board[R-2][C+5] = '\\';
    board[R-2][C+6] = '_';
    board[R-2][C+7] = '_';
    board[R-2][C+8] = '_';
    board[R-2][C+9] = '_';
    board[R-2][C+10] = '_';
    board[R-2][C+11] = '/';
    
    board[R-3][C+5] = '|';
    board[R-3][C+11] = '|';
    board[R-4][C+5] = '|';
    board[R-4][C+11] = '|';
    board[R-5][C+5] = '|';
    board[R-5][C+11] = '|';

    board[R-5][C+6] ='-';
    board[R-5][C+7] ='-';
    board[R-5][C+8] ='v';
    board[R-5][C+9] ='-';
    board[R-5][C+10] ='-';

    //Head
    board[R - 7][C + 10] = '\\';
    board[R - 6][C + 10] = '/';

    board[R - 8][C + 6] = '_';
    board[R - 8][C + 7] = '_';
    board[R - 8][C + 8] = '_';
    board[R - 8][C + 9] = '_';

    board[R - 7][C + 9] = ')';
    board[R - 7][C + 6] = '(';
    board[R - 7][C + 7] = '.';
    board[R - 7][C + 8] = '.';
    board[R - 6][C + 6] = '\\';
    board[R - 6][C + 7] = '-';
    board[R - 6][C + 8] = '-';
    board[R - 6][C + 9] = '-';

}

void DrawPlayerLeftFrame3(char board[24][80], int R, int C, int& shootingR, int& shootingC) {

    //Left arm
    board[R-4][C] = '\\';
    board[R-4][C+1] = '|';
    board[R-4][C+2] = '-';
    board[R-4][C+3] = '-';
    board[R-4][C+4] = '-';
    shootingR = R-4;
    shootingC = C-1;
    board[R-5][C] = '/';
    board[R-5][C+1] = '|';
    board[R-5][C+2] = '-';
    board[R-5][C+3] = '-';
    board[R-5][C+4] = '-';


    //Right arm

    board[R-5][C+12] = '\\';
    board[R-4][C+13] = '\\';
    board[R-3][C+13] = '/';


    //Left leg
    board[R][C+5] = '|';
    board[R][C+6] = '_';
    board[R][C+7] = '|';
    board[R-1][C+5] = '/';
    board[R-1][C+7] = '/';

    //Right Leg
    board[R-1][C+10] = '|';
    board[R-1][C+11] = '_';
    board[R-1][C+12] = '_';
    board[R-1][C+13] = '_';
    board[R-1][C+14] = '|';
    board[R-2][C+12] = '_';
    board[R-2][C+13] = '_';


    //Body
    board[R-2][C+5] = '\\';
    board[R-2][C+6] = '_';
    board[R-2][C+7] = '_';
    board[R-2][C+8] = '_';
    board[R-2][C+9] = '_';
    board[R-2][C+10] = '_';
    board[R-2][C+11] = '/';
    
    board[R-3][C+5] = '|';
    board[R-3][C+11] = '|';
    board[R-4][C+5] = '|';
    board[R-4][C+11] = '|';
    board[R-5][C+5] = '|';
    board[R-5][C+11] = '|';

    board[R-5][C+6] ='-';
    board[R-5][C+7] ='-';
    board[R-5][C+8] ='v';
    board[R-5][C+9] ='-';
    board[R-5][C+10] ='-';

    //Head
    board[R - 7][C + 10] = '\\';
    board[R - 6][C + 10] = '/';

    board[R - 8][C + 6] = '_';
    board[R - 8][C + 7] = '_';
    board[R - 8][C + 8] = '_';
    board[R - 8][C + 9] = '_';

    board[R - 7][C + 9] = ')';
    board[R - 7][C + 6] = '(';
    board[R - 7][C + 7] = '.';
    board[R - 7][C + 8] = '.';
    board[R - 6][C + 6] = '\\';
    board[R - 6][C + 7] = '-';
    board[R - 6][C + 8] = '-';
    board[R - 6][C + 9] = '-';
}



void DrawPlayerLeftFrame4(char board[24][80], int R, int C, int& shootingR, int& shootingC) {

    //Left arm
    board[R-4][C] = '\\';
    board[R-4][C+1] = '|';
    board[R-4][C+2] = '-';
    board[R-4][C+3] = '-';
    board[R-4][C+4] = '-';
    shootingR = R-4;
    shootingC = C-1;
    board[R-5][C] = '/';
    board[R-5][C+1] = '|';
    board[R-5][C+2] = '-';
    board[R-5][C+3] = '-';
    board[R-5][C+4] = '-';


    //Right arm

    board[R-5][C+12] = '\\';
    board[R-4][C+13] = '\\';
    board[R-3][C+14] = '\\';


    //Left leg
    board[R][C+5] = '\\';
    board[R][C+6] = '_';
    board[R][C+7] = '\\';
    board[R-1][C+5] = '/';
    board[R-1][C+7] = '/';

    //Right leg
    board[R][C+9] = '|';
    board[R][C+10] = '_';
    board[R][C+11] = '|';
    board[R-1][C+9] = '/';
    board[R-1][C+11] = '/';

    //Body
    board[R-2][C+5] = '\\';
    board[R-2][C+6] = '_';
    board[R-2][C+7] = '_';
    board[R-2][C+8] = '_';
    board[R-2][C+9] = '_';
    board[R-2][C+10] = '_';
    board[R-2][C+11] = '/';
    
    board[R-3][C+5] = '|';
    board[R-3][C+11] = '|';
    board[R-4][C+5] = '|';
    board[R-4][C+11] = '|';
    board[R-5][C+5] = '|';
    board[R-5][C+11] = '|';

    board[R-5][C+6] ='-';
    board[R-5][C+7] ='-';
    board[R-5][C+8] ='v';
    board[R-5][C+9] ='-';
    board[R-5][C+10] ='-';

    //Head
    board[R - 7][C + 10] = '\\';
    board[R - 6][C + 10] = '/';

    board[R - 8][C + 6] = '_';
    board[R - 8][C + 7] = '_';
    board[R - 8][C + 8] = '_';
    board[R - 8][C + 9] = '_';

    board[R - 7][C + 9] = ')';
    board[R - 7][C + 6] = '(';
    board[R - 7][C + 7] = '.';
    board[R - 7][C + 8] = '.';
    board[R - 6][C + 6] = '\\';
    board[R - 6][C + 7] = '-';
    board[R - 6][C + 8] = '-';
    board[R - 6][C + 9] = '-';
}




void DrawPlayerLeftFrame5(char board[24][80], int R, int C, int& shootingR, int& shootingC) {

    //Left arm
    board[R-4][C] = '\\';
    board[R-4][C+1] = '|';
    board[R-4][C+2] = '-';
    board[R-4][C+3] = '-';
    board[R-4][C+4] = '-';
    shootingR = R-4;
    shootingC = C-1;
    board[R-5][C] = '/';
    board[R-5][C+1] = '|';
    board[R-5][C+2] = '-';
    board[R-5][C+3] = '-';
    board[R-5][C+4] = '-';


    //Right arm

    board[R-5][C+12] = '\\';
    board[R-4][C+13] = '\\';
    board[R-3][C+13] = '/';


    //Left leg
    board[R][C+7] = '/';
    board[R][C+8] = '_';
    board[R][C+9] = '/';
    board[R-1][C+8] = '/';
    board[R-1][C+10] = '/';

    //Right leg
    board[R-1][C+6] = '|';
    board[R-1][C+7] = '_';
    board[R-1][C+11] = '_';
    board[R-1][C+12] = '|';
    board[R-2][C+12] = '_';


    //Body
    board[R-2][C+5] = '\\';
    board[R-2][C+6] = '_';
    board[R-2][C+7] = '_';
    board[R-2][C+8] = '_';
    board[R-2][C+9] = '_';
    board[R-2][C+10] = '_';
    board[R-2][C+11] = '/';
    
    board[R-3][C+5] = '|';
    board[R-3][C+11] = '|';
    board[R-4][C+5] = '|';
    board[R-4][C+11] = '|';
    board[R-5][C+5] = '|';
    board[R-5][C+11] = '|';

    board[R-5][C+6] ='-';
    board[R-5][C+7] ='-';
    board[R-5][C+8] ='v';
    board[R-5][C+9] ='-';
    board[R-5][C+10] ='-';

    //Head
    board[R - 7][C + 10] = '\\';
    board[R - 6][C + 10] = '/';

    board[R - 8][C + 6] = '_';
    board[R - 8][C + 7] = '_';
    board[R - 8][C + 8] = '_';
    board[R - 8][C + 9] = '_';

    board[R - 7][C + 9] = ')';
    board[R - 7][C + 6] = '(';
    board[R - 7][C + 7] = '.';
    board[R - 7][C + 8] = '.';
    board[R - 6][C + 6] = '\\';
    board[R - 6][C + 7] = '-';
    board[R - 6][C + 8] = '-';
    board[R - 6][C + 9] = '-';
}




///////RightFrames


void drawPlayerRightFrame2 (char board[24][80], int row, int col, int& shootR, int shootC) {
	//left arm
	board[row - 3][col] = '/';
	board[row - 4][col + 1] = '/';
	board[row - 5][col + 2] = '/';

	//left leg
    board[row][col +2 ] = '/';
    board[row][col +3 ] = '_';
    board[row][col +4 ] = '/';
    board[row-1][col +3 ] = '|';
    board[row-1][col +5 ] = '|';
    //right leg
    board[row-1][col + 7] = '\\';    
    board[row-1][col + 9] = '\\';    
    board[row][col + 8] = '\\';    
    board[row][col + 9] = '_';    
    board[row][col + 10] = '\\';   

    
	//right arm
	board[row - 4][col + 10] = '-';
	board[row - 4][col + 11] = '-';
	board[row - 4][col + 12] = '-';
	board[row - 4][col + 13] = '|';
	board[row - 4][col + 14] = '/';
	shootR = row - 4;
	shootC = col + 15;
	board[row - 5][col + 14] = '\\';
	board[row - 5][col + 13] = '|';
	board[row - 5][col + 12] = '-';
	board[row - 5][col + 11] = '-';
	board[row - 5][col + 10] = '-';

	//body

	board[row - 2][col + 3] = '\\';
	board[row - 2][col + 4] = '_';
	board[row - 2][col + 5] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 8] = '_';
	board[row - 2][col + 9] = '/';
	board[row - 3][col + 9] = '|';
	board[row - 4][col + 9] = '|';
	board[row - 5][col + 9] = '|';
	board[row - 3][col + 3] = '|';
	board[row - 4][col + 3] = '|';
	board[row - 5][col + 3] = '|';
	board[row - 5][col + 4] = '-';
	board[row - 5][col + 5] = '-';
	board[row - 5][col + 6] = 'v';
	board[row - 5][col + 7] = '-';
	board[row - 5][col + 8] = '-';




	//head

	board[row - 6][col + 4] = '\\';
	board[row - 7][col + 4] = '/';
	board[row - 8][col + 5] = '_';
	board[row - 8][col + 6] = '_';
	board[row - 8][col + 7] = '_';
	board[row - 7][col + 8] = ')';
	board[row - 7][col + 5] = '(';
	board[row - 7][col + 6] = '.';
	board[row - 7][col + 7] = '.';
	board[row - 6][col + 8] = '/';
	board[row - 6][col + 7] = '-';
	board[row - 6][col + 6] = '-';
	board[row - 6][col + 5] = '-';





}
void drawPlayerRightFrame3 (char board[24][80], int row, int col, int& shootR, int shootC) {
	//left arm
	board[row - 3][col+1] = '\\';
	board[row - 4][col + 1] = '/';
	board[row - 5][col + 2] = '/';

	//left leg
    board[row-2][col + 1] = '_';
    board[row-1][col] = '|';
    board[row-1][col + 1] = '_';
    board[row-1][col + 2] = '_';
    board[row-1][col + 3] = '_';
    board[row-1][col + 4] = '|';    
    
    //right leg
    board[row][col+6] = '|';
    board[row][col + 7] = '_';
    board[row][col + 8] = '|';
    board[row-1][col + 6] = '\\';
    board[row-1][col + 8] = '\\';

	//right arm
	board[row - 4][col + 10] = '-';
	board[row - 4][col + 11] = '-';
	board[row - 4][col + 12] = '-';
	board[row - 4][col + 13] = '|';
	board[row - 4][col + 14] = '/';
	shootR = row - 4;
	shootC = col + 15;
	board[row - 5][col + 14] = '\\';
	board[row - 5][col + 13] = '|';
	board[row - 5][col + 12] = '-';
	board[row - 5][col + 11] = '-';
	board[row - 5][col + 10] = '-';

	//body

	board[row - 2][col + 3] = '\\';
	board[row - 2][col + 4] = '_';
	board[row - 2][col + 5] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 8] = '_';
	board[row - 2][col + 9] = '/';
	board[row - 3][col + 9] = '|';
	board[row - 4][col + 9] = '|';
	board[row - 5][col + 9] = '|';
	board[row - 3][col + 3] = '|';
	board[row - 4][col + 3] = '|';
	board[row - 5][col + 3] = '|';
	board[row - 5][col + 4] = '-';
	board[row - 5][col + 5] = '-';
	board[row - 5][col + 6] = 'v';
	board[row - 5][col + 7] = '-';
	board[row - 5][col + 8] = '-';




	//head

	board[row - 6][col + 4] = '\\';
	board[row - 7][col + 4] = '/';
	board[row - 8][col + 5] = '_';
	board[row - 8][col + 6] = '_';
	board[row - 8][col + 7] = '_';
	board[row - 7][col + 8] = ')';
	board[row - 7][col + 5] = '(';
	board[row - 7][col + 6] = '.';
	board[row - 7][col + 7] = '.';
	board[row - 6][col + 8] = '/';
	board[row - 6][col + 7] = '-';
	board[row - 6][col + 6] = '-';
	board[row - 6][col + 5] = '-';


}


void drawPlayerRightFrame4 (char board[24][80], int row, int col, int& shootR, int shootC) {
	//left arm
	board[row - 3][col] = '/';
	board[row - 4][col + 1] = '/';
	board[row - 5][col + 2] = '/';

	//left leg
    board[row][col +3 ] = '|';
    board[row][col +4 ] = '_';
    board[row][col +5 ] = '|';

    board[row-1][col +3 ] = '\\';
    board[row-1][col +5 ] = '\\';

    //right leg
    board[row][col + 7] = '/';    
    board[row][col + 8] = '_';    
    board[row][col + 9] = '/';    
    board[row-1][col + 7] = '\\';    
    board[row-1][col + 9] = '\\';    

    
	//right arm
	board[row - 4][col + 10] = '-';
	board[row - 4][col + 11] = '-';
	board[row - 4][col + 12] = '-';
	board[row - 4][col + 13] = '|';
	board[row - 4][col + 14] = '/';
	shootR = row - 4;
	shootC = col + 15;
	board[row - 5][col + 14] = '\\';
	board[row - 5][col + 13] = '|';
	board[row - 5][col + 12] = '-';
	board[row - 5][col + 11] = '-';
	board[row - 5][col + 10] = '-';

	//body

	board[row - 2][col + 3] = '\\';
	board[row - 2][col + 4] = '_';
	board[row - 2][col + 5] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 8] = '_';
	board[row - 2][col + 9] = '/';
	board[row - 3][col + 9] = '|';
	board[row - 4][col + 9] = '|';
	board[row - 5][col + 9] = '|';
	board[row - 3][col + 3] = '|';
	board[row - 4][col + 3] = '|';
	board[row - 5][col + 3] = '|';
	board[row - 5][col + 4] = '-';
	board[row - 5][col + 5] = '-';
	board[row - 5][col + 6] = 'v';
	board[row - 5][col + 7] = '-';
	board[row - 5][col + 8] = '-';




	//head

	board[row - 6][col + 4] = '\\';
	board[row - 7][col + 4] = '/';
	board[row - 8][col + 5] = '_';
	board[row - 8][col + 6] = '_';
	board[row - 8][col + 7] = '_';
	board[row - 7][col + 8] = ')';
	board[row - 7][col + 5] = '(';
	board[row - 7][col + 6] = '.';
	board[row - 7][col + 7] = '.';
	board[row - 6][col + 8] = '/';
	board[row - 6][col + 7] = '-';
	board[row - 6][col + 6] = '-';
	board[row - 6][col + 5] = '-';





}


void drawPlayerRightFrame5 (char board[24][80], int row, int col, int& shootR, int shootC) {
	//left arm
	board[row - 3][col+1] = '\\';
	board[row - 4][col + 1] = '/';
	board[row - 5][col + 2] = '/';

    //Left leg
    board[row-2][col+2] = '_';
    board[row-1][col+2] = '|';
    board[row-1][col+3] = '_';
    board[row-1][col+7] = '_';
    board[row-1][col+8] = '|';

    //Right leg

    board[row-1][col+4] = '\\';
    board[row-1][col+6] = '\\';
    board[row][col+5] = '\\';
    board[row][col+5] = '_';
    board[row][col+6] ='\\';

	//right arm
	board[row - 4][col + 10] = '-';
	board[row - 4][col + 11] = '-';
	board[row - 4][col + 12] = '-';
	board[row - 4][col + 13] = '|';
	board[row - 4][col + 14] = '/';
	shootR = row - 4;
	shootC = col + 15;
	board[row - 5][col + 14] = '\\';
	board[row - 5][col + 13] = '|';
	board[row - 5][col + 12] = '-';
	board[row - 5][col + 11] = '-';
	board[row - 5][col + 10] = '-';

	//body

	board[row - 2][col + 3] = '\\';
	board[row - 2][col + 4] = '_';
	board[row - 2][col + 5] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 8] = '_';
	board[row - 2][col + 9] = '/';
	board[row - 3][col + 9] = '|';
	board[row - 4][col + 9] = '|';
	board[row - 5][col + 9] = '|';
	board[row - 3][col + 3] = '|';
	board[row - 4][col + 3] = '|';
	board[row - 5][col + 3] = '|';
	board[row - 5][col + 4] = '-';
	board[row - 5][col + 5] = '-';
	board[row - 5][col + 6] = 'v';
	board[row - 5][col + 7] = '-';
	board[row - 5][col + 8] = '-';




	//head

	board[row - 6][col + 4] = '\\';
	board[row - 7][col + 4] = '/';
	board[row - 8][col + 5] = '_';
	board[row - 8][col + 6] = '_';
	board[row - 8][col + 7] = '_';
	board[row - 7][col + 8] = ')';
	board[row - 7][col + 5] = '(';
	board[row - 7][col + 6] = '.';
	board[row - 7][col + 7] = '.';
	board[row - 6][col + 8] = '/';
	board[row - 6][col + 7] = '-';
	board[row - 6][col + 6] = '-';
	board[row - 6][col + 5] = '-';


}