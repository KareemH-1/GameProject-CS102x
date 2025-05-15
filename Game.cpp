//NEXT STEPS::

/*
ADD ASSUALT RIFLE

ADD TELEPORTER
ADD ENEMIES AND THIER LOGIC

BUILD MAP
ADD BOSS FIGHT
ADD THE ASSUALT RIFLE COLLECTABLE
END SCREEN
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
	int assaultRow = 49;
	int assaultCol = 120;

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
	int hitRow = -1, hitCol = -1, frame = 0;
	int direction = 0;
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


void FallingCrystal(char board[100][1000], Enemy& crystal) {
	int frame = crystal.frame;
	int row = crystal.Row;
	int col = crystal.Col;

	if (frame == 0) {
		// Ceiling with spikes
		crystal.hitRow = -10;
		crystal.hitCol = -10;
	}
	else if (frame == 1) {
		board[row][col - 9] = '^'; board[row][col - 8] = '^'; board[row][col - 7] = '^';
		board[row][col - 6] = '\'';
		board[row][col - 5] = '-';
		board[row][col - 4] = '-';
		board[row][col - 3] = '\'';
		board[row][col - 2] = '^'; board[row][col - 1] = '^'; board[row][col] = '^';
		crystal.hitRow = -10;
		crystal.hitCol = -10;
	}
	else if (frame == 2) {
		board[row][col - 9] = '^'; board[row][col - 8] = '^';
		board[row][col - 7] = '\'';
		board[row][col - 6] = '-';
		board[row][col - 5] = '_';
		board[row][col - 4] = '_';
		board[row][col - 3] = '-';
		board[row][col - 2] = '\'';
		board[row][col - 1] = '^'; board[row][col] = '^';
		crystal.hitRow = -10;
		crystal.hitCol = -10;
	}
	else if (frame == 3) {
		board[row][col - 9] = '^';
		board[row][col - 8] = '_';
		board[row + 1][col - 7] = ' ';
		board[row + 1][col - 6] = '-';
		board[row + 1][col - 5] = '\\';
		board[row + 1][col - 4] = '/';
		board[row + 1][col - 3] = '-';
		board[row + 1][col - 2] = ' ';
		board[row][col - 1] = '_';
		board[row][col] = '^';
		crystal.hitRow = -10;
		crystal.hitCol = -10;
	}

	/////
	else if (frame == 4) {
		board[row + 3][col - 5] = '/';
		board[row + 3][col - 4] = '\\';
		board[row + 4][col - 6] = '(';
		board[row + 4][col - 3] = ')';
		board[row + 5][col - 5] = '\\';
		board[row + 5][col - 4] = '/';
		crystal.hitRow = row + 5;
		crystal.hitCol = col - 3;
	}
	else if (frame == 5) {
		board[row + 7][col - 5] = '/';
		board[row + 7][col - 4] = '\\';
		board[row + 8][col - 6] = '(';
		board[row + 8][col - 3] = ')';
		board[row + 9][col - 5] = '\\';
		board[row + 9][col - 4] = '/';
		crystal.hitRow = row + 9;
		crystal.hitCol = col - 3;
	}
	else if (frame == 6) {
		board[row + 11][col - 5] = '/';
		board[row + 11][col - 4] = '\\';
		board[row + 12][col - 6] = '(';
		board[row + 12][col - 3] = ')';
		board[row + 13][col - 5] = '\\';
		board[row + 13][col - 4] = '/';
		crystal.hitRow = row + 13;
		crystal.hitCol = col - 3;
	}
	else if (frame == 7) {
		board[row + 15][col - 5] = '/';
		board[row + 15][col - 4] = '\\';
		board[row + 16][col - 6] = '(';
		board[row + 16][col - 3] = ')';
		board[row + 17][col - 5] = '\\';
		board[row + 17][col - 4] = '/';
		crystal.hitRow = row + 17;
		crystal.hitCol = col - 3;
	}
	else if (frame == 8) {
		board[row + 18][col - 5] = '/';
		board[row + 18][col - 4] = '\\';
		board[row + 19][col - 6] = '(';
		board[row + 19][col - 3] = ')';
		board[row + 20][col - 5] = '\\';
		board[row + 20][col - 4] = '/';
		crystal.hitRow = row + 20;
		crystal.hitCol = col - 3;
	}
	else if (frame == 9) {
		board[row + 20][col - 5] = '/';
		board[row + 20][col - 4] = '\\';
		board[row + 21][col - 6] = '(';
		board[row + 21][col - 3] = ')';
		crystal.hitRow = row + 21;
		crystal.hitCol = col - 3;
	}
	else if (frame == 10) {
		//need to adjust the position of the crystal
		board[row + 22][col - 7] = '>';
		board[row + 22][col - 6] = '\'';
		board[row + 22][col - 5] = '#';
		board[row + 22][col - 4] = '&';
		board[row + 22][col - 3] = '&';
		board[row + 22][col - 2] = '<';
		board[row + 21][col - 1] = ';';
		board[row + 21][col] = ':';
		board[row + 21][col + 1] = ';';
		board[row + 20][col + 2] = '^';
		board[row + 20][col + 3] = '^';
	}
	else if (frame == 11) {
		//need to adjust the position of the crystal
		board[row + 22][col - 7] = '_';
		board[row + 22][col - 6] = '_';
		board[row + 22][col - 5] = '_';
		board[row + 22][col - 4] = '_';
		board[row + 20][col - 3] = ';';
		board[row + 20][col - 2] = '\'';
		board[row + 20][col - 1] = '.';
		board[row + 19][col] = '^';
		board[row + 19][col + 1] = '^';
	}

	crystal.frame++;
	if (crystal.frame >= 11) {
		crystal.frame = 0;
	}
}

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
	cout << "||                                              ||" << endl;
	cout << "||                                              ||" << endl;
	cout << "||  Game Rules:                                 ||" << endl;
	cout << "||                                              ||" << endl;
	cout << "||  1. Collect 10 coins scattered across the    ||" << endl;
	cout << "||     map to unlock the teleporter to the boss.||" << endl;
	cout << "||                                              ||" << endl;
	cout << "||  2. Once the teleporter is unlocked, reach   ||" << endl;
	cout << "||     it to face the boss.                     ||" << endl;
	cout << "||                                              ||" << endl;
	cout << "||  3. Defeat the boss to win the game.         ||" << endl;
	cout << "||                                              ||" << endl;
	cout << "||  4. If your health reaches zero, you lose.   ||" << endl;
	cout << "||                                              ||" << endl;
	cout << "||  5. Enemies and traps will decrease your     ||" << endl;
	cout << "||     health, so stay alert.                   ||" << endl;
	cout << "||                                              ||" << endl;
	cout << "||  6. Collect hearts to regain health.         ||" << endl;
	cout << "||                                              ||" << endl;
	cout << "||  7. A powerful weapon is hidden on the map.  ||" << endl;
	cout << "||     Find it to increase your attack power.   ||" << endl;
	cout << "||                                              ||" << endl;
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

void gameOverScreen() {
	cout << "========================================================================================================" << endl;
	cout << "||                                                                                                    ||" << endl;
	cout << "||     ▄████     ▄▄▄          ███▄ ▄███▓   ▓█████        ▒█████      ██▒   █▓   ▓█████     ██▀███     ||" << endl;
	cout << "||    ██▒ ▀█▒   ▒████▄       ▓██▒▀█▀ ██▒   ▓█   ▀       ▒██▒  ██▒   ▓██░   █▒   ▓█   ▀    ▓██ ▒ ██▒   ||" << endl;
	cout << "||   ▒██░▄▄▄░   ▒██  ▀█▄     ▓██    ▓██░   ▒███         ▒██░  ██▒    ▓██  █▒░   ▒███      ▓██ ░▄█ ▒   ||" << endl;
	cout << "||   ░▓█  ██▓   ░██▄▄▄▄██    ▒██    ▒██    ▒▓█  ▄       ▒██   ██░     ▒██ █░░   ▒▓█  ▄    ▒██▀▀█▄     ||" << endl;
	cout << "||   ░▒▓███▀▒    ▓█   ▓██▒   ▒██▒   ░██▒   ░▒████▒      ░ ████▓▒░      ▒▀█░     ░▒████▒   ░██▓ ▒██▒   ||" << endl;
	cout << "||    ░▒   ▒     ▒▒   ▓▒█░   ░ ▒░   ░  ░   ░░ ▒░ ░      ░ ▒░▒░▒░       ░ ▐░     ░░ ▒░ ░   ░ ▒▓ ░▒▓░   ||" << endl;
	cout << "||     ░   ░      ▒   ▒▒ ░   ░  ░      ░    ░ ░  ░        ░ ▒ ▒░       ░ ░░      ░ ░  ░     ░▒ ░ ▒░   ||" << endl;
	cout << "||   ░ ░   ░      ░   ▒      ░      ░         ░         ░ ░ ░ ▒          ░░        ░        ░░   ░    ||" << endl;
	cout << "||         ░          ░  ░          ░         ░  ░          ░ ░           ░        ░  ░      ░        ||" << endl;
	cout << "||                                                                                                    ||" << endl;
	cout << "||                                             G A M E  O V E R                                       ||" << endl;
	cout << "||                                                                                                    ||" << endl;
	cout << "||                                                 YOU LOST!                                          ||" << endl;
	cout << "||                                                                                                    ||" << endl;
	cout << "========================================================================================================" << endl;
}

void winScreen() {
	cout << "======================================================================================================" << endl;
	cout << "||                                                                                                  ||" << endl;
	cout << "||  ▄████████  ▄██████▄  ███▄▄▄▄      ▄██████▄     ▄████████    ▄████████     ███        ▄████████  ||" << endl;
	cout << "|| ███    ███ ███    ███ ███▀▀▀██▄   ███    ███   ███    ███   ███    ███ ▀█████████▄   ███    ███  ||" << endl;
	cout << "|| ███    █▀  ███    ███ ███   ███   ███    █▀    ███    ███   ███    ███    ▀███▀▀██   ███    █▀   ||" << endl;
	cout << "|| ███        ███    ███ ███   ███  ▄███         ▄███▄▄▄▄██▀   ███    ███     ███   ▀   ███         ||" << endl;
	cout << "|| ███        ███    ███ ███   ███ ▀▀███ ████▄  ▀▀███▀▀▀▀▀   ▀███████████     ███     ▀███████████  ||" << endl;
	cout << "|| ███    █▄  ███    ███ ███   ███   ███    ███ ▀███████████   ███    ███     ███              ███  ||" << endl;
	cout << "|| ███    ███ ███    ███ ███   ███   ███    ███   ███    ███   ███    ███     ███        ▄█    ███  ||" << endl;
	cout << "|| ████████▀   ▀██████▀   ▀█   █▀    ████████▀    ███    ███   ███    █▀     ▄████▀    ▄████████▀   ||" << endl;
	cout << "||                                             ███    ███                                           ||" << endl;
	cout << "||                                                                                                  ||" << endl;
	cout << "||                                  C O N G R A T U L A T I O N S                                   ||" << endl;
	cout << "||                                                                                                  ||" << endl;
	cout << "||                                   YOU HAVE FINISHED THE GAME!                                    ||" << endl;
	cout << "||                                                                                                  ||" << endl;
	cout << "======================================================================================================" << endl;
}


void initializePlayerValues(int& Row, int& Col, int& maxHeight, int& maxWidth, int& Health, int& coins, int& gun, int ammo[], int& maxAmmo, int& shootC, int& shootR) {
	Row = 98;
	Col = 640;
	maxHeight = 9;
	maxWidth = 15;
	Health = 500;
	coins = 250;
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


	cout << char(201);
	for (int i = 1; i < 79; i++) {
		cout << char(205);
	}
	cout << char(187) << endl;

	cout << char(186);

	cout << "  HEALTH " << health;

	int h = health;
	int h_digits = 1;
	if (h >= 100) h_digits = 3;
	else if (h >= 10) h_digits = 2;

	cout << "  " << "|" << "  COINS " << coins;

	int c = coins;
	int c_digits = 1;
	if (c >= 100) c_digits = 3;
	else if (c >= 10) c_digits = 2;

	cout << "  " << "|" << "  ";

	if (gun == 0) cout << "Lazer ";
	else if (gun == 1) cout << "Pistol";
	else if (gun == 2) cout << "Rifle ";


	cout << "  " << "|" << "  AMMO ";

	int bullet = 0;
	int max_bullet = 0;
	if (gun == 0) {
		bullet = ammo[0];
		max_bullet = 7;
	}
	else if (gun == 1) {
		bullet = ammo[1];
		max_bullet = 24;
	}
	else if (gun == 2) {
		bullet = ammo[2];
		max_bullet = 56;
	}

	int b_digits = 1;
	if (bullet >= 10) b_digits = 2;

	int max_digits = 1;
	if (max_bullet >= 10) max_digits = 2;

	int usedChars = 0;


	usedChars += 2;
	usedChars += 7;
	usedChars += h_digits;
	usedChars += 5;
	usedChars += 6;
	usedChars += c_digits;
	usedChars += 5;
	usedChars += 6;
	usedChars += 9;

	if (bullet > 0) {
		usedChars += b_digits + 3 + max_digits;
		cout << bullet << " / " << max_bullet;
	}
	else {
		usedChars += 7; // length of "NO AMMO"
		cout << "NO AMMO";
	}


	for (int i = usedChars; i < 77; i++) {
		cout << " ";
	}

	cout << char(186) << endl;
}


void dispBoard(char board[100][1000]) {


	for (int i = 0; i < 80; i++) {
		cout << board[0][i];
	}
	cout << endl;
	//i =1 to ignore first border and i<23 to ignore last border
	for (int i = 1; i < 23; i++) {
		cout << board[i][0]; //Left border
		for (int j = 1; j < 79; j++) {
			cout << board[i][j];
		}
		cout << board[i][79]; //Right border
		cout << endl;
	}
	for (int i = 0; i < 80; i++) {
		cout << board[23][i];
	}
	cout << endl;

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


void controlBird(char board[100][1000], Enemy& bird, int startC, int endC, int rEggs[], int cEggs[], int& count, player& Player) {

	if (bird.Col == startC) {
		bird.direction = 0;
	}

	else if (bird.Col == endC) {
		bird.direction = 1;
	}

	if (bird.direction == 0) {
		drawEnemyBirdRight(board, bird);
		bird.Col++;
	}
	else if (bird.direction == 1) {
		drawEnemyBirdLeft(board, bird);
		bird.Col--;
	}
	count++;
	if (count % 4 == 0) {
		for (int i = 0; i < 5; i++) {
			if (rEggs[i] == -1 && cEggs[i] == -1) {
				rEggs[i] = bird.Row;
				cEggs[i] = bird.Col;
				break;
			}
		}

		for (int i = 0; i < 5; i++) {
			if (rEggs[i] != -1 && cEggs[i] != -1) {
				int check = 1;

				if (board[rEggs[i] + 1][cEggs[i]] != ' ') {
					check = 0;
				}

				if (Player.Row - Player.maxHeight < rEggs[i] && rEggs[i] < Player.Row && Player.Col + Player.maxWidth >= cEggs[i] && Player.Col <= cEggs[i]) {
					check = 2;
				}



				if (check == 1) {
					rEggs[i]++;
				}
				else if (check == 0) {
					rEggs[i] = -1;
					cEggs[i] = -1;
				}
				else {
					Player.Health -= bird.attackPower;
					rEggs[i] = -1;
					cEggs[i] = -1;
				}

				board[rEggs[i]][cEggs[i]] = 'o';
			}
		}


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
	int playerRight = Player.Col + 15 - 1;
	int playerTop = Player.Row - 9 + 1;
	int playerLeft = Player.Col;

	if (ballR >= playerTop && ballR <= playerBottom && ballC >= playerLeft && ballC <= playerRight) return 1;
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
///////////
void drawAndMoveBlob(char board[100][1000], Enemy& blob, int& row, int& col, int startCol, int endCol, int& direction, int& isJumping) {


	if (direction == 1) {
		if (!isJumping) {
			row--;
			col++;
			isJumping = 1;
		}
		else {
			row++;
			col++;
			isJumping = 0;
		}
	}
	else if (direction == 2) {
		if (!isJumping) {
			row--;
			col--;
			isJumping = 1;
		}
		else {
			row++;
			col--;
			isJumping = 0;
		}
	}
	if (col >= endCol) direction = 2;
	else if (col <= startCol) direction = 1;

	if (blob.isKillable != -1) {
		if (direction == 1) {
			board[row][col + 3] = '|';
			board[row][col + 4] = '_';
			board[row][col + 5] = '|';

			board[row][col + 8] = '|';
			board[row][col + 9] = '_';
			board[row][col + 10] = '|';

			board[row - 1][col] = '`';
			board[row - 1][col + 2] = '\\';
			board[row - 1][col + 3] = '_';
			board[row - 1][col + 4] = '_';
			board[row - 1][col + 5] = '_';
			board[row - 1][col + 6] = '_';
			board[row - 1][col + 7] = '_';
			board[row - 1][col + 8] = '_';
			board[row - 1][col + 9] = '_';
			board[row - 1][col + 10] = '_';
			board[row - 1][col + 11] = '/';


			board[row - 2][col + 1] = '/';
			board[row - 2][col + 2] = '|';
			board[row - 2][col + 3] = ' ';
			board[row - 2][col + 4] = ' ';
			board[row - 2][col + 5] = ' ';
			board[row - 2][col + 6] = ' ';
			board[row - 2][col + 7] = '_';
			board[row - 2][col + 8] = '_';
			board[row - 2][col + 9] = '_';
			board[row - 2][col + 10] = ' ';
			board[row - 2][col + 11] = '|';


			board[row - 3][col + 2] = '|';
			board[row - 3][col + 3] = ' ';
			board[row - 3][col + 4] = ' ';
			board[row - 3][col + 5] = ' ';
			board[row - 3][col + 6] = ' ';
			board[row - 3][col + 7] = 'O';
			board[row - 3][col + 8] = ' ';
			board[row - 3][col + 9] = 'O';
			board[row - 3][col + 10] = ' ';
			board[row - 3][col + 11] = '|';
			board[row - 3][col + 12] = '/';

			board[row - 4][col + 3] = '/';
			board[row - 4][col + 4] = ' ';
			board[row - 4][col + 5] = ' ';
			board[row - 4][col + 6] = ' ';
			board[row - 4][col + 7] = ' ';
			board[row - 4][col + 8] = ' ';
			board[row - 4][col + 9] = ' ';
			board[row - 4][col + 10] = '\\';
			board[row - 4][col + 13] = '|';

			board[row - 5][col + 4] = '_';
			board[row - 5][col + 5] = '_';
			board[row - 5][col + 6] = '_';
			board[row - 5][col + 7] = '_';
			board[row - 5][col + 8] = '_';
			board[row - 5][col + 9] = '_';


		}


		else if (direction == 2) {


			board[row][col + 3] = '|';
			board[row][col + 4] = '_';
			board[row][col + 5] = '|';

			board[row][col + 8] = '|';
			board[row][col + 9] = '_';
			board[row][col + 10] = '|';

			board[row - 1][col + 2] = '\\';
			board[row - 1][col + 3] = '_';
			board[row - 1][col + 4] = '_';
			board[row - 1][col + 5] = '_';
			board[row - 1][col + 6] = '_';
			board[row - 1][col + 7] = '_';
			board[row - 1][col + 8] = '_';
			board[row - 1][col + 9] = '_';
			board[row - 1][col + 10] = '_';
			board[row - 1][col + 11] = '/';

			board[row - 1][col + 13] = '`';


			board[row - 2][col + 2] = '|';
			board[row - 2][col + 3] = ' ';
			board[row - 2][col + 4] = '_';
			board[row - 2][col + 5] = '_';
			board[row - 2][col + 6] = '_';
			board[row - 2][col + 7] = ' ';
			board[row - 2][col + 8] = ' ';
			board[row - 2][col + 9] = ' ';
			board[row - 2][col + 10] = ' ';
			board[row - 2][col + 11] = '|';
			board[row - 2][col + 12] = '\\';


			board[row - 3][col + 1] = '\\';
			board[row - 3][col + 2] = '|';
			board[row - 3][col + 3] = ' ';
			board[row - 3][col + 4] = 'O';
			board[row - 3][col + 5] = ' ';
			board[row - 3][col + 6] = 'O';
			board[row - 3][col + 7] = ' ';
			board[row - 3][col + 8] = ' ';
			board[row - 3][col + 9] = ' ';
			board[row - 3][col + 10] = ' ';
			board[row - 3][col + 11] = '|';

			board[row - 4][col] = '|';
			board[row - 4][col + 3] = '/';
			board[row - 4][col + 4] = ' ';
			board[row - 4][col + 5] = ' ';
			board[row - 4][col + 6] = ' ';
			board[row - 4][col + 7] = ' ';
			board[row - 4][col + 8] = ' ';
			board[row - 4][col + 9] = ' ';
			board[row - 4][col + 10] = '\\';

			board[row - 5][col + 4] = '_';
			board[row - 5][col + 5] = '_';
			board[row - 5][col + 6] = '_';
			board[row - 5][col + 7] = '_';
			board[row - 5][col + 8] = '_';
			board[row - 5][col + 9] = '_';



		}


		int hp = blob.Health;
		board[row - 16][col + 3] = 'H';
		board[row - 16][col + 4] = 'P';
		board[row - 16][col + 5] = ':';

		if (hp > 9 && hp < 100) {
			int fDig = hp / 10, sDig = hp % 10;

			board[row - 16][col + 6] = fDig + '0';
			board[row - 16][col + 7] = sDig + '0';
		}
		else if (hp >= 100) {
			int fDig = hp / 100, sDig = (hp / 10) % 10, tDig = hp % 10;

			board[row - 16][col + 6] = fDig + '0';
			board[row - 16][col + 7] = sDig + '0';
			board[row - 16][col + 8] = tDig + '0';
		}
		else if (hp >= 0 && hp <= 9) {
			board[row - 16][col + 6] = hp + '0';
		}
	}

}
//////////// MAP /////////////

void drawTerrain(char board[100][1000], int r, int c, int NumR, int NumC) {
	int tempCol;
	if (NumR == 1) {
		tempCol = c;
		for (int j = 0; j < NumC; j++) {
			board[r][tempCol] = char(205);
			tempCol++;
		}
	}
	else if (NumR == 2) {
		board[r][c] = char(201);
		tempCol = c + 1;
		for (int j = 0; j < NumC - 1; j++) {
			board[r][tempCol] = char(205);
			tempCol++;
		}
		board[r][tempCol] = char(187);
		tempCol = c;
		board[r + 1][tempCol] = char(200);
		tempCol++;
		for (int j = 0; j < NumC - 1; j++) {
			board[r + 1][tempCol] = char(205);
			tempCol++;

		}
		board[r + 1][tempCol] = char(188);
	}



}

void drawWall(char board[100][1000], int r, int c, int length, int direction, int doTop, int doBottom) {

	if (doTop == 1) {
		if (direction == 0) {
			board[r][c] = char(201);
		}
		else if (direction == 1) {
			board[r][c] = char(187);
		}

		r++;
		length--;
	}
	if (doBottom == 1) length--;

	for (int i = 0; i < length; i++) {
		board[r][c] = char(186);
		r++;
	}

	if (doBottom == 1) {
		if (direction == 0) {
			board[r][c] = char(200);
		}
		else if (direction == 1) {
			board[r][c] = char(188);
		}
	}
}



void drawTeleporter(char board[100][1000], int r, int c) {

	board[r - 4][c + 0] = '\\';
	board[r - 4][c + 1] = '_';
	board[r - 4][c + 2] = '_';
	board[r - 4][c + 3] = '_';
	board[r - 4][c + 4] = '_';
	board[r - 4][c + 5] = '_';
	board[r - 4][c + 6] = '_';
	board[r - 4][c + 7] = '_';
	board[r - 4][c + 8] = '_';
	board[r - 4][c + 9] = '_';
	board[r - 4][c + 10] = '_';
	board[r - 4][c + 11] = '_';
	board[r - 4][c + 12] = '_';
	board[r - 4][c + 13] = '_';
	board[r - 4][c + 14] = '_';
	board[r - 4][c + 15] = '_';
	board[r - 4][c + 16] = '_';
	board[r - 4][c + 17] = '_';
	board[r - 4][c + 18] = '/';
	board[r - 3][c + 1] = '\\';
	board[r - 3][c + 2] = '_';
	board[r - 3][c + 3] = '_';
	board[r - 3][c + 4] = '_';
	board[r - 3][c + 5] = '_';
	board[r - 3][c + 6] = '_';
	board[r - 3][c + 7] = '_';
	board[r - 3][c + 8] = '_';
	board[r - 3][c + 9] = '_';
	board[r - 3][c + 10] = '_';
	board[r - 3][c + 11] = '_';
	board[r - 3][c + 12] = '_';
	board[r - 3][c + 13] = '_';
	board[r - 3][c + 14] = '_';
	board[r - 3][c + 15] = '_';
	board[r - 3][c + 16] = '_';
	board[r - 3][c + 17] = '/';
	board[r - 2][c + 2] = '\\';
	board[r - 2][c + 3] = '.';
	board[r - 2][c + 4] = '/';
	board[r - 2][c + 5] = '\\';
	board[r - 2][c + 6] = '.';
	board[r - 2][c + 7] = '/';
	board[r - 2][c + 8] = '\\';
	board[r - 2][c + 9] = '.';
	board[r - 2][c + 10] = '/';
	board[r - 2][c + 11] = '\\';
	board[r - 2][c + 12] = '.';
	board[r - 2][c + 13] = '/';
	board[r - 2][c + 14] = '\\';
	board[r - 2][c + 15] = '.';
	board[r - 2][c + 16] = '/';
	board[r - 1][c + 2] = '|';
	board[r - 1][c + 3] = '\\';
	board[r - 1][c + 4] = '/';
	board[r - 1][c + 5] = '_';
	board[r - 1][c + 6] = '\\';
	board[r - 1][c + 7] = '/';
	board[r - 1][c + 8] = '_';
	board[r - 1][c + 9] = '|';
	board[r - 1][c + 10] = '_';
	board[r - 1][c + 11] = '\\';
	board[r - 1][c + 12] = '/';
	board[r - 1][c + 13] = '_';
	board[r - 1][c + 14] = '\\';
	board[r - 1][c + 15] = '/';
	board[r - 1][c + 16] = '|';
	board[r - 0][c + 2] = '|';
	board[r - 0][c + 3] = '|';
	board[r - 0][c + 15] = '|';
	board[r - 0][c + 16] = '|';


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
		board[row - i][col] = char(186);
		board[row - i][col + 1] = char(186);

		board[row - i][col + 2] = char(205);
		board[row - i][col + 3] = char(205);
		board[row - i][col + 4] = char(205);
		board[row - i][col + 5] = char(205);
		board[row - i][col + 6] = char(205);
		board[row - i][col + 7] = char(205);
		board[row - i][col + 8] = char(205);
		board[row - i][col + 9] = char(205);
		board[row - i][col + 10] = char(205);
		board[row - i][col + 11] = char(205);

		board[row - i][col + 12] = char(186);
		board[row - i][col + 13] = char(186);
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

		board[row - 14][col + 1] = 'G';
		board[row - 14][col + 2] = 'O';
		board[row - 14][col + 3] = ' ';
		board[row - 14][col + 4] = 'B';
		board[row - 14][col + 5] = 'A';
		board[row - 14][col + 6] = 'C';
		board[row - 14][col + 7] = 'K';
		board[row - 14][col + 8] = '!';


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


void EnemyPlayerCollision(Enemy iskill[], int numberIsKill, Enemy unkill[], int numberUnKill, player& P) {

	for (int i = 0; i < numberIsKill; i++) {

		int enemyTop = iskill[i].Row - iskill[i].maxHeight;
		int enemyBottom = iskill[i].Row + 1;
		int enemyLeft = iskill[i].Col;
		int enemyRight = iskill[i].Col + iskill[i].maxWidth;

		int  pTop = P.Row - 8;
		int  pBottom = P.Row;
		int pLeft = P.Col;
		int pRight = P.Col + 14;

		if (pRight >= enemyLeft && pLeft <= enemyRight && pBottom >= enemyTop && pTop <= enemyBottom) {
			P.Health -= iskill[i].attackPower;
		}
	}
	for (int i = 0; i < 19; i++) {
		if (i >= 5) {
			int enemyTop = unkill[i].Row - unkill[i].maxHeight;
			int enemyBottom = unkill[i].Row + 1;
			int enemyLeft = unkill[i].Col;
			int enemyRight = unkill[i].Col + unkill[i].maxWidth;

			int  pTop = P.Row - 8;
			int  pBottom = P.Row;
			int pLeft = P.Col;
			int pRight = P.Col + 14;
			if (pRight >= enemyLeft && pLeft <= enemyRight && pBottom >= enemyTop && pTop <= enemyBottom) {
				P.Health -= unkill[i].attackPower;
			}
		}
		else {
			int  pTop = P.Row - 8;
			int  pBottom = P.Row;
			int pLeft = P.Col;
			int pRight = P.Col + 14;

			int enemyTop = unkill[i].hitRow - 3 + 1;
			int enemyBottom = unkill[i].hitRow;
			int enemyLeft = unkill[i].hitCol;
			int enemyRight = unkill[i].hitCol + 4 - 1;
			if (pRight >= enemyLeft && pLeft <= enemyRight && pBottom >= enemyTop && pTop <= enemyBottom) {
				P.Health -= unkill[i].attackPower;
			}
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

	dispR = posIHero + 4;
	if (dispR <= 20) dispR = 24;
	if (dispR > 94) dispR = 98;

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

	if (direction == 1) col += 2;
	else if (direction == 2) col -= 2;
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
	for (int i = 0; i < 3; i++) {
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
					if (elevator[i].col == elevator[i].startCol) pY += 2;
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

/////////////////////////////////

void drawAssaultRifle(char board[100][1000], int row, int col, int isTaken) {
	// row is the bottom row, col is the leftmost column

	// Top row
	if (isTaken == 0) {
		// Top "scope"/barrel cover
		board[row - 3][col + 5] = '/';
		board[row - 3][col + 6] = '=';
		board[row - 3][col + 7] = '=';
		board[row - 3][col + 8] = '\\';

		// Middle (main) gun body
		board[row - 2][col + 1] = '=';
		board[row - 2][col + 2] = '#';
		board[row - 2][col + 3] = '%';
		board[row - 2][col + 4] = '#';
		board[row - 2][col + 5] = '-';
		board[row - 2][col + 6] = '#';
		board[row - 2][col + 7] = '#';
		board[row - 2][col + 8] = '|';
		board[row - 2][col + 9] = '=';
		board[row - 2][col + 10] = '>';

		// Bottom grip
		board[row - 1][col + 5] = '^';
		board[row - 1][col + 6] = '-';
		board[row - 1][col + 7] = '^';

		// Bottom frame or gun case
		board[row][col] = '|';
		board[row][col + 1] = '_';
		board[row][col + 2] = '_';
		board[row][col + 3] = '_';
		board[row][col + 4] = '_';
		board[row][col + 5] = '_';
		board[row][col + 6] = '_';
		board[row][col + 7] = '_';
		board[row][col + 8] = '_';
		board[row][col + 9] = '_';
		board[row][col + 10] = '_';
		board[row][col + 11] = '|';

		// Vertical frame sides
		board[row - 1][col] = '|';
		board[row - 2][col] = '|';
		board[row - 3][col] = '|';
		board[row - 1][col + 11] = '|';
		board[row - 2][col + 11] = '|';
		board[row - 3][col + 11] = '|';

		// Top frame
		board[row - 4][col + 1] = '_';
		board[row - 4][col + 2] = '_';
		board[row - 4][col + 3] = '_';
		board[row - 4][col + 4] = '_';
		board[row - 4][col + 5] = '_';
		board[row - 4][col + 6] = '_';
		board[row - 4][col + 7] = '_';
		board[row - 4][col + 8] = '_';
		board[row - 4][col + 9] = '_';
		board[row - 4][col + 10] = '_';

		board[row - 12][col + 2] = 'P';
		board[row - 12][col + 3] = 'I';
		board[row - 12][col + 4] = 'C';
		board[row - 12][col + 5] = 'K';
		board[row - 12][col + 6] = ' ';
		board[row - 12][col + 7] = 'M';
		board[row - 12][col + 8] = 'E';
		board[row - 12][col + 9] = '!';
	}

}

/////////////////////////////////


void checkIsAssaultTaken(player& Player) {
	if (!Player.didGetRifle) {
		int Top = Player.assaultRow - 10;
		int Bottom = Player.assaultRow + 1;
		int Left = Player.assaultCol - 1;
		int Right = Player.assaultCol + 12;

		int playerTop = Player.Row - Player.maxHeight + 1;
		int playerBottom = Player.Row;
		int playerLeft = Player.Col;
		int playerRight = Player.Col + Player.maxWidth - 1;

		int overlapX = 0;
		int overlapY = 0;


		if (playerLeft <= Right && playerRight >= Left) {
			overlapX = 1;
		}

		if (playerTop <= Bottom && playerBottom >= Top) {
			overlapY = 1;
		}

		if (overlapX && overlapY) {
			Player.didGetRifle = 1;
		}
	}

}

//////////////////BOSS///////////////////
////////////////////////////////////////
////////////////////////////////////////
void Draw_And_Move_Boss(char board[100][1000], Enemy& boss, int& row, int& col, int startc, int endc, int& direction) {


	if (direction == 1) {
		if (col < endc) {
			col++;
		}
		else {
			direction = 2;
		}
	}
	else if (direction == 2) {
		if (col > startc) {
			col--;
		}
		else {
			direction = 1;
		}
	}

	if (boss.isKillable != -1) {


		board[row - 9][col + 8] = '.';
		board[row - 9][col + 9] = '-';
		board[row - 9][col + 10] = '"';
		board[row - 9][col + 16] = '"';
		board[row - 9][col + 17] = '-';
		board[row - 9][col + 18] = '.';

		board[row - 8][col + 7] = '/';
		board[row - 8][col + 9] = 'o';
		board[row - 8][col + 17] = 'o';
		board[row - 8][col + 19] = '\\';

		board[row - 7][col + 6] = '/';
		board[row - 7][col + 10] = '\\';
		board[row - 7][col + 16] = '/';
		board[row - 7][col + 20] = '\\';

		board[row - 6][col + 5] = '/';
		board[row - 6][col + 11] = ')';
		board[row - 6][col + 12] = '-';
		board[row - 6][col + 13] = '"';
		board[row - 6][col + 14] = '-';
		board[row - 6][col + 15] = '(';
		board[row - 6][col + 21] = '\\';

		board[row - 5][col + 4] = '/';
		board[row - 5][col + 11] = '(';
		board[row - 5][col + 12] = '6';
		board[row - 5][col + 14] = '6';
		board[row - 5][col + 15] = ')';
		board[row - 5][col + 22] = '\\';

		board[row - 4][col + 3] = '/';
		board[row - 4][col + 11] = '\\';
		board[row - 4][col + 13] = '=';
		board[row - 4][col + 15] = '/';
		board[row - 4][col + 23] = '\\';

		board[row - 3][col + 2] = '(';
		board[row - 3][col + 3] = '"';
		board[row - 3][col + 4] = '.';
		board[row - 3][col + 5] = '_';
		board[row - 3][col + 6] = '_';
		board[row - 3][col + 7] = '\\';
		board[row - 3][col + 8] = '/';
		board[row - 3][col + 9] = '_';
		board[row - 3][col + 10] = '_';
		board[row - 3][col + 11] = '\\';
		board[row - 3][col + 12] = '_';
		board[row - 3][col + 13] = '_';
		board[row - 3][col + 14] = '_';
		board[row - 3][col + 15] = '/';
		board[row - 3][col + 16] = '_';
		board[row - 3][col + 17] = '_';
		board[row - 3][col + 18] = '\\';
		board[row - 3][col + 19] = '/';
		board[row - 3][col + 20] = '_';
		board[row - 3][col + 21] = '_';
		board[row - 3][col + 22] = '.';
		board[row - 3][col + 23] = '"';
		board[row - 3][col + 24] = ')';

		board[row - 2][col + 2] = '"';
		board[row - 2][col + 3] = '-';
		board[row - 2][col + 4] = '_';
		board[row - 2][col + 7] = 'o';
		board[row - 2][col + 9] = 'O';
		board[row - 2][col + 11] = 'o';
		board[row - 2][col + 13] = 'O';
		board[row - 2][col + 15] = 'o';
		board[row - 2][col + 17] = 'O';
		board[row - 2][col + 19] = 'o';
		board[row - 2][col + 22] = '_';
		board[row - 2][col + 23] = '-';
		board[row - 2][col + 24] = '"';

		board[row - 1][col + 2] = '`';
		board[row - 1][col + 3] = '-';
		board[row - 1][col + 4] = 'Y';
		board[row - 1][col + 5] = '-';
		board[row - 1][col + 6] = '-';
		board[row - 1][col + 7] = '.';
		board[row - 1][col + 8] = '_';
		board[row - 1][col + 9] = '_';
		board[row - 1][col + 10] = '_';
		board[row - 1][col + 11] = '_';
		board[row - 1][col + 12] = '_';
		board[row - 1][col + 13] = '_';
		board[row - 1][col + 14] = '_';
		board[row - 1][col + 15] = '_';
		board[row - 1][col + 16] = '_';
		board[row - 1][col + 17] = '_';
		board[row - 1][col + 18] = '.';
		board[row - 1][col + 19] = '-';
		board[row - 1][col + 20] = '-';
		board[row - 1][col + 21] = 'Y';
		board[row - 1][col + 22] = '-';
		board[row - 1][col + 23] = '\'';

		board[row][col + 2] = '`';
		board[row][col + 3] = '-';
		board[row][col + 4] = 'Y';
		board[row][col + 5] = '-';
		board[row][col + 6] = '-';
		board[row][col + 7] = '.';
		board[row][col + 8] = '_';
		board[row][col + 9] = '_';
		board[row][col + 10] = '_';
		board[row][col + 11] = '_';
		board[row][col + 12] = '_';
		board[row][col + 13] = '_';
		board[row][col + 14] = '_';
		board[row][col + 15] = '_';
		board[row][col + 16] = '_';
		board[row][col + 17] = '_';

		board[row][col + 18] = '.';
		board[row][col + 19] = '-';
		board[row][col + 20] = '-';
		board[row][col + 21] = 'Y';
		board[row][col + 22] = '-';
		board[row][col + 23] = '\'';

		int hp = boss.Health;
		board[row - 9][col + 3] = 'H';
		board[row - 9][col + 4] = 'P';
		board[row - 9][col + 5] = ':';

		if (hp > 9 && hp < 100) {
			int fDig = hp / 10, sDig = hp % 10;

			board[row - 9][col + 6] = fDig + '0';
			board[row - 9][col + 7] = sDig + '0';
		}
		else if (hp >= 100) {
			int fDig = hp / 100, sDig = (hp / 10) % 10, tDig = hp % 10;

			board[row - 9][col + 6] = fDig + '0';
			board[row - 9][col + 7] = sDig + '0';
			board[row - 9][col + 8] = tDig + '0';
		}
		else if (hp >= 0 && hp <= 9) {
			board[row - 9][col + 6] = hp + '0';
		}

	}
}












void controlBoss(char board[100][1000], Enemy& boss, int startRLazer[], int rLazer[], int cLazer[], int& countLazBoss, player& Player, Enemy enemyKill[]) {

	if (enemyKill[6].isKillable != -1) {
		countLazBoss++;

		// Laser spawning logic
		if (countLazBoss % 5 == 0) {
			for (int i = 0; i < 10; i++) {
				if (rLazer[i] == -1 && cLazer[i] == -1) {
					startRLazer[i] = enemyKill[6].Row + 1;
					rLazer[i] = enemyKill[6].Row + 1;
					cLazer[i] = enemyKill[6].Col + 12;
					break;
				}
			}
		}

		for (int i = 0; i < 10; i++) {
			if (rLazer[i] != -1 && cLazer[i] != -1) {

				int check = 1;

				// Check board 
				if (rLazer[i] + 1 < 100 && board[rLazer[i] + 1][cLazer[i]] != ' ') {
					check = 0;
				}

				// Collision with player
				if (Player.Row - Player.maxHeight <= rLazer[i] && rLazer[i] <= Player.Row && Player.Col <= cLazer[i] && cLazer[i] <= Player.Col + Player.maxWidth) {
					check = 2;
				}

				if (check == 1) {
					// Clear previous laser
					for (int a = startRLazer[i]; a < rLazer[i]; a++) {
						if (a >= 0 && a < 100) {
							board[a][cLazer[i]] = ' ';
							board[a][cLazer[i] + 1] = ' ';

						}
					}

					// Move laser
					rLazer[i]++;
					if (rLazer[i] >= startRLazer[i] + 5) startRLazer[i]++;

					// Draw laser
					for (int a = startRLazer[i]; a <= rLazer[i]; a++) {
						if (a >= 0 && a < 100) {
							board[a][cLazer[i]] = 'v';
							board[a][cLazer[i] + 1] = 'v';
						}
					}
				}
				else if (check == 0) {
					// Clear laser trail before resetting
					for (int a = startRLazer[i]; a <= rLazer[i]; a++) {
						if (a >= 0 && a < 100) {
							board[a][cLazer[i]] = ' ';
							board[a][cLazer[i] + 1] = ' ';

						}
					}

					// Reset laser
					rLazer[i] = -1;
					cLazer[i] = -1;
					startRLazer[i] = -1;
				}
				else {
					// Collision with player
					Player.Health -= boss.attackPower;

					// Clear laser
					for (int a = startRLazer[i]; a <= rLazer[i]; a++) {
						if (a >= 0 && a < 100) {
							board[a][cLazer[i]] = ' ';
							board[a][cLazer[i] + 1] = ' ';

						}
					}

					// Reset laser
					rLazer[i] = -1;
					cLazer[i] = -1;
					startRLazer[i] = -1;
				}
			}
		}
	}

}


////////////////////////////////////////
////////////////////////////////////////
/////////////////////////////////////////


void drawMoveSkeleton(char board[100][1000], Enemy& Skeleton, int stCol, int endCol, int& direction) {

	if (Skeleton.Col == endCol) {
		direction = 1;
	}
	if (Skeleton.Col == stCol) {
		direction = 0;
	}

	if (direction == 0) {
		Skeleton.Col++;

	}
	else {
		Skeleton.Col--;
	}

	//height = 13 , width =11

	int row = Skeleton.Row, col = Skeleton.Col;
	//head
	int isDead = Skeleton.isKillable;
	if (Skeleton.isKillable != -1) {
		board[row - 13][col + 5] = '-';
		board[row - 13][col + 4] = '.';
		board[row - 13][col + 6] = '.';
		board[row - 12][col + 3] = '(';
		board[row - 12][col + 4] = 'o';
		board[row - 12][col + 5] = '.';
		board[row - 12][col + 6] = 'o';
		board[row - 12][col + 7] = ')';
		board[row - 11][col + 6] = '|';
		board[row - 11][col + 5] = '=';
		board[row - 11][col + 4] = '|';


		//body

		board[row - 10][col + 3] = '_';
		board[row - 9][col + 3] = '.';
		board[row - 8][col + 3] = '.';
		board[row - 7][col + 3] = '.';
		board[row - 6][col + 3] = '(';
		board[row - 10][col + 4] = '_';
		board[row - 9][col + 4] = '=';
		board[row - 8][col + 4] = '=';
		board[row - 7][col + 4] = '=';
		board[row - 6][col + 4] = '_';
		board[row - 10][col + 5] = '|';
		board[row - 9][col + 5] = '|';
		board[row - 8][col + 5] = '|';
		board[row - 7][col + 5] = '|';
		board[row - 6][col + 5] = '=';
		board[row - 10][col + 6] = '_';
		board[row - 9][col + 6] = '=';
		board[row - 8][col + 6] = '=';
		board[row - 7][col + 6] = '=';
		board[row - 6][col + 6] = '_';
		board[row - 10][col + 7] = '_';
		board[row - 9][col + 7] = '.';
		board[row - 8][col + 7] = '.';
		board[row - 7][col + 7] = '.';
		board[row - 6][col + 7] = '_';



		//right hand


		board[row - 9][col + 8] = '\\';
		board[row - 9][col + 9] = '\\';
		board[row - 8][col + 9] = '\\';
		board[row - 8][col + 10] = '\\';
		board[row - 7][col + 10] = '/';
		board[row - 7][col + 9] = '/';
		board[row - 6][col + 9] = '/';
		board[row - 6][col + 8] = '/';
		board[row - 5][col + 8] = ')';



		//left hand
		board[row - 9][col + 2] = '/';
		board[row - 9][col + 1] = '/';
		board[row - 8][col + 1] = '/';
		board[row - 8][col] = '/';
		board[row - 7][col] = '\\';
		board[row - 7][col + 1] = '\\';
		board[row - 6][col + 1] = '\\';
		board[row - 6][col + 2] = '\\';
		board[row - 5][col + 2] = '(';


		//right leg

		board[row - 5][col + 3] = ':';
		board[row - 4][col + 3] = '|';
		board[row - 3][col + 3] = '(';
		board[row - 2][col + 3] = '|';
		board[row - 1][col + 3] = '|';
		board[row][col + 3] = '=';
		board[row][col + 2] = '=';
		board[row - 5][col + 4] = '|';
		board[row - 4][col + 4] = '|';
		board[row - 3][col + 4] = ')';
		board[row - 2][col + 4] = '|';
		board[row - 1][col + 4] = '|';
		board[row][col + 4] = '\'';



		//left leg
		board[row - 5][col + 6] = '|';
		board[row - 4][col + 6] = '|';
		board[row - 3][col + 6] = '(';
		board[row - 2][col + 6] = '|';
		board[row - 1][col + 6] = '|';
		board[row][col + 6] = '\'';
		board[row - 5][col + 7] = ':';
		board[row - 4][col + 7] = '|';
		board[row - 3][col + 7] = ')';
		board[row - 2][col + 7] = '|';
		board[row - 1][col + 7] = '|';
		board[row][col + 7] = '=';
		board[row][col + 8] = '=';




		int hp = Skeleton.Health;
		board[row - 16][col + 3] = 'H';
		board[row - 16][col + 4] = 'P';
		board[row - 16][col + 5] = ':';

		if (hp > 9 && hp < 100) {
			int fDig = hp / 10, sDig = hp % 10;

			board[row - 16][col + 6] = fDig + '0';
			board[row - 16][col + 7] = sDig + '0';
		}
		else if (hp >= 100) {
			int fDig = hp / 100, sDig = (hp / 10) % 10, tDig = hp % 10;

			board[row - 16][col + 6] = fDig + '0';
			board[row - 16][col + 7] = sDig + '0';
			board[row - 16][col + 8] = tDig + '0';
		}
		else if (hp >= 0 && hp <= 9) {
			board[row - 16][col + 6] = hp + '0';
		}
	}
}





///////////////////////////////////
// 
void drawHittableDoor(char board[100][1000], Enemy& Door, int height) {
	if (Door.isKillable != -1) {
		int r = Door.Row;
		for (int i = 0; i < height; i++) {
			board[r][Door.Col] = '|';
			r--;
		}
	}
}

///////////////////////////////////

void drawAlien(char board[100][1000], int row, int col, int& frame, Enemy& Alien) {
	if (Alien.isKillable != -1) {
			if (frame == 1) {
		board[row - 8][col + 30-15] = '\\';
		board[row - 8][col + 31-15] = '_';
		board[row - 8][col + 32-15] = '_';
		board[row - 8][col + 33-15] = '/';
		board[row - 7][col + 29-15] = '/';
		board[row - 7][col + 30-15] = '(';
		board[row - 7][col + 31-15] = 'o';
		board[row - 7][col + 32-15] = ')';
		board[row - 7][col + 34-15] = '\\';
		board[row - 6][col + 29-15] = '\\';
		board[row - 6][col + 31-15] = '-';
		board[row - 6][col + 32-15] = '-';
		board[row - 6][col + 34-15] = '/';
		board[row - 5][col + 15-15] = '_';
		board[row - 5][col + 17-15] = '_';
		board[row - 5][col + 18-15] = '_';
		board[row - 5][col + 19-15] = '_';
		board[row - 5][col + 20-15] = '_';
		board[row - 5][col + 21-15] = '_';
		board[row - 5][col + 22-15] = '_';
		board[row - 5][col + 23-15] = '|';
		board[row - 5][col + 24-15] = '\\';
		board[row - 5][col + 25-15] = '_';
		board[row - 5][col + 26-15] = '_';
		board[row - 5][col + 27-15] = '(';
		board[row - 5][col + 28-15] = '-';
		board[row - 5][col + 29-15] = '-';
		board[row - 5][col + 30-15] = '=';
		board[row - 5][col + 31-15] = '=';
		board[row - 5][col + 32-15] = '=';
		board[row - 5][col + 33-15] = '=';
		board[row - 5][col + 34-15] = '-';
		board[row - 5][col + 35-15] = '-';
		board[row - 5][col + 36-15] = ')';
		board[row - 4][col + 15-15] = '\\';
		board[row - 4][col + 16-15] = '_';
		board[row - 4][col + 17-15] = '_';
		board[row - 4][col + 18-15] = '_';
		board[row - 4][col + 19-15] = '_';
		board[row - 4][col + 20-15] = '_';
		board[row - 4][col + 21-15] = '_';
		board[row - 4][col + 22-15] = '_';
		board[row - 4][col + 23-15] = '_';
		board[row - 4][col + 24-15] = '_';
		board[row - 4][col + 25-15] = '\\';
		board[row - 4][col + 26-15] = '=';
		board[row - 4][col + 27-15] = '=';
		board[row - 4][col + 28-15] = '=';
		board[row - 4][col + 29-15] = '=';
		board[row - 4][col + 30-15] = '=';
		board[row - 4][col + 31-15] = '=';
		board[row - 4][col + 32-15] = '/';
		board[row - 4][col + 33-15] = '\\';
		board[row - 4][col + 35-15] = '\\';
		board[row - 4][col + 36-15] = '[';
		board[row - 4][col + 37-15] = '[';
		board[row - 4][col + 38-15] = '/';
		board[row - 3][col + 27-15] = '/';
		board[row - 3][col + 30-15] = '\\';
		board[row - 3][col + 33-15] = '\\';
		board[row - 3][col + 34-15] = '_';
		board[row - 3][col + 35-15] = '-';
		board[row - 3][col + 36-15] = '/';
		board[row - 2][col + 29-15] = '|';
		board[row - 2][col + 30-15] = '=';
		board[row - 2][col + 31-15] = '=';
		board[row - 2][col + 32-15] = '=';
		board[row - 2][col + 33-15] = '=';
		board[row - 2][col + 34-15] = '|';
		board[row - 1][col + 28-15] = '(';
		board[row - 1][col + 31-15] = '/';
		board[row - 1][col + 32-15] = '\\';
		board[row - 1][col + 35-15] = ')';
		board[row - 0][col + 28-15] = '_';
		board[row - 0][col + 29-15] = '|';
		board[row - 0][col + 30-15] = '|';
		board[row - 0][col + 33-15] = '|';
		board[row - 0][col + 34-15] = '|';
		board[row - 0][col + 35-15] = '_';
	}




	else if (frame == 2) {
		board[row - 8][col + 30-15] = '\\';
		board[row - 8][col + 31-15] = '_';
		board[row - 8][col + 32-15] = '_';
		board[row - 8][col + 33-15] = '/';
		board[row - 7][col + 29-15] = '/';
		board[row - 7][col + 30-15] = '(';
		board[row - 7][col + 31-15] = 'o';
		board[row - 7][col + 32-15] = ')';
		board[row - 7][col + 34-15] = '\\';
		board[row - 6][col + 29-15] = '\\';
		board[row - 6][col + 31-15] = '-';
		board[row - 6][col + 32-15] = '-';
		board[row - 6][col + 34-15] = '/';
		board[row - 5][col + 18-15] = '_';
		board[row - 5][col + 20-15] = '_';
		board[row - 5][col + 21-15] = '_';
		board[row - 5][col + 22-15] = '_';
		board[row - 5][col + 23-15] = '_';
		board[row - 5][col + 24-15] = '_';
		board[row - 5][col + 25-15] = '_';
		board[row - 5][col + 26-15] = '|';
		board[row - 5][col + 27-15] = '\\';
		board[row - 5][col + 28-15] = '_';
		board[row - 5][col + 29-15] = '_';
		board[row - 5][col + 30-15] = '(';
		board[row - 5][col + 31-15] = '-';
		board[row - 5][col + 32-15] = '-';
		board[row - 5][col + 33-15] = '=';
		board[row - 5][col + 34-15] = '=';
		board[row - 5][col + 35-15] = '=';
		board[row - 5][col + 36-15] = '=';
		board[row - 5][col + 37-15] = '-';
		board[row - 5][col + 38-15] = '-';
		board[row - 5][col + 39-15] = ')';
		board[row - 4][col + 17-15] = '\\';
		board[row - 4][col + 18-15] = '_';
		board[row - 4][col + 19-15] = '_';
		board[row - 4][col + 20-15] = '_';
		board[row - 4][col + 21-15] = '_';
		board[row - 4][col + 22-15] = '_';
		board[row - 4][col + 23-15] = '_';
		board[row - 4][col + 24-15] = '_';
		board[row - 4][col + 25-15] = '_';
		board[row - 4][col + 26-15] = '_';
		board[row - 4][col + 27-15] = '\\';
		board[row - 4][col + 28-15] = '=';
		board[row - 4][col + 29-15] = '=';
		board[row - 4][col + 30-15] = '=';
		board[row - 4][col + 31-15] = '=';
		board[row - 4][col + 32-15] = '=';
		board[row - 4][col + 33-15] = '=';
		board[row - 4][col + 34-15] = '/';
		board[row - 4][col + 35-15] = '\\';
		board[row - 4][col + 37-15] = '\\';
		board[row - 4][col + 38-15] = '[';
		board[row - 4][col + 39-15] = '[';
		board[row - 4][col + 40-15] = '/';
		board[row - 3][col + 27-15] = '/';
		board[row - 3][col + 30-15] = '\\';
		board[row - 3][col + 33-15] = '\\';
		board[row - 3][col + 34-15] = '_';
		board[row - 3][col + 35-15] = '-';
		board[row - 3][col + 36-15] = '/';
		board[row - 2][col + 29-15] = '|';
		board[row - 2][col + 30-15] = '=';
		board[row - 2][col + 31-15] = '=';
		board[row - 2][col + 32-15] = '=';
		board[row - 2][col + 33-15] = '=';
		board[row - 2][col + 34-15] = '|';
		board[row - 1][col + 28-15] = '(';
		board[row - 1][col + 31-15] = '/';
		board[row - 1][col + 32-15] = '\\';
		board[row - 1][col + 35-15] = ')';
		board[row - 0][col + 28-15] = '_';
		board[row - 0][col + 29-15] = '|';
		board[row - 0][col + 30-15] = '|';
		board[row - 0][col + 33-15] = '|';
		board[row - 0][col + 34-15] = '|';
		board[row - 0][col + 35-15] = '_';
	}						  
							   
	else if (frame == 3) {	   
		board[row - 8][col + 30-15] = '\\';
		board[row - 8][col + 31-15] = '_';
		board[row - 8][col + 32-15] = '_';
		board[row - 8][col + 33-15] = '/';
		board[row - 7][col + 29-15] = '/';
		board[row - 7][col + 30-15] = '(';
		board[row - 7][col + 31-15] = 'o';
		board[row - 7][col + 32-15] = ')';
		board[row - 7][col + 34-15] = '\\';
		board[row - 6][col + 29-15] = '\\';
		board[row - 6][col + 31-15] = '-';
		board[row - 6][col + 32-15] = '-';
		board[row - 6][col + 34-15] = '/';
		board[row - 5][col + 19-15] = '_';
		board[row - 5][col + 21-15] = '_';
		board[row - 5][col + 22-15] = '_';
		board[row - 5][col + 23-15] = '_';
		board[row - 5][col + 24-15] = '_';
		board[row - 5][col + 25-15] = '_';
		board[row - 5][col + 26-15] = '_';
		board[row - 5][col + 27-15] = '|';
		board[row - 5][col + 28-15] = '\\';
		board[row - 5][col + 29-15] = '_';
		board[row - 5][col + 30-15] = '_';
		board[row - 5][col + 31-15] = '(';
		board[row - 5][col + 32-15] = '-';
		board[row - 5][col + 33-15] = '-';
		board[row - 5][col + 34-15] = '=';
		board[row - 5][col + 35-15] = '=';
		board[row - 5][col + 36-15] = '=';
		board[row - 5][col + 37-15] = '=';
		board[row - 5][col + 38-15] = '-';
		board[row - 5][col + 39-15] = '-';
		board[row - 5][col + 40-15] = ')';
		board[row - 4][col + 18-15] = '\\';
		board[row - 4][col + 19-15] = '_';
		board[row - 4][col + 20-15] = '_';
		board[row - 4][col + 21-15] = '_';
		board[row - 4][col + 22-15] = '_';
		board[row - 4][col + 23-15] = '_';
		board[row - 4][col + 24-15] = '_';
		board[row - 4][col + 25-15] = '_';
		board[row - 4][col + 26-15] = '_';
		board[row - 4][col + 27-15] = '_';
		board[row - 4][col + 28-15] = '\\';
		board[row - 4][col + 29-15] = '=';
		board[row - 4][col + 30-15] = '=';
		board[row - 4][col + 31-15] = '=';
		board[row - 4][col + 32-15] = '=';
		board[row - 4][col + 33-15] = '=';
		board[row - 4][col + 34-15] = '=';
		board[row - 4][col + 35-15] = '/';
		board[row - 4][col + 36-15] = '\\';
		board[row - 4][col + 38-15] = '\\';
		board[row - 4][col + 39-15] = '[';
		board[row - 4][col + 40-15] = '[';
		board[row - 4][col + 41-15] = '/';
		board[row - 3][col + 27-15] = '/';
		board[row - 3][col + 30-15] = '\\';
		board[row - 3][col + 33-15] = '\\';
		board[row - 3][col + 34-15] = '_';
		board[row - 3][col + 35-15] = '-';
		board[row - 3][col + 36-15] = '/';
		board[row - 2][col + 29-15] = '|';
		board[row - 2][col + 30-15] = '=';
		board[row - 2][col + 31-15] = '=';
		board[row - 2][col + 32-15] = '=';
		board[row - 2][col + 33-15] = '=';
		board[row - 2][col + 34-15] = '|';
		board[row - 1][col + 28-15] = '(';
		board[row - 1][col + 31-15] = '/';
		board[row - 1][col + 32-15] = '\\';
		board[row - 1][col + 35-15] = ')';
		board[row - 0][col + 28-15] = '_';
		board[row - 0][col + 29-15] = '|';
		board[row - 0][col + 30-15] = '|';
		board[row - 0][col + 33-15] = '|';
		board[row - 0][col + 34-15] = '|';
		board[row - 0][col + 35-15] = '_';
	}						  
							   
	else if (frame == 5) {	   
							   
		board[row - 8][col + 30-15] = '\\';
		board[row - 8][col + 31-15] = '_';
		board[row - 8][col + 32-15] = '_';
		board[row - 8][col + 33-15] = '/';
		board[row - 7][col + 29-15] = '/';
		board[row - 7][col + 30-15] = '(';
		board[row - 7][col + 31-15] = 'o';
		board[row - 7][col + 32-15] = ')';
		board[row - 7][col + 34-15] = '\\';
		board[row - 6][col + 29-15] = '\\';
		board[row - 6][col + 31-15] = '-';
		board[row - 6][col + 32-15] = '-';
		board[row - 6][col + 34-15] = '/';
		board[row - 5][col + 18-15] = '_';
		board[row - 5][col + 20-15] = '_';
		board[row - 5][col + 21-15] = '_';
		board[row - 5][col + 22-15] = '_';
		board[row - 5][col + 23-15] = '_';
		board[row - 5][col + 24-15] = '_';
		board[row - 5][col + 25-15] = '_';
		board[row - 5][col + 26-15] = '|';
		board[row - 5][col + 27-15] = '\\';
		board[row - 5][col + 28-15] = '_';
		board[row - 5][col + 29-15] = '_';
		board[row - 5][col + 30-15] = '(';
		board[row - 5][col + 31-15] = '-';
		board[row - 5][col + 32-15] = '-';
		board[row - 5][col + 33-15] = '=';
		board[row - 5][col + 34-15] = '=';
		board[row - 5][col + 35-15] = '=';
		board[row - 5][col + 36-15] = '=';
		board[row - 5][col + 37-15] = '-';
		board[row - 5][col + 38-15] = '-';
		board[row - 5][col + 39-15] = ')';
		board[row - 4][col + 17-15] = '\\';
		board[row - 4][col + 18-15] = '_';
		board[row - 4][col + 19-15] = '_';
		board[row - 4][col + 20-15] = '_';
		board[row - 4][col + 21-15] = '_';
		board[row - 4][col + 22-15] = '_';
		board[row - 4][col + 23-15] = '_';
		board[row - 4][col + 24-15] = '_';
		board[row - 4][col + 25-15] = '_';
		board[row - 4][col + 26-15] = '_';
		board[row - 4][col + 27-15] = '\\';
		board[row - 4][col + 28-15] = '=';
		board[row - 4][col + 29-15] = '=';
		board[row - 4][col + 30-15] = '=';
		board[row - 4][col + 31-15] = '=';
		board[row - 4][col + 32-15] = '=';
		board[row - 4][col + 33-15] = '=';
		board[row - 4][col + 34-15] = '/';
		board[row - 4][col + 35-15] = '\\';
		board[row - 4][col + 37-15] = '\\';
		board[row - 4][col + 38-15] = '[';
		board[row - 4][col + 39-15] = '[';
		board[row - 4][col + 40-15] = '/';
		board[row - 3][col + 27-15] = '/';
		board[row - 3][col + 30-15] = '\\';
		board[row - 3][col + 33-15] = '\\';
		board[row - 3][col + 34-15] = '_';
		board[row - 3][col + 35-15] = '-';
		board[row - 3][col + 36-15] = '/';
		board[row - 2][col + 29-15] = '|';
		board[row - 2][col + 30-15] = '=';
		board[row - 2][col + 31-15] = '=';
		board[row - 2][col + 32-15] = '=';
		board[row - 2][col + 33-15] = '=';
		board[row - 2][col + 34-15] = '|';
		board[row - 1][col + 28-15] = '(';
		board[row - 1][col + 31-15] = '/';
		board[row - 1][col + 32-15] = '\\';
		board[row - 1][col + 35-15] = ')';
		board[row - 0][col + 28-15] = '_';
		board[row - 0][col + 29-15] = '|';
		board[row - 0][col + 30-15] = '|';
		board[row - 0][col + 33-15] = '|';
		board[row - 0][col + 34-15] = '|';
		board[row - 0][col + 35-15] = '_';
	}						   
							   
	else if (frame == 6) {	   
		board[row - 8][col + 30-15] = '\\';
		board[row - 8][col + 31-15] = '_';
		board[row - 8][col + 32-15] = '_';
		board[row - 8][col + 33-15] = '/';
		board[row - 7][col + 29-15] = '/';
		board[row - 7][col + 30-15] = '(';
		board[row - 7][col + 31-15] = 'o';
		board[row - 7][col + 32-15] = ')';
		board[row - 7][col + 34-15] = '\\';
		board[row - 6][col + 29-15] = '\\';
		board[row - 6][col + 31-15] = '-';
		board[row - 6][col + 32-15] = '-';
		board[row - 6][col + 34-15] = '/';
		board[row - 5][col + 15-15] = '_';
		board[row - 5][col + 17-15] = '_';
		board[row - 5][col + 18-15] = '_';
		board[row - 5][col + 19-15] = '_';
		board[row - 5][col + 20-15] = '_';
		board[row - 5][col + 21-15] = '_';
		board[row - 5][col + 22-15] = '_';
		board[row - 5][col + 23-15] = '|';
		board[row - 5][col + 24-15] = '\\';
		board[row - 5][col + 25-15] = '_';
		board[row - 5][col + 26-15] = '_';
		board[row - 5][col + 27-15] = '(';
		board[row - 5][col + 28-15] = '-';
		board[row - 5][col + 29-15] = '-';
		board[row - 5][col + 30-15] = '=';
		board[row - 5][col + 31-15] = '=';
		board[row - 5][col + 32-15] = '=';
		board[row - 5][col + 33-15] = '=';
		board[row - 5][col + 34-15] = '-';
		board[row - 5][col + 35-15] = '-';
		board[row - 5][col + 36-15] = ')';
		board[row - 4][col + 15-15] = '\\';
		board[row - 4][col + 16-15] = '_';
		board[row - 4][col + 17-15] = '_';
		board[row - 4][col + 18-15] = '_';
		board[row - 4][col + 19-15] = '_';
		board[row - 4][col + 20-15] = '_';
		board[row - 4][col + 21-15] = '_';
		board[row - 4][col + 22-15] = '_';
		board[row - 4][col + 23-15] = '_';
		board[row - 4][col + 24-15] = '_';
		board[row - 4][col + 25-15] = '\\';
		board[row - 4][col + 26-15] = '=';
		board[row - 4][col + 27-15] = '=';
		board[row - 4][col + 28-15] = '=';
		board[row - 4][col + 29-15] = '=';
		board[row - 4][col + 30-15] = '=';
		board[row - 4][col + 31-15] = '=';
		board[row - 4][col + 32-15] = '/';
		board[row - 4][col + 33-15] = '\\';
		board[row - 4][col + 35-15] = '\\';
		board[row - 4][col + 36-15] = '[';
		board[row - 4][col + 37-15] = '[';
		board[row - 4][col + 38-15] = '/';
		board[row - 3][col + 27-15] = '/';
		board[row - 3][col + 30-15] = '\\';
		board[row - 3][col + 33-15] = '\\';
		board[row - 3][col + 34-15] = '_';
		board[row - 3][col + 35-15] = '-';
		board[row - 3][col + 36-15] = '/';
		board[row - 2][col + 29-15] = '|';
		board[row - 2][col + 30-15] = '=';
		board[row - 2][col + 31-15] = '=';
		board[row - 2][col + 32-15] = '=';
		board[row - 2][col + 33-15] = '=';
		board[row - 2][col + 34-15] = '|';
		board[row - 1][col + 28-15] = '(';
		board[row - 1][col + 31-15] = '/';
		board[row - 1][col + 32-15] = '\\';
		board[row - 1][col + 35-15] = ')';
		board[row - 0][col + 28-15] = '_';
		board[row - 0][col + 29-15] = '|';
		board[row - 0][col + 30-15] = '|';
		board[row - 0][col + 33-15] = '|';
		board[row - 0][col + 34-15] = '|';
		board[row - 0][col + 35-15] = '_';
	}

		frame++;

		if (frame == 7) {
			frame = 1;
		}

		int hp = Alien.Health;
		board[row - 11][col + 3] = 'H';
		board[row - 11][col + 4] = 'P';
		board[row - 11][col + 5] = ':';

		if (hp > 9 && hp < 100) {
			int fDig = hp / 10, sDig = hp % 10;

			board[row - 11][col + 6] = fDig + '0';
			board[row - 11][col + 7] = sDig + '0';
		}
		else if (hp >= 100) {
			int fDig = hp / 100, sDig = (hp / 10) % 10, tDig = hp % 10;

			board[row - 11][col + 6] = fDig + '0';
			board[row - 11][col + 7] = sDig + '0';
			board[row - 11][col + 8] = tDig + '0';
		}
		else if (hp >= 0 && hp <= 9) {
			board[row - 11][col + 6] = hp + '0';
		}
	}
}
///////////////////////////////////

void callObj(char board[100][1000], coin coins[], Enemy isKill[], hearts heart[], int isClicked, player& Player, Enemy unKill[], int isTeleClicked , int &alienFrame) {
	//The part for the devil
	drawTerrain(board, 95, 60, 2, 13); //first platform

	drawTerrain(board, 92, 45, 2, 13); //second platform
	drawTerrain(board, 89, 2, 2, 39); //third platform

	drawLadder(board, 88, 19, 18);



	drawTerrain(board, 71, 33, 1, 32);
	drawLadder(board, 70, 51, 21);
	drawTerrain(board, 50, 1, 1, 50);
	drawDevil(board, isKill[0]);
	drawCoin(board, coins[0].Row, coins[0].Col, coins[0].isCollected);




	//The snail part

	drawTerrain(board, 70, 100, 1, 33);
	drawWall(board, 51, 100, 20, 0, 0, 1);
	drawCoin(board, coins[1].Row, coins[1].Col, coins[1].isCollected); // row = 69 , col = 66


	//Crystals part
	//each crystal takes width 10 , there are 5 crystals and we must leave a distance of 20 between each so its 10*5 + 20*5= 150
	//this terrain is drawn over the crystals+ above the button so lets say 150 + 25 = 175  , 25 cols to leave space for button

	FallingCrystal(board, unKill[0]);
	FallingCrystal(board, unKill[1]);
	FallingCrystal(board, unKill[2]);
	FallingCrystal(board, unKill[3]);
	FallingCrystal(board, unKill[4]);


	drawTerrain(board, 70, 134 + 15, 1, 162);
	//col at end is 100+ 175 = 275


	//drawButton(board , 97 , 250);




	drawSpike(board, 98, 110);
	Hiddenladder(board, 98, 134, 98 - 70, isClicked);
	drawButton(board, 98, 290, isClicked);

	drawWall(board, 70, 310, 29, 1, 1, 0);



	drawSpike(board, 69, 250);
	spawnHeart(board, heart, 0); // row = 69 , col = 130

	spawnHeart(board, heart, 1); // row = 98 , col = 210

	//the part where the assault rifle drop should be 



	//////place to put 2nd elevator
	drawTerrain(board, 98, 330, 1, 3);
	board[98][333] = char(188);
	drawTerrain(board, 97, 334, 1, 3);
	board[97][337] = char(188);
	drawTerrain(board, 96, 338, 1, 11);
	drawWall(board, 96, 349, 3, 1, 1, 0);

	drawTerrain(board, 98, 350, 1, 12);


	drawWall(board, 96, 362, 3, 0, 1, 0);
	drawTerrain(board, 96, 363, 1, 10);

	board[97][373] = char(200);
	drawTerrain(board, 97, 374, 1, 3);
	board[98][377] = char(200);
	drawTerrain(board, 98, 378, 1, 3);
	////////////////////////////////////

	drawTerrain(board, 50, 170 - 70, 1, 70);
	drawTerrain(board, 50, 180, 1, 30);
	drawWall(board, 2, 150 - 50, 49, 0, 0, 1);

	drawAssaultRifle(board, Player.assaultRow, Player.assaultCol, Player.didGetRifle);
	drawCoin(board, coins[2].Row, coins[2].Col, coins[2].isCollected); // row = 69 , col = 66
	drawAlien( board, isKill[4].Row, isKill[4].Col, alienFrame, isKill[4]);

	drawWall(board, 2, 210, 49, 1, 0, 1);

	//Upper terrain for skeleton and bird

	drawTerrain(board, 30, 362, 1, 38);
	drawLadder(board, 50, 400, 21);
	drawTerrain(board, 51, 400, 1, 214);

	drawLadder(board, 50, 600, 21);
	drawTerrain(board, 30, 614, 1, 86);
	drawCoin(board, coins[3].Row, coins[3].Col, coins[3].isCollected);
	drawCoin(board, coins[6].Row, coins[6].Col, coins[6].isCollected);



	//////////////////////////////////
	/////////////SPIKE AREA//////////


		//430 , 478
	drawTerrain(board, 99 - 1, 396, 2, 3);
	drawTerrain(board, 99 - 2, 400, 2, 3);
	drawTerrain(board, 99 - 3, 404, 2, 3);
	drawTerrain(board, 99 - 4, 408, 2, 3);
	drawTerrain(board, 99 - 5, 412, 2, 3);
	drawTerrain(board, 99 - 6, 416, 2, 3);
	drawTerrain(board, 99 - 7, 420, 2, 9);
	drawWall(board, 99 - 7, 429, 7, 1, 0, 0);


	int i = 430;
	for (; i <= 478; i += 6) {
		drawSpike(board, 98, i);
	}

	drawCoin(board, coins[4].Row, coins[4].Col, coins[4].isCollected);


	drawWall(board, 99 - 7, 483, 7, 1, 0, 0);
	drawTerrain(board, 99 - 7, 484, 2, 3);
	drawTerrain(board, 99 - 6, 488, 2, 3);
	drawTerrain(board, 99 - 5, 492, 2, 3);
	drawTerrain(board, 99 - 4, 496, 2, 3);
	drawTerrain(board, 99 - 3, 500, 2, 3);
	drawTerrain(board, 99 - 2, 504, 2, 3);
	drawTerrain(board, 99 - 1, 508, 2, 3);

	drawCoin(board, coins[5].Row, coins[5].Col, coins[5].isCollected);


	drawCoin(board, coins[8].Row, coins[8].Col, coins[8].isCollected);

	drawCoin(board, coins[9].Row, coins[9].Col, coins[9].isCollected);


	/////////////////////////////////


	drawSpike(board, 98, 530);
	drawSpike(board, 98, 535);

	///


	spawnHeart(board, heart, 2);



	///////////TELEPORTER;///////////
	drawTeleporter(board, 98, 680);
	drawTeleporter(board, 98, 702);
	drawWall(board, 2, 732, 85, 1, 0, 0);



	int row = 98, col = 680;
	drawTerrain(board, row - 18, col - 8, 1, 698 - 671);
	drawCoin(board, coins[7].Row, coins[7].Col, coins[7].isCollected);

	int teleport2x = 98, teleport2y = 702;
	if (isTeleClicked == 0) {
		if (Player.coins >= 250) {
			board[row - 16][col + 4] = 'B';
			board[row - 16][col + 5] = 'O';
			board[row - 16][col + 6] = 'S';
			board[row - 16][col + 7] = 'S';
			board[row - 16][col + 8] = ' ';
			board[row - 16][col + 9] = 'R';
			board[row - 16][col + 10] = 'O';
			board[row - 16][col + 11] = 'O';
			board[row - 16][col + 12] = 'M';

		}


		else {
			//isOnTelep
			board[row - 16][col + 4] = 'L';
			board[row - 16][col + 5] = 'A';
			board[row - 16][col + 6] = 'C';
			board[row - 16][col + 7] = 'K';
			board[row - 16][col + 8] = 'I';
			board[row - 16][col + 9] = 'N';
			board[row - 16][col + 10] = 'G';
			board[row - 16][col + 11] = ' ';
			board[row - 16][col + 12] = 'C';
			board[row - 16][col + 13] = 'O';
			board[row - 16][col + 14] = 'I';
			board[row - 16][col + 15] = 'N';
			board[row - 16][col + 16] = 'S';
		}

	}
	/////
	////////////////
	// 
	// 
	//boss area
	
	drawTerrain(board, 82, 915, 1, 40);
	drawTerrain(board, 82, 761, 1, 40);


	drawWall(board, 2, 761, 97, 1, 0, 0);
	drawWall(board, 2, 800, 80, 1, 0, 0);
	drawWall(board, 2, 915, 80, 1, 0, 0);
	drawWall(board, 2, 955, 97, 1, 0, 0);

}


void callDynamicObj(char board[100][1000], Elevator elevator[], int& posXLaz, int posYLaz[], int direction, int& whatLaz, int& isShooting, Enemy enemyKill[], int& posXGUn, int& posYGun, int blobStartC, int blobEndC, int& blobIsJumping, int& blobDirection, int AssaultR[], int AssaultC[], int startCAssault[], int assaultDirection[], int rEggs[], int cEggs[], int& countE, player& Player, Enemy enemyUnKill[], int startRLazer[], int rLazer[], int cLazer[], int& countLazBoss, int& isGunShooting, int& countGun) {
	drawAndMoveElevatorV(board, elevator, 0);
	drawAndMoveElevatorH(board, elevator, 1);

	drawAndMoveElevatorV(board, elevator, 2); // Col = 350 , row = 99 -> 20

	// //Skeleton  skeletonCol = 430, skeletonRow = 50;
	// startC is 430 , endC is 500
	drawMoveSkeleton(board, enemyKill[3], 430, 500, enemyKill[3].direction);
	drawMoveSkeleton(board, enemyKill[7], 880, 940, enemyKill[7].direction);
	drawMoveSkeleton(board, enemyKill[8], 766, 830, enemyKill[8].direction);

	drawHittableDoor(board, enemyKill[1], 18);
	drawAndMoveBlob(board, enemyKill[2], enemyKill[2].Row, enemyKill[2].Col, blobStartC, blobEndC, blobDirection, blobIsJumping);

	controlBird(board, enemyUnKill[5], 520, 590, rEggs, cEggs, countE, Player);

	Draw_And_Move_Boss(board, enemyKill[6], enemyKill[6].Row, enemyKill[6].Col, 800, 890, enemyKill[6].direction);
	controlBoss(board, enemyKill[6], startRLazer, rLazer, cLazer, countLazBoss, Player, enemyKill);








	/////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	// Assault rifleسسس
	//int AssaultR[] , int AssaultC[] , int & assaultDirection , int& AssaultIndex
	int checkShooting =0 ;
	for(int i =0 ; i< 20 ; i++){
		if(posYLaz[i] != -1){ 
			checkShooting = 1;
			break;
		}
	}

	if (posYGun != -1){
		checkShooting =1;
	}

	if(checkShooting == 0) isShooting = 0;



	for (int i = 0; i < 20; i++) {
		if (AssaultR[i] != -1 && AssaultC[i] != -1) {
			if (assaultDirection[i] == 0) {
				if (AssaultC[i] + 1 < 999 && AssaultC[i] + 1 <= startCAssault[i] + 20 && board[AssaultR[i]][AssaultC[i] + 1] == ' ') {
					AssaultC[i]++;
				}
				else {
					AssaultC[i] = -1;
					assaultDirection[i] = -1;
					AssaultR[i] = -1;
					startCAssault[i] = -1;
					isShooting = 0;
				}
			}

			else if (assaultDirection[i] == 1) {
				if (AssaultC[i] - 1 >= 1 && AssaultC[i] - 1 >= startCAssault[i] - 20 && board[AssaultR[i]][AssaultC[i] - 1] == ' ') {
					AssaultC[i]--;
				}
				else {
					AssaultC[i] = -1;
					assaultDirection[i] = -1;
					AssaultR[i] = -1;
					startCAssault[i] = -1;
					isShooting =0;
				}
			}

			int isHit = 0;

			for (int j = 0; j < 9; j++) {
				int check = checkEnemyHit(AssaultR[i], AssaultC[i], enemyKill[j]);
				if (check == 1) {
					if (i >= 7) enemyKill[6].Health -= 7;
					enemyKill[j].Health -= 7;
					isHit = 1;

					if (enemyKill[j].Health <= 0) {
						enemyKill[j].isKillable = -1;
						enemyKill[j].Row = -100;
						enemyKill[j].Col = -100;
					}
				}
			}

			if (isHit == 1) {
				AssaultC[i] = -1;
				assaultDirection[i] = -1;
				AssaultR[i] = -1;
				startCAssault[i] = -1;
				isShooting = 0;
			}
		}

		if (AssaultR[i] != -1 && AssaultC[i] != -1) {
			board[AssaultR[i]][AssaultC[i]] = '*';
		}
	}





	/////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	// Laser shooting logic
	if (whatLaz <= 19 && isShooting == 1 && posXLaz >= 0 && posYLaz[0] >= 0) {
		int nextLazerY;

		// Decide nextY based on direction
		if (direction == 0) {
			nextLazerY = posYLaz[whatLaz] + 1;
		}
		else if (direction == 1) {
			nextLazerY = posYLaz[whatLaz] - 1;
		}

		// Make sure nextY is valid and space is empty
		if (nextLazerY >= 0 && nextLazerY < 1000 && board[posXLaz][nextLazerY] == ' ') {
			whatLaz++;
			posYLaz[whatLaz] = nextLazerY;

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
			for (int i = 0; i < 9; i++) {
				int check = checkEnemyHit(posXLaz, posYLaz[whatLaz], enemyKill[i]);
				if (check == 1) {
					if (i >= 7) enemyKill[6].Health -= 50;
					enemyKill[i].Health -= 50;
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

	//////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////

// Gun shooting logic


	if (isGunShooting == 1) {
		countGun++;
		if (countGun >= 25) {
			countGun = 0;
			isGunShooting = 0;
			isShooting = 0;
			posYGun = -1;
			posXGUn = -1;
		}
		
		// Decide next position based on direction
		else{
		if (direction == 0) {
			posYGun++;
		}
		else if (direction == 1) {
			posYGun--;
		
		}

		// Check if within board boundaries
	// Check if within board boundaries
		if (posXGUn >= 0 && posXGUn < 99 && posYGun >= 0 && posYGun <= 998 && posYGun >= 1) {


			// Collision: check for enemy hit
			int isEnemyHit = 0;
			for (int i = 0; i < 9; i++) {
				int check = checkEnemyHit(posXGUn, posYGun, enemyKill[i]);
				if (check == 1) {
					if (i >= 7) enemyKill[6].Health -= 30;
					enemyKill[i].Health -= 30;
					if (enemyKill[i].Health <= 0) {
						enemyKill[i].isKillable = -1;
						enemyKill[i].Row = -100;
						enemyKill[i].Col = -100;
					}
					isEnemyHit = 1;
					break;
				}
			}

			// If enemy hit, stop shooting
			if (isEnemyHit) {
				isShooting = 0;
				countGun = 0;
				isGunShooting = 0;
				posYGun = -1;
				posXGUn = -1;
			}
			// Draw bullet if no collision
			else if (board[posXGUn][posYGun] == ' ' && countGun < 25) {
				board[posXGUn][posYGun] = '*';
			}
			// Bullet hit a non-space object (e.g., wall), stop shooting
			else {
				isShooting = 0;

				countGun = 0;
				isGunShooting = 0;
				posYGun = -1;
				posXGUn = -1;
			}
		}
		else {
			// Bullet went out of board boundaries
			isShooting = 0;
			countGun = 0;
			isGunShooting = 0;;
			posYGun = -1;
			posXGUn = -1;
		}
	}

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
	;
	int top = dispR - 23;
	int bottom = dispR;

	for (int i = top - 1; i <= bottom + 1; i++) { // includes borders
		for (int j = dispC; j < dispC + 80; j++) {
			if (i == top - 1 || i == bottom + 1) { // top or bottom border
				cout << board[i][j];
			}
			else if (j == dispC || j == dispC + 80 - 1) { // side borders
				cout << board[i][j];
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

void checkCoinTouch(char board[100][1000], int pX, int pY, int pWidth, int pHeight, coin coins[], int& numCoinsP) {
	for (int a = 0; a < 10; a++) {
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


void checkHeartTouch(char board[100][1000], int pX, int pY, int pWidth, int pHeight, hearts Heart[], int& playerHp) {
	for (int a = 0; a < 3; a++) {
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
				playerHp += 500;
				break;
			}
		}

	}
}









///////////////////////////////////////
//Player Movement Functions

void moveRight(char board[100][1000], int& posJHero, int& posIHero, int widthHero, int heightHero, int LC[9], ladder ladders[], coin coins[], int& numCoinsP, hearts Heart[], int& playerHp) {
	int check = 1;
	// Check every cell in the column to the right of the player
	for (int i = posIHero; i >= posIHero - heightHero + 1; i--) {
		int lc_index = posIHero - i;
		// Convert to LC index (0=bottom)
		if (lc_index >= 0 && lc_index < 9) {
			if (board[i][LC[lc_index] + 1] != ' ') {
				check = 0;
				break;
			}
		}
	}
	int check2 = 1;
	for (int i = posIHero - 1; i >= posIHero - heightHero + 1; i--) {
		int lc_index = posIHero - i;  // Convert to LC index (0 to 8)
		if (lc_index >= 0 && lc_index < 9) {
			if (board[i][LC[lc_index] + 1] != ' ') {
				check2 = 0;
				break;
			}
		}
	}

	int isOnLadder = 0;
	for (int i = 0; i < 5; i++) {
		if (posJHero + widthHero >= ladders[i].Col - 1 && posJHero <= ladders[i].Col + ladders[i].length) {
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


	int check2ndCol = 1;
	for (int i = posIHero; i >= posIHero - heightHero + 1; i--) {
		int lc_index = posIHero - i;
		// Convert to LC index (0=bottom)
		if (lc_index >= 0 && lc_index < 9) {
			if (board[i][LC[lc_index] + 2] != ' ') {
				check2ndCol = 0;
				break;
			}
		}
	}
	if (board[posIHero][LC[0]] != ' ' && check2 && !check) {
		posIHero--;
		posJHero++;

		if (check2ndCol == 1) {
			posJHero++;
		}
	}
	// Only move if all checks passed AND we won't go out of bounds
	else if (check == 1 && posJHero + widthHero + 1 < 999) {
		posJHero++;
		if (check2ndCol == 1) {
			posJHero++;
		}
	}

	checkCoinTouch(board, posIHero, posJHero, widthHero, heightHero, coins, numCoinsP);

	checkHeartTouch(board, posIHero, posJHero, widthHero, heightHero, Heart, playerHp);
}

void moveLeft(char board[100][1000], int& posJHero, int& posIHero, int widthHero, int heightHero, int LC[9], ladder ladders[], coin coins[], int& numCoinsP, hearts Heart[], int& playerHp) {
	int check = 1;

	for (int i = posIHero; i >= posIHero - heightHero + 1; i--) {
		int lc_index = posIHero - i;
		if (lc_index >= 0 && lc_index < 9) {
			if (board[i][LC[lc_index] - 1] != ' ') {
				check = 0;
				break;
			}
		}
	}
	int check2 = 1;
	for (int i = posIHero - 1; i >= posIHero - heightHero + 1; i--) {
		int lc_index = posIHero - i;
		if (lc_index >= 0 && lc_index < 9) {
			if (board[i][LC[lc_index] - 1] != ' ') {
				check2 = 0;
				break;
			}
		}
	}

	int isOnLadder = 0;
	for (int i = 0; i < 5; i++) {
		if (posJHero >= ladders[i].Col - widthHero && posJHero <= ladders[i].Col + ladders[i].length + widthHero) {
			if (posIHero <= ladders[i].Row + 1 && posIHero - heightHero + 1 >= ladders[i].Row - ladders[i].length - 1) {
				isOnLadder = 1;
				break;
			}
		}
	}



	int check2ndCol = 1;
	for (int i = posIHero; i >= posIHero - heightHero + 1; i--) {
		int lc_index = posIHero - i;
		if (lc_index >= 0 && lc_index < 9) {
			if (board[i][LC[lc_index] - 2] != ' ') {
				check = 0;
				break;
			}
		}
	}


	if (isOnLadder == 1) {
		check = 1;
	}

	if (board[posIHero][LC[0]] != ' ' && check2 && !check) {
		posJHero--;
		posIHero--;
		if (check2ndCol == 1) {
			posJHero--;
		}

	}
	else if (check == 1 && posJHero - 1 >= 0) {
		posJHero--;
		if (check2ndCol == 1) {
			posJHero--;
		}

	}


	checkCoinTouch(board, posIHero, posJHero, widthHero, heightHero, coins, numCoinsP);
	checkHeartTouch(board, posIHero, posJHero, widthHero, heightHero, Heart, playerHp);


}

void jumpStraight(char board[100][1000], int& pX, int& pY, int pHeight, int pWidth, int& isJumping, player& Player, int gun, int animation, int dispR, int dispC, int LC[9], int LR[15], coin coins[], int& numCoinsP, Elevator elevator[], Enemy enemyKill[], int& DFireBallR, int& DFireBallC, int& chance, int& endR, int& endC, hearts Heart[], int& playerHp, int& posXLaz, int posYLaz[], int direction, int& whatlaz, int& isShooting, int isClicked, int& posXGun, int& posYGun, int blobStartC, int blobEndC, int& blobDirection, int& blobIsJumping, Enemy enemyUNKill[], int AssaultR[], int AssaultC[], int startCAssault[], int assaultDirection[], int rEggs[], int cEggs[], int& countE, int isTeleClicked, int startRLazer[], int rLazer[], int cLazer[], int& countLazBoss, int& isGunShooting, int& countGun , int & alienFrame) {


	scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
	clearMap(board, dispR, dispC);
	callObj(board, coins, enemyKill, Heart, isClicked, Player, enemyUNKill, isTeleClicked , alienFrame); // Call the function to draw the objects
	SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
	controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);

	addBorders(board, dispR, dispC);
	if (animation == 0 || animation == -1) {
		jumprightframe(board, pX, pY, LC, LR); // Draw the player jumping up
	}
	else if (animation == 1 || animation == -2) {
		jumpleftframe(board, pX, pY, LC, LR); // Draw the player jumping up
	}

	for (int i = 0; i < 5; i++) {
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


			EnemyPlayerCollision(enemyKill, 9, enemyUNKill, 19, Player);
			checkIsAssaultTaken(Player);
			checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
			checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
			ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
			scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
			clearMap(board, dispR, dispC);

			callObj(board, coins, enemyKill, Heart, isClicked, Player, enemyUNKill, isTeleClicked, alienFrame);
			SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
			controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);
			callDynamicObj(board, elevator, posXLaz, posYLaz, direction, whatlaz, isShooting, enemyKill, posXGun, posYGun, blobStartC, blobEndC, blobIsJumping, blobDirection, AssaultR, AssaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, Player, enemyUNKill, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun);
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


void FallStraight(char board[100][1000], int& pX, int& pY, int pHeight, int pWidth, int& isJumping, player& Player, int gun, int& isFalling, int animation, int dispR, int dispC, int LC[9], int LR[15], coin coins[], int& numCoinsP, Elevator elevator[], Enemy enemyKill[], int& DFireBallR, int& DFireBallC, int& chance, int& endR, int& endC, hearts Heart[], int& playerHp, int& posXLaz, int posYLaz[], int direction, int& whatlaz, int& isShooting, int isClicked, int& posXGun, int& posYGun, int blobStartC, int blobEndC, int& blobDirection, int& blobIsJumping, Enemy enemyUNKill[], int AssaultR[], int AssaultC[], int startCAssault[], int assaultDirection[], int rEggs[], int cEggs[], int& countE, int isTeleClicked, int startRLazer[], int rLazer[], int cLazer[], int& countLazBoss, int& isGunShooting, int& countGun , int & alienFrame) {
	for (; pX + 1 < 99; ) {
		if (pX - pHeight < 0) break;

		int check = 1; // Reset every fall attempt

		for (int j = pY + 3; j <= pY + 9; j++) {
			if (board[pX + 1][j] != ' ') {
				check = 0;
				break;
			}
		}

		if (check == 0) {
			break; // Landed on something, stop falling
		}

		pX++;

		EnemyPlayerCollision(enemyKill, 9, enemyUNKill, 17, Player);
		checkIsAssaultTaken(Player);
		checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
		checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
		ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
		scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
		clearMap(board, dispR, dispC);

		callObj(board, coins, enemyKill, Heart, isClicked, Player, enemyUNKill, isTeleClicked, alienFrame );
		SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
		controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);

		callDynamicObj(board, elevator, posXLaz, posYLaz, direction, whatlaz, isShooting, enemyKill, posXGun, posYGun, blobStartC, blobEndC, blobIsJumping, blobDirection, AssaultR, AssaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, Player, enemyUNKill, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun);
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


void jumpRight(char board[100][1000], int& pX, int& pY, int pHeight, int pWidth, int& isJumping, player& Player, int gun, int& isFalling, int& isWalking, int dispR, int dispC, int LC[9], int LR[15], coin coins[], int& numCoinsP, Elevator elevator[], Enemy enemyKill[], int& DFireBallR, int& DFireBallC, int& chance, int& endR, int& endC, hearts Heart[], int& playerHp, int& posXLaz, int posYLaz[], int direction, int& whatlaz, int& isShooting, int isClicked, int& posXGun, int& posYGun, int blobStartC, int blobEndC, int& blobDirection, int& blobIsJumping, Enemy enemyUNKill[], int AssaultR[], int AssaultC[], int startCAssault[], int assaultDirection[], int rEggs[], int cEggs[], int& countE, int isTeleClicked, int startRLazer[], int rLazer[], int cLazer[], int& countLazBoss, int& isGunShooting, int& countGun , int & alienFrame) {

	scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
	clearMap(board, dispR, dispC);
	SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
	controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);

	callObj(board, coins, enemyKill, Heart, isClicked, Player, enemyUNKill, isTeleClicked , alienFrame);
	addBorders(board, dispR, dispC);
	jumprightframe(board, pX, pY, LC, LR);

	for (int a = 0; a < 6; a++) {
		int canJump = 1; // 1 = can jump, 0 = cannot jump

		for (int row = pX; row >= pX - pHeight + 1; row--) {
			int lc_index = pX - row;
			if (lc_index >= 0 && lc_index < 9) {
				if (board[row][LC[lc_index] + 1] != ' ') {
					canJump = 0;
					break;
				}
			}
		}
		int canJump2ndCol = 1;
		for (int row = pX; row >= pX - pHeight + 1; row--) {
			int lc_index = pX - row;
			if (lc_index >= 0 && lc_index < 9) {
				if (board[row][LC[lc_index] + 2] != ' ') {
					canJump2ndCol = 0;
					break;
				}
			}
		}

		for (int col = pY; col < pY + pWidth; col++) {
			int lr_index = col - pY;
			if (lr_index >= 0 && lr_index < 15) {
				if (LR[lr_index] - 1 < 0 || (board[LR[lr_index] - 1][col] != ' ')) {
					canJump = 0;
					break;
				}
			}
		}

		for (int col = pY; col < pY + pWidth; col++) {
			int lr_index = col - pY;
			if (lr_index >= 0 && lr_index < 15) {
				if (LR[lr_index] - 2 < 0 || (board[LR[lr_index] - 2][col] != ' ')) {
					canJump2ndCol = 0;
					break;
				}
			}
		}


		if (canJump == 0) break;
		if (pY + pWidth >= 998) break;
		// Move diagonally up-right
		pX--;
		pY++;

		if (canJump2ndCol == 1) {
			pY++;
		}
		checkIsAssaultTaken(Player);
		EnemyPlayerCollision(enemyKill, 9, enemyUNKill, 17, Player);
		checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
		checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
		// Redraw everything
		scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
		ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
		clearMap(board, dispR, dispC);
		SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
		controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);


		callObj(board, coins, enemyKill, Heart, isClicked, Player, enemyUNKill, isTeleClicked, alienFrame);

		callDynamicObj(board, elevator, posXLaz, posYLaz, direction, whatlaz, isShooting, enemyKill, posXGun, posYGun, blobStartC, blobEndC, blobIsJumping, blobDirection, AssaultR, AssaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, Player, enemyUNKill, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun);
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
		for (int col = pY + 3; col <= pY + 9; col++) {
			if (pX + 1 < 100 && (board[pX + 1][col] == ' ')) {
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
			for (int row = pX - pHeight + 1; row <= pX; row++) {
				if (board[row][pY + pWidth + 1] != ' ') {
					canFallRight = 0;
					break;
				}
			}
		}
		else {
			canFallRight = 0;
		}

		if (canFallRight == 0) break;

		int canFallRight2ndCol = 1;
		if (pY + pWidth + 1 < 999) {
			for (int row = pX - pHeight; row <= pX + 1; row++) {
				if (board[row][pY + pWidth + 1] != ' ') {
					canFallRight2ndCol = 0;
					break;
				}
			}
		}
		else {
			canFallRight2ndCol = 0;
		}




		if (canFallRight == 1) {
			pX++;
			pY++;
		}
		else {
			pX++;
		}

		if (canFallRight2ndCol == 1) {
			pY++;
		}

		EnemyPlayerCollision(enemyKill, 9, enemyUNKill, 17, Player);
		checkIsAssaultTaken(Player);
		checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
		checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
		ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);

		// Redraw everything
		scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
		clearMap(board, dispR, dispC);


		callObj(board, coins, enemyKill, Heart, isClicked, Player, enemyUNKill, isTeleClicked, alienFrame );
		SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
		controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);


		callDynamicObj(board, elevator, posXLaz, posYLaz, direction, whatlaz, isShooting, enemyKill, posXGun, posYGun, blobStartC, blobEndC, blobIsJumping, blobDirection, AssaultR, AssaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, Player, enemyUNKill, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun);
		addBorders(board, dispR, dispC);
		jumprightframe(board, pX, pY, LC, LR);

		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, Player.gun);
		Clear_LoadMap(board, dispR, dispC);
		isFalling = 1;
	}
	checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
	checkIsAssaultTaken(Player);
	checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
	ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
	isJumping = 0;
	isFalling = 0;
	isWalking = 0;
}
void jumpLeft(char board[100][1000], int& pX, int& pY, int pHeight, int pWidth, int& isJumping, player& Player, int gun, int& isFalling, int& isWalking, int dispR, int dispC, int LC[9], int LR[15], coin coins[], int& numCoinsP, Elevator elevator[], Enemy enemyKill[], int& DFireBallR, int& DFireBallC, int& chance, int& endR, int& endC, hearts Heart[], int& playerHp, int& posXLaz, int posYLaz[], int direction, int& whatlaz, int& isShooting, int isClicked, int& posXGun, int& posYGun, int blobStartC, int blobEndC, int& blobDirection, int& blobIsJumping, Enemy enemyUNKill[], int AssaultR[], int AssaultC[], int startCAssault[], int assaultDirection[], int rEggs[], int cEggs[], int& countE, int isTeleClicked, int startRLazer[], int rLazer[], int cLazer[], int& countLazBoss, int& isGunShooting, int& countGun, int & alienFrame ) {

	scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
	clearMap(board, dispR, dispC);


	callObj(board, coins, enemyKill, Heart, isClicked, Player, enemyUNKill, isTeleClicked, alienFrame);

	addBorders(board, dispR, dispC);
	jumpleftframe(board, pX, pY, LC, LR);


	for (int a = 0; a < 6; a++) {

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
				if (board[i][LC[lc_index] - 1] != ' ') {
					check = 0;
					break;
				}
			}
		}

		int check2ndCol = 0;
		for (int i = pX; i >= pX - pHeight + 1; i--) {
			int lc_index = pX - i;  // Convert to LC index (0 to 8)
			if (lc_index >= 0 && lc_index < 9) {
				if (board[i][LC[lc_index] - 2] != ' ') {
					check2ndCol = 0;
					break;
				}
			}
		}

		if (pX - pHeight < 1) break;
		if (pY - 1 < 1) break;

		if (check == 0) break;


		pX--;
		pY--;

		if (check2ndCol == 0) pY--;

		checkIsAssaultTaken(Player);
		EnemyPlayerCollision(enemyKill, 9, enemyUNKill, 17, Player);
		checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
		checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
		ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
		scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
		clearMap(board, dispR, dispC);

		callObj(board, coins, enemyKill, Heart, isClicked, Player, enemyUNKill, isTeleClicked , alienFrame);

		callDynamicObj(board, elevator, posXLaz, posYLaz, direction, whatlaz, isShooting, enemyKill, posXGun, posYGun, blobStartC, blobEndC, blobIsJumping, blobDirection, AssaultR, AssaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, Player, enemyUNKill, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun);
		addBorders(board, dispR, dispC);
		jumpleftframe(board, pX, pY, LC, LR);

		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, Player.gun);
		Clear_LoadMap(board, dispR, dispC);
		isJumping = 1;

	}

	for (; pX + 1 < 98 && board[pX + 1][pY] == ' ' && pY > 1;) {
		int checkDown = 1;
		for (int j = pY + 3; j <= pY + 9; j++) {

			if (board[pX + 1][j] != ' ') {
				checkDown = 0;
				break;
			}
		}

		int checkLeft = 1;
		for (int i = pX; i >= pX - pHeight + 1; i--) {
			int lc_index = pX - i;  // Convert to LC index (0 to 8)
			if (lc_index >= 0 && lc_index < 9) {
				if (board[i][LC[lc_index] - 1] != ' ') {
					checkLeft = 0;
					break;
				}
			}
		}



		int check2ndCol = 1;

		for (int i = pX; i >= pX - pHeight + 1; i--) {
			int lc_index = pX - i;  // Convert to LC index (0 to 8)
			if (lc_index >= 0 && lc_index < 9) {
				if (board[i][LC[lc_index] - 2] != ' ') {
					check2ndCol = 0;
					break;
				}
			}
		}
		if (pX - pHeight <= 1) break;

		if (pY - 1 <= 1) break;
		if (checkDown == 0 || checkLeft == 0) break;

		if (checkDown && checkLeft) {
			pX++;
			pY--;
		}

		if (check2ndCol == 1 && checkDown && checkLeft) {
			pY--;
		}


		checkIsAssaultTaken(Player);
		EnemyPlayerCollision(enemyKill, 9, enemyUNKill, 17, Player);
		checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
		checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
		ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
		scroll(board, pY, pX, Player.maxWidth, Player.maxHeight, dispR, dispC);
		clearMap(board, dispR, dispC);

		callObj(board, coins, enemyKill, Heart, isClicked, Player, enemyUNKill, isTeleClicked, alienFrame );

		callDynamicObj(board, elevator, posXLaz, posYLaz, direction, whatlaz, isShooting, enemyKill, posXGun, posYGun, blobStartC, blobEndC, blobIsJumping, blobDirection, AssaultR, AssaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, Player, enemyUNKill, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun);
		SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
		controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);

		addBorders(board, dispR, dispC);
		jumpleftframe(board, pX, pY, LC, LR);

		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, Player.gun);
		Clear_LoadMap(board, dispR, dispC);
		isFalling = 1;

	}
	checkIsAssaultTaken(Player);
	checkCoinTouch(board, pX, pY, pWidth, pHeight, coins, numCoinsP);
	checkHeartTouch(board, pX, pY, pWidth, pHeight, Heart, playerHp);
	ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
	isWalking = 0;
	isJumping = 0, isFalling = 0; // Reset jumping and falling states after landing

}









//////////////////////////////////////////////////////////
////////////////////////Shooting/////////////////////////



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




void shootLazer(int shootR, int shootC, int& posXLaz, int posYlaz[], int direction) {

	posXLaz = shootR;

	if (direction == 0) posYlaz[0] = shootC + 1;
	else posYlaz[0] = shootC - 1;
}


void shootGUn(int shootR, int shootC, int& posXGun, int& posYGun, int direction) {
	posXGun = shootR;
	if (direction == 0) posYGun = shootC + 1;
	else posYGun = shootC - 1;
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



		////////////////Guns//////////////
		int posXGun = -1;
		int posYGun = -1;
		int isGunShooting = 0, countGun = 0;


		int posXLaz = -1;
		int posYLaz[20] = { -1 };
		int whatLaz = 0, direction = -1;


		int HiddenladderButtonClicked = 0, btnrow = 98, btnmaxR = 98 - 15, btnCol = 290, btnmaxC = 290 + 10;



		int assaultR[20] = { -1 };
		int assaultC[20] = { -1 };
		int assaultDirection[20] = { -1 };
		int startCAssault[20] = { -1 };

		int gun = Player.gun;

		//////////////TELEPORTER/////////////
		int isClicked1 = 0;
		int isClicked2 = 0;
		int teleportX = 98, teleportY = 680, teleport2X = 98, teleport2Y = 702;

		/////////////////////////////////////

		///////////Ladders////////////
		ladder ladders[5];
		ladders[0].Row = 88;
		ladders[0].Col = 19;
		ladders[0].length = 18;


		ladders[1].Row = 70;
		ladders[1].Col = 51;
		ladders[1].length = 21;


		//HIDDEN LADDER
		ladders[2].Row = 98;
		ladders[2].Col = 134;
		ladders[2].length = 28;

		ladders[3].Row = 50;
		ladders[3].Col = 400;
		ladders[3].length = 21;

		ladders[4].Row = 50;
		ladders[4].Col = 600;
		ladders[4].length = 21;


		////////////Coins/////////////
		coin coins[10];
		intializeCoin(board, coins[0], 49, 2);
		intializeCoin(board, coins[1], 69, 112);
		intializeCoin(board, coins[2], 49, 200);

		intializeCoin(board, coins[3], 29, 685);
		intializeCoin(board, coins[6], 29, 675);


		intializeCoin(board, coins[4], 94, 460);
		intializeCoin(board, coins[5], 98, 515);

		intializeCoin(board, coins[7], 98, 655);

		intializeCoin(board, coins[8], 98, 265);
		intializeCoin(board, coins[9], 69, 260);


		/////////////Hearts////////////////
		hearts heart[3];

		intializeHeart(board, heart[0], 95, 195);

		intializeHeart(board, heart[1], 50, 350);

		intializeHeart(board, heart[2], 98, 640);


		/////////////Elevators//////////////
		Elevator elevator[3];

		intializeElevator(board, elevator, 0, 70, 170, 70, 43, 170, 170, 0, 1); // Vertical  


		intializeElevator(board, elevator, 1, 95, 430, 95, 95, 430, 478 - 10, 1, 1);

		intializeElevator(board, elevator, 2, 99, 350, 99, 20, 350, 350, 0, 1); // Vertical 2 




		////////////Enemies//////////////////

		int blobStartC = 550, blobEndC = 635, blobIsJumping = 0, blobDirection = 1;
		Enemy enemyKill[9];
		intializeEnemy(enemyKill, 0, 49, 12, 1, 11, 13, 100, 10); //Devil / done

		intializeEnemy(enemyKill, 1, 98, 672, 1, 18, 1, 1, 0); //Hittable door / done 

		intializeEnemy(enemyKill, 2, 98, 600, 1, 6, 12, 150, 15); //Blob / done 

		intializeEnemy(enemyKill, 3, 50, 430, 1, 15, 10, 70, 30); //Skeleton  /done 

		intializeEnemy(enemyKill, 4, 69, 280, 1, 10, 40, 150 , 45);// //ALIEN
		int alienFrame = 0;
		//row = 49 , col = 190
		intializeEnemy(enemyKill, 5, -10, -10, 1, 10, 12, 100, 20);//Alien NOT 

		intializeEnemy(enemyKill, 6, 82, 850, 1, 10, 12, 500, 30);//Boss Done

		intializeEnemy(enemyKill, 7, 98, 900, 1, 15, 10, 250, 50);//Skeleton1 boss minion Done

		intializeEnemy(enemyKill, 8, 98, 800, 1, 15, 10, 250, 50);//Skeleton2 boss minion Done

		//Width  = 10 , col is most right one 
		//height = 23 , row is the top one
		//startc = 100 , endC = 295

		drawTerrain(board, 70, 134 + 15, 2, 178);
		Enemy enemyUnKill[21];
		intializeEnemy(enemyUnKill, 0, 98 - 23, 135 + 10, 0, 23, 10, 250, 3);//Crystal 1 done

		intializeEnemy(enemyUnKill, 1, 98 - 23, 160 + 20, 0, 23, 10, 250, 3);//Crystal 2 done

		intializeEnemy(enemyUnKill, 2, 98 - 23, 185 + 20, 0, 23, 10, 250, 3);//Crystal 3 done

		intializeEnemy(enemyUnKill, 3, 98 - 23, 210 + 20, 0, 23, 10, 250, 3);//Crystal 4 done

		intializeEnemy(enemyUnKill, 4, 98 - 23, 235 + 20, 0, 23, 10, 250, 3);//Crystal 5 done




		intializeEnemy(enemyUnKill, 5, 30, 520, 0, 4, 8, 250, 25);// Bird done



		intializeEnemy(enemyUnKill, 6, 98, 430, 0, 2, 2, 250, 5); //Spike 1 done
		intializeEnemy(enemyUnKill, 7, 98, 436, 0, 2, 2, 250, 5); //Spike 2 done
		intializeEnemy(enemyUnKill, 8, 98, 442, 0, 2, 2, 250, 5); //Spike 3 done
		intializeEnemy(enemyUnKill, 9, 98, 448, 0, 2, 2, 250, 5); //Spike 4 done
		intializeEnemy(enemyUnKill, 10, 98, 454, 0, 2, 2, 250, 5); //Spike 5 done
		intializeEnemy(enemyUnKill, 11, 98, 460, 0, 2, 2, 250, 5); //Spike 6  done
		intializeEnemy(enemyUnKill, 12, 98, 466, 0, 2, 2, 250, 5); //Spike 7 done
		intializeEnemy(enemyUnKill, 13, 98, 472, 0, 2, 2, 250, 5); //Spike 8 done
		intializeEnemy(enemyUnKill, 14, 98, 478, 0, 2, 2, 250, 5); //Spike 9 done
		intializeEnemy(enemyUnKill, 15, 98, 840, 0, 2, 2, 250, 1); //Spike 10 done
		intializeEnemy(enemyUnKill, 16, 98, 875, 0, 2, 2, 250, 1); //Spike 11 done



		intializeEnemy(enemyUnKill, 17, 98, 530, 0, 2, 2, 250, 5); //2nd place Spike 10
		intializeEnemy(enemyUnKill, 18, 98, 535, 0, 2, 2, 250, 5); //2nd place Spike 11

		intializeEnemy(enemyUnKill, 19, 69, 250, 0, 2, 2, 250, 5); //2nd place Spike 12 done 
		intializeEnemy(enemyUnKill, 20, 98, 110, 0, 2, 2, 250, 5); //2nd place Spike 13 done



		enemyKill[6].direction = 1;
		enemyKill[7].direction = 1;
		enemyKill[8].direction = 1;

		int DFireBallR = -1, DFireBallC = -1, chance = -1, endR = -1, endC = -1; //intializeValues for devil shooting



		//20 frames , could drop every count % 4 ==0; so its 5 eggs max
		int rEggs[5] = { -1 };
		int cEggs[5] = { -1 };
		int countE = 0;//Values for bird shooting


		///////////////////////////////////////////////////////////////
		//boss shooting 
		int startRLazer[10] = { -1 }; int rLazer[10] = { -1 }; int cLazer[10] = { -1 }; int countLazBoss = 0;






		int animation = 0, frame = 1, ResetFrame = 0;
		scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
		clearMap(board, dispR, dispC);
		callObj(board, coins, enemyKill, heart, HiddenladderButtonClicked, Player, enemyUnKill, isClicked2 , alienFrame);
		callDynamicObj(board, elevator, posXLaz, posYLaz, direction, whatLaz, isShooting, enemyKill, posXGun, posYGun, blobStartC, blobEndC, blobIsJumping, blobDirection, assaultR, assaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, Player, enemyUnKill, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun);
		//Devil's shooting mechanism
		SpawnFireBall(enemyKill[0], DFireBallR, DFireBallC, chance, endR, endC);
		controlFireBall(board, DFireBallR, DFireBallC, chance, endR, endC, Player);
		addBorders(board, dispR, dispC);
		drawPlayerRightFrame1(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
		system("cls");
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, Player.gun);
		Clear_LoadMap(board, dispR, dispC);
		FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked, posXGun, posYGun, blobStartC, blobEndC, blobDirection, blobIsJumping, enemyUnKill, assaultR, assaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, isClicked2, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun, alienFrame );
		int isWon = 0;

		for (; !isWon;) {
			if (Player.Health >= 999) Player.Health = 999;
			gun = Player.gun;
			checkIsAssaultTaken(Player);
			scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
			EnemyPlayerCollision(enemyKill, 9, enemyUnKill, 17, Player);
			checkCoinTouch(board, Player.Row, Player.Col, Player.maxWidth, Player.maxHeight, coins, Player.coins);
			checkHeartTouch(board, Player.Row, Player.Col, Player.maxWidth, Player.maxHeight, heart, Player.Health);
			FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked, posXGun, posYGun, blobStartC, blobEndC, blobDirection, blobIsJumping, enemyUnKill, assaultR, assaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, isClicked2, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun, alienFrame );
			ElevatePlayer(board, dispR, dispC, Player.Row, Player.Col, elevator, 2);
			clearMap(board, dispR, dispC);
			callObj(board, coins, enemyKill, heart, HiddenladderButtonClicked, Player, enemyUnKill, isClicked2 , alienFrame);
			callDynamicObj(board, elevator, posXLaz, posYLaz, direction, whatLaz, isShooting, enemyKill, posXGun, posYGun, blobStartC, blobEndC, blobIsJumping, blobDirection, assaultR, assaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, Player, enemyUnKill, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun);
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

				for (int i = 0; i < 5; i++) {
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
						FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked, posXGun, posYGun, blobStartC, blobEndC, blobDirection, blobIsJumping, enemyUnKill, assaultR, assaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, isClicked2, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun , alienFrame);
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
						FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked, posXGun, posYGun, blobStartC, blobEndC, blobDirection, blobIsJumping, enemyUnKill, assaultR, assaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, isClicked2, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun, alienFrame );
						isWalking = 1;
					}
				}
				else if (key == 'w' || key == 'W' || key == ' ') {
					if (isOnLadder == 0) {
						if (isWalking == 0) {
							if (Player.Row - Player.maxHeight > 0) {
								jumpStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked, posXGun, posYGun, blobStartC, blobEndC, blobDirection, blobIsJumping, enemyUnKill, assaultR, assaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, isClicked2, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun, alienFrame );
								scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
								FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked, posXGun, posYGun, blobStartC, blobEndC, blobDirection, blobIsJumping, enemyUnKill, assaultR, assaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, isClicked2, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun , alienFrame);
								scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
							}
						}
						else if (isWalking == 1) {
							jumpRight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, isWalking, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked, posXGun, posYGun, blobStartC, blobEndC, blobDirection, blobIsJumping, enemyUnKill, assaultR, assaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, isClicked2, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun , alienFrame);
							scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
							FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked, posXGun, posYGun, blobStartC, blobEndC, blobDirection, blobIsJumping, enemyUnKill, assaultR, assaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, isClicked2, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun, alienFrame );
							scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
							isWalking = 0;
						}
						else if (isWalking == 2) {
							jumpLeft(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, isWalking, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked, posXGun, posYGun, blobStartC, blobEndC, blobDirection, blobIsJumping, enemyUnKill, assaultR, assaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, isClicked2, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun , alienFrame);
							scroll(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, dispR, dispC);
							FallStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player, gun, isFalling, animation, dispR, dispC, lastCellCol, lastCellRow, coins, Player.coins, elevator, enemyKill, DFireBallR, DFireBallC, chance, endR, endC, heart, Player.Health, posXLaz, posYLaz, direction, whatLaz, isShooting, HiddenladderButtonClicked, posXGun, posYGun, blobStartC, blobEndC, blobDirection, blobIsJumping, enemyUnKill, assaultR, assaultC, startCAssault, assaultDirection, rEggs, cEggs, countE, isClicked2, startRLazer, rLazer, cLazer, countLazBoss, isGunShooting, countGun, alienFrame );
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
						if (animation == 0 || animation == -1) {
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
						if (animation == 0 || animation == -1) {
							isShooting = 1;
							countGun = 0;
							isGunShooting = 1;
							shootGUn(Player.shootR, Player.shootC, posXGun, posYGun, 0);
							direction = 0;
							Player.ammo[1]--;
						}
						else if (animation == 1 || animation == -2) {
							isShooting = 1;
							isGunShooting = 1;
							countGun = 0;
							shootGUn(Player.shootR, Player.shootC, posXGun, posYGun, 1);
							direction = 1;
							Player.ammo[1]--;
						}
					}
					else if (Player.ammo[2] >= 1 && gun == 2) {

						int firstFreeBullet = -1;
						for (int i = 0; i < 20; i++) {
							if (assaultR[i] == -1) firstFreeBullet = i;
						}
						if (firstFreeBullet != -1) {

							Player.ammo[2]--;
							if (animation == 0 || animation == -1) {
								assaultDirection[firstFreeBullet] = 0;
								assaultR[firstFreeBullet] = Player.shootR;
								assaultC[firstFreeBullet] = Player.shootC + 1;
								startCAssault[firstFreeBullet] = Player.shootC + 1;
							}
							else if (animation == 1 || animation == -2) {
								assaultDirection[firstFreeBullet] = 1;
								assaultR[firstFreeBullet] = Player.shootR;
								assaultC[firstFreeBullet] = Player.shootC - 1;
								startCAssault[firstFreeBullet] = Player.shootC - 1;

							}
						}

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
				else if ((key == 'E ' || key == 'e') && (Player.Row - 8 <= teleportX + 1 && Player.Row >= teleportX - 11 && Player.Col + 14 >= teleportY - 2 && Player.Col <= teleportY + 19)) {


					int coins = Player.coins;
					int row = teleportX;
					int col = teleportY;
					if (isClicked1 == 0) {
						if (coins >= 250) {
							isClicked1 = 1;
							board[row - 16][col + 4] = 'B';
							board[row - 16][col + 5] = 'O';
							board[row - 16][col + 6] = 'S';
							board[row - 16][col + 7] = 'S';
							board[row - 16][col + 8] = ' ';
							board[row - 16][col + 9] = 'R';
							board[row - 16][col + 10] = 'O';
							board[row - 16][col + 11] = 'O';
							board[row - 16][col + 12] = 'M';
							Player.Row = teleport2X - 5;
							Player.Col = teleport2Y + 20;
							Player.coins -= 250; // Deduct the cost of teleportation

						}


						else {
							//isOnTelep
							board[row - 16][col + 4] = 'L';
							board[row - 16][col + 5] = 'A';
							board[row - 16][col + 6] = 'C';
							board[row - 16][col + 6] = 'K';
							board[row - 16][col + 7] = 'I';
							board[row - 16][col + 8] = 'N';
							board[row - 16][col + 9] = 'G';
							board[row - 16][col + 10] = ' ';
							board[row - 16][col + 11] = 'C';
							board[row - 16][col + 12] = 'O';
							board[row - 16][col + 13] = 'I';
							board[row - 16][col + 14] = 'N';
							board[row - 16][col + 15] = 'S';
						}

					}
				}


				if (currentLadder != 2 || (HiddenladderButtonClicked == 1 && currentLadder == 2)) {
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
			}
			else {
				isWalking = 0;
				if (animation == 0) animation = -1;
				else if (animation == 1) animation = -2;
			}

			checkIsEnemyDead(enemyKill);
		}
		if (isWon == 1) {
			system("cls");
			winScreen();
		}
		else {
			system("cls");
			gameOverScreen();
		}
	}
	else return 0;
}