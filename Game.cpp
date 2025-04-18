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

	int gun; //Either 1 for gun (bullets) or 2 for Lazerbeam (lazer)
	int ammo, maxAmmo; // (ammo/maxAmmo) , max ammo could be 24 for gun , (maxammo == 1) for lazerbeam
	int Reload[2] = { 1 , 3 }; //coolDown[0] for gun , coolDown[1] for lazerbeam
};

struct Enemy{
	int Row, Col; //Position
	int maxHeight = 1, maxWidth = 1; //Max height and width
	int Health;
};
void showMainMenu(int& choice) {
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


void initializePlayerValues(int& Row, int& Col, int& maxHeight, int& maxWidth, int& Health, int& coins, int& gun, int& ammo, int& maxAmmo) {
	Row = 22;
	Col = 3;
	maxHeight = 9;
	maxWidth = 15;
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



void drawEnemyBirdLeft(char board[24][80], int row, int col) {
	//base
	board[row][col+2] = '`';
	board[row][col + 3] = '-';
	board[row][col + 4] = '-';
	board[row][col + 5] = '-';
	board[row][col + 6] = '-';
	board[row][col + 7] = '\'';

	//right
	board[row-1][col + 7] = '_';
	board[row-1][col + 6] = '.';
	board[row-1][col + 8] = '>';

	//top
	board[row-2][col + 7] = '_';
	board[row-2][col + 6] = '_';
	board[row-2][col + 5] = '_';
	board[row-2][col + 4] = ')';
	board[row-2][col + 3] = ' ';	
	board[row-3][col+3] ='_';
	board[row-3][col+2] = '_';

	//left
	board[row-2][col + 2] = 'o';
	board[row-2][col + 1] = '(';
	board[row-1][col + 1] = '(';
	board[row-2][col ] = '<';
}

void drawEnemyBirdRight(char board[24][80], int row, int col) {
	//base
	board[row][col+1] = '\'';
	board[row][col + 2] = '-';
	board[row][col + 3] = '-';
	board[row][col + 4] = '-';
	board[row][col + 5] = '-';
	board[row][col + 6] = '`';

	//Right
	board[row-1][col+7] = ')';
	board[row-2][col+7] = ')';
	board[row-2][col+8] = '>';
	board[row-2][col+6] = 'o';

	//top

	board[row-3][col+6] = '_';
	board[row-3][col+5] = '_';
	board[row-2][col+4] ='(';
	board[row-2][col+3] ='_';
	board[row-2][col+2] ='_';
	board[row-2][col+1] ='_';

	//Left
	board[row-1][col] = '<';
	board[row-1][col+1] = '_';
	board[row-1][col+2] = '.';
}


void drawPlayerRightFrame1(char board[24][80], int row, int col) {
    //left arm
	board[row-3][col]='/';
	board[row-4][col+1]='/';
	board[row-5][col+2]='/';
	
	//left leg
	board[row][col+3]='|';
	board[row-1][col+3]='|';
	board[row][col+4]='_';
    board[row][col+5]='|';
	board[row-1][col+5]='|';
	
	//right leg
	board[row][col+7]='|';
	board[row][col+8]='_';
	board[row][col+9]='|';
	board[row-1][col+7]='|';
	board[row-1][col+9]='|';
	
	
	//right arm
	board[row-4][col+10]='-';
	board[row-4][col+11]='-';
	board[row-4][col+12]='-';
	board[row-4][col+13]='|';
	board[row-4][col+14]='/';
	board[row-5][col+14]='\\';
	board[row-5][col+13]='|';
	board[row-5][col+12]='-';
	board[row-5][col+11]='-';
	board[row-5][col+10]='-';
	
//body

board[row-2][col+3]='\\';
board[row-2][col+4]='_';
board[row-2][col+5]='_';
board[row-2][col+6]='_';
board[row-2][col+7]='_';
board[row-2][col+8]='_';
board[row-2][col+9]='/';
board[row-3][col+9]='|';
board[row-4][col+9]='|';
board[row-5][col+9]='|';
board[row-3][col+3]='|';
board[row-4][col+3]='|';
board[row-5][col+3]='|';
board[row-5][col+4]='-';
board[row-5][col+5]='-';
board[row-5][col+6]='v';
board[row-5][col+7]='-';
board[row-5][col+8]='-';

	


//head

board[row-6][col+4]='\\';
board[row-7][col+4]='/';
board[row-8][col+5]='_';
board[row-8][col+6]='_';
board[row-8][col+7]='_';
board[row-7][col+8]=')';
board[row-7][col+5]='(';
board[row-7][col+6]='.';
board[row-7][col+7]='.';
board[row-6][col+8]='/';
board[row-6][col+7]='-';
board[row-6][col+6]='-';
board[row-6][col+5]='-';





}



void DrawPlayerLeftFrame1(char board[24][80], int row, int col){

//head

board[row-6][col+4]='\\';
board[row-7][col+4]='/';
board[row-8][col+5]='_';
board[row-8][col+6]='_';
board[row-8][col+7]='_';
board[row-7][col+8]=')';
board[row-7][col+5]='(';
board[row-7][col+6]='.';
board[row-7][col+7]='.';
board[row-6][col+8]='/';
board[row-6][col+7]='-';
board[row-6][col+6]='-';
board[row-6][col+5]='-';

	

	//body

board[row-2][col+3]='\\';
board[row-2][col+4]='_';
board[row-2][col+5]='_';
board[row-2][col+6]='_';
board[row-2][col+7]='_';
board[row-2][col+8]='_';
board[row-2][col+9]='/';
board[row-3][col+9]='|';
board[row-4][col+9]='|';
board[row-5][col+9]='|';
board[row-3][col+3]='|';
board[row-4][col+3]='|';
board[row-5][col+3]='|';
board[row-5][col+4]='-';
board[row-5][col+5]='-';
board[row-5][col+6]='v';
board[row-5][col+7]='-';
board[row-5][col+8]='-';


//right arm
board[row-4][col+10]='-';
board[row-4][col+11]='-';
board[row-4][col+12]='-';
board[row-4][col+13]='|';
board[row-4][col+14]='/';
board[row-5][col+14]='\\';
board[row-5][col+13]='|';
board[row-5][col+12]='-';
board[row-5][col+11]='-';
board[row-5][col+10]='-';



//right leg
board[row][col+7]='|';
board[row][col+8]='_';
board[row][col+9]='|';
board[row-1][col+7]='|';
board[row-1][col+9]='|';


//left arm
board[row-3][col]='/';
board[row-4][col+1]='/';
board[row-5][col+2]='/';


//left leg
board[row][col+3]='|';
board[row-1][col+3]='|';
board[row][col+4]='_';
board[row][col+5]='|';
board[row-1][col+5]='|';



}


void climbFrame(char board[24][80] , int row , int col){
	
	
	//body

board[row-2][col+3]='\\';
board[row-2][col+4]='_';
board[row-2][col+5]='_';
board[row-2][col+6]='_';
board[row-2][col+7]='_';
board[row-2][col+8]='_';
board[row-2][col+9]='/';
board[row-3][col+9]='|';
board[row-4][col+9]='|';
board[row-5][col+9]='|';
board[row-3][col+3]='|';
board[row-4][col+3]='|';
board[row-5][col+3]='|';
board[row-5][col+4]='-';
board[row-5][col+5]='-';
board[row-5][col+6]='v';
board[row-5][col+7]='-';
board[row-5][col+8]='-';
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
				if( i == 0 || i == 23) {
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

void callObj (char board[24][80]) {
		
	drawEnemyBirdLeft(board, 5, 60); // Draw the enemy bird
	drawEnemyBirdRight(board, 10, 10); // Draw the enemy bird
	
}

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

void jumpStraight(char board[24][80], int &pX , int &pY , int pHeight , int pWidth ,int & isJumping, player Player , char gun[]){
	for(int i = 0; i<3; i++){
		int check =1;
		for(int j = pY; j <= pY + (pWidth - 1); j++){
			if (board[pX-pHeight][j] != ' ') {
				check = 0;
				break;
			}
		}
		if (pX - (pHeight - 1) - 1 > 0 && board[pX - (pHeight - 1) - 1][pY] == ' ' && check ==1) {
			pX--;
			clearMap(board);
			addBorders(board);
			drawPlayerRightFrame1(board, pX, pY);
			callObj(board); // Call dynamic objects here
			system("cls");
			dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun); // Display the bar first
			Clear_LoadMap(board); // Clear the screen and load the map

			isJumping = 1;
		}
		else break;
		
	}
	isJumping =0;
}

/*
NEXT STEPS:
1. Add a function to check if the player is falling and apply gravity (apply after jump and after every movement)
2. Add jumpDiagonal function (jump left or right) , and add a function to check if the player is falling after jump diagonal and apply gravity (apply after jump diagonal)
3. Implement looking direction of the player
4. implement walking frames left and right 
5. implement jumping frames up , left diagonal and right diagonal 
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


	int choice;
	for(;;){
	system("cls"); // Clear the screen
	showMainMenu(choice);
	if(choice == 4) {
		cout << "Exiting game..." << endl;
		system("cls");
		break;
	}
	else if (choice == 1) {
		cout << "Starting Game..." << endl;
		system("cls");
		break; // Exit the loop to start the game
	}
	else
	if (choice == 2) {
		cout << "Instructions..." << endl;
		system("cls");
		displayInstructions(); // Call the function to display instructions
	}
	else if (choice == 3) {
		cout << "Credits..." << endl;
		system("cls");
		displayCredits(); // Call the function to display credits
	}
	
}

if(choice == 1) {
	system("cls");
	player Player;
	initializePlayerValues(Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, Player.Health, Player.coins, Player.gun, Player.ammo, Player.maxAmmo);
	initializeBoard(board); // Initialize the board

	char gun[] = "Pistol";
	
	
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
			callObj(board); // Call dynamic objects here
			system("cls");
			dispBar(Player.Health, Player.coins, Player.ammo, Player.maxAmmo, gun); // Display the bar first
			Clear_LoadMap(board); // Clear the screen and load the map

		if (_kbhit()) {
			char key = _getch();
			if ((key == 'a' || key == 'A') && isClimbing == 0 && isFalling ==0){
				moveLeft(board, Player.Col, Player.Row , Player.maxWidth);
				isWalking = 2;
			}
			else if ((key == 'd' || key == 'D') && isClimbing == 0 && isFalling == 0) {
				moveRight(board, Player.Col, Player.Row, Player.maxWidth , Player.maxHeight);
				isWalking = 1;
			}
			else if (key == 'w' || key == 'W') {
				if (isJumping == 0 && isFalling == 0 && isReloading == 0) {
					if(isWalking == 0) {
						jumpStraight(board, Player.Row, Player.Col, Player.maxHeight, Player.maxWidth, isJumping, Player , gun);
					}
				}
			}

		}
	}
}
else return 0;

}
