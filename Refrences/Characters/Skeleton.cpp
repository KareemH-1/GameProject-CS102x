#include <iostream>
#include <conio.h>
using namespace std;

void DrawSkeleton(char board[100][1000], int row, int col) {
  
  //head
  
    board[row-1][col+5]='-';
    board[row-2][col+4]='.';
    board[row-2][col+6]='.';
    board[row-3][col+3]='(';
    board[row-3][col+4]='o';
    board[row-3][col+5]='.';
    board[row-3][col+6]='o';
    board[row-3][col+7]=')';
    board[row-4][col+6]='|';
    board[row-4][col+5]='=';
    board[row-4][col+4]='|';


    //body

    board[row-5][col+3]='_';
    board[row-6][col+3]='.';
    board[row-7][col+3]='.';
    board[row-8][col+3]='.';
    board[row-9][col+3]=')';
    board[row-5][col+4]='_';
    board[row-6][col+4]='=';
    board[row-7][col+4]='=';
    board[row-8][col+4]='=';
    board[row-9][col+4]='_';
    board[row-5][col+5]='|';
    board[row-6][col+5]='|';
    board[row-7][col+5]='|';
    board[row-8][col+5]='|';
    board[row-9][col+5]='=';
    board[row-5][col+6]='_';
    board[row-6][col+6]='=';
    board[row-7][col+6]='=';
    board[row-8][col+6]='=';
    board[row-9][col+6]='_';
    board[row-5][col+7]='_';
    board[row-6][col+7]='.';
    board[row-7][col+7]='.';
    board[row-8][col+7]='.';
    board[row-9][col+7]='_';



    //right hand
    
    
    board[row-6][col+8]='\\';
    board[row-6][col+9]='\\';
    board[row-7][col+9]='\\';
    board[row-7][col+10]='\\';
    board[row-8][col+10]='/';
    board[row-8][col+9]='';
    board[row]-9[col]='';
    board[row][co-9l]='';



    //left hand
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';


    //right leg

    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';


    //left leg
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';

}







void skeleton(char board[100][1000], int& row, int& col ,int stRow,int stCol,int endCol) {
    
    
    for (int i = stCol; i < 100; i++) {
    DrawSkeleton(board, stRow, i);   
        
    }
}
///to do later:- make if the last skely row touch hero hp-- 