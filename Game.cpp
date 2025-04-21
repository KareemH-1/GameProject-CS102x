#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;


//ANSI CODE COLORS
char green[] = "\033[32m";
char blue[] = "\033[34m";
char red[] = "\033[31m";
char yellow[] = "\033[33m";
char cyan[] = "\033[36m";
char reset[] = "\033[0m";
char bold[] = "\033[1m";

struct player {
	int Row, Col; //Position
	int maxHeight = 9, maxWidth = 15; //Max height and width
	int Health;
	int coins; //Either coins or Level , until decided i will leave it as coins
	int shootR, shootC;
	int gun; //Either 1 for gun (bullets) or 2 for Lazerbeam (lazer)
	int ammo, maxAmmo; // (ammo/maxAmmo) , max ammo could be 24 for gun , (maxammo == 1) for lazerbeam
	int Reload[2] = { 1 , 3 }; //coolDown[0] for gun , coolDown[1] for lazerbeam
};

struct Enemy {
	int Row, Col; //Position
	int maxHeight = 1, maxWidth = 1; //Max height and width
	int Health;
};
void showMainMenu(char& choice) {
	cout << "==================================================" << endl;
	cout << "||                                              ||" << endl;
	cout << "||                                              ||" << endl;
	cout << "||           C S 1 0 2 x  P r o j e c t         ||" << endl;
	cout << "||                                              ||" << endl;
	cout << "||                1. Start Game                 ||" << endl;
	cout << "||                2. Instructions               ||" << endl;
	cout << "||                3. Credits                    ||" << endl;
	cout << "||                4. Exit                       ||" << endl;
	cout << "||                                              ||" << endl;
	cout << "==================================================" << endl;
	cout << "Please select an option: ";
	cin >> choice;
}

void displayInstructions() {
	cout << "==================================================" << endl;
	cout << "||              I N S T R U C T I O N S         ||" << endl;
	cout << "==================================================" << endl;
	cout << "||  Controls:                                   ||" << endl;
	cout << "||                                              ||" << endl;
	cout << "||  W  - Jump / Climb Up                        ||" << endl;
	cout << "||  A  - Move Left                              ||" << endl;
	cout << "||  D  - Move Right                             ||" << endl;
	cout << "||  S  - Climb Down                             ||" << endl;
	cout << "||  R  - Reload                                 ||" << endl;
	cout << "||  Q  - Switch Weapons                         ||" << endl;
	cout << "||  J  - Shoot                                  ||" << endl;
	cout << "==================================================" << endl;
	cout << "||  Press any key to return to main menu...     ||" << endl;
	cout << "==================================================" << endl;

	char Key;
	cin >> Key;
}


void displayCredits() {
	cout << "==================================================" << endl;
	cout << "||                C R E D I T S                 ||" << endl;
	cout << "==================================================" << endl;
	cout << "||  Game developed by:                          ||" << endl;
	cout << "||                                              ||" << endl;
	cout << "||  1. Kareem Ahmed Taha    - 254915            ||" << endl;
	cout << "||  2. Mazen Mahmoud Gamal  - 254720            ||" << endl;
	cout << "||  3. Ahmed Emad Mohammed  - 251147            ||" << endl;
	cout << "==================================================" << endl;
	cout << "||  Press any key to return to main menu...     ||" << endl;
	cout << "==================================================" << endl;

	char Key;
	cin >> Key;
}


void initializePlayerValues(int& Row, int& Col, int& maxHeight, int& maxWidth, int& Health, int& coins, int& gun, int& ammo, int& maxAmmo, int& shootC, int& shootR) {
	Row = 19;
	Col = 3;
	maxHeight = 9;
	maxWidth = 15;
	Health = 100;
	coins = 0;
	gun = 1; //Start with gun
	ammo = 24; //Full ammo on start
	maxAmmo = 24; //max ammo
	shootR = 19 - 4;
	shootC = 3 + 15;
}



void initializeBoard(char border[24][80]) {
	// Initialize all cells to be empty
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 80; j++) {
			border[i][j] = ' ';
		}
	}

	// Top border 
	border[0][0] = char(201);
	for (int j = 1; j < 80 - 1; j++) {
		border[0][j] = char(205);
	}
	border[0][79] = char(187);

	// Middle section with side borders
	for (int i = 1; i < 24 - 1; i++) {
		border[i][0] = char(186);
		border[i][79] = char(186);
	}

	// Bottom border
	border[23][0] = char(200);
	for (int j = 1; j < 80 - 1; j++) {
		border[23][j] = char(205);
	}
	border[23][79] = char(188);
}
void dispBar(int health, int coins, int ammo, int maxAmmo, char gun[]) {
	cout << blue;
	//upper border
	cout << char(201);
	for (int i = 1; i < 79; i++) {
		cout << char(205);
	}
	cout << char(187);
	cout << endl;
	cout << reset;
	cout << blue << char(186) << reset << "           HEALTH " << green << bold << health << "%" << reset << "  |  COINS " << yellow << bold << coins << reset << "  |  " << yellow << bold << gun << reset << "  |  AMMO " << yellow << bold << ammo << " / " << maxAmmo << reset << blue << "                " << char(186) << reset << endl;
}

void dispBoard(char board[24][80]) {


	cout << blue; // Blue color for the board

	for (int i = 0; i < 80; i++) {
		cout << board[0][i];
	}
	cout << endl;
	//i =1 to ignore first border and i<23 to ignore last border
	for (int i = 1; i < 23; i++) {
		cout << board[i][0]; //Left border
		cout << reset; //reset the blue color , as we dont want the whole board to be blue
		for (int j = 1; j < 79; j++) {
			cout << board[i][j];
		}
		cout << blue; //Blue color for the right board
		cout << board[i][79]; //Right border
		cout << endl;
	}
	for (int i = 0; i < 80; i++) {
		cout << board[23][i];
	}
	cout << endl;
	cout << reset;

}



