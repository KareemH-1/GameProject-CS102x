#include <iostream>
#include <conio.h>
using namespace std;

void TeleportPlayer1(char board[100][1000],int row,int col, int& pX, int& pY, int teleportX, int teleportY,int& coins,char& signal,int teleport2x, int teleport2y,int& hp)  {
         if(coins>=250 && pX==teleportX-1 && pY>=teleportY && pY<=teleportY+17) {
            if(_kbhit()) {
                char signal = _getch();
                if(signal == 'e' || signal == 'E') {
                    pX = teleport2x - 1;
                    pY = teleport2y + 1;
                    coins -= 250; // Deduct the cost of teleportation
                    signal = 'e'; // Signal that teleportation has occurred
                }
            }
         }   
     else {

        //isOnTelep
        board[row-1][col+4] = 'L';
        board[row-1][col+5] = 'A';
        board[row-1][col+6] = 'C';
        board[row-1][col+6] = 'K';
        board[row-1][col+7] = 'I';
        board[row-1][col+8] = 'N';
        board[row-1][col+9] = 'G';
        board[row-1][col+10] = ' ';
        board[row-1][col+11] = 'C';
        board[row-1][col+12] = 'O';
        board[row-1][col+13] = 'I';
        board[row-1][col+14] = 'N';
        board[row-1][col+15] = 'S';
        cout << "lacking coins" << endl; //???? maybe send a variable to the draw teleporter 1 and display this message in a form of board[row-number][col+ anotherNumber] = 'Y'; and so on
    }
    if(pX==teleport2x-1 && pY>=teleport2y && pY<=teleport2y+17){
        if(_kbhit()) {
            char signal = _getch();
            if(signal == 'e' || signal == 'E') {
            
                //The teleporter takes no cowards massage
                board[teleport2x-16][teleport2y] = 'T';
                board[teleport2x-16][teleport2y+1] = 'h';
                board[teleport2x-16][teleport2y+2] = 'e';
                board[teleport2x-16][teleport2y+3] = ' ';
                board[teleport2x-16][teleport2y+4] = 't';
                board[teleport2x-16][teleport2y+5] = 'e';
                board[teleport2x-16][teleport2y+6] = 'l';
                board[teleport2x-16][teleport2y+7] = 'e';
                board[teleport2x-16][teleport2y+8] = 'p';
                board[teleport2x-16][teleport2y+9] = 'o';
                board[teleport2x-16][teleport2y+10] = 'r';
                board[teleport2x-16][teleport2y+11] = 't';
                board[teleport2x-16][teleport2y+12] = 'e';
                board[teleport2x-16][teleport2y+13] = 'r';
                board[teleport2x-16][teleport2y+14] = ' ';
                board[teleport2x-16][teleport2y+15] = 't';
                board[teleport2x-16][teleport2y+16] = 'a';
                board[teleport2x-16][teleport2y+17] = 'k';
                board[teleport2x-16][teleport2y+18] = 'e';
                board[teleport2x-16][teleport2y+19] = 's';
                board[teleport2x-16][teleport2y+20] = ' ';
                board[teleport2x-16][teleport2y+21] = 'n';
                board[teleport2x-16][teleport2y+22] = 'o';
                board[teleport2x-16][teleport2y+23] = ' ';
                board[teleport2x-16][teleport2y+24] = 'c';
                board[teleport2x-16][teleport2y+25] = 'o';
                board[teleport2x-16][teleport2y+26] = 'w';
                board[teleport2x-16][teleport2y+28] = 'a';
                board[teleport2x-16][teleport2y+29] = 'r';
                board[teleport2x-16][teleport2y+30] = 'd';
                board[teleport2x-16][teleport2y+31] = 's';

                hp--;
            }
        }
    }
}


