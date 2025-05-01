#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

    struct Enemy{
        int Row, Col; //Position
        int isKillable; // 1 for killable , 0 for not killable
        int maxHeight = 11, maxWidth = 13; //Max height and width
        int Health = 100;
        int attackPower = 10;
    };

  
    struct player {
	    int Row, Col; //Position
    	int maxHeight = 9, maxWidth = 15; //Max height and width

	    int Health;
    	int coins; //Either coins or Level , until decided i will leave it as coins

	    int shootR, shootC;
	    int gun; //Either 1 for gun (bullets) or 2 for Lazerbeam (lazer)
	    int ammo, maxAmmo; // (ammo/maxAmmo) , max ammo could be 24 for gun , (maxammo == 1) for lazerbeam

    };

    int chanceShoot(){
        int chance = rand() % 3 + 1;
        
        if(chance == 1) return 1;
        else return 0; 
    }

    int chanceMove(){
        int chance = rand() % 2 + 1;
        
        if(chance == 1) return 1;
        else return 2; 
    }
    
    
void drawDevil(char board[100][1000], Enemy devil) {
	int row = devil.Row, col = devil.Col;

	//legs
	board[row][col + 2] = '#';
	board[row][col + 6] = '#';
	board[row][col + 7] = '`';

	//staff
	board[row][col + 10] = '|';
	board[row - 1][col + 10] = '|';
	board[row - 2][col + 10] = '|';
	board[row - 3][col + 10] = '|';
	board[row - 4][col + 10] = '|';
	board[row - 7][col + 10] = '|';
	board[row - 8][col + 10] = '|';
	board[row - 9][col + 10] = '|';

	board[row - 9][col + 8] = 'v';
	board[row - 10][col + 10] = 'v';
	board[row - 9][col + 12] = 'v';

	board[row - 8][col + 8] = '\\';
	board[row - 8][col + 12] = '/';

	board[row - 8][col + 11] = '_';
	board[row - 8][col + 9] = '_';

	//Body
	board[row - 1][col] = ')';
	board[row - 1][col + 1] = '_';
	board[row - 1][col + 2] = '/';
	board[row - 1][col + 3] = '/';
	board[row - 1][col + 4] = '`';
	board[row - 1][col + 5] = '_';
	board[row - 1][col + 6] = '_';
	board[row - 1][col + 7] = '>';
	board[row - 1][col + 8] = '>';

	board[row - 2][col] = '/';
	board[row - 2][col + 1] = ' ';
	board[row - 2][col + 2] = ' ';
	board[row - 2][col + 3] = ')';
	board[row - 2][col + 4] = '^';
	board[row - 2][col + 5] = '/';
	board[row - 2][col + 6] = '\\';

	board[row - 2][col + 7] = '^';
	board[row - 2][col + 8] = '(';

	board[row - 3][col + 1] = '/';
	board[row - 3][col + 2] = ' ';
	board[row - 3][col + 3] = '/';
	board[row - 3][col + 4] = '^';
	board[row - 3][col + 5] = ' ';
	board[row - 3][col + 6] = '^';
	board[row - 3][col + 7] = ' ';
	board[row - 3][col + 8] = '\\';

	board[row - 4][col + 2] = '/';
	board[row - 4][col + 3] = ')';
	board[row - 4][col + 4] = ')';
	board[row - 4][col + 5] = ')';
	board[row - 4][col + 6] = '-';
	board[row - 4][col + 7] = '(';

	board[row - 5][col + 2] = '\\';
	board[row - 5][col + 3] = ' ';
	board[row - 5][col + 4] = '(';
	board[row - 5][col + 5] = ' ';
	board[row - 5][col + 6] = ' ';
	board[row - 5][col + 7] = '|';
	board[row - 5][col + 8] = '\\';
	board[row - 5][col + 9] = '_';
	board[row - 5][col + 10] = '/';

	board[row - 6][col + 2] = '\\';
	board[row - 6][col + 3] = ' ';
	board[row - 6][col + 4] = ' ';
	board[row - 6][col + 5] = '\\';
	board[row - 6][col + 6] = '/';
	board[row - 6][col + 7] = '`';
	board[row - 6][col + 8] = '\\';
	board[row - 6][col + 9] = '<';
	board[row - 6][col + 10] = '`';
	board[row - 6][col + 11] = ')';

	//head

	board[row - 7][col + 3] = '_';
	board[row - 7][col + 4] = '\\';
	board[row - 7][col + 5] = '_';
	board[row - 7][col + 6] = '/';

	board[row - 8][col + 4] = '/';
	board[row - 8][col + 5] = '\\';
	board[row - 8][col + 6] = '/';
	board[row - 8][col + 7] = '\\';

	board[row - 9][col + 4] = '(';
	board[row - 9][col + 5] = '_';
	board[row - 9][col + 6] = '_';
	board[row - 9][col + 7] = ')';
}

    void SpawnFireBall(Enemy devil , int& row,int& col , int & r , int & endR , int & endC){
        int chance = chanceShoot();
        
        if(chanceShoot() && row ==NULL && col == NULL){                                
            r = chanceMove();

            if(r == 1){
                row = devil.Row - 10;
                col = devil.Col + devil.maxWidth;
            }
            else if(r == 2){
                row = devil.Row - 3;
                col = devil.Col + devil.maxWidth;
            }
   
        
        if(r == 1){ //Diagonal shoot
            endR = row + 10;
            endC = col + 10;
        }

        else if(r == 2){  //Horizontal shoot
            endR = row;
            endC = col+ 20
        }
    }

    else {
        row = NULL;
        col = NULL;
    }
}

    //asci 
    void drawMoveFireBallDiagonal(char board[100][1000],int& row, int& col , int  endR , int endC){
        if(row <= endR && col<=endC){
            board[row][col] = char(232);
            row++;
            col++;
        }
        else {
            row = NULL;
            col = NULL;
        }
    }
    
    void drawMoveFireBallHorizontal(char board[100][1000],int& row, int& col , int endC){
        if(col<=endC){
            board[row][col] = char(232);
            col++;
        }
        else {
            row = NULL;
            col = NULL;
        }
    }

    
    void controlFireBall(char board[100][1000],int& row, int& col , int r , int  endR , int endC , player& Player){

        if (row !=NULL && col != NULL && !collisionCheckFireballPlayer(row , col ,Player )){

            if(r == 1 && board[row+1][col+1]==' ') drawMoveFireBallDiagonal(board , row , col ,endR , endC);
            else if(r ==2 && board[row][col+1] == ' ') drawMoveFireBallHorizontal(board , row , col , endC);
        }
        else if(collisionCheckFireballPlayer(row , col , Player)){
            row = NULL;
            col = NULL;
            Player.Health -=10; // player gets damaged if the fireball hits him
        }
    }

    int collisionCheckFireballPlayer(int ballR , int ballC , player Player){
        int playerBottom = Player.Row;
        int playerRight = Player.Col + 14;
        int playerTop = Player.Row - 8;
        int playerLeft = Player.Col;

        if (ballR >= playerTop-1 && ballR <= playerBottom+1 && ballC >= playerLeft-1 && ballC <= playerRight+1) return 1;

    }


int main(){
    srand(time(0));
 }