void drawEnemyBirdLeft(char board[24][80], int row, int col) {
	//base
	board[row][col + 2] = '`';
	board[row][col + 3] = '-';
	board[row][col + 4] = '-';
	board[row][col + 5] = '-';
	board[row][col + 6] = '-';
	board[row][col + 7] = '\'';

	//right
	board[row - 1][col + 7] = '_';
	board[row - 1][col + 6] = '.';
	board[row - 1][col + 8] = '>';

	//top
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 5] = '_';
	board[row - 2][col + 4] = ')';
	board[row - 3][col + 3] = '_';
	board[row - 3][col + 2] = '_';

	//left
	board[row - 2][col + 2] = 'o';
	board[row - 2][col + 1] = '(';
	board[row - 1][col + 1] = '(';
	board[row - 2][col] = '<';
}

void drawEnemyBirdRight(char board[24][80], int row, int col) {
	//base
	board[row][col + 1] = '\'';
	board[row][col + 2] = '-';
	board[row][col + 3] = '-';
	board[row][col + 4] = '-';
	board[row][col + 5] = '-';
	board[row][col + 6] = '`';

	//Right
	board[row - 1][col + 7] = ')';
	board[row - 2][col + 7] = ')';
	board[row - 2][col + 8] = '>';
	board[row - 2][col + 6] = 'o';

	//top

	board[row - 3][col + 6] = '_';
	board[row - 3][col + 5] = '_';
	board[row - 2][col + 4] = '(';
	board[row - 2][col + 3] = '_';
	board[row - 2][col + 2] = '_';
	board[row - 2][col + 1] = '_';

	//Left
	board[row - 1][col] = '<';
	board[row - 1][col + 1] = '_';
	board[row - 1][col + 2] = '.';
}








// Walking right frames
void drawPlayerRightFrame1(char board[24][80], int row, int col, int& shootR, int shootC) {
	//left arm
	board[row - 3][col] = '/';
	board[row - 4][col + 1] = '/';
	board[row - 5][col + 2] = '/';

	//left leg
	board[row][col + 3] = '|';
	board[row - 1][col + 3] = '|';
	board[row][col + 4] = '_';
	board[row][col + 5] = '|';
	board[row - 1][col + 5] = '|';

	//right leg
	board[row][col + 7] = '|';
	board[row][col + 8] = '_';
	board[row][col + 9] = '|';
	board[row - 1][col + 7] = '|';
	board[row - 1][col + 9] = '|';


	//right arm
	board[row - 4][col + 10] = '-';
	board[row - 4][col + 11] = '-';
	board[row - 4][col + 12] = '-';
	board[row - 4][col + 13] = '|';
	board[row - 4][col + 14] = '/';
	shootR = row - 4;
	shootC = col + 15;
	board[row - 5][col + 14] = '\\';
	board[row - 5][col + 13] = '|';
	board[row - 5][col + 12] = '-';
	board[row - 5][col + 11] = '-';
	board[row - 5][col + 10] = '-';

	//body

	board[row - 2][col + 3] = '\\';
	board[row - 2][col + 4] = '_';
	board[row - 2][col + 5] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 8] = '_';
	board[row - 2][col + 9] = '/';
	board[row - 3][col + 9] = '|';
	board[row - 4][col + 9] = '|';
	board[row - 5][col + 9] = '|';
	board[row - 3][col + 3] = '|';
	board[row - 4][col + 3] = '|';
	board[row - 5][col + 3] = '|';
	board[row - 5][col + 4] = '-';
	board[row - 5][col + 5] = '-';
	board[row - 5][col + 6] = 'v';
	board[row - 5][col + 7] = '-';
	board[row - 5][col + 8] = '-';




	//head

	board[row - 6][col + 4] = '\\';
	board[row - 7][col + 4] = '/';
	board[row - 8][col + 5] = '_';
	board[row - 8][col + 6] = '_';
	board[row - 8][col + 7] = '_';
	board[row - 7][col + 8] = ')';
	board[row - 7][col + 5] = '(';
	board[row - 7][col + 6] = '.';
	board[row - 7][col + 7] = '.';
	board[row - 6][col + 8] = '/';
	board[row - 6][col + 7] = '-';
	board[row - 6][col + 6] = '-';
	board[row - 6][col + 5] = '-';





}



