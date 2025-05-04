//NEXT STEPS::

/*
FIX LASER DAMAGING MORE THAN 35
LET PLAYER MOVE WHILE SHOOTING
ADD PISTOL
ADD ASSUALT RIFLE

FIX ELEVATOR
ADD TELEPORTER
ADD ENEMIES AND THIER LOGIC
BUILD MAP
ADD BOSS FIGHT
*/

#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;


struct player {
	int Row, Col; //Position
	int maxHeight = 9, maxWidth = 15; //Max height and width

	int Health;
	int coins; //Either coins or Level , until decided i will leave it as coins

	int shootR, shootC;
	int gun; //Either 1 Lazer or 0 for pistol , 2 for rifle
	int ammo[3] = { 7 , 24 ,56 };
	int didGetRifle = 0;

	void reload(int amount) {
		if (ammo[0] <= 2)
		{
			ammo[0] += amount;
		}
		else if (ammo[1] <= 19)
		{
			ammo[1] += amount;
		}
		else if (ammo[2] <= 51)
		{
			ammo[2] += amount;
		}
	}

	int maxAmmo; // (ammo/maxAmmo) , max ammo could be 24 for gun , (maxammo == 1) for lazerbeam
};

struct Enemy {
	int Row, Col; //Position
	int isKillable; // 1 for killable , 0 for not killable
	int maxHeight = 1, maxWidth = 1; //Max height and width
	int Health = 100;
	int attackPower = 10;
};

struct ladder {
	int Row = -1, Col = -1; //Position
	int length = -1;
};

struct coin {
	int Row = -1, Col = -1; //Position
	int isCollected = 0; // 1 for collected , 0 for not collected
	int maxHeight = 4, maxWidth = 8; //Max height and width
};

struct hearts {
	int Row = -1, Col = -1; //Position
	int isCollected = 0; // 1 for collected , 0 for not collected
	int maxHeight = 4, maxWidth = 9; //Max height and width
};

struct Elevator {
	int row, col; //Position
	int startRow, endRow;
	int startCol, endCol;
	int length = 11;
	int whichD = 1; // 1 Vertical , 0 for horizonatal
	int direction = 1; // if vertical : 1 for up , 2 for down ..... if horizonatal 1 for right , 2 for left
};

void intializeCoin(char board[100][1000], coin& e, int row, int col) {
	e.Row = row;
	e.Col = col;
}
void intializeHeart(char board[100][1000], hearts& e, int row, int col) {
	e.Row = row;
	e.Col = col;
}

void intializeElevator(char board[100][1000], Elevator elevator[], int i, int row, int col, int startR, int endR, int startC, int endC, int whichD, int direction) {
	elevator[i].row = row;
	elevator[i].col = col;
	elevator[i].startRow = startR;
	elevator[i].endRow = endR;
	elevator[i].startCol = startC;
	elevator[i].endCol = endC;
	elevator[i].whichD = whichD;
	elevator[i].direction = direction;
}


void intializeEnemy(Enemy e[], int i, int row, int col, int  iskillable, int maxH, int maxW, int health, int power) {
	e[i].Row = row;

	e[i].Col = col;
	e[i].maxHeight = maxH;
	e[i].maxWidth = maxW;
	e[i].isKillable = iskillable;
	e[i].attackPower = power;
	e[i].Health = health;
}


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
	cout << "||  W/Space  - Jump / Climb Up                  ||" << endl;
	cout << "||  A  - Move Left                              ||" << endl;
	cout << "||  D  - Move Right                             ||" << endl;
	cout << "||  S  - Climb Down                             ||" << endl;
	cout << "||  F  - Shoot                                  ||" << endl;
	cout << "||  R  - Reload                                 ||" << endl;
	cout << "||  T  - Switch Weapons                         ||" << endl;
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


void initializePlayerValues(int& Row, int& Col, int& maxHeight, int& maxWidth, int& Health, int& coins, int& gun, int ammo[], int& maxAmmo, int& shootC, int& shootR) {
	Row = 95;
	Col = 70;
	maxHeight = 9;
	maxWidth = 15;
	Health = 100;
	coins = 0;
	gun = 0; //Start with gun
	ammo[0] = 7;
	ammo[1] = 24;
	ammo[2] = 56;
	shootR = 19 - 4;
	shootC = 3 + 15;
}



void initializeBoard(char border[100][1000]) {
	// Initialize all cells to be empty
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 1000; j++) {
			border[i][j] = ' ';
		}
	}

	// Top border 
	border[0][0] = char(201);
	for (int j = 1; j < 1000 - 1; j++) {
		border[0][j] = char(205);
	}
	border[0][999] = char(187);

	// Middle section with side borders
	for (int i = 1; i < 100 - 1; i++) {
		border[i][0] = char(186);
		border[i][999] = char(186);
	}

	// Bottom border
	border[23][0] = char(200);
	for (int j = 1; j < 1000 - 1; j++) {
		border[23][j] = char(205);
	}
	border[23][999] = char(188);
}

void dispBar(int health, int coins, int ammo[], int maxAmmo, int gun) {

	//ANSI CODE COLORS
	char green[] = "\033[32m";
	char blue[] = "\033[34m";
	char red[] = "\033[31m";
	char yellow[] = "\033[33m";
	char cyan[] = "\033[36m";
	char reset[] = "\033[0m";
	char bold[] = "\033[1m";

	cout << blue;
	//upper border
	cout << char(201);
	for (int i = 1; i < 79; i++) {
		cout << char(205);
	}
	cout << char(187);
	cout << endl;
	cout << reset;
	int countSpaces = 0;
	if (gun == 0 && ammo[0] >= 1) cout << blue << char(186) << reset << "                 HEALTH " << red << bold << health << reset << "  |  COINS " << yellow << bold << coins << reset << "  |  " << yellow << bold << "Lazer " << reset << "  |  AMMO " << yellow << bold << ammo[0] << " / " << 7 << reset << blue << "             " << char(186) << reset << endl;
	else if (gun == 1 && ammo[1] >= 1) cout << blue << char(186) << reset << "                 HEALTH " << red << bold << health << reset << "  |  COINS " << yellow << bold << coins << reset << "  |  " << yellow << bold << "Pistol" << reset << "  |  AMMO " << yellow << bold << ammo[1] << " / " << 24 << reset << blue << "             " << char(186) << reset << endl;
	else if (gun == 2 && ammo[2] >= 1) cout << blue << char(186) << reset << "                 HEALTH " << red << bold << health << reset << "  |  COINS " << yellow << bold << coins << reset << "  |  " << yellow << bold << "Rifle " << reset << "  |  AMMO " << yellow << bold << ammo[2] << " / " << 56 << reset << blue << "             " << char(186) << reset << endl;


	if (gun == 0 && ammo[0] <= 0) cout << blue << char(186) << reset << "                 HEALTH " << red << bold << health << reset << "  |  COINS " << yellow << bold << coins << reset << "  |  " << yellow << bold << "Lazer " << reset << "  |  AMMO " << yellow << bold << "NO AMMO "  << reset << blue << "             " << char(186) << reset << endl;
	else if (gun == 1 && ammo[1] <= 0) cout << blue << char(186) << reset << "                 HEALTH " << red << bold << health << reset << "  |  COINS " << yellow << bold << coins << reset << "  |  " << yellow << bold << "Pistol" << reset << "  |  AMMO " << yellow << bold << "NO AMMO "<< reset << blue << "             " << char(186) << reset << endl;
	else if (gun == 2 && ammo[2] <= 0) cout << blue << char(186) << reset << "                 HEALTH " << red << bold << health << reset << "  |  COINS " << yellow << bold << coins << reset << "  |  " << yellow << bold << "Rifle " << reset << "  |  AMMO " << yellow << bold << "NO AMMO " << reset << blue << "             " << char(186) << reset << endl;

}

