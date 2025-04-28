#include <iostream>
#include <conio.h>
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
	int isKillable; // 1 for killable , 0 for not killable
	int maxHeight = 1, maxWidth = 1; //Max height and width
	int Health = 100;
	int attackPower = 10;

};

struct ladder {
	int Row = NULL, Col = NULL; //Position
	int length = NULL;
};

struct coin {
	int Row = NULL, Col = NULL; //Position
	int isCollected = 0; // 1 for collected , 0 for not collected
	int maxHeight = 4, maxWidth = 8; //Max height and width
};

struct elevator {
	int Row, Col; //Position
	int length = 11;
	int whichD = 1; // 1 Vertical , 0 for horizonatal
	int max , min;
};

void intializeCoin(char board[100][1000], coin& e, int row, int col) {
	e.Row = row;
	e.Col = col;
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
	Row = 95;
	Col = 40;
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
	cout << blue << char(186) << reset << "          HEALTH " << red << bold << char(177) << char(177) << char(177) << char(177) << char(177) << char(177) << char(177) << char(177) << char(177) << char(177) << reset << "  |  COINS " << yellow << bold << coins << reset << "  |  " << yellow << bold << gun << reset << "  |  AMMO " << yellow << bold << ammo << " / " << maxAmmo << reset << blue << "           " << char(186) << reset << endl;
}