void drawPlayerRightFrame2 (char board[24][80], int row, int col, int& shootR, int shootC) {
	//left arm
	board[row - 3][col] = '/';
	board[row - 4][col + 1] = '/';
	board[row - 5][col + 2] = '/';

	//left leg
    board[row][col +2 ] = '/';
    board[row][col +3 ] = '_';
    board[row][col +4 ] = '/';
    board[row-1][col +3 ] = '|';
    board[row-1][col +5 ] = '|';
    //right leg
    board[row-1][col + 7] = '\\';    
    board[row-1][col + 9] = '\\';    
    board[row][col + 8] = '\\';    
    board[row][col + 9] = '_';    
    board[row][col + 10] = '\\';   

    
	//right arm
	board[row - 4][col + 10] = '-';
	board[row - 4][col + 11] = '-';
	board[row - 4][col + 12] = '-';
	board[row - 4][col + 13] = '|';
	board[row - 4][col + 14] = '/';
	shootR = row - 4;
	shootC = col + 15;
	board[row - 5][col + 14] = '\\';
	board[row - 5][col + 13] = '|';
	board[row - 5][col + 12] = '-';
	board[row - 5][col + 11] = '-';
	board[row - 5][col + 10] = '-';

	//body

	board[row - 2][col + 3] = '\\';
	board[row - 2][col + 4] = '_';
	board[row - 2][col + 5] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 8] = '_';
	board[row - 2][col + 9] = '/';
	board[row - 3][col + 9] = '|';
	board[row - 4][col + 9] = '|';
	board[row - 5][col + 9] = '|';
	board[row - 3][col + 3] = '|';
	board[row - 4][col + 3] = '|';
	board[row - 5][col + 3] = '|';
	board[row - 5][col + 4] = '-';
	board[row - 5][col + 5] = '-';
	board[row - 5][col + 6] = 'v';
	board[row - 5][col + 7] = '-';
	board[row - 5][col + 8] = '-';




	//head

	board[row - 6][col + 4] = '\\';
	board[row - 7][col + 4] = '/';
	board[row - 8][col + 5] = '_';
	board[row - 8][col + 6] = '_';
	board[row - 8][col + 7] = '_';
	board[row - 7][col + 8] = ')';
	board[row - 7][col + 5] = '(';
	board[row - 7][col + 6] = '.';
	board[row - 7][col + 7] = '.';
	board[row - 6][col + 8] = '/';
	board[row - 6][col + 7] = '-';
	board[row - 6][col + 6] = '-';
	board[row - 6][col + 5] = '-';





}
void drawPlayerRightFrame3 (char board[24][80], int row, int col, int& shootR, int shootC) {
	//left arm
	board[row - 3][col+1] = '\\';
	board[row - 4][col + 1] = '/';
	board[row - 5][col + 2] = '/';

	//left leg
    board[row-2][col + 2] = '_';
    board[row-1][col+1] = '|';
    board[row-1][col + 2] = '_';
    board[row-1][col + 3] = '_';
    board[row-1][col + 4] = '_';
    board[row-1][col + 5] = '|';    
    
    //right leg
    board[row][col+6] = '|';
    board[row][col + 7] = '_';
    board[row][col + 8] = '|';
    board[row-1][col + 6] = '\\';
    board[row-1][col + 8] = '\\';

	//right arm
	board[row - 4][col + 10] = '-';
	board[row - 4][col + 11] = '-';
	board[row - 4][col + 12] = '-';
	board[row - 4][col + 13] = '|';
	board[row - 4][col + 14] = '/';
	shootR = row - 4;
	shootC = col + 15;
	board[row - 5][col + 14] = '\\';
	board[row - 5][col + 13] = '|';
	board[row - 5][col + 12] = '-';
	board[row - 5][col + 11] = '-';
	board[row - 5][col + 10] = '-';

	//body

	board[row - 2][col + 3] = '\\';
	board[row - 2][col + 4] = '_';
	board[row - 2][col + 5] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 8] = '_';
	board[row - 2][col + 9] = '/';
	board[row - 3][col + 9] = '|';
	board[row - 4][col + 9] = '|';
	board[row - 5][col + 9] = '|';
	board[row - 3][col + 3] = '|';
	board[row - 4][col + 3] = '|';
	board[row - 5][col + 3] = '|';
	board[row - 5][col + 4] = '-';
	board[row - 5][col + 5] = '-';
	board[row - 5][col + 6] = 'v';
	board[row - 5][col + 7] = '-';
	board[row - 5][col + 8] = '-';




	//head

	board[row - 6][col + 4] = '\\';
	board[row - 7][col + 4] = '/';
	board[row - 8][col + 5] = '_';
	board[row - 8][col + 6] = '_';
	board[row - 8][col + 7] = '_';
	board[row - 7][col + 8] = ')';
	board[row - 7][col + 5] = '(';
	board[row - 7][col + 6] = '.';
	board[row - 7][col + 7] = '.';
	board[row - 6][col + 8] = '/';
	board[row - 6][col + 7] = '-';
	board[row - 6][col + 6] = '-';
	board[row - 6][col + 5] = '-';


}


void drawPlayerRightFrame4 (char board[24][80], int row, int col, int& shootR, int shootC) {
	//left arm
	board[row - 3][col] = '/';
	board[row - 4][col + 1] = '/';
	board[row - 5][col + 2] = '/';

	//left leg
    board[row][col +3 ] = '|';
    board[row][col +4 ] = '_';
    board[row][col +5 ] = '|';

    board[row-1][col +3 ] = '\\';
    board[row-1][col +5 ] = '\\';

    //right leg
    board[row][col + 7] = '/';    
    board[row][col + 8] = '_';    
    board[row][col + 9] = '/';    
    board[row-1][col + 7] = '\\';    
    board[row-1][col + 9] = '\\';    

    
	//right arm
	board[row - 4][col + 10] = '-';
	board[row - 4][col + 11] = '-';
	board[row - 4][col + 12] = '-';
	board[row - 4][col + 13] = '|';
	board[row - 4][col + 14] = '/';
	shootR = row - 4;
	shootC = col + 15;
	board[row - 5][col + 14] = '\\';
	board[row - 5][col + 13] = '|';
	board[row - 5][col + 12] = '-';
	board[row - 5][col + 11] = '-';
	board[row - 5][col + 10] = '-';

	//body

	board[row - 2][col + 3] = '\\';
	board[row - 2][col + 4] = '_';
	board[row - 2][col + 5] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 8] = '_';
	board[row - 2][col + 9] = '/';
	board[row - 3][col + 9] = '|';
	board[row - 4][col + 9] = '|';
	board[row - 5][col + 9] = '|';
	board[row - 3][col + 3] = '|';
	board[row - 4][col + 3] = '|';
	board[row - 5][col + 3] = '|';
	board[row - 5][col + 4] = '-';
	board[row - 5][col + 5] = '-';
	board[row - 5][col + 6] = 'v';
	board[row - 5][col + 7] = '-';
	board[row - 5][col + 8] = '-';




	//head

	board[row - 6][col + 4] = '\\';
	board[row - 7][col + 4] = '/';
	board[row - 8][col + 5] = '_';
	board[row - 8][col + 6] = '_';
	board[row - 8][col + 7] = '_';
	board[row - 7][col + 8] = ')';
	board[row - 7][col + 5] = '(';
	board[row - 7][col + 6] = '.';
	board[row - 7][col + 7] = '.';
	board[row - 6][col + 8] = '/';
	board[row - 6][col + 7] = '-';
	board[row - 6][col + 6] = '-';
	board[row - 6][col + 5] = '-';





}


