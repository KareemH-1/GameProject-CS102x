#include <iostream>
#include <conio.h>
using namespace std;

void DrawSkeleton(char board[100][1000], int row, int col) {
  
  //head
  
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


    //body

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
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';



    //right hand
    
    
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';
    board[row][col]='';



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


void skely(char board[100][1000], int& row, int& col ,int stRow,int stCol,int endCol) {
    
    
    for (int i = stCol; i < 100; i++) {
    DrawSkeleton(board, stRow, i);   
        
    }
}
///to do later:- make if the last skely row touch hero hp-- 