void dispBoard(char board[100][1000]) {


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




void drawPlayerRightFrame1(char board[100][1000], int row, int col, int& shootR, int shootC, int LC[9]) {
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



void drawPlayerRightFrame2(char board[100][1000], int row, int col, int& shootR, int shootC, int LC[9]) {
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
void drawPlayerRightFrame3(char board[100][1000], int row, int col, int& shootR, int shootC, int LC[9]) {
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


void drawPlayerRightFrame4(char board[100][1000], int row, int col, int& shootR, int shootC, int LC[9]) {
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


void drawPlayerRightFrame5(char board[100][1000], int row, int col, int& shootR, int shootC, int LC[9]) {
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
	shootingR = R - 4;
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
	shootingR = R - 4;
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
	shootingR = R - 4;
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
	shootingR = R - 4;
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

void intializeEnemy(Enemy& e, int row, int col, int  iskillable, int maxH, int maxW, int health, int power) {
	e.Row = row;
	e.Col = col;
	e.maxHeight = maxH;
	e.maxWidth = maxW;
	e.isKillable = iskillable;
	e.attackPower = power;
	e.Health = health;
}


void drawSpike(char board[100][1000], int R, int C) {
	board[R][C] = '/';
	board[R - 1][C + 1] = '/';
	board[R][C + 3] = '\\';
	board[R - 1][C + 2] = '\\';
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



void drawEnemyBirdLeft(char board[100][1000], int row, int col) {
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

void drawEnemyBirdRight(char board[100][1000], int row, int col) {
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



/////////////// CALL OBJECTS ////////////////

void moveElevatorVertically(int& row, int startRow, int endRow, int& direction) {
	if (row == endRow) direction = 2;
	else if (row == startRow) direction = 1;

	if (direction == 1) row--;
	else row++;
}

void moveElevatorHorizontally(int& col, int startCol, int endCol, int& direction) {
	if (col == endCol) direction = 2;
	else if (col == startCol) direction = 1;

	if (direction == 1) col++;
	else col--;
}
void drawElevator(char board[100][1000], int row, int col) {
	board[row][col] = '_';
	board[row][col + 1] = '_';
	board[row][col + 2] = '_';
	board[row][col + 4] = '_';
	board[row][col + 5] = '_';
	board[row][col + 6] = '_';
	board[row][col + 7] = '_';
	board[row][col + 8] = '_';
	board[row][col + 9] = '_';
	board[row][col + 10] = '_';
}

void drawAndMoveElevatorV(char board[100][1000], int& row , int col, int startRow, int endRow , int& direction) {
	
	drawElevator(board, row, col);
	moveElevatorVertically(row, startRow, endRow, direction);
}

void drawAndMoveElevatorH(char board[100][1000], int row, int &col, int startCol, int endCol, int& direction) {

	drawElevator(board, row, col);
	moveElevatorVertically(row, startCol, endCol, direction);
}

void callObj(char board[100][1000], coin coins[5]) {
	drawTerrain(board, 95, 30, 1, 10);
	drawTerrain(board, 91, 15, 1, 10);
	drawTerrain(board, 87, 5, 1, 10);
	drawLadder(board, 98, 50, 25);
	drawCoin(board, coins[0].Row, coins[0].Col, coins[0].isCollected);
	
}

void callDynamicObj(char board[100][1000], Enemy bird, Enemy devil, Enemy spike , elevator elevators[2]) {
	drawEnemyBirdLeft(board, 82, 60); // Draw the enemy bird
	drawEnemyBirdRight(board, 84, 10); // Draw the enemy bird
	drawAndMoveElevatorV(board , elevators[0].Row , elevators[0].Col , elevators[0].min , elevators[0].max , elevators[0].whichD );
}

///////////////////////////////

void scroll(char board[100][1000], int& posJHero, int& posIHero, int widthHero, int heightHero, int& dispR, int& dispC) {
	dispC = posJHero - 30;
	if (dispC < 0) dispC = 0;
	if (dispC > 1000 - 80) dispC = 1000 - 80;

	dispR = posIHero + 2;
	if (dispR < 24) dispR = 23;
	if (dispR > 86) dispR = 98;

}

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
		if (coins[a].isCollected) continue; // Skip if already collected

		int coinTop = coins[a].Row - coins[a].maxHeight + 1;
		int coinBottom = coins[a].Row;
		int coinLeft = coins[a].Col;
		int coinRight = coins[a].Col + coins[a].maxWidth - 1;

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









///////////////////////////////////////
//Player Movement Functions

void moveRight(char board[100][1000], int& posJHero, int& posIHero, int widthHero, int heightHero, int LC[9], ladder ladders[4], coin coins[5], int& numCoinsP) {
	int check = 1;
	// Check every cell in the column to the right of the player
	for (int i = posIHero; i >= posIHero - heightHero + 1; i--) {
		int lc_index = posIHero - i;  // Convert to LC index (0=bottom)
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


}

void moveLeft(char board[100][1000], int& posJHero, int& posIHero, int widthHero, int heightHero, int LC[9], ladder ladders[4], coin coins[5], int& numCoinsP) {
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


}

void jumpStraight(char board[100][1000], int& pX, int& pY, int pHeight, int pWidth, int& isJumping, player Player, char gun[], int animation, int dispR, int dispC, int LC[9], int LR[15], coin coins[5], int& numCoinsP) {


	scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
	clearMap(board, dispR, dispC);
	callObj(board, coins); // Call the function to draw the objects
	addBorders(board, dispR, dispC);
	if (animation == 0) {
		jumprightframe(board, pX, pY, LC, LR); // Draw the player jumping up
	}
	else if (animation == 1) {
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

			checkCoinTouch(board, pX, pX, pWidth, pHeight, coins, numCoinsP);
			scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
			clearMap(board, dispR, dispC);
			callObj(board, coins); // Call the function to draw the objects
			addBorders(board, dispR, dispC);
			if (animation == 0) {
				jumprightframe(board, pX, pY, LC, LR); // Draw the player jumping up
			}
			else if (animation == 1) {
				jumpleftframe(board, pX, pY, LC, LR); // Draw the player jumping up
			}
			system("cls");
			dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun); // Display the bar first
			Clear_LoadMap(board, dispR, dispC); // Clear the screen and load the map

			isJumping = 1;
		}
		else break;

	}
	isJumping = 0;
}


void FallStraight(char board[100][1000], int& pX, int& pY, int pHeight, int pWidth, int& isJumping, player Player, char gun[], int& isFalling, int animation, int dispR, int dispC, int LC[9], int LR[15], coin coins[5], int& numCoinsP) {
	for (; pX + 1 < 99; ) {
		if (pX - pHeight < 0) break;

		int check = 1; // Reset every fall attempt

		for (int j = pY + 3; j <= pY + 9; j++) {
			if (board[pX + 1][j] != ' ' && board[pX + 1][j] != char(186)) {
				check = 0;
				break;
			}
		}

		if (check == 0) {
			break; // Landed on something, stop falling
		}

		pX++;
		checkCoinTouch(board, pX, pX, pWidth, pHeight, coins, numCoinsP);
		scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
		clearMap(board, dispR, dispC);
		callObj(board, coins);
		addBorders(board, dispR, dispC);

		if (animation == 0) {
			jumprightframe(board, pX, pY, LC, LR);
		}
		else if (animation == 1) {
			jumpleftframe(board, pX, pY, LC, LR);
		}

		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun);
		Clear_LoadMap(board, dispR, dispC);

		isFalling = 1;
	}

	isJumping = 0;
	isFalling = 0;
}


void jumpRight(char board[100][1000], int& pX, int& pY, int pHeight, int pWidth,
	int& isJumping, player Player, char gun[], int& isFalling,
	int& isWalking, int dispR, int dispC, int LC[9], int LR[15], coin coins[5], int& numCoinsP) {
	// Initial setup
	scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
	clearMap(board, dispR, dispC);
	callObj(board, coins);
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

		checkCoinTouch(board, pX, pX, pWidth, pHeight, coins, numCoinsP);
		// Redraw everything
		scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
		clearMap(board, dispR, dispC);
		callObj(board, coins);
		addBorders(board, dispR, dispC);
		jumprightframe(board, pX, pY, LC, LR);

		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun);
		Clear_LoadMap(board, dispR, dispC);
		isJumping = 1;
	}

	// Falling logic
	for (;;) {
		int canFall = 0;

		// Check if we can fall straight down
		for (int col = pY + 3; col <= pY + 9; col++) {
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

		checkCoinTouch(board, pX, pX, pWidth, pHeight, coins, numCoinsP);
		// Redraw everything
		scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
		clearMap(board, dispR, dispC);
		callObj(board, coins);
		addBorders(board, dispR, dispC);
		jumprightframe(board, pX, pY, LC, LR);

		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun);
		Clear_LoadMap(board, dispR, dispC);
		isFalling = 1;
	}

	isJumping = 0;
	isFalling = 0;
	isWalking = 0;
}
void jumpLeft(char board[100][1000], int& pX, int& pY, int pHeight, int pWidth, int& isJumping, player Player, char gun[], int& isFalling, int& isWalking, int dispR, int dispC, int LC[9], int LR[15], coin coins[5], int& numCoinsP) {

	scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
	clearMap(board, dispR, dispC);
	callObj(board, coins);
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

		checkCoinTouch(board, pX, pX, pWidth, pHeight, coins, numCoinsP);
		scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
		clearMap(board, dispR, dispC);
		callObj(board, coins);
		addBorders(board, dispR, dispC);
		jumpleftframe(board, pX, pY, LC, LR);

		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun);
		Clear_LoadMap(board, dispR, dispC);
		isJumping = 1;

	}

	int check = 1;
	for (int j = pY + 3; j <= pY + 9; j++) {
		if (board[pX + 1][j] != ' ') {
			check = 0;
			break;
		}
	}

	for (; pX + 1 < 23 && board[pX + 1][pY] == ' ' && pY > 1;) {
		int checkDiagonal = 1;
		for (int j = pY + 3; j <= pY + 9; j++) {
			if (board[pX + 1][j] != ' ') {
				checkDiagonal = 0;
				break;
			}
		}


		if (checkDiagonal && check) {
			pX++;
			pY--;


			checkCoinTouch(board, pX, pX, pWidth, pHeight, coins, numCoinsP);
			scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
			clearMap(board, dispR, dispC);
			callObj(board, coins);
			addBorders(board, dispR, dispC);
			jumpleftframe(board, pX, pY, LC, LR);

			system("cls");
			dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun);
			Clear_LoadMap(board, dispR, dispC);
			isFalling = 1;
		}
	}
	isWalking = 0;
	isJumping = 0, isFalling = 0; // Reset jumping and falling states after landing

}
/*
NEXT STEPS:
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

		int lastCellCol[9], lastCellRow[15];
		char gun[] = "Pistol";

		int isWalking = 0, isJumping = 0, isFalling = 0, isShooting = 0, isReloading = 0;

		Enemy devil;
		intializeEnemy(devil, 97, 50, 1, 11, 13, 100, 12);

		ladder ladders[4];
		ladders[0].Row = 98;
		ladders[0].Col = 50;
		ladders[0].length = 25;

		coin coins[5];
		intializeCoin(board, coins[0], 97, 70);


		elevator elevators[2];
		
		elevators[0].Row = 97, elevators[0].Col = 90 , elevators[0].min = 97 , elevators[0].max = 85, elevators[0].whichD = 1;


		int animation = 0, frame = 1, ResetFrame = 0;
		scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
		clearMap(board, dispR, dispC);
		callObj(board, coins);
		addBorders(board, dispR, dispC);
		drawPlayerRightFrame1(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun);
		Clear_LoadMap(board, dispR, dispC);
		FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins);
		int isWon = 0;

		for (; !isWon;) {
			clearMap(board, dispR, dispC);
			callObj(board, coins);
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

			system("cls");
			dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun);
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
						moveLeft(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, lastCellCol, ladders, coins, Player.coins);
						scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
						animation = 1;
						isWalking = 2;
						FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins);
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
						moveRight(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, lastCellCol, ladders, coins, Player.coins);
						scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
						animation = 0;
						FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins);
						isWalking = 1;
					}
				}
				else if (key == 'w' || key == 'W') {
					if (isOnLadder == 0) {
						if (isWalking == 0) {
							if (Player.Row - Player.maxHeight > 0) {
								jumpStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins);
								scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
								FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins);
								scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
							}
						}
						else if (isWalking == 1) {
							jumpRight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, isWalking, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins);
							scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
							FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins);
							scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
							isWalking = 0;
						}
						else if (isWalking == 2) {
							jumpLeft(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, isWalking, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins);
							scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
							FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins);
							scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
							isWalking = 0;
						}
					}
				}

				if (isOnLadder == 1) {
					if ((key == 'w' || key == 'W')) {
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
						if (Player.Row <= 97) {
							Player.Row++;
							scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
						}
						animation = 2;
						isWalking = 3;
					}
				}
			}
		}
	}
	else return 0;
}