void drawPlayerRightFrame5 (char board[24][80], int row, int col, int& shootR, int shootC) {
	//left arm
	board[row - 3][col+1] = '\\';
	board[row - 4][col + 1] = '/';
	board[row - 5][col + 2] = '/';

    //Left leg
    board[row-2][col+2] = '_';
    board[row-1][col+2] = '|';
    board[row-1][col+3] = '_';
    board[row-1][col+7] = '_';
    board[row-1][col+8] = '|';

    //Right leg

    board[row-1][col+4] = '\\';
    board[row-1][col+6] = '\\';
    board[row][col+5] = '\\';
    board[row][col+6] = '_';
    board[row][col+7] ='\\';

	//right arm
	board[row - 4][col + 10] = '-';
	board[row - 4][col + 11] = '-';
	board[row - 4][col + 12] = '-';
	board[row - 4][col + 13] = '|';
	board[row - 4][col + 14] = '/';
	shootR = row - 4;
	shootC = col + 15;
	board[row - 5][col + 14] = '\\';
	board[row - 5][col + 13] = '|';
	board[row - 5][col + 12] = '-';
	board[row - 5][col + 11] = '-';
	board[row - 5][col + 10] = '-';

	//body

	board[row - 2][col + 3] = '\\';
	board[row - 2][col + 4] = '_';
	board[row - 2][col + 5] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 8] = '_';
	board[row - 2][col + 9] = '/';
	board[row - 3][col + 9] = '|';
	board[row - 4][col + 9] = '|';
	board[row - 5][col + 9] = '|';
	board[row - 3][col + 3] = '|';
	board[row - 4][col + 3] = '|';
	board[row - 5][col + 3] = '|';
	board[row - 5][col + 4] = '-';
	board[row - 5][col + 5] = '-';
	board[row - 5][col + 6] = 'v';
	board[row - 5][col + 7] = '-';
	board[row - 5][col + 8] = '-';




	//head

	board[row - 6][col + 4] = '\\';
	board[row - 7][col + 4] = '/';
	board[row - 8][col + 5] = '_';
	board[row - 8][col + 6] = '_';
	board[row - 8][col + 7] = '_';
	board[row - 7][col + 8] = ')';
	board[row - 7][col + 5] = '(';
	board[row - 7][col + 6] = '.';
	board[row - 7][col + 7] = '.';
	board[row - 6][col + 8] = '/';
	board[row - 6][col + 7] = '-';
	board[row - 6][col + 6] = '-';
	board[row - 6][col + 5] = '-';


}
/////////////////////////////////////////////






// Walking Left Frames
void DrawPlayerLeftFrame1(char board[24][80], int row, int col, int& shootingR, int& shootingC) {

	//head
	board[row - 7][col + 10] = '\\';
	board[row - 6][col + 10] = '/';

	board[row - 8][col + 6] = '_';
	board[row - 8][col + 7] = '_';
	board[row - 8][col + 8] = '_';
	board[row - 8][col + 9] = '_';

	board[row - 7][col + 9] = ')';
	board[row - 7][col + 6] = '(';
	board[row - 7][col + 7] = '.';
	board[row - 7][col + 8] = '.';
	board[row - 6][col + 6] = '\\';
	board[row - 6][col + 7] = '-';
	board[row - 6][col + 8] = '-';
	board[row - 6][col + 9] = '-';



	//body

	board[row - 2][col + 5] = '\\';
	board[row - 2][col + 9] = '_';
	board[row - 2][col + 10] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 8] = '_';
	board[row - 2][col + 11] = '/';
	board[row - 3][col + 11] = '|';
	board[row - 4][col + 11] = '|';
	board[row - 5][col + 11] = '|';
	board[row - 3][col + 5] = '|';
	board[row - 4][col + 5] = '|';
	board[row - 5][col + 5] = '|';
	board[row - 5][col + 6] = '-';
	board[row - 5][col + 7] = '-';
	board[row - 5][col + 8] = 'v';
	board[row - 5][col + 9] = '-';
	board[row - 5][col + 10] = '-';


	//left arm
	board[row - 4][col + 4] = '-';
	board[row - 4][col + 2] = '-';
	board[row - 4][col + 3] = '-';
	board[row - 4][col + 1] = '|';
	board[row - 5][col] = '/';
	board[row - 4][col] = '\\';
	shootingR = row - 4;
	shootingC = col - 1;
	board[row - 5][col + 1] = '|';
	board[row - 5][col + 2] = '-';
	board[row - 5][col + 3] = '-';
	board[row - 5][col + 4] = '-';



	//right leg
	board[row][col + 9] = '|';
	board[row][col + 10] = '_';
	board[row][col + 11] = '|';
	board[row - 1][col + 9] = '|';
	board[row - 1][col + 11] = '|';


	//right arm
	board[row - 3][col + 14] = '\\';
	board[row - 4][col + 13] = '\\';
	board[row - 5][col + 12] = '\\';


	//left leg
	board[row][col + 5] = '|';
	board[row - 1][col + 5] = '|';
	board[row][col + 6] = '_';
	board[row][col + 7] = '|';
	board[row - 1][col + 7] = '|';



}


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




