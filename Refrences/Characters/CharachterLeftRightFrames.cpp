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