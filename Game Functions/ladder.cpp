#include<iostream>
#include<conio.h>
using namespace std;


void drawLadderDependingOnLength(char board[24][80], int row, int col , int length) {

    for (int i = 0; i < length; i++) {
        board[row - i][col] = '|';
        board[row - i][col + 1] = '|';

        board[row - i][col + 2] = '-';
        board[row - i][col + 3] = '-';
        board[row - i][col + 4] = '-';
        board[row - i][col + 5] = '-';
        board[row - i][col + 6] = '-';
        board[row - i][col + 7] = '-';
        board[row - i][col + 8] = '-';
        board[row - i][col + 9] = '-';
        board[row - i][col + 10] = '-';
        board[row - i][col + 11] = '-';

        board[row - i][col + 12] = '|';
        board[row - i][col + 13] = '|';
    }

}   

void drawladder(char board[24][80], int row, int col) {
        //retard ladder under construction still

        board[row - 1][col] = '|';
        board[row - 2][col] = '|';
        board[row - 3][col] = '|';
        board[row - 4][col] = '|';
        board[row - 5][col] = '|';
        board[row - 6][col] = '|';
        board[row - 7][col] = '|';
        board[row - 8][col] = '|';
        board[row - 9][col] = '|';

        board[row - 1][col + 1] = '|';
        board[row - 2][col + 1] = '|';
        board[row - 3][col + 1] = '|';
        board[row - 4][col + 1] = '|';
        board[row - 5][col + 1] = '|';
        board[row - 6][col + 1] = '|';
        board[row - 7][col + 1] = '|';
        board[row - 8][col + 1] = '|';
        board[row - 9][col + 1] = '|';

        board[row - 1][col + 2] = '-';
        board[row - 1][col + 3] = '-';
        board[row - 1][col + 4] = '-';

        board[row - 2][col + 2] = '-';
        board[row - 2][col + 3] = '-';
        board[row - 2][col + 4] = '-';


        board[row - 3][col + 2] = '-';
        board[row - 3][col + 3] = '-';
        board[row - 3][col + 4] = '-';

        board[row - 4][col + 2] = '-';
        board[row - 4][col + 3] = '-';
        board[row - 4][col + 4] = '-';

        board[row - 5][col + 2] = '-';
        board[row - 5][col + 3] = '-';
        board[row - 5][col + 4] = '-';


        board[row - 6][col + 2] = '-';
        board[row - 6][col + 3] = '-';
        board[row - 6][col + 4] = '-';

        board[row - 7][col + 2] = '-';
        board[row - 7][col + 3] = '-';
        board[row - 7][col + 4] = '-';


        board[row - 8][col + 2] = '-';
        board[row - 8][col + 3] = '-';
        board[row - 8][col + 4] = '-';

        board[row - 9][col + 2] = '-';
        board[row - 9][col + 3] = '-';
        board[row - 9][col + 4] = '-';


        board[row - 1][col + 5] = '|';
        board[row - 2][col + 5] = '|';
        board[row - 3][col + 5] = '|';
        board[row - 4][col + 5] = '|';
        board[row - 5][col + 5] = '|';
        board[row - 6][col + 5] = '|';
        board[row - 7][col + 5] = '|';
        board[row - 8][col + 5] = '|';
        board[row - 9][col + 5] = '|';

        board[row - 1][col + 6] = '|';
        board[row - 2][col + 6] = '|';
        board[row - 3][col + 6] = '|';
        board[row - 4][col + 6] = '|';
        board[row - 5][col + 6] = '|';
        board[row - 6][col + 6] = '|';
        board[row - 7][col + 6] = '|';
        board[row - 8][col + 6] = '|';
        board[row - 9][col + 6] = '|';
}

            
void climp(char board[24][80], int& posJHero, int& posIHero, int widthHero, int heightHero, int col,int row , int length) {
    int check = 1;
    // Check every cell in the column to the right of the player
    for (int i = posIHero; i >= posIHero - heightHero + 1; i--) {
         if (posJHero <=col + 11 && posJHero >= col) {
             if(getch()=='w'){
                 if (posIHero + 1 <=row-1 && posIHero - heightHero + 1 >= row - length) {
                     
                     posIHero--;
                 }
             }
             
         }
    }
       
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
    

    
    