void dispBoard(char board[100][1000]) {

	//ANSI CODE COLORS
	char green[] = "\033[32m";
	char blue[] = "\033[34m";
	char red[] = "\033[31m";
	char yellow[] = "\033[33m";
	char cyan[] = "\033[36m";
	char reset[] = "\033[0m";
	char bold[] = "\033[1m";


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




void drawPlayerRightFrame1(char board[100][1000], int row, int col, int& shootR, int& shootC, int LC[9]) {
	//left arm
	board[row - 3][col] = '/';
	board[row - 4][col + 1] = '/';
	board[row - 5][col + 2] = '/';

	//left leg
	board[row][col + 3] = '|';
	board[row - 1][col + 3] = '|';
	board[row - 1][col + 4] = ' ';
	board[row][col + 4] = '_';
	board[row][col + 5] = '|';
	board[row - 1][col + 5] = '|';

	//right leg
	board[row][col + 7] = '|';
	board[row][col + 8] = '_';
	board[row][col + 9] = '|';

	board[row - 1][col + 8] = ' ';
	board[row - 1][col + 7] = '|';
	board[row - 1][col + 9] = '|';

	//right arm
	board[row - 4][col + 10] = '-';
	board[row - 4][col + 11] = '-';
	board[row - 4][col + 12] = '-';
	board[row - 4][col + 13] = '|';
	board[row - 4][col + 14] = '/';
	shootR = row - 5;
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

	board[row - 3][col + 4] = ' ';
	board[row - 3][col + 5] = ' ';
	board[row - 3][col + 6] = ' ';
	board[row - 3][col + 7] = ' ';
	board[row - 3][col + 8] = ' ';

	board[row - 4][col + 4] = ' ';
	board[row - 4][col + 5] = ' ';
	board[row - 4][col + 6] = ' ';
	board[row - 4][col + 7] = ' ';
	board[row - 4][col + 8] = ' ';

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

	LC[0] = col + 9;
	LC[1] = col + 9;
	LC[2] = col + 9;
	LC[3] = col + 9;
	LC[4] = col + 14;
	LC[5] = col + 14;
	LC[6] = col + 8;
	LC[7] = col + 8;
	LC[8] = col + 7;

}



void drawPlayerRightFrame2(char board[100][1000], int row, int col, int& shootR, int& shootC, int LC[9]) {
	//left arm
	board[row - 3][col] = '/';
	board[row - 4][col + 1] = '/';
	board[row - 5][col + 2] = '/';

	//left leg
	board[row][col + 2] = '/';
	board[row][col + 3] = '_';
	board[row][col + 4] = '/';
	board[row - 1][col + 4] = ' ';
	board[row - 1][col + 3] = '|';
	board[row - 1][col + 5] = '|';

	//right leg
	board[row - 1][col + 7] = '\\';
	board[row - 1][col + 9] = '\\';
	board[row - 1][col + 8] = ' ';
	board[row][col + 8] = '\\';
	board[row][col + 9] = '_';
	board[row][col + 10] = '\\';


	//right arm
	board[row - 4][col + 10] = '-';
	board[row - 4][col + 11] = '-';
	board[row - 4][col + 12] = '-';
	board[row - 4][col + 13] = '|';
	board[row - 4][col + 14] = '/';
	shootR = row - 5;
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


	board[row - 3][col + 4] = ' ';
	board[row - 3][col + 5] = ' ';
	board[row - 3][col + 6] = ' ';
	board[row - 3][col + 7] = ' ';
	board[row - 3][col + 8] = ' ';

	board[row - 4][col + 4] = ' ';
	board[row - 4][col + 5] = ' ';
	board[row - 4][col + 6] = ' ';
	board[row - 4][col + 7] = ' ';
	board[row - 4][col + 8] = ' ';


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

	LC[0] = col + 10; // row     (feet: '\\' at col+10)
	LC[1] = col + 9;  // row - 1 (legs: '\\' at col+9)
	LC[2] = col + 9;  // row - 2 (torso: '/' at col+9)
	LC[3] = col + 9;  // row - 3 (left arm/body: '|' at col+9)
	LC[4] = col + 14; // row - 4 (right arm: '/' at col+14)
	LC[5] = col + 14; // row - 5 (upper body: '\\' at col+14)
	LC[6] = col + 8;  // row - 6 (head base: '/' at col+8)
	LC[7] = col + 8;  // row - 7 (eyes: ')' at col+8)
	LC[8] = col + 7;  // row - 8 (top head: '_' at col+7)


}
void drawPlayerRightFrame3(char board[100][1000], int row, int col, int& shootR, int& shootC, int LC[9]) {
	//left arm
	board[row - 3][col + 1] = '\\';
	board[row - 4][col + 1] = '/';
	board[row - 5][col + 2] = '/';

	//left leg
	board[row - 2][col + 2] = '_';
	board[row - 1][col + 1] = '|';
	board[row - 1][col + 2] = '_';
	board[row - 1][col + 3] = '_';
	board[row - 1][col + 4] = '_';
	board[row - 1][col + 5] = '|';

	//right leg
	board[row][col + 6] = '|';
	board[row][col + 7] = '_';
	board[row][col + 8] = '|';
	board[row - 1][col + 7] = ' ';
	board[row - 1][col + 6] = '\\';
	board[row - 1][col + 8] = '\\';

	//right arm
	board[row - 4][col + 10] = '-';
	board[row - 4][col + 11] = '-';
	board[row - 4][col + 12] = '-';
	board[row - 4][col + 13] = '|';
	board[row - 4][col + 14] = '/';
	shootR = row - 5;
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


	board[row - 3][col + 4] = ' ';
	board[row - 3][col + 5] = ' ';
	board[row - 3][col + 6] = ' ';
	board[row - 3][col + 7] = ' ';
	board[row - 3][col + 8] = ' ';

	board[row - 4][col + 4] = ' ';
	board[row - 4][col + 5] = ' ';
	board[row - 4][col + 6] = ' ';
	board[row - 4][col + 7] = ' ';
	board[row - 4][col + 8] = ' ';

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

	LC[0] = col + 8;  // row     (feet: '|' at col+8)
	LC[1] = col + 8;  // row - 1 (legs: '\\' at col+8)
	LC[2] = col + 9;  // row - 2 (torso: '/' at col+9)
	LC[3] = col + 9;  // row - 3 (left arm/body: '|' at col+9)
	LC[4] = col + 14; // row - 4 (right arm: '/' at col+14)
	LC[5] = col + 14; // row - 5 (upper body: '\\' at col+14)
	LC[6] = col + 8;  // row - 6 (head base: '/' at col+8)
	LC[7] = col + 8;  // row - 7 (eyes: ')' at col+8)
	LC[8] = col + 7;  // row - 8 (top head: '_' at col+7)

}


void drawPlayerRightFrame4(char board[100][1000], int row, int col, int& shootR, int& shootC, int LC[9]) {
	//left arm
	board[row - 3][col] = '/';
	board[row - 4][col + 1] = '/';
	board[row - 5][col + 2] = '/';

	//left leg
	board[row][col + 3] = '|';
	board[row][col + 4] = '_';
	board[row][col + 5] = '|';

	board[row - 1][col + 3] = '\\';
	board[row - 1][col + 4] = ' ';
	board[row - 1][col + 5] = '\\';

	//right leg
	board[row][col + 7] = '/';
	board[row][col + 8] = '_';
	board[row][col + 9] = '/';
	board[row - 1][col + 7] = '\\';
	board[row - 1][col + 8] = ' ';
	board[row - 1][col + 9] = '\\';


	//right arm
	board[row - 4][col + 10] = '-';
	board[row - 4][col + 11] = '-';
	board[row - 4][col + 12] = '-';
	board[row - 4][col + 13] = '|';
	board[row - 4][col + 14] = '/';
	shootR = row - 5;
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

	board[row - 3][col + 4] = ' ';
	board[row - 3][col + 5] = ' ';
	board[row - 3][col + 6] = ' ';
	board[row - 3][col + 7] = ' ';
	board[row - 3][col + 8] = ' ';

	board[row - 4][col + 4] = ' ';
	board[row - 4][col + 5] = ' ';
	board[row - 4][col + 6] = ' ';
	board[row - 4][col + 7] = ' ';
	board[row - 4][col + 8] = ' ';



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

	LC[0] = col + 9;  // row     (feet: '/' at col+9)
	LC[1] = col + 9;  // row - 1 (legs: '\\' at col+9)
	LC[2] = col + 9;  // row - 2 (torso: '/' at col+9)
	LC[3] = col + 9;  // row - 3 (left arm/body: '|' at col+9)
	LC[4] = col + 14; // row - 4 (right arm: '/' at col+14)
	LC[5] = col + 14; // row - 5 (upper body: '\\' at col+14)
	LC[6] = col + 8;  // row - 6 (head base: '/' at col+8)
	LC[7] = col + 8;  // row - 7 (eyes: ')' at col+8)
	LC[8] = col + 7;  // row - 8 (top head: '_' at col+7)

}


void drawPlayerRightFrame5(char board[100][1000], int row, int col, int& shootR, int& shootC, int LC[9]) {
	//left arm
	board[row - 3][col + 1] = '\\';
	board[row - 4][col + 1] = '/';
	board[row - 5][col + 2] = '/';

	//Left leg
	board[row - 2][col + 2] = '_';
	board[row - 1][col + 2] = '|';
	board[row - 1][col + 3] = '_';
	board[row - 1][col + 7] = '_';
	board[row - 1][col + 8] = '|';

	//Right leg

	board[row - 1][col + 4] = '\\';
	board[row - 1][col + 5] = ' ';
	board[row - 1][col + 6] = '\\';
	board[row][col + 5] = '\\';
	board[row][col + 6] = '_';
	board[row][col + 7] = '\\';

	//right arm
	board[row - 4][col + 10] = '-';
	board[row - 4][col + 11] = '-';
	board[row - 4][col + 12] = '-';
	board[row - 4][col + 13] = '|';
	board[row - 4][col + 14] = '/';
	shootR = row - 5;
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


	board[row - 3][col + 4] = ' ';
	board[row - 3][col + 5] = ' ';
	board[row - 3][col + 6] = ' ';
	board[row - 3][col + 7] = ' ';
	board[row - 3][col + 8] = ' ';

	board[row - 4][col + 4] = ' ';
	board[row - 4][col + 5] = ' ';
	board[row - 4][col + 6] = ' ';
	board[row - 4][col + 7] = ' ';
	board[row - 4][col + 8] = ' ';

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
	LC[0] = col + 7;  // row     (feet: '\\' at col+7)
	LC[1] = col + 8;  // row - 1 (legs: '|' at col+8)
	LC[2] = col + 9;  // row - 2 (torso: '/' at col+9)
	LC[3] = col + 9;  // row - 3 (left arm/body: '|' at col+9)
	LC[4] = col + 14; // row - 4 (right arm: '/' at col+14)
	LC[5] = col + 14; // row - 5 (upper body: '\\' at col+14)
	LC[6] = col + 8;  // row - 6 (head base: '/' at col+8)
	LC[7] = col + 8;  // row - 7 (eyes: ')' at col+8)
	LC[8] = col + 7;  // row - 8 (top head: '_' at col+7)

}
/////////////////////////////////////////////






// Walking Left Frames
void DrawPlayerLeftFrame1(char board[100][1000], int row, int col, int& shootingR, int& shootingC, int LC[9]) {

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

	board[row - 3][col + 6] = ' ';
	board[row - 3][col + 7] = ' ';
	board[row - 3][col + 8] = ' ';
	board[row - 3][col + 9] = ' ';
	board[row - 3][col + 10] = ' ';

	board[row - 4][col + 6] = ' ';
	board[row - 4][col + 7] = ' ';
	board[row - 4][col + 8] = ' ';
	board[row - 4][col + 9] = ' ';
	board[row - 4][col + 10] = ' ';

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
	shootingR = row - 5;
	shootingC = col - 1;
	board[row - 5][col + 1] = '|';
	board[row - 5][col + 2] = '-';
	board[row - 5][col + 3] = '-';
	board[row - 5][col + 4] = '-';



	//right leg
	board[row][col + 9] = '|';
	board[row][col + 10] = '_';
	board[row][col + 11] = '|';
	board[row - 1][col + 10] = ' ';
	board[row - 1][col + 9] = '|';
	board[row - 1][col + 11] = '|';


	//right arm
	board[row - 3][col + 14] = '\\';
	board[row - 4][col + 13] = '\\';
	board[row - 5][col + 12] = '\\';


	//left leg
	board[row][col + 5] = '|';
	board[row - 1][col + 5] = '|';
	board[row - 1][col + 6] = ' ';
	board[row][col + 6] = '_';
	board[row][col + 7] = '|';
	board[row - 1][col + 7] = '|';

	LC[0] = col + 5;   // Correct (left leg '|')
	LC[1] = col + 5;   // Correct (left leg '|')
	LC[2] = col + 5;   // Correct (body '\')
	LC[3] = col + 5;   // Correct (body '|')
	LC[4] = col;       // Correct (left arm '\')
	LC[5] = col;       // Correct (left arm '/')
	LC[6] = col + 6;   // Correct (head '\')
	LC[7] = col + 6;   // Correct (head '(')
	LC[8] = col + 6;   // Correct (head '_')
}


void DrawPlayerLeftFrame2(char board[100][1000], int R, int C, int& shootingR, int& shootingC, int LC[9]) {

	//Left arm
	board[R - 4][C] = '\\';
	board[R - 4][C + 1] = '|';
	board[R - 4][C + 2] = '-';
	board[R - 4][C + 3] = '-';
	board[R - 4][C + 4] = '-';
	shootingR = R - 5;
	shootingC = C - 1;
	board[R - 5][C] = '/';
	board[R - 5][C + 1] = '|';
	board[R - 5][C + 2] = '-';
	board[R - 5][C + 3] = '-';
	board[R - 5][C + 4] = '-';


	//Right arm

	board[R - 5][C + 12] = '\\';
	board[R - 4][C + 13] = '\\';
	board[R - 3][C + 14] = '\\';

	//Left leg

	board[R][C + 4] = '/';
	board[R][C + 5] = '_';
	board[R][C + 6] = '/';
	board[R - 1][C + 6] = ' ';
	board[R - 1][C + 5] = '/';
	board[R - 1][C + 7] = '/';

	//Right leg
	board[R][C + 10] = '\\';
	board[R][C + 11] = '_';
	board[R][C + 12] = '\\';
	board[R - 1][C + 9] = '|';
	board[R - 1][C + 10] = ' ';
	board[R - 1][C + 11] = '|';

	//Body
	board[R - 2][C + 5] = '\\';
	board[R - 2][C + 6] = '_';
	board[R - 2][C + 7] = '_';
	board[R - 2][C + 8] = '_';
	board[R - 2][C + 9] = '_';
	board[R - 2][C + 10] = '_';
	board[R - 2][C + 11] = '/';

	board[R - 3][C + 6] = ' ';
	board[R - 3][C + 7] = ' ';
	board[R - 3][C + 8] = ' ';
	board[R - 3][C + 9] = ' ';
	board[R - 3][C + 10] = ' ';

	board[R - 4][C + 6] = ' ';
	board[R - 4][C + 7] = ' ';
	board[R - 4][C + 8] = ' ';
	board[R - 4][C + 9] = ' ';
	board[R - 4][C + 10] = ' ';



	board[R - 3][C + 5] = '|';
	board[R - 3][C + 11] = '|';
	board[R - 4][C + 5] = '|';
	board[R - 4][C + 11] = '|';
	board[R - 5][C + 5] = '|';
	board[R - 5][C + 11] = '|';

	board[R - 5][C + 6] = '-';
	board[R - 5][C + 7] = '-';
	board[R - 5][C + 8] = 'v';
	board[R - 5][C + 9] = '-';
	board[R - 5][C + 10] = '-';

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

	LC[0] = C + 4;   // Correct (left leg '/')
	LC[1] = C + 5;   // Should be col + 5 (left leg '/')
	LC[2] = C + 5;   // Correct (body '\')
	LC[3] = C + 5;   // Correct (body '|')
	LC[4] = C;       // Correct (left arm '\')
	LC[5] = C;       // Correct (left arm '/')
	LC[6] = C + 6;   // Correct (head '\')
	LC[7] = C + 6;   // Correct (head '(')
	LC[8] = C + 6;   // Correct (head '_')
}

void DrawPlayerLeftFrame3(char board[100][1000], int R, int C, int& shootingR, int& shootingC, int LC[9]) {

	//Left arm
	board[R - 4][C] = '\\';
	board[R - 4][C + 1] = '|';
	board[R - 4][C + 2] = '-';
	board[R - 4][C + 3] = '-';
	board[R - 4][C + 4] = '-';
	shootingR = R - 5;
	shootingC = C - 1;
	board[R - 5][C] = '/';
	board[R - 5][C + 1] = '|';
	board[R - 5][C + 2] = '-';
	board[R - 5][C + 3] = '-';
	board[R - 5][C + 4] = '-';


	//Right arm

	board[R - 5][C + 12] = '\\';
	board[R - 4][C + 13] = '\\';
	board[R - 3][C + 13] = '/';


	//Left leg
	board[R][C + 5] = '|';
	board[R][C + 6] = '_';
	board[R][C + 7] = '|';
	board[R - 1][C + 6] = ' ';
	board[R - 1][C + 5] = '/';
	board[R - 1][C + 7] = '/';

	//Right Leg
	board[R - 1][C + 10] = '|';
	board[R - 1][C + 11] = '_';
	board[R - 1][C + 12] = '_';
	board[R - 1][C + 13] = '_';
	board[R - 1][C + 14] = '|';
	board[R - 2][C + 12] = '_';
	board[R - 2][C + 13] = '_';


	//Body
	board[R - 2][C + 5] = '\\';
	board[R - 2][C + 6] = '_';
	board[R - 2][C + 7] = '_';
	board[R - 2][C + 8] = '_';
	board[R - 2][C + 9] = '_';
	board[R - 2][C + 10] = '_';
	board[R - 2][C + 11] = '/';


	board[R - 3][C + 5] = '|';
	board[R - 3][C + 11] = '|';
	board[R - 4][C + 5] = '|';
	board[R - 4][C + 11] = '|';
	board[R - 5][C + 5] = '|';
	board[R - 5][C + 11] = '|';

	board[R - 5][C + 6] = '-';
	board[R - 5][C + 7] = '-';
	board[R - 5][C + 8] = 'v';
	board[R - 5][C + 9] = '-';
	board[R - 5][C + 10] = '-';

	board[R - 3][C + 6] = ' ';
	board[R - 3][C + 7] = ' ';
	board[R - 3][C + 8] = ' ';
	board[R - 3][C + 9] = ' ';
	board[R - 3][C + 10] = ' ';

	board[R - 4][C + 6] = ' ';
	board[R - 4][C + 7] = ' ';
	board[R - 4][C + 8] = ' ';
	board[R - 4][C + 9] = ' ';
	board[R - 4][C + 10] = ' ';


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

	LC[0] = C + 5;   // R      (left leg: '|' at col+5)
	LC[1] = C + 5;   // R - 1  (left leg: '/' at col+5)
	LC[2] = C + 5;   // R - 2  (body: '\' at col+5)
	LC[3] = C + 5;   // R - 3  (body: '|' at col+5)
	LC[4] = C;       // R - 4  (left arm: '\' at col+0)
	LC[5] = C;       // R - 5  (left arm: '/' at col+0)
	LC[6] = C + 6;   // R - 6  (head: '\' at col+6)
	LC[7] = C + 6;   // R - 7  (head: '(' at col+6)
	LC[8] = C + 6;   // R - 8  (head: '_' at col+6)

}



void DrawPlayerLeftFrame4(char board[100][1000], int R, int C, int& shootingR, int& shootingC, int LC[9]) {

	//Left arm
	board[R - 4][C] = '\\';
	board[R - 4][C + 1] = '|';
	board[R - 4][C + 2] = '-';
	board[R - 4][C + 3] = '-';
	board[R - 4][C + 4] = '-';
	shootingR = R - 5;
	shootingC = C - 1;
	board[R - 5][C] = '/';
	board[R - 5][C + 1] = '|';
	board[R - 5][C + 2] = '-';
	board[R - 5][C + 3] = '-';
	board[R - 5][C + 4] = '-';


	//Right arm

	board[R - 5][C + 12] = '\\';
	board[R - 4][C + 13] = '\\';
	board[R - 3][C + 14] = '\\';


	//Left leg
	board[R][C + 5] = '\\';
	board[R][C + 6] = '_';
	board[R][C + 7] = '\\';
	board[R - 1][C + 6] = ' ';
	board[R - 1][C + 5] = '/';
	board[R - 1][C + 7] = '/';

	//Right leg
	board[R][C + 9] = '|';
	board[R][C + 10] = '_';
	board[R][C + 11] = '|';
	board[R - 1][C + 10] = ' ';
	board[R - 1][C + 9] = '/';
	board[R - 1][C + 11] = '/';

	//Body
	board[R - 2][C + 5] = '\\';
	board[R - 2][C + 6] = '_';
	board[R - 2][C + 7] = '_';
	board[R - 2][C + 8] = '_';
	board[R - 2][C + 9] = '_';
	board[R - 2][C + 10] = '_';
	board[R - 2][C + 11] = '/';

	board[R - 3][C + 5] = '|';
	board[R - 3][C + 11] = '|';
	board[R - 4][C + 5] = '|';
	board[R - 4][C + 11] = '|';
	board[R - 5][C + 5] = '|';
	board[R - 5][C + 11] = '|';

	board[R - 5][C + 6] = '-';
	board[R - 5][C + 7] = '-';
	board[R - 5][C + 8] = 'v';
	board[R - 5][C + 9] = '-';
	board[R - 5][C + 10] = '-';

	board[R - 3][C + 6] = ' ';
	board[R - 3][C + 7] = ' ';
	board[R - 3][C + 8] = ' ';
	board[R - 3][C + 9] = ' ';
	board[R - 3][C + 10] = ' ';

	board[R - 4][C + 6] = ' ';
	board[R - 4][C + 7] = ' ';
	board[R - 4][C + 8] = ' ';
	board[R - 4][C + 9] = ' ';
	board[R - 4][C + 10] = ' ';


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

	LC[0] = C + 5;   // R      (left leg: '\' at col+5)
	LC[1] = C + 5;   // R - 1  (left leg: '/' at col+5)
	LC[2] = C + 5;   // R - 2  (body: '\' at col+5)
	LC[3] = C + 5;   // R - 3  (body: '|' at col+5)
	LC[4] = C;       // R - 4  (left arm: '\' at col+0)
	LC[5] = C;       // R - 5  (left arm: '/' at col+0)
	LC[6] = C + 6;   // R - 6  (head: '\' at col+6)
	LC[7] = C + 6;   // R - 7  (head: '(' at col+6)
	LC[8] = C + 6;   // R - 8  (head: '_' at col+6)

}




void DrawPlayerLeftFrame5(char board[100][1000], int R, int C, int& shootingR, int& shootingC, int LC[9]) {

	//Left arm
	board[R - 4][C] = '\\';
	board[R - 4][C + 1] = '|';
	board[R - 4][C + 2] = '-';
	board[R - 4][C + 3] = '-';
	board[R - 4][C + 4] = '-';
	shootingR = R - 5;
	shootingC = C - 1;
	board[R - 5][C] = '/';
	board[R - 5][C + 1] = '|';
	board[R - 5][C + 2] = '-';
	board[R - 5][C + 3] = '-';
	board[R - 5][C + 4] = '-';


	//Right arm

	board[R - 5][C + 12] = '\\';
	board[R - 4][C + 13] = '\\';
	board[R - 3][C + 13] = '/';


	//Left leg
	board[R][C + 7] = '/';
	board[R][C + 8] = '_';
	board[R][C + 9] = '/';
	board[R - 1][C + 9] = ' ';
	board[R - 1][C + 8] = '/';
	board[R - 1][C + 10] = '/';

	//Right leg
	board[R - 1][C + 6] = '|';
	board[R - 1][C + 7] = '_';
	board[R - 1][C + 11] = '_';
	board[R - 1][C + 12] = '|';
	board[R - 2][C + 12] = '_';


	//Body
	board[R - 2][C + 5] = '\\';
	board[R - 2][C + 6] = '_';
	board[R - 2][C + 7] = '_';
	board[R - 2][C + 8] = '_';
	board[R - 2][C + 9] = '_';
	board[R - 2][C + 10] = '_';
	board[R - 2][C + 11] = '/';

	board[R - 3][C + 5] = '|';
	board[R - 3][C + 11] = '|';
	board[R - 4][C + 5] = '|';
	board[R - 4][C + 11] = '|';
	board[R - 5][C + 5] = '|';
	board[R - 5][C + 11] = '|';

	board[R - 5][C + 6] = '-';
	board[R - 5][C + 7] = '-';
	board[R - 5][C + 8] = 'v';
	board[R - 5][C + 9] = '-';
	board[R - 5][C + 10] = '-';

	board[R - 3][C + 6] = ' ';
	board[R - 3][C + 7] = ' ';
	board[R - 3][C + 8] = ' ';
	board[R - 3][C + 9] = ' ';
	board[R - 3][C + 10] = ' ';

	board[R - 4][C + 6] = ' ';
	board[R - 4][C + 7] = ' ';
	board[R - 4][C + 8] = ' ';
	board[R - 4][C + 9] = ' ';
	board[R - 4][C + 10] = ' ';


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

	LC[0] = C + 7;   // R      (left leg: '/' at col+7)
	LC[1] = C + 6;   // R - 1  (right leg: '|' at col+6)
	LC[2] = C + 5;   // R - 2  (body: '\' at col+5)
	LC[3] = C + 5;   // R - 3  (body: '|' at col+5)
	LC[4] = C;       // R - 4  (left arm: '\' at col+0)
	LC[5] = C;       // R - 5  (left arm: '/' at col+0)
	LC[6] = C + 6;   // R - 6  (head: '\' at col+6)
	LC[7] = C + 6;   // R - 7  (head: '(' at col+6)
	LC[8] = C + 6;   // R - 8  (head: '_' at col+6)
}




//Jump frames
void jumprightframe(char board[100][1000], int row, int col, int LC[9], int LR[15]) {

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


	LC[0] = col + 6;   // row-6  
	LC[1] = col + 10;  // row-1   
	LC[2] = col + 10;  // row-2
	LC[3] = col + 10;  // row-3
	LC[4] = col + 10;  // row-4
	LC[5] = col + 14;  // row-5
	LC[6] = col + 14;  // row-6
	LC[7] = col + 13;  // row-7
	LC[8] = col + 9;   // row-8

	LR[0] = row - 5;   // col+0
	LR[1] = row - 5;   // col+1
	LR[2] = row - 5;   // col+2
	LR[3] = row - 5;   // col+3
	LR[4] = row - 5;   // col+4
	LR[5] = row - 7;   // col+5
	LR[6] = row - 8;   // col+6
	LR[7] = row - 8;   // col+7
	LR[8] = row - 8;   // col+8
	LR[9] = row - 8;   // col+9
	LR[10] = row - 5;  // col+10  
	LR[11] = row - 6;  // col+11 
	LR[12] = row - 6;  // col+12   
	LR[13] = row - 7;  // col+13  
	LR[14] = row - 6;  // col+14  
}



void jumpleftframe(char board[100][1000], int row, int col, int LC[9], int LR[15]) {


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

	LC[0] = col + 8;   // row (left leg: '\\' at col+8)
	LC[1] = col + 4;   // row-1 (left leg: '\\' at col+4)
	LC[2] = col + 4;   // row-2 (body: '\\' at col+4)
	LC[3] = col + 4;   // row-3 (body: '|' at col+4)
	LC[4] = col + 4;   // row-4 (body: '|' at col+4)
	LC[5] = col;       // row-5 (left arm: '|' at col+0)
	LC[6] = col;       // row-6 (left arm: '|' at col+0)
	LC[7] = col + 1;   // row-7 (left arm: '_' at col+1)
	LC[8] = col + 5;   // row-8 (head: '_' at col+5)

	LR[0] = row - 6;   // col+0 (left arm '|')
	LR[1] = row - 7;   // col+1 (left arm '_')
	LR[2] = row - 6;   // col+2 (left arm '|')
	LR[3] = row - 6;   // col+3 (left arm '_')
	LR[4] = row - 8;   // col+4 (body '|')
	LR[5] = row - 8;   // col+5 (head '_')
	LR[6] = row - 8;   // col+6 (head '_')
	LR[7] = row - 8;   // col+7 (head '_')
	LR[8] = row - 8;   // col+8 (head '_')
	LR[9] = row - 8;   // col+9 (head '_')
	LR[10] = row - 8;  // col+10 (body '|')
	LR[11] = row - 6;  // col+11 (right arm '_')
	LR[12] = row - 6;  // col+12 (right arm '_')
	LR[13] = row - 6;  // col+13 (right arm '_')
	LR[14] = row - 8;  // col+14 (right arm '|')

}

/////////////////////////////

// Climb frames
void climbFrame1(char board[100][1000], int row, int col) {

	//head  

	board[row - 8][col + 3] = '_';
	board[row - 8][col + 4] = '_';
	board[row - 8][col + 5] = '_';
	board[row - 8][col + 6] = '_';
	board[row - 8][col + 7] = '_';
	board[row - 7][col + 3] = '(';
	board[row - 7][col + 4] = '|';
	board[row - 7][col + 5] = '|';
	board[row - 7][col + 6] = '|';
	board[row - 7][col + 7] = ')';
	board[row - 6][col + 3] = '\\';
	board[row - 6][col + 4] = '-';
	board[row - 6][col + 5] = '-';
	board[row - 6][col + 6] = '-';
	board[row - 6][col + 7] = '/';


	//body

	board[row - 5][col + 2] = '|';
	board[row - 4][col + 2] = '|';
	board[row - 3][col + 2] = '|';
	board[row - 2][col + 2] = '\\';
	board[row - 2][col + 3] = '_';
	board[row - 2][col + 4] = '_';
	board[row - 2][col + 5] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 8] = '/';
	board[row - 3][col + 8] = '|';
	board[row - 4][col + 8] = '|';
	board[row - 5][col + 8] = '|';
	board[row - 3][col + 3] = ' ';
	board[row - 3][col + 4] = ' ';
	board[row - 3][col + 5] = ' ';
	board[row - 3][col + 6] = ' ';
	board[row - 3][col + 7] = ' ';
	board[row - 4][col + 7] = ' ';
	board[row - 4][col + 6] = ' ';
	board[row - 4][col + 5] = ' ';
	board[row - 4][col + 4] = ' ';
	board[row - 4][col + 3] = ' ';
	board[row - 5][col + 3] = ' ';
	board[row - 5][col + 4] = ' ';
	board[row - 5][col + 5] = ' ';
	board[row - 5][col + 6] = ' ';
	board[row - 5][col + 7] = ' ';


	//right hand
	board[row - 5][col + 9] = '|';
	board[row - 5][col + 11] = '|';
	board[row - 6][col + 9] = '|';
	board[row - 6][col + 11] = '|';
	board[row - 7][col + 10] = '_';
	board[row - 7][col + 11] = '_';


	//LEFT HAND

	board[row - 5][col] = '|';
	board[row - 6][col] = '|';
	board[row - 7][col] = '|';
	board[row - 8][col] = '_';
	board[row - 5][col + 1] = '|';
	board[row - 6][col + 1] = '|';
	board[row - 7][col + 1] = '|';
	board[row - 8][col + 1] = '_';



	//left leg

	board[row][col + 2] = '|';
	board[row][col + 3] = '_';
	board[row][col + 4] = '|';
	board[row - 1][col + 2] = '|';
	board[row - 1][col + 3] = ' ';
	board[row - 1][col + 4] = '|';



	//right leg

	board[row - 1][col + 8] = '|';
	board[row - 1][col + 6] = '|';
	board[row - 1][col + 7] = '_';




}