//Jump frames
void jumprightframe(char board[24][80], int row, int col) {

	//head

	board[row - 6][col + 5] = '\\';
	board[row - 6][col + 9] = '/';
	board[row - 6][col + 6] = '_';
	board[row - 6][col + 7] = '_';
	board[row - 6][col + 8] = '_';
	board[row - 8][col + 6] = '_';
	board[row - 8][col + 7] = '_';
	board[row - 8][col + 8] = '_';
	board[row - 8][col + 9] = '_';
	board[row - 7][col + 5] = '/';
	board[row - 7][col + 6] = '(';
	board[row - 7][col + 7] = '.';
	board[row - 7][col + 8] = '.';
	board[row - 7][col + 9] = ')';


	//body

	board[row - 2][col + 4] = '\\';
	board[row - 2][col + 5] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 8] = '_';
	board[row - 2][col + 9] = '_';
	board[row - 2][col + 10] = '/';
	board[row - 3][col + 10] = '|';
	board[row - 4][col + 10] = '|';
	board[row - 5][col + 10] = '|';
	board[row - 3][col + 4] = '|';
	board[row - 4][col + 4] = '|';
	board[row - 5][col + 4] = '|';
	board[row - 5][col + 6] = '-';
	board[row - 5][col + 5] = '-';
	board[row - 5][col + 7] = 'v';
	board[row - 5][col + 8] = '-';
	board[row - 5][col + 9] = '-';




	//left arm

	board[row - 5][col] = '_';
	board[row - 5][col + 1] = '_';
	board[row - 5][col + 2] = '_';
	board[row - 5][col + 3] = '_';
	board[row - 4][col] = '|';
	board[row - 3][col] = '|';
	board[row - 3][col + 2] = '|';
	board[row - 3][col + 1] = '_';
	board[row - 4][col + 3] = '_';




	//right arm
	board[row - 5][col + 11] = '_';
	board[row - 5][col + 12] = '_';
	board[row - 5][col + 13] = '_';
	board[row - 5][col + 14] = '|';
	board[row - 6][col + 14] = '|';
	board[row - 6][col + 11] = '_';
	board[row - 6][col + 12] = '|';
	board[row - 7][col + 13] = '_';




	//left leg
	board[row][col + 4] = '|';
	board[row - 1][col + 4] = '|';
	board[row][col + 5] = '_';
	board[row][col + 6] = '|';
	board[row - 1][col + 6] = '|';



	//right leg
	board[row - 1][col + 10] = '/';
	board[row - 1][col + 8] = '/';
	board[row - 1][col + 9] = '_';

}



void jumpleftframe(char board[24][80], int row, int col) {


	//head

	board[row - 6][col + 5] = '\\';
	board[row - 6][col + 9] = '/';
	board[row - 6][col + 6] = '_';
	board[row - 6][col + 7] = '_';
	board[row - 6][col + 8] = '_';
	board[row - 8][col + 6] = '_';
	board[row - 8][col + 7] = '_';
	board[row - 8][col + 8] = '_';
	board[row - 8][col + 5] = '_';
	board[row - 7][col + 9] = '\\';
	board[row - 7][col + 5] = '(';
	board[row - 7][col + 7] = '.';
	board[row - 7][col + 6] = '.';
	board[row - 7][col + 8] = ')';
	board[row - 7][col + 9] = '\\';


	//body

	board[row - 2][col + 4] = '\\';
	board[row - 2][col + 5] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 8] = '_';
	board[row - 2][col + 9] = '_';
	board[row - 2][col + 10] = '/';
	board[row - 3][col + 10] = '|';
	board[row - 4][col + 10] = '|';
	board[row - 5][col + 10] = '|';
	board[row - 3][col + 4] = '|';
	board[row - 4][col + 4] = '|';
	board[row - 5][col + 4] = '|';
	board[row - 5][col + 6] = '-';
	board[row - 5][col + 5] = '-';
	board[row - 5][col + 7] = 'v';
	board[row - 5][col + 8] = '-';
	board[row - 5][col + 9] = '-';




	//right arm

	board[row - 6][col + 11] = '_';
	board[row - 6][col + 12] = '_';
	board[row - 6][col + 13] = '_';
	board[row - 6][col + 14] = '_';
	board[row - 5][col + 11] = '_';
	board[row - 4][col + 13] = '_';
	board[row - 5][col + 14] = '|';
	board[row - 4][col + 14] = '|';
	board[row - 4][col + 12] = '|';
	board[row - 4][col + 13] = '_';





	//left arm
	board[row - 5][col + 1] = '_';
	board[row - 5][col + 2] = '_';
	board[row - 5][col + 3] = '_';
	board[row - 6][col] = '|';
	board[row - 5][col] = '|';
	board[row - 7][col + 1] = '_';
	board[row - 6][col + 2] = '|';
	board[row - 6][col + 3] = '_';




	//right leg
	board[row][col + 8] = '|';
	board[row - 1][col + 8] = '|';
	board[row][col + 9] = '_';
	board[row][col + 10] = '|';
	board[row - 1][col + 10] = '|';



	//left leg
	board[row - 1][col + 4] = '\\';
	board[row - 1][col + 6] = '\\';
	board[row - 1][col + 5] = '_';



}

