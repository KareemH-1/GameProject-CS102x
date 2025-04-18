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
	int maxHeight = 11, maxWidth = 9; //Max height and width
	int Health;
	int coins; //Either coins or Level , until decided i will leave it as coins

	int gun; //Either 1 for gun (bullets) or 2 for Lazerbeam (lazer)
	int ammo, maxAmmo; // (ammo/maxAmmo) , max ammo could be 24 for gun , (maxammo == 1) for lazerbeam
	int Reload[2] = { 1 , 3 }; //coolDown[0] for gun , coolDown[1] for lazerbeam
};

void initializePlayerValues(int& Row, int& Col, int& maxHeight, int& maxWidth, int& Health, int& coins, int& gun, int& ammo, int& maxAmmo) {
	Row = 22;
	Col = 3;
	maxHeight = 1;
	maxWidth = 1;
	Health = 100;
	coins = 0;
	gun = 1; //Start with gun
	ammo = 24; //Full ammo on start
	maxAmmo = 24; //max ammo
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

	system("cls");

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



void drawPlayerRightFrame1(char board[24][80], int Row, int Col) {

	//left leg
	board[Row][Col] = '/';
	board[Row - 1][Col + 1] = '/';
	board[Row - 2][Col + 2] = '/';

	//right leg
	board[Row - 2][Col + 3] = '\\';
	board[Row - 1][Col + 4] = '\\';
	board[Row][Col + 5] = '\\';

	//body
	board[Row - 3][Col + 2] = '|'; board[Row - 3][Col + 3] = '|';
	board[Row - 4][Col + 2] = '|'; board[Row - 4][Col + 3] = '|';
	board[Row - 5][Col + 2] = '|'; board[Row - 5][Col + 3] = '|';
	board[Row - 6][Col + 2] = '|'; board[Row - 6][Col + 3] = '|';

	//Left arm
	board[Row - 4][Col] = '/';
	board[Row - 5][Col + 1] = '/';

	//Right arm
	board[Row - 5][Col + 4] = '\\';

	//Head
	board[Row - 9][Col + 1] = '/';
	board[Row - 8][Col] = '|';
	board[Row - 7][Col + 1] = '\\';
	board[Row - 7][Col + 2] = '_'; board[Row - 7][Col + 3] = '_';
	board[Row - 10][Col + 2] = '_'; board[Row - 10][Col + 3] = '_';
	board[Row - 7][Col + 4] = '/';
	board[Row - 8][Col + 4] = '.';
	board[Row - 8][Col + 5] = ')';
	board[Row - 9][Col + 4] = '\\';
}

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
		if (i == 0 || i == 23) {
			cout << blue << board[i];
			cout << reset << endl;
		}
		else {
			for (int j = 0; j < 80; j++) {
				if (j == 0 || j == 79) {
					cout << blue << board[i][j] << reset;
				}
				else {
					cout << board[i][j];
				}
			}
			cout << endl;
		}
	}
}

void moveRight(char board[24][80] , int posJHero , int posIHero , int widthHero){
	if (posJHero +(widthHero-1) + 1 < 79 && board[posIHero][posJHero +(widthHero-1) + 1] == ' ') posJHero++;
}

void moveLeft(char board[24][80], int posJHero, int posIHero) {
	if (posJHero - 1 > 0 && board[posIHero][posJHero -1] == ' ' ) posJHero--;
}

void gravityAfterJump(char board[24][80], int& posJHero, int& posIHero, int direction, player Player, char gun[]) {

	//Fall straight
	if (direction == 0) {
		for (; posIHero + 1 < 23 && board[posIHero + 1][posJHero] == ' ';) {
			posIHero++;
			clearMap(board);
			addBorders(board);
			drawPlayerRightFrame1(board, posIHero, posJHero);
			dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun); // Display the bar first
			Clear_LoadMap(board); // Clear the screen and load the map

		}
	}
}

void jump( char board[24][80] ,int &posJHero , int& posIHero ,int maxHeight , int & isWalking , int& isJumping , player Player , char gun[]) {
	
	if (isWalking == 0) {
		// Straight jump
		for (int i = 0; i < 3; i++) {
			if (posIHero - (maxHeight - 1) - 1 > 0 && board[posIHero - (maxHeight - 1) - 1][posJHero] == ' ') {
				posIHero--;
				clearMap(board);
				addBorders(board);
				drawPlayerRightFrame1(board, posIHero, posJHero);
				dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun); // Display the bar first
				Clear_LoadMap(board); // Clear the screen and load the map

				isJumping = 1;
			}
			else break;
		}

		gravityAfterJump(board, posJHero, posIHero, 0 , Player , gun);
	}
}

void gravity() {

}



int main() {
	char board[24][80]; // Border for the game frame

	player Player;

	initializePlayerValues(Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, Player.Health, Player.coins, Player.gun, Player.ammo, Player.maxAmmo);
	initializeBoard(board); // Initialize the board

	char gun[] = "Pistol";
	dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun); // Display the bar first
	
	//Intialize the movement vaiables
	int isWalking = 0, isJumping = 0 ,isFalling = 0, isClimbing = 0, isShooting = 0, isReloading = 0 ;
	//Iswalking =0 standing ,isWalking = 1 walkign right , isWalking = 2 walking left
	//isJumping = 0 standing , isJumping = 1 jumping (player shouldnt be able to move if isJumping = 1)
	//isClimbing = 0 standing , isClimbing = 1 climbing (player shouldnt be able to move left or right if isClimbing = 1)
	//isFalling = 0  not falling , isFalling = 1 falling (player shouldnt be able move or jump if isFalling = 1)
	//isShooting = 0 not shooting , isShooting = 1 shooting (player shouldnt be able to climb if isshooting = 1)
	//isReloading = 0 not reloading , isReloading = 1 reloading (player shouldnt be able to jump or shoot if isReloading = 1)
	
	int isWon = 0;
	for (; !isWon;) {
		clearMap(board);
		addBorders(board);
		drawPlayerRightFrame1(board, Player.Row, Player.Col);
		dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun); // Display the bar first
		Clear_LoadMap(board); // Clear the screen and load the map

		if (_kbhit()) {
			char key = _getch();
			if ((key == 'a' || key == 'A') && isClimbing == 0 && isFalling ==0){
				moveLeft(board, Player.Col, Player.Row);
				isWalking = 2;
			}
			else if ((key == 'd' || key == 'D' )&& isClimbing == 0 && isFalling ==0) {
				moveRight( board, Player.Col, Player.Row, Player.maxWidth);
				isWalking = 1;
			}
			else if ((key == 'w' || key == 'W') && isJumping == 0 && isFalling == 0 && isReloading == 0) { 

			}
		}
	}


}