void climbFrame2(char board[100][1000], int row, int col) {

	//head  

	board[row - 8][col + 3] = '_';
	board[row - 8][col + 4] = '_';
	board[row - 8][col + 5] = '_';
	board[row - 8][col + 6] = '_';
	board[row - 8][col + 7] = '_';
	board[row - 7][col + 3] = '(';
	board[row - 7][col + 4] = '|';
	board[row - 7][col + 5] = '|';
	board[row - 7][col + 6] = '|';
	board[row - 7][col + 7] = ')';
	board[row - 6][col + 3] = '\\';
	board[row - 6][col + 4] = '-';
	board[row - 6][col + 5] = '-';
	board[row - 6][col + 6] = '-';
	board[row - 6][col + 7] = '/';


	//body

	board[row - 5][col + 2] = '|';
	board[row - 4][col + 2] = '|';
	board[row - 3][col + 2] = '|';
	board[row - 2][col + 2] = '\\';
	board[row - 2][col + 3] = '_';
	board[row - 2][col + 4] = '_';
	board[row - 2][col + 5] = '_';
	board[row - 2][col + 6] = '_';
	board[row - 2][col + 7] = '_';
	board[row - 2][col + 8] = '/';
	board[row - 3][col + 8] = '|';
	board[row - 4][col + 8] = '|';
	board[row - 5][col + 8] = '|';
	board[row - 3][col + 3] = ' ';
	board[row - 3][col + 4] = ' ';
	board[row - 3][col + 5] = ' ';
	board[row - 3][col + 6] = ' ';
	board[row - 3][col + 7] = ' ';
	board[row - 4][col + 7] = ' ';
	board[row - 4][col + 6] = ' ';
	board[row - 4][col + 5] = ' ';
	board[row - 4][col + 4] = ' ';
	board[row - 4][col + 3] = ' ';


	//left hand
	board[row - 5][col] = '|';
	board[row - 6][col] = '|';
	board[row - 5][col + 1] = '|';
	board[row - 6][col + 1] = '|';
	board[row - 7][col] = '_';
	board[row - 7][col + 1] = '_';


	//right HAND

	board[row - 5][col + 9] = '|';
	board[row - 6][col + 9] = '|';
	board[row - 7][col + 9] = '|';
	board[row - 8][col + 9] = '_';
	board[row - 5][col + 10] = '|';
	board[row - 6][col + 10] = '|';
	board[row - 7][col + 10] = '|';
	board[row - 8][col + 10] = '_';



	//right leg

	board[row][col + 6] = '|';
	board[row][col + 7] = '_';
	board[row][col + 8] = '|';
	board[row - 1][col + 6] = '|';
	board[row - 1][col + 7] = ' ';
	board[row - 1][col + 8] = '|';



	//left leg

	board[row - 1][col + 2] = '|';
	board[row - 1][col + 4] = '|';
	board[row - 1][col + 3] = '_';



}