/////////////////////////////

// Climb frames
void climbFrame(char board[24][80], int row, int col) {

	//head  

	board[row - 8][col + 3] = '_';
	board[row - 8][col + 3] = '_';
	board[row - 8][col + 3] = '_';
	board[row - 8][col + 3] = '_';
	board[row - 8][col + 3] = '_';
	






	//body

	board[row - 2][col + 3] = '\\';
	board[row - 2][col + 4] = '_';
	board[row - 2][col + 5] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 8] = '_';
	board[row - 2][col + 9] = '/';
	board[row - 3][col + 9] = '|';
	board[row - 4][col + 9] = '|';
	board[row - 5][col + 9] = '|';
	board[row - 3][col + 3] = '|';
	board[row - 4][col + 3] = '|';
	board[row - 5][col + 3] = '|';
	board[row - 5][col + 4] = '-';
	board[row - 5][col + 5] = '-';
	board[row - 5][col + 6] = 'v';
	board[row - 5][col + 7] = '-';
	board[row - 5][col + 8] = '-';
}

///////////////////////////////

void callObj(char board[24][80]) {

	drawEnemyBirdLeft(board, 5, 60); // Draw the enemy bird
	drawEnemyBirdRight(board, 5, 10); // Draw the enemy bird

}

///////////////////////////////

void clearMap(char board[24][80]) {
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 80; j++) {
			board[i][j] = ' ';
		}
	}
}
void addBorders(char border[24][80]) {
	border[0][0] = char(201);
	for (int j = 1; j < 80 - 1; j++) {
		border[0][j] = char(205);
	}
	border[0][79] = char(187);

	// Middle section with side borders
	for (int i = 1; i < 24 - 1; i++) {
		border[i][0] = char(186);
		border[i][79] = char(186);
	}

	// Bottom border
	border[23][0] = char(200);
	for (int j = 1; j < 80 - 1; j++) {
		border[23][j] = char(205);
	}
	border[23][79] = char(188);
}

void Clear_LoadMap(char board[24][80]) {
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 80; j++) {
			if (i == 0 || i == 23) {
				cout << blue << board[i][j] << reset;
			}
			else if (j == 0 || j == 79) {
				cout << blue << board[i][j] << reset;
			}
			else {
				cout << board[i][j];
			}

		}
		cout << endl;
	}
}


/////////////////////////////////////
//Call dynamic objects


/////////////////////////////////////
//Player Movement Functions

void moveRight(char board[24][80], int& posJHero, int& posIHero, int widthHero, int heightHero) {
	int check = 1;
	// Check every cell in the column to the right of the player
	for (int i = posIHero; i >= posIHero - heightHero + 1; i--) {
		if (board[i][posJHero + widthHero] != ' ') {
			check = 0;
			break;
		}
	}
	// Only move if all checks passed AND we won't go out of bounds
	if (check == 1 && posJHero + widthHero + 1 < 79) {
		posJHero++;
	}
}

void moveLeft(char board[24][80], int& posJHero, int& posIHero, int heightHero) {
	int check = 1;  // Start with check = 1 for consistency
	//Check every cell in the column in front of the player to if its empty
	for (int i = posIHero; i >= posIHero - heightHero + 1; i--) {
		if (board[i][posJHero - 1] != ' ') {
			check = 0;
			break;
		}
	}
	if (posJHero - 1 > 0 && check == 1) posJHero--;
}

void jumpStraight(char board[24][80], int& pX, int& pY, int pHeight, int pWidth, int& isJumping, player Player, char gun[], int animation) {
	int check = 1;
	for (int i = 0; i < 3; i++) {
		if (pX - pHeight < 0) break;
		for (int j = pY; j <= pY + (pWidth - 1) && j < 80; j++) {
			if (board[pX - pHeight][j] != ' ') {
				check = 0;
				break;
			}
		}

		if (pX - (pHeight - 1) - 1 >= 0 && board[pX - (pHeight - 1) - 1][pY] == ' ' && check == 1) {
			pX--;
			clearMap(board);
			addBorders(board);
			if (animation == 0) {
				jumprightframe(board, pX, pY); // Draw the player jumping up
			}
			else if (animation == 1) {
				jumpleftframe(board, pX, pY); // Draw the player jumping up
			}
			callObj(board); // Call the function to draw the objects
			system("cls");
			dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun); // Display the bar first
			Clear_LoadMap(board); // Clear the screen and load the map

			isJumping = 1;
		}
		else break;

	}
}
void FallStraight(char board[24][80], int& pX, int& pY, int pHeight, int pWidth, int& isJumping, player Player, char gun[], int& isFalling, int animation) {
	int check = 1;
	for (int j = pY; j <= pY + (pWidth - 1); j++) {
		if (board[pX + 1][j] != ' ') {
			check = 0;
			break;
		}
	}

	//Fall straight
	for (; pX + 1 < 23 && board[pX + 1][pY] == ' ' && check; ) {
		if (pX - pHeight < 0) break;
		for (int j = pY; j <= pY + (pWidth - 1) && j < 80; j++) {
			if (board[pX - pHeight][j] != ' ') {
				check = 0;
				break;
			}
		}
		pX++;
		clearMap(board);
		addBorders(board);
		if (animation == 0) {
			jumprightframe(board, pX, pY); // Draw the player jumping up
		}
		else if (animation == 1) {
			jumpleftframe(board, pX, pY); // Draw the player jumping up
		}
		callObj(board); // Call the function to draw the objects
		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun); // Display the bar first
		Clear_LoadMap(board); // Clear the screen and load the map
		isFalling = 1;
	}
	isJumping = 0, isFalling = 0; // Reset jumping and falling states after landing
}


