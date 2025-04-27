#include<iostream>
#include<conio.h>
using namespace std;


struct ladder {
    int Row, Col; //Position
    int length;
};

void drawLadder(char board[24][80], int row, int col , int length) {

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

void placeLadder(ladder& L , int row , int col , int length) {
    L.Row = row;
    L.Col = col;
    L.length = length;
    //drawLadderDependingOnLength(board, row, col, length);
}
            
void climp(char board[24][80], int& posJHero, int& posIHero, int widthHero, int heightHero, int col,int row , int length) {
    
    ladder ladders[4];
    
    // Check every cell in the column to the right of the player
    for(int i =0 ; i< 4 ; i++){
        if (posJHero <= ladders[i].Col + 11 && posJHero >= ladders[i].Col) {
            if (posIHero <= ladders[i].Row && posIHero - heightHero + 1 >= ladders[i].Row - length) {
            
                if(getch()=='w') posIHero--;
               
                else if (getch()=='s'){ 
                    posIHero++;
                 }
            
            }
        }       
    }

}
    

    
    