/////// ENEMIES ////////



void drawSpike(char board[100][1000], int R, int C) {
	board[R][C] = '/';
	board[R - 1][C + 1] = '/';
	board[R][C + 3] = '\\';
	board[R - 1][C + 2] = '\\';
}



void drawEnemyBirdLeft(char board[100][1000], Enemy bird) {
	int row = bird.Row;
	int col = bird.Col;
	int isDead = bird.isKillable;

	if (isDead != -1) {
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
}

void drawEnemyBirdRight(char board[100][1000], Enemy bird) {
	int row = bird.Row;
	int col = bird.Col;
	int isDead = bird.isKillable;

	if (isDead != -1) {

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
}


////////////////////DEVIL/////////////////////////
/////////////////////////////////////////////////
////////////////////////////////////////////////



void drawDevil(char board[100][1000], Enemy devil) {
	int row = devil.Row, col = devil.Col;
	int isDead = devil.isKillable;
	if (isDead != -1) {
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

		board[row - 11][col] = 'Y';
		board[row - 11][col + 1] = 'O';
		board[row - 11][col + 2] = 'U';
		board[row - 11][col + 3] = ' ';
		board[row - 11][col + 4] = 'S';
		board[row - 11][col + 5] = 'H';
		board[row - 11][col + 6] = 'A';
		board[row - 11][col + 7] = 'L';
		board[row - 11][col + 8] = 'L';
		board[row - 11][col + 9] = ' ';
		board[row - 11][col + 10] = 'N';
		board[row - 11][col + 11] = 'O';
		board[row - 11][col + 12] = 'T';
		board[row - 11][col + 13] = ' ';
		board[row - 11][col + 14] = 'P';
		board[row - 11][col + 15] = 'A';
		board[row - 11][col + 16] = 'S';
		board[row - 11][col + 17] = 'S';
		board[row - 11][col + 18] = '!';

		int hp = devil.Health;
		board[row - 12][col + 7] = 'H';
		board[row - 12][col + 8] = 'P';
		board[row - 12][col + 9] = ':';

		if (hp > 9 && hp < 100) {
			int fDig = hp / 10, sDig = hp % 10;

			board[row - 12][col + 10] = fDig + '0';
			board[row - 12][col + 11] = sDig + '0';
		}
		else if (hp >= 100) {
			int fDig = hp / 100, sDig = (hp / 10) % 10, tDig = hp % 10;

			board[row - 12][col + 10] = fDig + '0';
			board[row - 12][col + 11] = sDig + '0';
			board[row - 12][col + 12] = tDig + '0';
		}
		else if (hp >= 0 && hp <= 9) {
			board[row - 12][col + 10] = hp + '0';
		}
	}
}




/////////////////////////


int chanceMove() {
	int chance = rand() % 2 + 1;

	if (chance == 1) return 1;
	else return 2;
}

void SpawnFireBall(Enemy devil, int& row, int& col, int& r, int& endR, int& endC) {
	if (row == -1 && col == -1 && devil.isKillable != -1) {
		r = chanceMove();

		if (r == 1) {
			row = devil.Row - 10;
			col = devil.Col + devil.maxWidth;
		}
		else if (r == 2) {
			row = devil.Row - 3;
			col = devil.Col + devil.maxWidth;
		}


		if (r == 1) { //Diagonal shoot
			endR = row + 10;
			endC = col + 10;
		}

		else if (r == 2) {  //Horizontal shoot
			endR = row;
			endC = col + 20;
		}
	}
}

//asci 
void drawMoveFireBallDiagonal(char board[100][1000], int& row, int& col, int  endR, int endC) {
	if (row <= endR && col <= endC) {
		board[row][col] = char(232);
		row++;
		col++;
	}
	else {
		row = -1;
		col = -1;
	}
}

void drawMoveFireBallHorizontal(char board[100][1000], int& row, int& col, int endC) {
	if (col <= endC) {
		board[row][col] = char(232);
		col++;
	}
	else {

		row = -1;
		col = -1;
	}
}

int collisionCheckFireballPlayer(int ballR, int ballC, player Player) {
	int playerBottom = Player.Row;
	int playerRight = Player.Col + 14;
	int playerTop = Player.Row - 8;
	int playerLeft = Player.Col;

	if (ballR >= playerTop - 1 && ballR <= playerBottom + 1 && ballC >= playerLeft - 1 && ballC <= playerRight + 1) return 1;
	else return 0;
}



void controlFireBall(char board[100][1000], int& row, int& col, int r, int& endR, int& endC, player& Player) {

	if (row != -1 && col != -1 && !collisionCheckFireballPlayer(row, col, Player)) {

		if (r == 1 && board[row + 1][col + 1] == ' ') drawMoveFireBallDiagonal(board, row, col, endR, endC);
		else if (r == 2 && board[row][col + 1] == ' ') drawMoveFireBallHorizontal(board, row, col, endC);
	}
	else if (collisionCheckFireballPlayer(row, col, Player)) {

		row = -1;
		col = -1;
		Player.Health -= 10; // player gets damaged if the fireball hits him
	}
}




//////////// MAP /////////////

void drawTerrain(char board[100][1000], int r, int c, int NumR, int NumC) {
	int tempCol;
	tempCol = c;
	for (int i = 0; i < NumR; i++) {
		for (int j = 0; j < NumC; j++) {
			board[r][tempCol] = '#';
			tempCol++;
		}
		tempCol = c;
		r++;
	}
}

void drawWall(char board[100][1000], int r, int c, int length) {

	for (int i = 0; i < length; i++) {
		board[r][c] = '#';
		r++;
	}
}


void drawTeleporter(char board[100][1000], int R, int C) {
	board[R - 1][C] = char(186); board[R - 1][C + 17] = char(186);
	board[R - 2][C] = char(186);  board[R - 2][C + 17] = char(186);
	board[R - 3][C] = char(186); board[R - 3][C + 17] = char(186);
	board[R - 4][C] = char(186); board[R - 4][C + 17] = char(186);
	board[R - 5][C] = char(186); board[R - 5][C + 17] = char(186);
	board[R - 6][C] = char(186); board[R - 6][C + 17] = char(186);
	board[R - 7][C] = char(186); board[R - 7][C + 17] = char(186);
	board[R - 8][C] = char(186); board[R - 8][C + 17] = char(186);
	board[R - 9][C] = char(186); board[R - 9][C + 17] = char(186);

	board[R][C] = char(200);

	board[R - 10][C] = char(201);
	board[R - 10][C + 1] = char(205);
	board[R - 10][C + 2] = char(205);
	board[R - 10][C + 3] = char(205);
	board[R - 10][C + 4] = char(205);
	board[R - 10][C + 5] = char(205);
	board[R - 10][C + 6] = char(205);
	board[R - 10][C + 7] = char(205);
	board[R - 10][C + 8] = char(205);
	board[R - 10][C + 9] = char(205);
	board[R - 10][C + 10] = char(205);
	board[R - 10][C + 11] = char(205);
	board[R - 10][C + 12] = char(205);
	board[R - 10][C + 13] = char(205);
	board[R - 10][C + 14] = char(205);
	board[R - 10][C + 15] = char(205);
	board[R - 10][C + 16] = char(205);
	board[R - 10][C + 17] = char(187);


	board[R][C + 1] = char(205);
	board[R][C + 2] = char(205);
	board[R][C + 3] = char(205);
	board[R][C + 4] = char(205);
	board[R][C + 5] = char(205);
	board[R][C + 6] = char(205);
	board[R][C + 7] = char(205);
	board[R][C + 8] = char(205);
	board[R][C + 9] = char(205);
	board[R][C + 10] = char(205);
	board[R][C + 11] = char(205);
	board[R][C + 12] = char(205);
	board[R][C + 13] = char(205);
	board[R][C + 14] = char(205);
	board[R][C + 15] = char(205);
	board[R][C + 16] = char(205);
	board[R][C + 17] = char(188);

}

void drawCoin(char board[100][1000], int R, int C, int  isCollectable) {
	if (isCollectable == 0) {
		board[R][C + 1] = '\\';
		board[R][C + 2] = '_';
		board[R][C + 3] = '_';
		board[R][C + 4] = '_';
		board[R][C + 5] = '_';
		board[R][C + 6] = '_';
		board[R][C + 7] = '/';

		board[R - 1][C] = '|';
		board[R - 1][C + 1] = ' ';
		board[R - 1][C + 2] = ' ';
		board[R - 1][C + 3] = ' ';
		board[R - 1][C + 4] = '$';
		board[R - 1][C + 5] = ' ';
		board[R - 1][C + 6] = ' ';
		board[R - 1][C + 7] = ' ';
		board[R - 1][C + 8] = '|';

		board[R - 2][C + 1] = '/';
		board[R - 2][C + 2] = ' ';
		board[R - 2][C + 3] = ' ';
		board[R - 2][C + 4] = ' ';
		board[R - 2][C + 5] = ' ';
		board[R - 2][C + 6] = ' ';
		board[R - 2][C + 7] = '\\';

		board[R - 3][C + 2] = '_';
		board[R - 3][C + 3] = '_';
		board[R - 3][C + 4] = '_';
		board[R - 3][C + 5] = '_';
		board[R - 3][C + 6] = '_';

	}

}




void spawnHeart(char board[100][1000], hearts heart[], int  i) {
	if (heart[i].isCollected == 0) {
		int row = heart[i].Row;
		int col = heart[i].Col;

		board[row - 2][col] = ':';
		board[row - 3][col] = '.';

		board[row - 3][col + 1] = ':';
		board[row - 2][col + 1] = ':';
		board[row - 1][col + 1] = '\'';

		board[row - 3][col + 2] = ':';
		board[row - 2][col + 2] = ':';
		board[row - 1][col + 2] = ':';

		board[row - 3][col + 3] = ':';
		board[row - 2][col + 3] = ':';
		board[row - 1][col + 3] = ':';
		board[row][col + 3] = '\'';


		board[row - 3][col + 4] = '.';
		board[row - 2][col + 4] = ':';
		board[row - 1][col + 4] = ':';
		board[row - 0][col + 4] = ':';



		board[row - 2][col + 8] = ':';
		board[row - 3][col + 8] = '.';

		board[row - 3][col + 7] = ':';
		board[row - 2][col + 7] = ':';
		board[row - 1][col + 7] = '\'';

		board[row - 3][col + 6] = ':';
		board[row - 2][col + 6] = ':';
		board[row - 1][col + 6] = ':';

		board[row - 3][col + 5] = ':';
		board[row - 2][col + 5] = ':';
		board[row - 1][col + 5] = ':';
		board[row][col + 5] = '\'';

	}
}

void drawLadder(char board[100][1000], int row, int col, int length) {

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

void Hiddenladder(char board[100][1000], int row, int col, int length, int isClicked) {
	if (isClicked)
	{
		drawLadder(board, row, col, length);
	}
}

void drawButton(char board[100][1000], int row, int col, int isClicked) {
	board[row][col] = '(';
	board[row][col + 1] = '#';
	board[row][col + 2] = '#';
	board[row][col + 3] = '#';
	board[row][col + 4] = '#';
	board[row][col + 5] = '#';
	board[row][col + 6] = '#';
	board[row][col + 7] = '#';
	board[row][col + 8] = '#';
	board[row][col + 9] = '#';
	board[row][col + 10] = '#';
	board[row][col + 11] = '#';
	board[row][col + 12] = '#';
	board[row][col + 13] = ')';

	if (isClicked) {
		board[row - 1][col + 4] = '#';
		board[row - 1][col + 5] = '#';
		board[row - 1][col + 6] = '#';
		board[row - 1][col + 7] = '#';
		board[row - 1][col + 8] = '#';

		board[row - 15][col - 5] = 'L';
		board[row - 15][col - 4] = 'A';
		board[row - 15][col - 3] = 'D';
		board[row - 15][col - 2] = 'D';
		board[row - 15][col - 1] = 'E';
		board[row - 15][col] = 'R';
		board[row - 15][col + 1] = ' ';
		board[row - 15][col + 2] = 'H';
		board[row - 15][col + 3] = 'A';
		board[row - 15][col + 4] = 'S';
		board[row - 15][col + 5] = ' ';
		board[row - 15][col + 6] = 'D';
		board[row - 15][col + 7] = 'E';
		board[row - 15][col + 8] = 'S';
		board[row - 15][col + 9] = 'C';
		board[row - 15][col + 10] = 'E';
		board[row - 15][col + 11] = 'N';
		board[row - 15][col + 12] = 'D';
		board[row - 15][col + 13] = 'E';
		board[row - 15][col + 14] = 'D';
		board[row - 15][col + 15] = '!';

		board[row - 14][col + 6] = 'G';
		board[row - 14][col + 7] = 'O';
		board[row - 14][col + 8] = ' ';
		board[row - 14][col + 9] = 'B';
		board[row - 14][col + 10] = 'A';
		board[row - 14][col + 11] = 'C';
		board[row - 14][col + 12] = 'K';
		board[row - 14][col + 13] = '!';


	}
	else {
		board[row - 1][col + 4] = '#';
		board[row - 1][col + 5] = '#';
		board[row - 1][col + 6] = '#';
		board[row - 1][col + 7] = '#';
		board[row - 1][col + 8] = '#';

		board[row - 15][col] = 'P';
		board[row - 15][col + 1] = 'R';
		board[row - 15][col + 2] = 'E';
		board[row - 15][col + 3] = 'S';
		board[row - 15][col + 4] = 'S';
		board[row - 15][col + 5] = ' ';
		board[row - 15][col + 6] = '\'';
		board[row - 15][col + 7] = 'E';
		board[row - 15][col + 8] = '\'';
	}

}



/////////////////////////////////////////////
/////////////////////////////////////////////
//////////////// HIT BOX ////////////////////


void EnemyPlayerCollision(Enemy iskill[], int numberIsKill, Enemy unkill[], int numberUnKill, player P) {

	for (int i = 0; i < numberIsKill; i++) {

		int enemyTop = iskill[i].Row - iskill[i].maxHeight + 1;
		int enemyBottom = iskill[i].Row;
		int enemyLeft = iskill[i].Col;
		int enemyRight = iskill[i].Col + iskill[i].maxWidth - 1;

		int  pTop = P.Row - 8;
		int  pBottom = P.Row;
		int pLeft = P.Col;
		int pRight = P.Col + 14;

		if (pRight >= enemyLeft - 1 && pLeft <= enemyRight + 1 && pBottom >= enemyTop - 1 && pTop <= enemyBottom + 1) {
			P.Health -= iskill[i].attackPower;
		}
	}
	for (int i = 0; i < numberUnKill; i++) {

		int enemyTop = unkill[i].Row - unkill[i].maxHeight + 1;
		int enemyBottom = unkill[i].Row;
		int enemyLeft = unkill[i].Col;
		int enemyRight = unkill[i].Col + unkill[i].maxWidth - 1;

		int  pTop = P.Row - 8;
		int  pBottom = P.Row;
		int pLeft = P.Col;
		int pRight = P.Col + 14;

		if (pRight >= enemyLeft - 1 && pLeft <= enemyRight + 1 && pBottom >= enemyTop - 1 && pTop <= enemyBottom + 1) {
			P.Health -= unkill[i].attackPower;
		}
	}




}









//////////////////////////////////////////////
/////////////////////////////////////////////
////////////////////////////////////////////

void scroll(char board[100][1000], int& posJHero, int& posIHero, int widthHero, int heightHero, int& dispR, int& dispC) {
	dispC = posJHero - 30;
	if (dispC < 0) dispC = 0;
	if (dispC > 1000 - 80) dispC = 1000 - 80;

	dispR = posIHero + 2;
	if (dispR < 24) dispR = 23;
	if (dispR > 86) dispR = 98;

}





/////////////// CALL OBJECTS /////////////////
//////////////////////////////////////////////
//////////////////////////////////////////////



void moveElevatorVertically(int& row, int startRow, int endRow, int& direction) {
	if (row == endRow) direction = 2;
	else if (row == startRow) direction = 1;

	if (direction == 1) row--;
	else if (direction == 2)row++;
}

void moveElevatorHorizontally(int& col, int startCol, int endCol, int& direction) {
	if (col == endCol) direction = 2;
	else if (col == startCol) direction = 1;

	if (direction == 1) col++;
	else if (direction == 2) col--;
}

void drawElevator(char board[100][1000], int row, int col) {
	board[row][col] = '_';
	board[row][col + 1] = '_';
	board[row][col + 2] = '_';
	board[row][col + 3] = '_';
	board[row][col + 4] = '_';
	board[row][col + 5] = '_';
	board[row][col + 6] = '_';
	board[row][col + 7] = '_';
	board[row][col + 8] = '_';
	board[row][col + 9] = '_';
}

void drawAndMoveElevatorV(char board[100][1000], Elevator elevator[], int i) {
	moveElevatorVertically(elevator[i].row, elevator[i].startRow, elevator[i].endRow, elevator[i].direction);
	drawElevator(board, elevator[i].row, elevator[i].col);

}

void drawAndMoveElevatorH(char board[100][1000], Elevator elevator[], int i) {
	moveElevatorHorizontally(elevator[i].col, elevator[i].startCol, elevator[i].endCol, elevator[i].direction);
	drawElevator(board, elevator[i].row, elevator[i].col);
}


void ElevatePlayer(char board[100][1000], int& dispR, int& dispC, int& pX, int& pY, Elevator elevator[], int nElevators) {
	for (int i = 0; i < nElevators; i++) {
		// Vertical Elevator
		if (elevator[i].whichD == 0) {
			int ignoreElevetor = 0;
			int elTop = elevator[i].row;
			int elLeft = elevator[i].col;
			int elRight = elevator[i].col + elevator[i].length - 1;

			// Same horizontal range logic
			if ((pX + 1) == elTop && pY + 14 - 1 >= elLeft && pY <= elRight) {
				if (elevator[i].direction == 1) { // Up
					if (elevator[i].endRow == elevator[i].row) {
						pX++;
					}
					else pX--;
					scroll(board, pY, pX, 15, 8, dispR, dispC);
				}
				else if (elevator[i].direction == 2) { // Down
					if (elevator[i].row < 97) {
						if (pX > 97) pX = 97;
						else {
							if (elevator[i].startRow == elevator[i].row)pX--;
							else pX++;
						}
					}
					scroll(board, pY, pX, 15, 8, dispR, dispC);
				}
			}
		}
		// Horizontal Elevator
		if (elevator[i].whichD == 1) {
			int elTop = elevator[i].row;
			int elLeft = elevator[i].col;
			int elRight = elevator[i].col + elevator[i].length - 1;

			// Check if player's feet are on elevator
			if ((pX + 1) == elTop && pY + 14 - 1 >= elLeft && pY <= elRight) {
				if (elevator[i].direction == 1) { // Right
					if (elevator[i].col == elevator[i].endCol) pY--;
					else pY++;
					scroll(board, pY, pX, 15, 8, dispR, dispC);
				}
				else if (elevator[i].direction == 2) { // Left
					if (elevator[i].col == elevator[i].startCol) pY++;
					pY--;
					scroll(board, pY, pX, 15, 8, dispR, dispC);
				}
			}
		}

	}

}





int checkEnemyHit(int row, int col, Enemy enemy) {
	int checkhit = 0;
	// Enemy bounding box
	int top = enemy.Row - enemy.maxHeight + 1;
	int bottom = enemy.Row + 1;
	int left = enemy.Col - 1;
	int right = enemy.Col + enemy.maxWidth + 1;

	if (row >= top && row <= bottom && col >= left && col <= right) {
		checkhit = 1;
	}
	return checkhit;
}



void callObj(char board[100][1000], coin coins[5], Enemy isKill[], hearts heart[] , int isClicked) {
	//The part for the devil
	drawTerrain(board, 95, 61, 1, 11);
	drawTerrain(board, 92, 46, 1, 11);
	drawTerrain(board, 88, 20, 1, 20);
	drawLadder(board, 87, 20, 15);
	drawTerrain(board, 71, 31, 1, 30);
	drawLadder(board, 70, 50, 20);
	drawTerrain(board, 50, 1, 1, 50);
	drawDevil(board, isKill[0]);
	drawCoin(board, coins[0].Row, coins[0].Col, coins[0].isCollected);


	//The snail part

	drawTerrain(board, 70, 65, 1, 23);
	drawCoin(board, coins[1].Row, coins[1].Col, coins[1].isCollected); // row = 69 , col = 66


	//Crystals part
	//each crystal takes width 10 , there are 5 crystals and we must leave a distance of 20 between each so its 10*5 + 20*5= 150
	//this terrain is drawn over the crystals+ above the button so lets say 150 + 25 = 175  , 25 cols to leave space for button
	drawTerrain(board, 70, 97, 1, 178);
	//col at end is 100+ 175 = 275


	//drawButton(board , 97 , 250); 
	drawButton(board , 98 , 250 , isClicked);
	drawWall(board, 70, 275, 27);
	
	Hiddenladder(board, 97, 88, 27, isClicked);

	spawnHeart(board, heart, 0); // row = 69 , col = 130

	//elevator takes player to row 50 , col 150

	//the part where the assault rifle drop should be 
	drawWall(board, 2, 150 - 50, 47);
	drawTerrain(board, 50, 150 - 50, 1, 50);

	drawTerrain(board, 50, 150 + 10, 1, 50);

	drawWall(board, 2, 210, 47);
}


void callDynamicObj(char board[100][1000], Elevator elevator[], int &posXLaz , int posYLaz[], int direction, int &whatLaz , int &isShooting , Enemy enemyKill[]) {
	drawAndMoveElevatorV(board, elevator, 0); //(board, elevator, 0, 69, 150, 69, 51, 150, 150, 0, 1); // Vertical  
	drawAndMoveElevatorH(board, elevator, 1);



	//drawSnail( board , 69 , 75); DRAW IT IN CALLDYNAMICOBJ
	//Draw crystal *5; . start col for the first should be 110 , leave 20 columns space between each , end col for the last should be 240

	if (whatLaz <= 19 && isShooting == 1 && posXLaz >= 0 && posYLaz[0] >= 0) {
		int nextY;

		// Decide nextY based on direction
		if (direction == 0) {
			nextY = posYLaz[whatLaz] + 1;
		}
		else if (direction == 1) {
			nextY = posYLaz[whatLaz] - 1;
		}

		// Make sure nextY is valid and space is empty
		if (nextY >= 0 && nextY < 1000 && board[posXLaz][nextY] == ' ') {
			whatLaz++;
			posYLaz[whatLaz] = nextY;

			// Draw trail (last 10 segments or less)
			if (whatLaz >= 10) {
				for (int i = whatLaz - 10; i <= whatLaz; i++) {
					board[posXLaz][posYLaz[i]] = '_';
				}
			}
			else {
				for (int i = 0; i <= whatLaz; i++) {
					board[posXLaz][posYLaz[i]] = '_';
				}
			}
		}
		else {
			// Collision: check for enemy hit
			for (int i = 0; i <= 9; i++) {
				int check = checkEnemyHit(posXLaz, posYLaz[whatLaz], enemyKill[i]);
				if (check == 1) {
					enemyKill[i].Health -= 30;
					if (enemyKill[i].Health <= 0) {
						enemyKill[i].isKillable = -1;
						enemyKill[i].Row = -100;
						enemyKill[i].Col = -100;
					}
				}
			}

			// Stop shooting
			isShooting = 0;
			whatLaz = 0;
			for (int i = 0; i < 20; i++) {
				posYLaz[i] = -1;
			}
			posXLaz = -1;
		}
	}
	else {
		// Reset if invalid
		whatLaz = 0;
		isShooting = 0;
		for (int i = 0; i < 20; i++) {
			posYLaz[i] = -1;
		}
		posXLaz = -1;
	}

}

///////////////////////////////


void clearMap(char board[100][1000], int dispR, int dispC) {
	int top = dispR - 23;
	if (top < 0) top = 0;
	for (int i = top; i <= dispR; i++) {
		for (int j = dispC + 1; j < dispC + 80 - 1; j++) {
			board[i][j] = ' ';
		}
	}


}

void addBorders(char board[100][1000], int dispR, int dispC) {
	int top = dispR - 23;
	int bottom = dispR;

	// Top border
	board[top - 1][dispC] = char(201);
	for (int j = dispC + 1; j < dispC + 80 - 1; j++) {
		board[top - 1][j] = char(205);
	}
	board[top - 1][dispC + 80 - 1] = char(187);

	// Side borders
	for (int i = top; i <= bottom; i++) {
		board[i][dispC] = char(186);
		board[i][dispC + 80 - 1] = char(186);
	}

	// Bottom border
	board[bottom + 1][dispC] = char(200);
	for (int j = dispC + 1; j < dispC + 80 - 1; j++) {
		board[bottom + 1][j] = char(205);
	}
	board[bottom + 1][dispC + 80 - 1] = char(188);
}


void Clear_LoadMap(char board[100][1000], int dispR, int dispC) {

	//ANSI CODE COLORS
	char green[] = "\033[32m";
	char blue[] = "\033[34m";
	char red[] = "\033[31m";
	char yellow[] = "\033[33m";
	char cyan[] = "\033[36m";
	char reset[] = "\033[0m";
	char bold[] = "\033[1m";

	int top = dispR - 23;
	int bottom = dispR;

	for (int i = top - 1; i <= bottom + 1; i++) { // includes borders
		for (int j = dispC; j < dispC + 80; j++) {
			if (i == top - 1 || i == bottom + 1) { // top or bottom border
				cout << blue << board[i][j] << reset;
			}
			else if (j == dispC || j == dispC + 80 - 1) { // side borders
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

void checkCoinTouch(char board[100][1000], int pX, int pY, int pWidth, int pHeight, coin coins[5], int& numCoinsP) {
	for (int a = 0; a < 5; a++) {
		if (!coins[a].isCollected) {

			int coinTop = coins[a].Row - coins[a].maxHeight + 1 - 1;
			int coinBottom = coins[a].Row + 1;
			int coinLeft = coins[a].Col - 1;
			int coinRight = coins[a].Col + coins[a].maxWidth - 1 + 1;

			int playerTop = pX - pHeight + 1;
			int playerBottom = pX;
			int playerLeft = pY;
			int playerRight = pY + pWidth - 1;

			int overlapX = 0;
			int overlapY = 0;


			if (playerLeft <= coinRight && playerRight >= coinLeft) {
				overlapX = 1;
			}

			if (playerTop <= coinBottom && playerBottom >= coinTop) {
				overlapY = 1;
			}

			if (overlapX && overlapY) {
				coins[a].isCollected = 1;
				numCoinsP += 25;
				break;
			}
		}

	}
}


void checkHeartTouch(char board[100][1000], int pX, int pY, int pWidth, int pHeight, hearts Heart[4], int& playerHp) {
	for (int a = 0; a < 4; a++) {
		if (!Heart[a].isCollected) {

			int heartTop = Heart[a].Row - Heart[a].maxHeight + 1 - 1;
			int heartBottom = Heart[a].Row + 1;
			int heartLeft = Heart[a].Col - 1;
			int heartRight = Heart[a].Col + Heart[a].maxWidth - 1 + 1;

			int playerTop = pX - pHeight + 1;
			int playerBottom = pX;
			int playerLeft = pY;
			int playerRight = pY + pWidth - 1;

			int overlapX = 0;
			int overlapY = 0;


			if (playerLeft <= heartRight && playerRight >= heartLeft) {
				overlapX = 1;
			}

			if (playerTop <= heartBottom && playerBottom >= heartTop) {
				overlapY = 1;
			}

			if (overlapX && overlapY) {
				Heart[a].isCollected = 1;
				playerHp += 100;
				break;
			}
		}

	}
}









///////////////////////////////////////
//Player Movement Functions

void moveRight(char board[100][1000], int& posJHero, int& posIHero, int widthHero, int heightHero, int LC[9], ladder ladders[4], coin coins[5], int& numCoinsP, hearts Heart[4], int& playerHp) {
	int check = 1;
	// Check every cell in the column to the right of the player
	for (int i = posIHero; i >= posIHero - heightHero + 1; i--) {
		int lc_index = posIHero - i;
		// Convert to LC index (0=bottom)
		if (lc_index >= 0 && lc_index < 9) {
			if (board[i][LC[lc_index] + 1] != ' ' && board[i][LC[lc_index] + 1] != char(186)) {
				check = 0;
				break;
			}
		}
	}
	int check2 = 1;
	for (int i = posIHero - 1; i >= posIHero - heightHero + 1; i--) {
		int lc_index = posIHero - i;  // Convert to LC index (0 to 8)
		if (lc_index >= 0 && lc_index < 9) {
			if (board[i][LC[lc_index] + 1] != ' ' && board[i][LC[lc_index] + 1] != char(186)) {
				check2 = 0;
				break;
			}
		}
	}

	int isOnLadder = 0;
	for (int i = 0; i < 4; i++) {
		if (posJHero + widthHero >= ladders[i].Col - 1 && posJHero <= ladders[i].Col + ladders[i].length) { // <- FIXED here
			if (posIHero <= ladders[i].Row + 1 && posIHero - heightHero + 1 >= ladders[i].Row - ladders[i].length - 1) {
				isOnLadder = 1;
				break;
			}
		}
	}


	if (isOnLadder == 1) {
		check = 1;
	}
	//Go up a row if its only 1 row diffrence in terrain


	if (board[posIHero][LC[0]] != ' ' && board[posIHero][LC[0]] != char(186) && check2 && !check) {
		posIHero--;
		posJHero++;
	}
	// Only move if all checks passed AND we won't go out of bounds
	else if (check == 1 && posJHero + widthHero + 1 < 999) {
		posJHero++;
	}

	checkCoinTouch(board, posIHero, posJHero, widthHero, heightHero, coins, numCoinsP);

	checkHeartTouch(board, posIHero, posJHero, widthHero, heightHero, Heart, playerHp);
}

void moveLeft(char board[100][1000], int& posJHero, int& posIHero, int widthHero, int heightHero, int LC[9], ladder ladders[4], coin coins[5], int& numCoinsP, hearts Heart[4], int& playerHp) {
	int check = 1;

	for (int i = posIHero; i >= posIHero - heightHero + 1; i--) {
		int lc_index = posIHero - i;
		if (lc_index >= 0 && lc_index < 9) {
			if (board[i][LC[lc_index] - 1] != ' ' && board[i][LC[lc_index] - 1] != char(186)) {
				check = 0;
				break;
			}
		}
	}
	int check2 = 1;
	for (int i = posIHero - 1; i >= posIHero - heightHero + 1; i--) {
		int lc_index = posIHero - i;
		if (lc_index >= 0 && lc_index < 9) {
			if (board[i][LC[lc_index] - 1] != ' ' && board[i][LC[lc_index] - 1] != char(186)) {
				check2 = 0;
				break;
			}
		}
	}

	int isOnLadder = 0;
	for (int i = 0; i < 4; i++) {
		if (posJHero >= ladders[i].Col - widthHero && posJHero <= ladders[i].Col + ladders[i].length + widthHero) { // <- FIXED here
			if (posIHero <= ladders[i].Row + 1 && posIHero - heightHero + 1 >= ladders[i].Row - ladders[i].length - 1) {
				isOnLadder = 1;
				break;
			}
		}
	}

	if (isOnLadder == 1) {
		check = 1;
	}

	if (board[posIHero][LC[0]] != ' ' && board[posIHero][LC[0]] != char(186) && check2 && !check) {
		posJHero--;
		posIHero--;
	}
	else if (check == 1 && posJHero - 1 >= 0) {
		posJHero--;
	}


	checkCoinTouch(board, posIHero, posJHero, widthHero, heightHero, coins, numCoinsP);
	checkHeartTouch(board, posIHero, posJHero, widthHero, heightHero, Heart, playerHp);


}

void jumpStraight(char board[100][1000], int& pX, int& pY, int pHeight, int pWidth, int& isJumping, player Player, int gun, int animation, int dispR, int dispC, int LC[9], int LR[15], coin coins[5], int& numCoinsP, Elevator elevator[], Enemy enemyKill[], int& DFireBallR, int& DFireBallC, int& chance, int& endR, int& endC, hearts Heart[4], int& playerHp ,int &posXLaz,int posYLaz[], int direction, int &whatlaz, int &isShooting , int isClicked ) {


	scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
	clearMap(board, dispR, dispC);
	callObj(board, coins, enemyKill, Heart , isClicked); // Call the function to draw the objects
	SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
	controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);

	addBorders(board, dispR, dispC);
	if (animation == 0 || animation == -1) {
		jumprightframe(board, pX, pY, LC, LR); // Draw the player jumping up
	}
	else if (animation == 1 || animation == -2) {
		jumpleftframe(board, pX, pY, LC, LR); // Draw the player jumping up
	}

	for (int i = 0; i < 4; i++) {
		if (pX - pHeight < 0) break;
		int check = 1;

		for (int j = pY; j <= pY + (pWidth - 1) && j < 999; j++) {
			int LR_index = j - pY;  // Correctly calculate LR_index based on the position you're checking
			if (LR_index >= 0 && LR_index < 15) {  // Ensure it's within bounds
				int checkR = LR[LR_index] - 1; // Check the row index
				if (board[checkR][j] != ' ') {  // If there's a solid block, stop the jump
					check = 0;
					break;
				}
			}
			else {
				check = 0; // Exit loop if out-of-bounds
				break;
			}
		}

		if (pX - pHeight - 1 > 0 && check == 1) {
			pX--;

			checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
			checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
			ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
			scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
			clearMap(board, dispR, dispC);

			callObj(board, coins, enemyKill, Heart, isClicked);
			SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
			controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);
			callDynamicObj(board, elevator , posXLaz , posYLaz , direction , whatlaz , isShooting , enemyKill);
			addBorders(board, dispR, dispC);

			if (animation == 0 || animation == -1) {
				jumprightframe(board, pX, pY, LC, LR); // Draw the player jumping up
			}
			else if (animation == 1 || animation == -2) {
				jumpleftframe(board, pX, pY, LC, LR); // Draw the player jumping up
			}
			system("cls");
			dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, Player.gun); // Display the bar first
			Clear_LoadMap(board, dispR, dispC); // Clear the screen and load the map

			isJumping = 1;
		}
		else break;

	}
	isJumping = 0;
}


void FallStraight(char board[100][1000], int& pX, int& pY, int pHeight, int pWidth, int& isJumping, player Player, int gun, int& isFalling, int animation, int dispR, int dispC, int LC[9], int LR[15], coin coins[5], int& numCoinsP, Elevator elevator[], Enemy enemyKill[], int& DFireBallR, int& DFireBallC, int& chance, int& endR, int& endC, hearts Heart[4], int& playerHp, int& posXLaz, int posYLaz[], int direction, int& whatlaz, int& isShooting, int isClicked) {
	for (; pX + 1 < 99; ) {
		if (pX - pHeight < 0) break;

		int check = 1; // Reset every fall attempt

		for (int j = pY + 2; j <= pY + 10; j++) {
			if (board[pX + 1][j] != ' ' && board[pX + 1][j] != char(186)) {
				check = 0;
				break;
			}
		}

		if (check == 0) {
			break; // Landed on something, stop falling
		}

		pX++;
		checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
		checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
		ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
		scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
		clearMap(board, dispR, dispC);

		callObj(board, coins, enemyKill, Heart, isClicked);
		SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
		controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);

		callDynamicObj(board, elevator, posXLaz, posYLaz, direction, whatlaz, isShooting, enemyKill);
		addBorders(board, dispR, dispC);

		if (animation == 0 || animation == -1) {
			jumprightframe(board, pX, pY, LC, LR);
		}
		else if (animation == 1 || animation == -2) {
			jumpleftframe(board, pX, pY, LC, LR);
		}

		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, Player.gun);
		Clear_LoadMap(board, dispR, dispC);

		isFalling = 1;
	}
	checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
	checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
	ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
	isJumping = 0;
	isFalling = 0;
}


void jumpRight(char board[100][1000], int& pX, int& pY, int pHeight, int pWidth,
	int& isJumping, player Player, int gun, int& isFalling,
	int& isWalking, int dispR, int dispC, int LC[9], int LR[15], coin coins[5], int& numCoinsP, Elevator elevator[], Enemy enemyKill[], int& DFireBallR, int& DFireBallC, int& chance, int& endR, int& endC, hearts Heart[4], int& playerHp, int& posXLaz, int posYLaz[], int direction, int& whatlaz, int& isShooting, int isClicked) {
	// Initial setup
	scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
	clearMap(board, dispR, dispC);
	SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
	controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);

	callObj(board, coins, enemyKill, Heart, isClicked);
	addBorders(board, dispR, dispC);
	jumprightframe(board, pX, pY, LC, LR);

	// Jump right (diagonal up-right movement)
	for (int a = 0; a < 5; a++) {
		int canJump = 1; // 1 = can jump, 0 = cannot jump

		// Check right side collision using LC (last column in each row)
		for (int row = pX; row >= pX - pHeight + 1; row--) {
			int lc_index = pX - row;
			if (lc_index >= 0 && lc_index < 9) {
				if (board[row][LC[lc_index] + 1] != ' ' &&
					board[row][LC[lc_index] + 1] != char(186)) {
					canJump = 0;
					break;
				}
			}
		}

		// Check upward clearance using LR (highest row in each column)
		for (int col = pY; col < pY + pWidth; col++) {
			int lr_index = col - pY;
			if (lr_index >= 0 && lr_index < 15) {
				if (LR[lr_index] - 1 < 0 ||  // Check bounds
					(board[LR[lr_index] - 1][col] != ' ' &&
						board[LR[lr_index] - 1][col] != char(186))) {
					canJump = 0;
					break;
				}
			}
		}

		if (canJump == 0) break;
		if (pY + pWidth >= 998) break;
		// Move diagonally up-right
		pX--;
		pY++;
		checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
		checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
		// Redraw everything
		scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
		ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
		clearMap(board, dispR, dispC);
		SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
		controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);


		callObj(board, coins, enemyKill, Heart, isClicked);

		callDynamicObj(board, elevator, posXLaz, posYLaz, direction, whatlaz, isShooting, enemyKill);
		addBorders(board, dispR, dispC);
		jumprightframe(board, pX, pY, LC, LR);

		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, Player.gun);
		Clear_LoadMap(board, dispR, dispC);
		isJumping = 1;
	}

	// Falling logic
	for (;;) {
		int canFall = 0;

		// Check if we can fall straight down
		for (int col = pY + 2; col <= pY + 10; col++) {
			if (pX + 1 < 100 && (board[pX + 1][col] == ' ' || board[pX + 1][col] == char(186))) {
				canFall = 1;
			}
			else {
				canFall = 0;
				break;
			}
		}

		if (canFall == 0) break;

		// Check if we can fall diagonally right
		int canFallRight = 1;
		if (pY + pWidth < 999) {
			for (int row = pX; row <= pX + 1; row++) {
				if (board[row][pY + pWidth] != ' ' &&
					board[row][pY + pWidth] != char(186)) {
					canFallRight = 0;
					break;
				}
			}
		}
		else {
			canFallRight = 0;
		}

		if (canFallRight == 1) {
			pX++;
			pY++;
		}
		else {
			pX++;
		}
		checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
		checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
		ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);

		// Redraw everything
		scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
		clearMap(board, dispR, dispC);

		callObj(board, coins, enemyKill, Heart, isClicked);
		SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
		controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);


		callDynamicObj(board, elevator, posXLaz, posYLaz, direction, whatlaz, isShooting, enemyKill);
		addBorders(board, dispR, dispC);
		jumprightframe(board, pX, pY, LC, LR);

		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, Player.gun);
		Clear_LoadMap(board, dispR, dispC);
		isFalling = 1;
	}
	checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
	checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
	ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
	isJumping = 0;
	isFalling = 0;
	isWalking = 0;
}
void jumpLeft(char board[100][1000], int& pX, int& pY, int pHeight, int pWidth, int& isJumping, player Player, int gun, int& isFalling, int& isWalking, int dispR, int dispC, int LC[9], int LR[15], coin coins[5], int& numCoinsP, Elevator elevator[], Enemy enemyKill[], int& DFireBallR, int& DFireBallC, int& chance, int& endR, int& endC, hearts Heart[4], int& playerHp, int& posXLaz, int posYLaz[], int direction, int& whatlaz, int& isShooting , int isClicked) {

	scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
	clearMap(board, dispR, dispC);


	callObj(board, coins, enemyKill, Heart, isClicked);

	addBorders(board, dispR, dispC);
	jumpleftframe(board, pX, pY, LC, LR);


	for (int a = 0; a < 5; a++) {

		int check = 1;
		for (int j = pY; j <= pY + (pWidth - 1) && j < 999; j++) {
			int LR_index = j - pY;  // Correctly calculate LR_index based on the position you're checking
			if (LR_index >= 0 && LR_index < 15) {  // Ensure it's within bounds
				int checkR = LR[LR_index] - 1; // Check the row index
				if (board[checkR][j] != ' ') {  // If there's a solid block, stop the jump
					check = 0;
					break;
				}
			}
			else {
				check = 0; // Exit loop if out-of-bounds
				break;
			}

		}

		for (int i = pX; i >= pX - pHeight + 1; i--) {
			int lc_index = pX - i;  // Convert to LC index (0 to 8)
			if (lc_index >= 0 && lc_index < 9) {
				if (board[i][LC[lc_index] - 1] != ' ' && board[i][LC[lc_index] - 1] != char(186)) {
					check = 0;
					break;
				}
			}
		}

		if (pX - pHeight < 1) break;
		if (pY - 1 < 1) break;

		if (check == 0) break;


		pX--;
		pY--;

		checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
		checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
		ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
		scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
		clearMap(board, dispR, dispC);

		callObj(board, coins, enemyKill, Heart, isClicked);

		callDynamicObj(board, elevator, posXLaz, posYLaz, direction, whatlaz, isShooting, enemyKill);
		addBorders(board, dispR, dispC);
		jumpleftframe(board, pX, pY, LC, LR);

		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, Player.gun);
		Clear_LoadMap(board, dispR, dispC);
		isJumping = 1;

	}

	int check = 1;
	for (int j = pY + 2; j <= pY + 10; j++) {
		if (board[pX + 1][j] != ' ') {
			check = 0;
			break;
		}
	}

	for (; pX + 1 < 23 && board[pX + 1][pY] == ' ' && pY > 1;) {
		int checkDiagonal = 1;
		for (int j = pY + 2; j <= pY + 10; j++) {

			if (board[pX + 1][j] != ' ') {
				checkDiagonal = 0;
				break;
			}
		}


		if (checkDiagonal && check) {
			pX++;
			pY--;


			checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
			checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
			ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
			scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
			clearMap(board, dispR, dispC);

			callObj(board, coins, enemyKill, Heart, isClicked);

			callDynamicObj(board, elevator, posXLaz, posYLaz, direction, whatlaz, isShooting, enemyKill);
			SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
			controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);

			addBorders(board, dispR, dispC);
			jumpleftframe(board, pX, pY, LC, LR);

			system("cls");
			dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, Player.gun);
			Clear_LoadMap(board, dispR, dispC);
			isFalling = 1;
		}
	}
	checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
	checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
	ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
	isWalking = 0;
	isJumping = 0, isFalling = 0; // Reset jumping and falling states after landing

}









