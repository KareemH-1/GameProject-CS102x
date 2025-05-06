

#include <iostream>
using namespace std;


char board[100][1000];

void clearBoard(char board[100][1000]) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 1000; j++) {
            board[i][j] = ' ';
        }
    }
}

void drawBoss(char board[100][1000], int row, int col) {

    int BOSS_HEIGHT = 10;
    int BOSS_WIDTH = 25;
    if (row < BOSS_HEIGHT - 1 || col + BOSS_WIDTH >= 1000) {
        cout << "Error: Boss drawing out of board boundaries!" << endl;
        return;
    }

    board[row - 9][col + 8] = '.';
    board[row - 9][col + 9] = '-';
    board[row - 9][col + 10] = '"';
    board[row - 9][col + 16] = '"';
    board[row - 9][col + 17] = '-';
    board[row - 9][col + 18] = '.';

    board[row - 8][col + 7] = '/';
    board[row - 8][col + 9] = 'o';
    board[row - 8][col + 17] = 'o';
    board[row - 8][col + 19] = '\\';

    board[row - 7][col + 6] = '/';
    board[row - 7][col + 10] = '\\';
    board[row - 7][col + 16] = '/';
    board[row - 7][col + 20] = '\\';

    board[row - 6][col + 5] = '/';
    board[row - 6][col + 11] = ')';
    board[row - 6][col + 12] = '-';
    board[row - 6][col + 13] = '"';
    board[row - 6][col + 14] = '-';
    board[row - 6][col + 15] = '(';
    board[row - 6][col + 21] = '\\';

    board[row - 5][col + 4] = '/';
    board[row - 5][col + 11] = '(';
    board[row - 5][col + 12] = '6';
    board[row - 5][col + 14] = '6';
    board[row - 5][col + 15] = ')';
    board[row - 5][col + 22] = '\\';

    board[row - 4][col + 3] = '/';
    board[row - 4][col + 11] = '\\';
    board[row - 4][col + 13] = '=';
    board[row - 4][col + 15] = '/';
    board[row - 4][col + 23] = '\\';

    board[row - 3][col + 2] = '(';
    board[row - 3][col + 3] = '"';
    board[row - 3][col + 4] = '.';
    board[row - 3][col + 5] = '_';
    board[row - 3][col + 6] = '_';
    board[row - 3][col + 7] = '\\';
    board[row - 3][col + 8] = '/';
    board[row - 3][col + 9] = '_';
    board[row - 3][col + 10] = '_';
    board[row - 3][col + 11] = '\\';
    board[row - 3][col + 12] = '_';
    board[row - 3][col + 13] = '_';
    board[row - 3][col + 14] = '_';
    board[row - 3][col + 15] = '/';
    board[row - 3][col + 16] = '_';
    board[row - 3][col + 17] = '_';
    board[row - 3][col + 18] = '\\';
    board[row - 3][col + 19] = '/';
    board[row - 3][col + 20] = '_';
    board[row - 3][col + 21] = '_';
    board[row - 3][col + 22] = '.';
    board[row - 3][col + 23] = '"';
    board[row - 3][col + 24] = ')';

    board[row - 2][col + 2] = '"';
    board[row - 2][col + 3] = '-';
    board[row - 2][col + 4] = '_';
    board[row - 2][col + 7] = 'o';
    board[row - 2][col + 9] = 'O';
    board[row - 2][col + 11] = 'o';
    board[row - 2][col + 13] = 'O';
    board[row - 2][col + 15] = 'o';
    board[row - 2][col + 17] = 'O';
    board[row - 2][col + 19] = 'o';
    board[row - 2][col + 22] = '_';
    board[row - 2][col + 23] = '-';
    board[row - 2][col + 24] = '"';

    board[row - 1][col + 2] = '`';
    board[row - 1][col + 3] = '-';
    board[row - 1][col + 4] = 'Y';
    board[row - 1][col + 5] = '-';
    board[row - 1][col + 6] = '-';
    board[row - 1][col + 7] = '.';
    board[row - 1][col + 8] = '_';
    board[row - 1][col + 9] = '_';
    board[row - 1][col + 10] = '_';
    board[row - 1][col + 11] = '_';
    board[row - 1][col + 12] = '_';
    board[row - 1][col + 13] = '_';
    board[row - 1][col + 14] = '_';
    board[row - 1][col + 15] = '_';
    board[row - 1][col + 16] = '_';
    board[row - 1][col + 17] = '_';
    board[row - 1][col + 18] = '.';
    board[row - 1][col + 19] = '-';
    board[row - 1][col + 20] = '-';
    board[row - 1][col + 21] = 'Y';
    board[row - 1][col + 22] = '-';
    board[row - 1][col + 23] = '\'';

    board[row][col + 2] = '`';
    board[row][col + 3] = '-';
    board[row][col + 4] = 'Y';
    board[row][col + 5] = '-';
    board[row][col + 6] = '-';
    board[row][col + 7] = '.';
    board[row][col + 8] = '_';
    board[row][col + 9] = '_';
    board[row][col + 10] = '_';
    board[row][col + 11] = '_';
    board[row][col + 12] = '_';
    board[row][col + 13] = '_';
    board[row][col + 14] = '_';
    board[row][col + 15] = '_';
    board[row][col + 16] = '_';
    board[row][col + 17] = '_';

    board[row][col + 18] = '.';
    board[row][col + 19] = '-';
    board[row][col + 20] = '-';
    board[row][col + 21] = 'Y';
    board[row][col + 22] = '-';
    board[row][col + 23] = '\'';

}



int boss(char board[100][1000], int row, int col,int stCol, int endCol) {
   
int ct=0;
    int direction =0;
    if(col==endCol) {
      direction = 1;
    }
    if(col==stCol) {
      direction = 0;
    }
  
    if(direction==0) {
      col++;
      ct++;
    } else {
      col--;
      ct++
    }

    if (col%5==0 {
         
        board[i][col+12]='0';


   }
    
    return 0;
}