void jumpRight(char board[24][80], int& pX, int& pY, int pHeight, int pWidth, int& isJumping, player Player, char gun[], int& isFalling, int& isWalking) {
	int check = 1;
	// Check every cell in the column to the right of the player
	for (int i = pX; i >= pX - pHeight + 1; i--) {
		if (board[i][pY + pWidth] != ' ') {
			check = 0;
			break;
		}
	}

	for (int j = pY; j <= pY + (pWidth - 1) && j < 80; j++) {
		if (board[pX - pHeight][j] != ' ') {
			check = 0;
			break;
		}
	}

	for (int a = 0; a < 3; a++) {
		if (pX - (pHeight + 1) - 1 >= 0 && pY + pWidth < 79 && board[pX - (pHeight - 1) - 1][pY + 1] == ' ' && check == 1) {
			for (int i = pX; i >= pX - pHeight + 1; i--) {
				if (board[i][pY + pWidth] != ' ') {
					check = 0;
					break;
				}
			}


			if (pX - pHeight < 0)break;

			for (int j = pY; j <= pY + (pWidth - 1) && j < 80; j++) {
				if (board[pX - pHeight][j] != ' ') {
					check = 0;
					break;
				}
			}

			if (check == 0) break;

			pX--;
			pY++;
			clearMap(board);
			addBorders(board);
			jumprightframe(board, pX, pY); // Draw the player jumping up

			callObj(board); // Call the function to draw the objects
			system("cls");
			dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun); // Display the bar first
			Clear_LoadMap(board); // Clear the screen and load the map

			isJumping = 1;
		}
		else {
			break;
		}

	}

	check = 1;
	for (int j = pY; j <= pY + (pWidth - 1); j++) {
		if (board[pX + 1][j] != ' ') {
			check = 0;
			break;
		}
	}

	for (; pX + 1 < 23 && board[pX + 1][pY] == ' ' && pY + pWidth < 79;) {
		int checkDiagonal = 1;
		for (int j = pY; j <= pY + (pWidth - 1); j++) {
			if (board[pX + 1][j] != ' ') {
				checkDiagonal = 0;
				break;
			}
		}


		if (checkDiagonal && check) {
			pX++;
			pY++;
			clearMap(board);
			addBorders(board);
			jumprightframe(board, pX, pY);
			callObj(board);
			system("cls");
			dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun);
			Clear_LoadMap(board);
			isFalling = 1;
		}
	} 
	isWalking = 0;
	isJumping = 0, isFalling = 0; // Reset jumping and falling states after landing
}
void jumpLeft(char board[24][80], int& pX, int& pY, int pHeight, int pWidth, int& isJumping, player Player, char gun[], int& isFalling, int& isWalking) {
	int check = 1;

		for (int j = pY; j <= pY + (pWidth - 1) && j < 80; j++) {
			if (board[pX - pHeight][j] != ' ') {
				check = 0;
				break;
			}
		}

		for (int i = pX; i >= pX - pHeight + 1; i--) {
			if (board[i][pY - 1] != ' ') {
				check = 0;
				break;
			}
		}
		
	for (int a = 0; a < 3; a++) {
		if (pX - (pHeight + 1) - 1 >= 0 && pY - 1 > 0 && board[pX - (pHeight + 1) - 1][pY - 1] == ' ' && check == 1) {
			for (int i = pX; i >= pX - pHeight + 1; i--) {
				if (board[i][pY + pWidth] != ' ') {
					check = 0;
					break;
				}
			}


			if (pX - pHeight < 1) break;

			for (int j = pY; j <= pY + (pWidth - 1) && j < 80; j++) {
				if (board[pX - pHeight][j] != ' ') {
					check = 0;
					break;
				}
			}

			if (check == 0) break;

			pX--;
			pY--;
			clearMap(board);
			addBorders(board);
			jumpleftframe(board, pX, pY); // Draw the player jumping up

			callObj(board); // Call the function to draw the objects
			system("cls");
			dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun); // Display the bar first
			Clear_LoadMap(board); // Clear the screen and load the map

			isJumping = 1;
		}
		else {
			break;
		}

	}

	check = 1;
	for (int j = pY; j <= pY + (pWidth - 1); j++) {
		if (board[pX + 1][j] != ' ') {
			check = 0;
			break;
		}
	}

	for (; pX + 1 < 23 && board[pX + 1][pY] == ' ' && pY > 1;) {
		int checkDiagonal = 1;
		for (int j = pY; j <= pY + (pWidth - 1); j++) {
			if (board[pX + 1][j] != ' ') {
				checkDiagonal = 0;
				break;
			}
		}


		if (checkDiagonal && check) {
			pX++;
			pY--;
			clearMap(board);
			addBorders(board);
			jumpleftframe(board, pX, pY);
			callObj(board);
			system("cls");
			dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun);
			Clear_LoadMap(board);
			isFalling = 1;
		}
	} 
	isWalking = 0;
	isJumping = 0, isFalling = 0; // Reset jumping and falling states after landing
	
}