//////////////////////////////////////////////////////////
////////////////////////Shooting/////////////////////////
void checkEnemyHit(int row, int col, Enemy& enemy, int& checkhit) {
	checkhit = 0;
	// Enemy bounding box
	int top = enemy.Row - enemy.maxHeight + 1;
	int bottom = enemy.Row + 1;
	int left = enemy.Col - 1;
	int right = enemy.Col + enemy.maxWidth + 1;

	if (row >= top && row <= bottom && col >= left && col <= right) {
		checkhit = 1;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			




void shootLazer(int shootR , int shootC ,int& posXLaz , int posYlaz[] , int direction) {

	posXLaz = shootR;

	if(direction == 0) posYlaz[0] = shootC+1;
	else posYlaz[0] = shootC-1;
}



/////////////////////////////////////////////////////////////////////



void checkIsEnemyDead(Enemy enemyKill[]) {
	for (int i = 0; i < 9; i++) {
		if (enemyKill[i].Health <= 0) {
			enemyKill[i].isKillable = -1;
			enemyKill[i].Row = -100;
			enemyKill[i].Col = -100;
		}
	}
}


int main() {
	srand(time(0));

	int width = 80, height = 24;
	char board[100][1000];
	int dispR = 95, dispC = 3;

	char choice;
	for (;;) {
		system("cls");
		showMainMenu(choice);
		if (choice == '4') {
			cout << "Exiting game..." << endl;
			system("cls");
			break;
		}
		else if (choice == '1') {
			cout << "Starting Game..." << endl;
			system("cls");
			break;
		}
		else if (choice == '2') {
			cout << "Instructions..." << endl;
			system("cls");
			displayInstructions();
		}
		else if (choice == '3') {
			cout << "Credits..." << endl;
			system("cls");
			displayCredits();
		}
	}

	if (choice == '1') {
		system("cls");
		player Player;
		initializePlayerValues(Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, Player.Health, Player.coins, Player.gun, Player.ammo, Player.maxAmmo, Player.shootR, Player.shootC);
		initializeBoard(board);
		Player.gun = 0;
		int lastCellCol[9], lastCellRow[15];

		int isWalking = 0, isJumping = 0, isFalling = 0, isShooting = 0, isReloading = 0, isClimbing = 0;

		int posXLaz= -1;
		int posYLaz[20] = { -1 };
		int whatLaz = 0 , direction =-1;

		int HiddenladderButtonClicked = 0 , btnrow = 98 , btnmaxR = 98-15 , btnCol = 250 , btnmaxC = 250 + 10;

		ladder ladders[4];
		ladders[0].Row = 87;
		ladders[0].Col = 20;
		ladders[0].length = 15;


		ladders[1].Row = 70;
		ladders[1].Col = 50;
		ladders[1].length = 20;

		int gun = Player.gun;

		coin coins[5];
		intializeCoin(board, coins[0], 49, 2);
		intializeCoin(board, coins[1], 69, 66);
		//Coin 2 row = 69, col = 66

		hearts heart[4];
		intializeHeart(board, heart[0], 69, 130);

		Elevator elevator[2];

		intializeElevator(board, elevator, 0, 69, 150, 69, 51, 150, 150, 0, 1); // Vertical  

		intializeElevator(board, elevator, 1, 95, 130, 95, 95, 130, 150, 1, 1); //horizonatal

		Enemy enemyKill[9];
		intializeEnemy(enemyKill, 0, 49, 12, 1, 11, 13, 100, 10); //Devil

		intializeEnemy(enemyKill, 1, 50, 30, 1, 10, 12, 250, 30); //Reaper

		intializeEnemy(enemyKill, 2, 97, 720, 1, 10, 12, 100, 15); //Blob

		intializeEnemy(enemyKill, 3, 50, 30, 1, 15, 10, 70, 15); //Skeleton

		intializeEnemy(enemyKill, 4, 10, 800, 1, 10, 12, 100, 15);// Bird

		intializeEnemy(enemyKill, 5, 50, 30, 1, 10, 12, 100, 20);//Alien

		intializeEnemy(enemyKill, 6, 50, 30, 1, 10, 12, 500, 30);//Boss

		intializeEnemy(enemyKill, 7, 50, 30, 1, 10, 12, 100, 20);//Devil boss minion

		intializeEnemy(enemyKill, 8, 50, 30, 1, 10, 12, 100, 20);//Alien boss minion

		intializeEnemy(enemyKill, 9, 50, 30, 1, 10, 12, 250, 30);//Reaper boss minion



		Enemy enemyUnKill[17];
		intializeEnemy(enemyUnKill, 0, 97, 200, 0, 10, 12, 250, 30);//Crystal 1
		intializeEnemy(enemyUnKill, 1, 97, 215, 0, 10, 12, 250, 30);//Crystal 2
		intializeEnemy(enemyUnKill, 2, 97, 230, 0, 10, 12, 250, 30);//Crystal 3
		intializeEnemy(enemyUnKill, 3, 97, 245, 0, 10, 12, 250, 30);//Crystal 4
		intializeEnemy(enemyUnKill, 4, 97, 260, 0, 10, 12, 250, 30);//Crystal 5

		intializeEnemy(enemyUnKill, 5, 75, 230, 0, 10, 12, 250, 30);//snail 1

		intializeEnemy(enemyUnKill, 6, 75, 230, 0, 10, 12, 250, 30); //Spike 1
		intializeEnemy(enemyUnKill, 7, 75, 230, 0, 10, 12, 250, 30); //Spike 2 
		intializeEnemy(enemyUnKill, 8, 75, 230, 0, 10, 12, 250, 30); //Spike 3
		intializeEnemy(enemyUnKill, 9, 75, 230, 0, 10, 12, 250, 30); //Spike 4
		intializeEnemy(enemyUnKill, 10, 75, 230, 0, 10, 12, 250, 30); //Spike 5
		intializeEnemy(enemyUnKill, 11, 75, 230, 0, 10, 12, 250, 30); //Spike 6 
		intializeEnemy(enemyUnKill, 12, 75, 230, 0, 10, 12, 250, 30); //Spike 7 
		intializeEnemy(enemyUnKill, 13, 75, 230, 0, 10, 12, 250, 30); //Spike 8
		intializeEnemy(enemyUnKill, 14, 75, 230, 0, 10, 12, 250, 30); //Spike 9

		intializeEnemy(enemyUnKill, 15, 75, 830, 0, 10, 12, 250, 30); //2nd place Spike 10
		intializeEnemy(enemyUnKill, 16, 75, 831, 0, 10, 12, 250, 30); //2nd place Spike 11




		int DFireBallR = -1, DFireBallC = -1, chance = -1, endR = -1, endC = -1; //intializeValues for devil shooting


		int animation = 0, frame = 1, ResetFrame = 0;
		scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
		clearMap(board, dispR, dispC);
		callObj(board, coins, enemyKill, heart , HiddenladderButtonClicked);

		callDynamicObj(board, elevator, posXLaz, posYLaz, direction, whatLaz, isShooting, enemyKill);
		//Devil's shooting mechanism
		SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
		controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);
		addBorders(board, dispR, dispC);
		drawPlayerRightFrame1(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, Player.gun);
		Clear_LoadMap(board, dispR, dispC);
		FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health , posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked);
		int isWon = 0;

		for (; !isWon;) {
			gun = Player.gun;
			checkCoinTouch(board, Player.Row, Player.Col, Player.maxWidth, Player.maxHeight, coins, Player.coins);
			checkHeartTouch(board, Player.Row, Player.Col, Player.maxWidth, Player.maxHeight, heart, Player.Health);
			FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked);
			ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
			clearMap(board, dispR, dispC);
			callObj(board, coins, enemyKill, heart, HiddenladderButtonClicked);
			callDynamicObj(board, elevator, posXLaz, posYLaz, direction, whatLaz, isShooting, enemyKill);
			//Devil's shooting mechanism
			SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
			controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);
			addBorders(board, dispR, dispC);
			if (animation == 0) {
				if (frame == 1) {
					drawPlayerRightFrame1(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
				}
				else if (frame == 2) {
					drawPlayerRightFrame2(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
				}
				else if (frame == 3) {
					drawPlayerRightFrame3(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
				}
				else if (frame == 4) {
					drawPlayerRightFrame4(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
				}
				else if (frame == 5) {
					drawPlayerRightFrame5(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
				}
			}
			else if (animation == 1) {
				if (frame == 1) {
					DrawPlayerLeftFrame1(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
				}
				else if (frame == 2) {
					DrawPlayerLeftFrame2(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
				}
				else if (frame == 3) {
					DrawPlayerLeftFrame3(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
				}
				else if (frame == 4) {
					DrawPlayerLeftFrame4(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
				}
				else if (frame == 5) {
					DrawPlayerLeftFrame5(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
				}
			}
			else if (animation == 2) {
				if (frame == 1) {
					climbFrame1(board, Player.Row, Player.Col);
				}
				else if (frame == 2) {
					climbFrame2(board, Player.Row, Player.Col);
				}
			}
			else if (animation == -1) {
				drawPlayerRightFrame1(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
			}
			else if (animation == -2) {
				DrawPlayerLeftFrame1(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
			}

			system("cls");
			dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, Player.gun);
			Clear_LoadMap(board, dispR, dispC);

			int isOnLadder = 0;
			int currentLadder = -1;
			if (_kbhit()) {

				char key = _getch();
				isOnLadder = 0;
				int canGoDown = 0;

				for (int i = 0; i < 4; i++) {
					if (Player.Col >= ladders[i].Col - 1 && Player.Col <= ladders[i].Col + 12) {
						if (Player.Row >= ladders[i].Row - ladders[i].length && Player.Row <= ladders[i].Row) {
							canGoDown = 1;
							currentLadder = i;
						}
						if (Player.Row >= ladders[i].Row - ladders[i].length + 1 && Player.Row <= ladders[i].Row) {
							isOnLadder = 1;
							currentLadder = i;
							break;
						}
					}
				}

				if ((key == 'a' || key == 'A') && isFalling == 0) {
					if (Player.Col >= 2) {
						if (isWalking == 2) {
							if (frame == 5) frame = 1;
							else frame++;
						}
						else {
							frame = 1;
						}
						moveLeft(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, lastCellCol, ladders, coins, Player.coins, heart, Player.Health);
						scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
						animation = 1;
						isWalking = 2;
						FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked);
					}
				}
				else if ((key == 'd' || key == 'D') && isFalling == 0) {
					if (Player.Col + Player.maxWidth < 999) {
						if (isWalking == 1) {
							if (frame == 5) frame = 1;
							else frame++;
						}
						else {
							frame = 1;
						}
						moveRight(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, lastCellCol, ladders, coins, Player.coins, heart, Player.Health);
						scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
						animation = 0;
						FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked);
						isWalking = 1;
					}
				}
				else if (key == 'w' || key == 'W' || key == ' ') {
					if (isOnLadder == 0) {
						if (isWalking == 0) {
							if (Player.Row - Player.maxHeight > 0) {
								jumpStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked);
								scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
								FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked);
								scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
							}
						}
						else if (isWalking == 1) {
							jumpRight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, isWalking, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked);
							scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
							FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked);
							scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
							isWalking = 0;
						}
						else if (isWalking == 2) {
							jumpLeft(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, isWalking, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked);
							scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
							FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked);
							scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
							isWalking = 0;
						}
					}
				}
				else if (key == 'r' || key == 'R') {



					if (Player.gun == 0) {

						if (Player.ammo[0] <= 5) {
							Player.ammo[0] += 2;
						}
						else {
							Player.ammo[0] = 7;
						}
					}

					else if (Player.gun == 1) {
						if (Player.ammo[1] <= 18) Player.ammo[1] += 6;
						else Player.ammo[1] = 24;
					}

					else {
						if (Player.ammo[2] <= 46) Player.ammo[2] += 10;
						else Player.ammo[2] = 56;
					}


				}
				else if (key == 'f' || key == 'F') {
					if (isShooting == 0 && Player.ammo[0] >= 1 && gun == 0) {

						if (animation == 0 || animation == -1)
						{
							isShooting = 1;
							shootLazer(Player.shootR, Player.shootC, posXLaz, posYLaz, 0);
							direction = 0;
							whatLaz = 0;
							Player.ammo[0]--;

						}
						else if (animation == 1 || animation == -2) {
							isShooting = 1;
							shootLazer(Player.shootR, Player.shootC, posXLaz, posYLaz, 1);
							whatLaz = 0;
							direction = 1;
							Player.ammo[0]--;

						}
					}


					else if (isShooting == 0 && Player.ammo[1] >= 1 && gun == 1) {
						//shootPistol();
					}
					else if (Player.ammo[2] >= 1 && gun == 2) {
						//ShootAssualt();
					}
				}
				else if (key == 'T' || key == 't') {
					if (Player.didGetRifle == 1) {
						if (Player.gun == 0 || Player.gun == 1) Player.gun++;
						else Player.gun = 0;
					}
					else {
						if (Player.gun == 0) Player.gun = 1;
						else Player.gun = 0;
					}
				}
				else if ((key == 'E' || key == 'e') && Player.Row <= btnrow + 1 && Player.Row >= btnmaxR - 1 && Player.Col <= btnmaxC + 1 && Player.Col >= btnCol - 5) {
					HiddenladderButtonClicked = 1;
				}
			
				if (isOnLadder == 1) {
					if ((key == 'w' || key == 'W' || key == ' ')) {
						if (Player.Row == ladders[currentLadder].Row - ladders[currentLadder].length + 1) {
							animation = 0;
						}
						else {
							if (isWalking == 3) {
								if (frame == 2) frame = 1;
								else frame++;
							}
							else {
								frame = 1;
							}


							animation = 2;
							isWalking = 3;
						}
						if (Player.Row - 1 > 1) {
							Player.Row--;
							scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
						}
						isClimbing = 1;
					}
					else {
						isClimbing = 0;
					}
				}
				if (canGoDown) {
					if (key == 's' || key == 'S') {
						if (isWalking == 3) {
							if (frame == 2) frame = 1;
							else frame++;
						}
						else {
							frame = 1;
						}
						if (Player.Row <= 97 && Player.Row <= ladders[currentLadder].Row - 1) {
							Player.Row++;
							scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
						}
						animation = 2;
						isClimbing = 1;
						isWalking = 3;
					}
					else {
						isClimbing = 0;
					}
				}

			}
			else {
				if (animation == 0) animation = -1;
				else if (animation == 1) animation = -2;
			}

			checkIsEnemyDead(enemyKill);
		}
	}
	else return 0;
}