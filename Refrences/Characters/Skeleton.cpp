#include <iostream>
#include <conio.h>
using namespace std;


struct enemy{
int Row , Col , Health;
};

void DrawSkeleton(char board[100][1000] , enemy Skeleton) {
  
  int row = Skeleton.Row , col = Skeleton.Col;
  //head
  
    board[row-14][col+5]='-';
    board[row-13][col+4]='.';
    board[row-13][col+6]='.';
    board[row-12][col+3]='(';
    board[row-12][col+4]='o';
    board[row-12][col+5]='.';
    board[row-12][col+6]='o';
    board[row-12][col+7]=')';
    board[row-11][col+6]='|';
    board[row-11][col+5]='=';
    board[row-11][col+4]='|';


    //body

    board[row-10][col+3]='_';
    board[row-9][col+3]='.';
    board[row-8][col+3]='.';
    board[row-7][col+3]='.';
    board[row-6][col+3]='(';
    board[row-10][col+4]='_';
    board[row-9][col+4]='=';
    board[row-8][col+4]='=';
    board[row-7][col+4]='=';
    board[row-6][col+4]='_';
    board[row-10][col+5]='|';
    board[row-9][col+5]='|';
    board[row-8][col+5]='|';
    board[row-7][col+5]='|';
    board[row-6][col+5]='=';
    board[row-10][col+6]='_';
    board[row-9][col+6]='=';
    board[row-8][col+6]='=';
    board[row-7][col+6]='=';
    board[row-6][col+6]='_';
    board[row-10][col+7]='_';
    board[row-9][col+7]='.';
    board[row-8][col+7]='.';
    board[row-7][col+7]='.';
    board[row-6][col+7]='_';



    //right hand
    
    
    board[row-9][col+8]='\\';
    board[row-9][col+9]='\\';
    board[row-8][col+9]='\\';
    board[row-8][col+10]='\\';
    board[row-7][col+10]='/';
    board[row-7][col+9]='/';
    board[row-6][col+9]='/';
    board[row-6][col+8]='/';
    board[row-5][col+8]=')';



    //left hand
    board[row-9][col+2]='/';
    board[row-9][col+1]='/';
    board[row-8][col+1]='/';
    board[row-8][col]='/';
    board[row-7][col]='\\';
    board[row-7][col+1]='\\';
    board[row-6][col+1]='\\';
    board[row-6][col+2]='\\';
    board[row-5][col+3]='(';


    //right leg

    board[row-5][col+3]=':';
    board[row-4][col+3]='|';
    board[row-3][col+3]=')';
    board[row-2][col+3]='|';
    board[row-1][col+3]='|';
    board[row][col+3]='=';
    board[row][col+2]='=';
    board[row-5][col+4]='|';
    board[row-4][col+4]='|';
    board[row-3][col+4]=')';
    board[row-2][col+4]='|'; 
    board[row-1][col+4]='|';
    board[row][col+4]='\'';
    


    //left leg
    board[row-5][col+6]='|';
    board[row-4][col+6]='|';
    board[row-3][col+6]='(';
    board[row-2][col+6]='|';
    board[row-1][col+6]='|';
    board[row][col+6]='\'';
    board[row-5][col+7]=':';
    board[row-4][col+7]='|';
    board[row-3][col+7]=')';
    board[row-2][col+7]='|';
    board[row-1][col+7]='|';
    board[row][col+7]='=';
    board[row][col+8]='=';
    

    

    int hp = Skeleton.Health;
    board[row-16][col+3] = 'H';
    board[row-16][col+4] = 'P';
    board[row-16][col+5] = ':';
    
    if (hp>9 && hp < 100){
      int fDig = hp/10 , sDig = hp%10;
  
       board[row-16][col+6] = fDig + '0';
       board[row-16][col+7] = sDig+ '0';
    }
    else if (hp >= 100){
      int fDig = hp/100 , sDig = (hp/10)%10 , tDig = hp%10;
  
      board[row-16][col+6] = fDig+ '0';
      board[row-16][col+7] = sDig+ '0';
      board[row-16][col+8] = tDig+ '0';
    }
    else if(hp >=0 && hp <=9){
      board[row-16][col+6] = hp+ '0';
    }

}







void skeleton(char board[100][1000], int& col ,int stCol,int endCol,int& direction) {
    
  int direction =0;
      if(col==endCol) {
        direction = 1;
      }
      if(col==stCol) {
        direction = 0;
      }
    
      if(direction==0) {
        col++;
      } else {
        col--;
      }
        
    
}
