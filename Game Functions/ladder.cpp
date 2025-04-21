#include<iostream>
#include<conio.h>
using namespace std;
void drawladder(char board[24][80], int row, int col) {
    //retard ladder under construction still
    board[row - 1][col + 4] = '|';
    board[row - 2][col + 4] = '|';
    board[row - 3][col + 4] = '|';
    board[row - 4][col + 4] = '|';
    board[row - 5][col + 4] = '|';
    board[row - 6][col + 4] = '|';
    board[row - 7][col + 4] = '|';
    board[row - 8][col + 4] = '|';
    board[row - 9][col + 4] = '|';
    board[row - 9][col + 3] = '_';
    board[row - 9][col + 2] = '_';
    board[row - 6][col + 3] = '_';
    board[row - 6][col + 2] = '_';
    board[row - 3][col + 3] = '_';
    board[row - 6][col + 2] = '_';
    board[row - 1][col + 1] = '|';
    board[row - 2][col + 1] = '|';
    board[row - 3][col + 1] = '|';
    board[row - 4][col + 1] = '|';
    board[row - 5][col + 1] = '|';
    board[row - 6][col + 1] = '|';
    board[row - 7][col + 1] = '|';
    board[row - 8][col + 1] = '|';
    board[row - 9][col + 1] = '|';
}


void main(){
    char board[24][80] = { ' ' };
    int row = 10, col = 10;
    drawladder(board, row, col);
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 80; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}