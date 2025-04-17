#include <iostream>
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




int main() {
	int width = 80, height = 24; // Lets keep the width and height stored as variables incase we want to change them later
	char board[24][80]; // Border for the game frame

	player Player;

	initializePlayerValues(Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, Player.Health, Player.coins, Player.gun, Player.ammo, Player.maxAmmo);
	initializeBoard(board); // Initialize the board

	char gun[] = "Pistol";
	dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun); // Display the bar first
	drawPlayerRightFrame1(board, Player.Row, Player.Col); //intialize player draw
	dispBoard(board); // Display the board


	//Intialize the movement vaiables
	int isWalking = 0, isJumping = 0, isClimbing = 0, isShooting = 0, isReloading = 0;
	//Iswalking =0 standing ,isWalking = 1 walkign right , isWalking = 2 walking left
	//isJumping = 0 standing , isJumping = 1 jumping (player shouldnt be able to move if isJumping = 1)
	//isClimbing = 0 standing , isClimbing = 1 climbing (player shouldnt be able to move left or right if isClimbing = 1)
	//isShooting = 0 not shooting , isShooting = 1 shooting (player shouldnt be able to climb if isshooting = 1)
	//isReloading = 0 not reloading , isReloading = 1 reloading (player shouldnt be able to jump or shoot if isReloading = 1)



}