/*
NEXT STEPS:
6. implement shooting (hitboxes)...pistol or lazer
8. implement reloading , for pistol and lazerbeam
7. implement climbing ** (up and down) , add climbing frames
8. implement enemies
9. implement maps
10. implement elevator
11.add reloading , climbing , elevator animations and implement them
12. implement shooting animation
13. add coins and health pickups
14. add level up system (level up = increase max health)
15. add player hitbox
16. add boss Level
17. add boss hitbox
18. add boss health bar
19. add boss attack animation
20. add boss attack hitbox
21. change game bar if needed
22. change game frame size if needed

*/
int main() {
	int width = 80, height = 24; // Lets keep the width and height stored as variables incase we want to change them later
	char board[24][80]; // Border for the game frame


	char choice;
	for (;;) {
		system("cls"); // Clear the screen
		showMainMenu(choice);
		if (choice == '4') {
			cout << "Exiting game..." << endl;
			system("cls");
			break;
		}
		else if (choice == '1') {
			cout << "Starting Game..." << endl;
			system("cls");
			break; // Exit the loop to start the game
		}
		else if (choice == '2') {
			cout << "Instructions..." << endl;
			system("cls");
			displayInstructions(); // Call the function to display instructions
		}
		else if (choice == '3') {
			cout << "Credits..." << endl;
			system("cls");
			displayCredits(); // Call the function to display credits
		}

	}

	if (choice == '1') {
		system("cls");
		player Player;
		initializePlayerValues(Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, Player.Health, Player.coins, Player.gun, Player.ammo, Player.maxAmmo, Player.shootR, Player.shootC); // Initialize the player values
		initializeBoard(board); // Initialize the board

		char gun[] = "Pistol";


		//Intialize the movement vaiables
		int isWalking = 0, isJumping = 0, isFalling = 0, isClimbing = 0, isShooting = 0, isReloading = 0;
		//Iswalking =0 standing ,isWalking = 1 walkign right , isWalking = 2 walking left
		//isJumping = 0 standing , isJumping = 1 jumping (player shouldnt be able to move if isJumping = 1)
		//isClimbing = 0 standing , isClimbing = 1 climbing (player shouldnt be able to move left or right if isClimbing = 1)
		//isFalling = 0  not falling , isFalling = 1 falling (player shouldnt be able move or jump if isFalling = 1)
		//isShooting = 0 not shooting , isShooting = 1 shooting (player shouldnt be able to climb if isshooting = 1)
		//isReloading = 0 not reloading , isReloading = 1 reloading (player shouldnt be able to jump or shoot if isReloading = 1)
		int animation = 0 , frame =1 , ResetFrame =0;

		clearMap(board);
		addBorders(board);
		drawPlayerRightFrame1(board, Player.Row, Player.Col, Player.shootR, Player.shootC); // Draw the player
		callObj(board); // Call the function to draw the objects
		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun); // Display the bar first
		Clear_LoadMap(board); // Clear the screen and load the map
		FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation);
		int isWon = 0;
		for (; !isWon;) {
			clearMap(board);
			addBorders(board);
			if (animation == 0) {
				if(frame == 1) {
					drawPlayerRightFrame1(board, Player.Row, Player.Col, Player.shootR, Player.shootC);
				}
				else if(frame == 2){
					drawPlayerRightFrame2(board, Player.Row, Player.Col, Player.shootR, Player.shootC);
				}
				else if(frame == 3){
					drawPlayerRightFrame3(board, Player.Row, Player.Col, Player.shootR, Player.shootC);
				}
				else if(frame == 4){
					drawPlayerRightFrame4(board, Player.Row, Player.Col, Player.shootR, Player.shootC);
				}
				else if(frame == 5){
					drawPlayerRightFrame5(board, Player.Row, Player.Col, Player.shootR, Player.shootC);
				}
				
			}
			else if (animation == 1) {
				if(frame == 1) {
					DrawPlayerLeftFrame1(board, Player.Row, Player.Col, Player.shootR, Player.shootC);
				}
				else if(frame == 2){
					DrawPlayerLeftFrame2(board, Player.Row, Player.Col, Player.shootR, Player.shootC);
				}
				else if(frame == 3){
					DrawPlayerLeftFrame3(board, Player.Row, Player.Col, Player.shootR, Player.shootC);
				}
				else if(frame == 4){
					DrawPlayerLeftFrame4(board, Player.Row, Player.Col, Player.shootR, Player.shootC);
				}
				else if(frame == 5){
					DrawPlayerLeftFrame5(board, Player.Row, Player.Col, Player.shootR, Player.shootC);
				}
			}
			
			callObj(board); // Call the function to draw the objects
			system("cls");
			dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun); // Display the bar first
			Clear_LoadMap(board); // Clear the screen and load the map
			FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation);
			if (_kbhit()) {
				char key = _getch();
				if ((key == 'a' || key == 'A') && isClimbing == 0 && isFalling == 0) {
					if(isWalking == 2){
						if(frame == 5) frame =1;
						else frame++;
					}
					else {
						frame =1;
					}
					moveLeft(board, Player.Col, Player.Row, Player.maxHeight );
					animation = 1;
					isWalking = 2;
					FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation);
				}
				else if ((key == 'd' || key == 'D') && isClimbing == 0 && isFalling == 0) {
					if(isWalking == 1){
						if(frame == 5) frame =1;
						else frame++;
					}
					else {
						frame =1;
					}
					moveRight(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight);
					animation = 0;
					FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation);
					isWalking = 1;
				}
				else if (key == 'w' || key == 'W') {
					if (isJumping == 0 && isFalling == 0 && isReloading == 0) {
						if (isWalking == 0) {
							if (Player.Row - Player.maxHeight > 0) {
								jumpStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, animation);
								FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation);

							}

						}
						else if (isWalking == 1) {
							jumpRight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, isWalking);
							FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation);
							isWalking = 0;
						}
						else if (isWalking == 2){
							jumpLeft(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, isWalking);
							FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation);
							isWalking = 0;
						}
					}
				}
			}
		}
	}
	else return 0;

}

