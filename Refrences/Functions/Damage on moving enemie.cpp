#include <iostream>   // For input/output operations
#include <conio.h>    // For keyboard input functions (_kbhit() and _getch())
#include <windows.h>  // For Sleep() function to pause the game
using namespace std;



char board[100][1000]; // Global board array for the game

void moveplayer(char move_dir, int& player_y, int& player_x);
void drawBoard(char move_dir, int& player_y, int& player_x);


struct Enemy {
	int health = 100;
	int row = 20;
	int col = 30;
	int width = 15;  // From col+7 to col+15 = 9 width
	int height = 4;   // From row-3 to row = 4 height

	void createEnemy(int row, int col) {
		this->row = row;
		this->col = col;
		for (int r = 0; r < 24; r++) {
			for (int c = 0; c < 80; c++) {
				board[r][c] = ' ';
			}
		}

		board[row - 8][col + 30] = '\\';
		board[row - 8][col + 31] = '_';
		board[row - 8][col + 32] = '_';
		board[row - 8][col + 33] = '/';
		board[row - 7][col + 29] = '/';
		board[row - 7][col + 30] = '(';
		board[row - 7][col + 31] = 'o';
		board[row - 7][col + 32] = ')';
		board[row - 7][col + 34] = '\\';
		board[row - 6][col + 29] = '\\';
		board[row - 6][col + 31] = '-';
		board[row - 6][col + 32] = '-';
		board[row - 6][col + 34] = '/';
		board[row - 5][col + 15] = '_';
		board[row - 5][col + 17] = '_';
		board[row - 5][col + 18] = '_';
		board[row - 5][col + 19] = '_';
		board[row - 5][col + 20] = '_';
		board[row - 5][col + 21] = '_';
		board[row - 5][col + 22] = '_';
		board[row - 5][col + 23] = '|';
		board[row - 5][col + 24] = '\\';
		board[row - 5][col + 25] = '_';
		board[row - 5][col + 26] = '_';
		board[row - 5][col + 27] = '(';
		board[row - 5][col + 28] = '-';
		board[row - 5][col + 29] = '-';
		board[row - 5][col + 30] = '=';
		board[row - 5][col + 31] = '=';
		board[row - 5][col + 32] = '=';
		board[row - 5][col + 33] = '=';
		board[row - 5][col + 34] = '-';
		board[row - 5][col + 35] = '-';
		board[row - 5][col + 36] = ')';
		board[row - 4][col + 15] = '\\';
		board[row - 4][col + 16] = '_';
		board[row - 4][col + 17] = '_';
		board[row - 4][col + 18] = '_';
		board[row - 4][col + 19] = '_';
		board[row - 4][col + 20] = '_';
		board[row - 4][col + 21] = '_';
		board[row - 4][col + 22] = '_';
		board[row - 4][col + 23] = '_';
		board[row - 4][col + 24] = '_';
		board[row - 4][col + 25] = '\\';
		board[row - 4][col + 26] = '=';
		board[row - 4][col + 27] = '=';
		board[row - 4][col + 28] = '=';
		board[row - 4][col + 29] = '=';
		board[row - 4][col + 30] = '=';
		board[row - 4][col + 31] = '=';
		board[row - 4][col + 32] = '/';
		board[row - 4][col + 33] = '\\';
		board[row - 4][col + 35] = '\\';
		board[row - 4][col + 36] = '[';
		board[row - 4][col + 37] = '[';
		board[row - 4][col + 38] = '/';
		board[row - 3][col + 27] = '/';
		board[row - 3][col + 30] = '\\';
		board[row - 3][col + 33] = '\\';
		board[row - 3][col + 34] = '_';
		board[row - 3][col + 35] = '-';
		board[row - 3][col + 36] = '/';
		board[row - 2][col + 29] = '|';
		board[row - 2][col + 30] = '=';
		board[row - 2][col + 31] = '=';
		board[row - 2][col + 32] = '=';
		board[row - 2][col + 33] = '=';
		board[row - 2][col + 34] = '|';
		board[row - 1][col + 28] = '(';
		board[row - 1][col + 31] = '/';
		board[row - 1][col + 32] = '\\';
		board[row - 1][col + 35] = ')';
		board[row - 0][col + 28] = '_';
		board[row - 0][col + 29] = '|';
		board[row - 0][col + 30] = '|';
		board[row - 0][col + 33] = '|';
		board[row - 0][col + 34] = '|';
		board[row - 0][col + 35] = '_';

		for (int r = 0; r < 24; r++) {
			for (int c = 0; c < 80; c++) {
				cout << board[r][c];
			}
			cout << endl;
		}
		system("cls");

		for (int r = 0; r < 24; r++) {
			for (int c = 0; c < 80; c++) {
				board[r][c] = ' ';
			}
		}
		board[row - 8][col + 30] = '\\';
		board[row - 8][col + 31] = '_';
		board[row - 8][col + 32] = '_';
		board[row - 8][col + 33] = '/';
		board[row - 7][col + 29] = '/';
		board[row - 7][col + 30] = '(';
		board[row - 7][col + 31] = 'o';
		board[row - 7][col + 32] = ')';
		board[row - 7][col + 34] = '\\';
		board[row - 6][col + 29] = '\\';
		board[row - 6][col + 31] = '-';
		board[row - 6][col + 32] = '-';
		board[row - 6][col + 34] = '/';
		board[row - 5][col + 18] = '_';
		board[row - 5][col + 20] = '_';
		board[row - 5][col + 21] = '_';
		board[row - 5][col + 22] = '_';
		board[row - 5][col + 23] = '_';
		board[row - 5][col + 24] = '_';
		board[row - 5][col + 25] = '_';
		board[row - 5][col + 26] = '|';
		board[row - 5][col + 27] = '\\';
		board[row - 5][col + 28] = '_';
		board[row - 5][col + 29] = '_';
		board[row - 5][col + 30] = '(';
		board[row - 5][col + 31] = '-';
		board[row - 5][col + 32] = '-';
		board[row - 5][col + 33] = '=';
		board[row - 5][col + 34] = '=';
		board[row - 5][col + 35] = '=';
		board[row - 5][col + 36] = '=';
		board[row - 5][col + 37] = '-';
		board[row - 5][col + 38] = '-';
		board[row - 5][col + 39] = ')';
		board[row - 4][col + 17] = '\\';
		board[row - 4][col + 18] = '_';
		board[row - 4][col + 19] = '_';
		board[row - 4][col + 20] = '_';
		board[row - 4][col + 21] = '_';
		board[row - 4][col + 22] = '_';
		board[row - 4][col + 23] = '_';
		board[row - 4][col + 24] = '_';
		board[row - 4][col + 25] = '_';
		board[row - 4][col + 26] = '_';
		board[row - 4][col + 27] = '\\';
		board[row - 4][col + 28] = '=';
		board[row - 4][col + 29] = '=';
		board[row - 4][col + 30] = '=';
		board[row - 4][col + 31] = '=';
		board[row - 4][col + 32] = '=';
		board[row - 4][col + 33] = '=';
		board[row - 4][col + 34] = '/';
		board[row - 4][col + 35] = '\\';
		board[row - 4][col + 37] = '\\';
		board[row - 4][col + 38] = '[';
		board[row - 4][col + 39] = '[';
		board[row - 4][col + 40] = '/';
		board[row - 3][col + 27] = '/';
		board[row - 3][col + 30] = '\\';
		board[row - 3][col + 33] = '\\';
		board[row - 3][col + 34] = '_';
		board[row - 3][col + 35] = '-';
		board[row - 3][col + 36] = '/';
		board[row - 2][col + 29] = '|';
		board[row - 2][col + 30] = '=';
		board[row - 2][col + 31] = '=';
		board[row - 2][col + 32] = '=';
		board[row - 2][col + 33] = '=';
		board[row - 2][col + 34] = '|';
		board[row - 1][col + 28] = '(';
		board[row - 1][col + 31] = '/';
		board[row - 1][col + 32] = '\\';
		board[row - 1][col + 35] = ')';
		board[row - 0][col + 28] = '_';
		board[row - 0][col + 29] = '|';
		board[row - 0][col + 30] = '|';
		board[row - 0][col + 33] = '|';
		board[row - 0][col + 34] = '|';
		board[row - 0][col + 35] = '_';
		for (int r = 0; r < 24; r++) {
			for (int c = 0; c < 80; c++) {

				cout << board[r][c];
			}
			cout << endl;
		}

		system("cls");

		for (int r = 0; r < 24; r++) {
			for (int c = 0; c < 80; c++) {
				board[r][c] = ' ';
			}
		}

		board[row - 8][col + 30] = '\\';
		board[row - 8][col + 31] = '_';
		board[row - 8][col + 32] = '_';
		board[row - 8][col + 33] = '/';
		board[row - 7][col + 29] = '/';
		board[row - 7][col + 30] = '(';
		board[row - 7][col + 31] = 'o';
		board[row - 7][col + 32] = ')';
		board[row - 7][col + 34] = '\\';
		board[row - 6][col + 29] = '\\';
		board[row - 6][col + 31] = '-';
		board[row - 6][col + 32] = '-';
		board[row - 6][col + 34] = '/';
		board[row - 5][col + 19] = '_';
		board[row - 5][col + 21] = '_';
		board[row - 5][col + 22] = '_';
		board[row - 5][col + 23] = '_';
		board[row - 5][col + 24] = '_';
		board[row - 5][col + 25] = '_';
		board[row - 5][col + 26] = '_';
		board[row - 5][col + 27] = '|';
		board[row - 5][col + 28] = '\\';
		board[row - 5][col + 29] = '_';
		board[row - 5][col + 30] = '_';
		board[row - 5][col + 31] = '(';
		board[row - 5][col + 32] = '-';
		board[row - 5][col + 33] = '-';
		board[row - 5][col + 34] = '=';
		board[row - 5][col + 35] = '=';
		board[row - 5][col + 36] = '=';
		board[row - 5][col + 37] = '=';
		board[row - 5][col + 38] = '-';
		board[row - 5][col + 39] = '-';
		board[row - 5][col + 40] = ')';
		board[row - 4][col + 18] = '\\';
		board[row - 4][col + 19] = '_';
		board[row - 4][col + 20] = '_';
		board[row - 4][col + 21] = '_';
		board[row - 4][col + 22] = '_';
		board[row - 4][col + 23] = '_';
		board[row - 4][col + 24] = '_';
		board[row - 4][col + 25] = '_';
		board[row - 4][col + 26] = '_';
		board[row - 4][col + 27] = '_';
		board[row - 4][col + 28] = '\\';
		board[row - 4][col + 29] = '=';
		board[row - 4][col + 30] = '=';
		board[row - 4][col + 31] = '=';
		board[row - 4][col + 32] = '=';
		board[row - 4][col + 33] = '=';
		board[row - 4][col + 34] = '=';
		board[row - 4][col + 35] = '/';
		board[row - 4][col + 36] = '\\';
		board[row - 4][col + 38] = '\\';
		board[row - 4][col + 39] = '[';
		board[row - 4][col + 40] = '[';
		board[row - 4][col + 41] = '/';
		board[row - 3][col + 27] = '/';
		board[row - 3][col + 30] = '\\';
		board[row - 3][col + 33] = '\\';
		board[row - 3][col + 34] = '_';
		board[row - 3][col + 35] = '-';
		board[row - 3][col + 36] = '/';
		board[row - 2][col + 29] = '|';
		board[row - 2][col + 30] = '=';
		board[row - 2][col + 31] = '=';
		board[row - 2][col + 32] = '=';
		board[row - 2][col + 33] = '=';
		board[row - 2][col + 34] = '|';
		board[row - 1][col + 28] = '(';
		board[row - 1][col + 31] = '/';
		board[row - 1][col + 32] = '\\';
		board[row - 1][col + 35] = ')';
		board[row - 0][col + 28] = '_';
		board[row - 0][col + 29] = '|';
		board[row - 0][col + 30] = '|';
		board[row - 0][col + 33] = '|';
		board[row - 0][col + 34] = '|';
		board[row - 0][col + 35] = '_';
		for (int r = 0; r < 24; r++) {
			for (int c = 0; c < 80; c++) {
				cout << board[r][c];
			}
			cout << endl;
		}
		system("cls");

		for (int r = 0; r < 24; r++) {
			for (int c = 0; c < 80; c++) {
				board[r][c] = ' ';
			}
		}


		board[row - 8][col + 30] = '\\';
		board[row - 8][col + 31] = '_';
		board[row - 8][col + 32] = '_';
		board[row - 8][col + 33] = '/';
		board[row - 7][col + 29] = '/';
		board[row - 7][col + 30] = '(';
		board[row - 7][col + 31] = 'o';
		board[row - 7][col + 32] = ')';
		board[row - 7][col + 34] = '\\';
		board[row - 6][col + 29] = '\\';
		board[row - 6][col + 31] = '-';
		board[row - 6][col + 32] = '-';
		board[row - 6][col + 34] = '/';
		board[row - 5][col + 18] = '_';
		board[row - 5][col + 20] = '_';
		board[row - 5][col + 21] = '_';
		board[row - 5][col + 22] = '_';
		board[row - 5][col + 23] = '_';
		board[row - 5][col + 24] = '_';
		board[row - 5][col + 25] = '_';
		board[row - 5][col + 26] = '|';
		board[row - 5][col + 27] = '\\';
		board[row - 5][col + 28] = '_';
		board[row - 5][col + 29] = '_';
		board[row - 5][col + 30] = '(';
		board[row - 5][col + 31] = '-';
		board[row - 5][col + 32] = '-';
		board[row - 5][col + 33] = '=';
		board[row - 5][col + 34] = '=';
		board[row - 5][col + 35] = '=';
		board[row - 5][col + 36] = '=';
		board[row - 5][col + 37] = '-';
		board[row - 5][col + 38] = '-';
		board[row - 5][col + 39] = ')';
		board[row - 4][col + 17] = '\\';
		board[row - 4][col + 18] = '_';
		board[row - 4][col + 19] = '_';
		board[row - 4][col + 20] = '_';
		board[row - 4][col + 21] = '_';
		board[row - 4][col + 22] = '_';
		board[row - 4][col + 23] = '_';
		board[row - 4][col + 24] = '_';
		board[row - 4][col + 25] = '_';
		board[row - 4][col + 26] = '_';
		board[row - 4][col + 27] = '\\';
		board[row - 4][col + 28] = '=';
		board[row - 4][col + 29] = '=';
		board[row - 4][col + 30] = '=';
		board[row - 4][col + 31] = '=';
		board[row - 4][col + 32] = '=';
		board[row - 4][col + 33] = '=';
		board[row - 4][col + 34] = '/';
		board[row - 4][col + 35] = '\\';
		board[row - 4][col + 37] = '\\';
		board[row - 4][col + 38] = '[';
		board[row - 4][col + 39] = '[';
		board[row - 4][col + 40] = '/';
		board[row - 3][col + 27] = '/';
		board[row - 3][col + 30] = '\\';
		board[row - 3][col + 33] = '\\';
		board[row - 3][col + 34] = '_';
		board[row - 3][col + 35] = '-';
		board[row - 3][col + 36] = '/';
		board[row - 2][col + 29] = '|';
		board[row - 2][col + 30] = '=';
		board[row - 2][col + 31] = '=';
		board[row - 2][col + 32] = '=';
		board[row - 2][col + 33] = '=';
		board[row - 2][col + 34] = '|';
		board[row - 1][col + 28] = '(';
		board[row - 1][col + 31] = '/';
		board[row - 1][col + 32] = '\\';
		board[row - 1][col + 35] = ')';
		board[row - 0][col + 28] = '_';
		board[row - 0][col + 29] = '|';
		board[row - 0][col + 30] = '|';
		board[row - 0][col + 33] = '|';
		board[row - 0][col + 34] = '|';
		board[row - 0][col + 35] = '_';




		for (int r = 0; r < 24; r++) {
			for (int c = 0; c < 80; c++) {
				cout << board[r][c];
			}
			cout << endl;
		}
		system("cls");

		for (int r = 0; r < 24; r++) {
			for (int c = 0; c < 80; c++) {
				board[r][c] = ' ';
			}
		}
		board[row - 8][col + 30] = '\\';
		board[row - 8][col + 31] = '_';
		board[row - 8][col + 32] = '_';
		board[row - 8][col + 33] = '/';
		board[row - 7][col + 29] = '/';
		board[row - 7][col + 30] = '(';
		board[row - 7][col + 31] = 'o';
		board[row - 7][col + 32] = ')';
		board[row - 7][col + 34] = '\\';
		board[row - 6][col + 29] = '\\';
		board[row - 6][col + 31] = '-';
		board[row - 6][col + 32] = '-';
		board[row - 6][col + 34] = '/';
		board[row - 5][col + 15] = '_';
		board[row - 5][col + 17] = '_';
		board[row - 5][col + 18] = '_';
		board[row - 5][col + 19] = '_';
		board[row - 5][col + 20] = '_';
		board[row - 5][col + 21] = '_';
		board[row - 5][col + 22] = '_';
		board[row - 5][col + 23] = '|';
		board[row - 5][col + 24] = '\\';
		board[row - 5][col + 25] = '_';
		board[row - 5][col + 26] = '_';
		board[row - 5][col + 27] = '(';
		board[row - 5][col + 28] = '-';
		board[row - 5][col + 29] = '-';
		board[row - 5][col + 30] = '=';
		board[row - 5][col + 31] = '=';
		board[row - 5][col + 32] = '=';
		board[row - 5][col + 33] = '=';
		board[row - 5][col + 34] = '-';
		board[row - 5][col + 35] = '-';
		board[row - 5][col + 36] = ')';
		board[row - 4][col + 15] = '\\';
		board[row - 4][col + 16] = '_';
		board[row - 4][col + 17] = '_';
		board[row - 4][col + 18] = '_';
		board[row - 4][col + 19] = '_';
		board[row - 4][col + 20] = '_';
		board[row - 4][col + 21] = '_';
		board[row - 4][col + 22] = '_';
		board[row - 4][col + 23] = '_';
		board[row - 4][col + 24] = '_';
		board[row - 4][col + 25] = '\\';
		board[row - 4][col + 26] = '=';
		board[row - 4][col + 27] = '=';
		board[row - 4][col + 28] = '=';
		board[row - 4][col + 29] = '=';
		board[row - 4][col + 30] = '=';
		board[row - 4][col + 31] = '=';
		board[row - 4][col + 32] = '/';
		board[row - 4][col + 33] = '\\';
		board[row - 4][col + 35] = '\\';
		board[row - 4][col + 36] = '[';
		board[row - 4][col + 37] = '[';
		board[row - 4][col + 38] = '/';
		board[row - 3][col + 27] = '/';
		board[row - 3][col + 30] = '\\';
		board[row - 3][col + 33] = '\\';
		board[row - 3][col + 34] = '_';
		board[row - 3][col + 35] = '-';
		board[row - 3][col + 36] = '/';
		board[row - 2][col + 29] = '|';
		board[row - 2][col + 30] = '=';
		board[row - 2][col + 31] = '=';
		board[row - 2][col + 32] = '=';
		board[row - 2][col + 33] = '=';
		board[row - 2][col + 34] = '|';
		board[row - 1][col + 28] = '(';
		board[row - 1][col + 31] = '/';
		board[row - 1][col + 32] = '\\';
		board[row - 1][col + 35] = ')';
		board[row - 0][col + 28] = '_';
		board[row - 0][col + 29] = '|';
		board[row - 0][col + 30] = '|';
		board[row - 0][col + 33] = '|';
		board[row - 0][col + 34] = '|';
		board[row - 0][col + 35] = '_';
	}

};

void checkEnemyHit(int row, int col, Enemy& enemy, int& checkhit) {
	checkhit = 0;
	// Enemy bounding box
	int top = enemy.row - 3;
	int bottom = enemy.row;
	int left = enemy.col + 6;
	int right = enemy.col + 16;

	if (row >= top && row <= bottom && col >= left && col <= right) {
		checkhit = 1;
	}
}

struct Laser {
	void shootLaser(Enemy& enemy, int& killed, char key, int& player_y, int& player_x) {
		int posr = -1, posc = -1;
		int checkhit = 0;
		int dir = 0;
		for (int r = 0; r < 24; r++) {
			for (int c = 0; c < 80; c++) {
				if (board[r][c] == (char)201) {
					posr = r;
					posc = c;
					dir = 1;
				}
				if (board[r][c] == (char)187) {
					posr = r;
					posc = c;
					dir = -1;
				}
			}
		}

		if ((posr != -1 && posc != -1) && dir == 1) {
			int alreadyHit = 0;
			int h = 1;
			while (board[posr][posc + h] == ' ' && h < 20) {
				board[posr][posc + h] = '=';

				// Check for collision with the enemy
				checkEnemyHit(posr, posc + h, enemy, checkhit);
				if (!alreadyHit && (checkhit == 1)) {
					enemy.health -= 30;  // Laser deals 10 damage
					cout << "Laser hit! Enemy health: " << enemy.health << endl;
					if (enemy.health <= 0) {
						cout << "You killed the duck :(" << endl;
						killed = 1;
					}
					alreadyHit = true;
				}

				h++;
				system("cls");
				for (int r = 0; r < 24; r++) {
					for (int c = 0; c < 80; c++) {
						cout << board[r][c];

					}
					cout << endl;
				}
			}

			// Reset laser position
			int k = h;
			h = 1;
			while (true) {
				if (board[posr][posc + h] == '=') {
					board[posr][posc + h] = ' ';
				}
				system("cls");
				for (int r = 0; r < 24; r++) {
					for (int c = 0; c < 80; c++) {
						cout << board[r][c];
					}
					cout << endl;
				}
				h++;
				if (h == k) {
					break;
				}
			}
		}


		else if ((posr != -1 && posc != -1) && dir == -1) {
			int alreadyHit = 0;
			int h = 1;
			while (board[posr][posc - h] == ' ' && h < 20)
			{
				board[posr][posc - h] = '=';

				// Check for collision with the enemy
				checkEnemyHit(posr, posc - h, enemy, checkhit);
				if (!alreadyHit && (checkhit == 1)) {
					enemy.health -= 30;  // Laser deals 10 damage
					cout << "Laser hit! Enemy health: " << enemy.health << endl;
					if (enemy.health <= 0) {
						cout << "You killed the duck :(" << endl;
						killed = 1;
					}
					alreadyHit = true;
				}

				h++;
				system("cls");
				for (int r = 0; r < 24; r++) {
					for (int c = 0; c < 80; c++) {
						cout << board[r][c];

					}
					cout << endl;
				}
			}

			int k = h;
			h = 1;

			while (true)
			{
				if (board[posr][posc - h] == '=') {
					board[posr][posc - h] = ' ';
				}
				system("cls");
				for (int r = 0; r < 24; r++) {
					for (int c = 0; c < 80; c++) {
						cout << board[r][c];
					}
					cout << endl;
				}
				h++;
				if (h == k) {
					break;
				}
			}

		}

	}
};

struct Ammo {
	int count = 10;

	void use() {
		if (count > 0) {
			count--;
			cout << "Ammo used. Remaining: " << count << endl;
		}
		else {
			cout << "Ammo is out!" << endl;
		}
	}

	void reload(int amount) {
		if (count <= 5)
		{
			count += amount;
			cout << "Ammo reloaded! Current ammo: " << count << endl;
		}
		else
		{
			cout << "You can't reload! ---Your max Ammo is 10" << endl;
		}

	}
};

struct Gun {
	void shootGun(Enemy& enemy, int& killed, char key, int& player_y, int& player_x) {
		int posr = -1, posc = -1;
		int checkhit = 0;
		int dir = 0;
		for (int r = 0; r < 24; r++) {
			for (int c = 0; c < 80; c++) {
				if (board[r][c] == (char)201) {
					posr = r;
					posc = c;
					dir = 1;
				}
				if (board[r][c] == (char)187) {
					posr = r;
					posc = c;
					dir = -1;
				}
			}
		}

		if (posr != -1 && posc != -1 && dir == 1) {
			int r = posr;
			int ct = 0;
			int h = 1;
			int hitRegistered = 0;

			for (int c = posc + 1; c < 80; c++) {
				if (board[r][c] == ' ') {
					board[r][c] = 'o';
				}
				else {
					h = -1;
				}

				// Check for collision with the enemy
				checkEnemyHit(r, c, enemy, checkhit);
				if (!hitRegistered && (checkhit == 1)) {
					enemy.health -= 10;  // Gun deals 10 damage
					cout << "Bullet hit! Enemy health: " << enemy.health << endl;
					if (enemy.health <= 0) {
						cout << "You killed the duck :(" << endl;
						killed = 1;
					}
					hitRegistered = true;
					board[r][c] = ' ';
					break;  // Stop the bullet after hit
				}

				system("cls");
				for (int i = 0; i < 24; i++) {
					for (int j = 0; j < 80; j++) {
						cout << board[i][j];

					}
					cout << endl;
				}

				Sleep(50);
				if (board[r][c] == 'o') {
					board[r][c] = ' ';
				}

				ct++;
				if (ct == 25)
					break;
			}
		}


		else if ((posr != -1 && posc != -1) && dir == -1) {
			int r = posr;
			int ct = 0;
			int h = 1;
			int hitRegistered = 0;

			for (int c = posc - 1; c > 0; c--) {
				if (board[r][c] == ' ') {
					board[r][c] = 'o';
				}
				else {
					h = -1;
				}

				// Check for collision with the enemy
				checkEnemyHit(r, c, enemy, checkhit);
				if (!hitRegistered && (checkhit == 1)) {
					enemy.health -= 10;  // Gun deals 10 damage
					cout << "Bullet hit! Enemy health: " << enemy.health << endl;
					if (enemy.health <= 0) {
						cout << "You killed the duck :(" << endl;
						killed = 1;
					}
					hitRegistered = true;
					board[r][c] = ' ';
					break;  // Stop the bullet after hit
				}

				system("cls");
				for (int i = 0; i < 24; i++) {
					for (int j = 0; j < 80; j++) {
						cout << board[i][j];

					}
					cout << endl;
				}

				Sleep(50);
				if (board[r][c] == 'o') {
					board[r][c] = ' ';
				}

				ct++;
				if (ct == 25)
					break;
			}

		}
	}
};


struct player {
	int Health = 100;
	Ammo ammo;
	Gun gun;
	Laser laser;
	int Row, Col; //Position
	int maxHeight = 9, maxWidth = 15; //Max height and width

	int coins; //Either coins or Level , until decided i will leave it as coins

	int shootR, shootC;
	int Reload[2] = { 1 , 3 }; //coolDown[0] for gun , coolDown[1] for lazerbeam
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}void DrawPlayerLeftFrame1(char board[100][1000], int row, int col, int& shootingR, int& shootingC, int LC[9]) {

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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Clear_LoadMap(char board[100][1000], int dispR, int dispC) {
	int top = dispR - 23;
	int bottom = dispR;

	for (int i = top - 1; i <= bottom + 1; i++) { // includes borders
		for (int j = dispC; j < dispC + 80; j++) {

			cout << board[i][j];

		}
		cout << endl;
	}

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

void moveRight(char board[100][1000], int& posJHero, int& posIHero, int widthHero, int heightHero, int LC[9], int& numCoinsP) {
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



	//Go up a row if its only 1 row diffrence in terrain
	if (board[posIHero][LC[0]] != ' ' && board[posIHero][LC[0]] != char(186) && check2 && !check) {
		posIHero--;
		posJHero++;
	}
	// Only move if all checks passed AND we won't go out of bounds
	else if (check == 1 && posJHero + widthHero + 1 < 999) {
		posJHero++;
	}
}

void moveLeft(char board[100][1000], int& posJHero, int& posIHero, int widthHero, int heightHero, int LC[9], int& numCoinsP) {
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
	if (board[posIHero][LC[0]] != ' ' && board[posIHero][LC[0]] != char(186) && check2 && !check) {
		posJHero--;
		posIHero--;
	}
	else if (check == 1 && posJHero - 1 >= 0) {
		posJHero--;
	}
}

void initializeBoard() {
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 80; j++) {
			board[i][j] = ' ';
		}
	}

	// Create the borders
	for (int j = 0; j < 80; j++) {
		board[0][j] = '-';
		board[23][j] = '-';
	}
	for (int i = 0; i < 24; i++) {
		board[i][0] = '|';
		board[i][79] = '|';
	}

	board[0][0] = '#';
	board[0][79] = '#';
	board[23][79] = '#';
	board[23][0] = '#';
}

void drawBoard(char move_dir, int& player_y, int& player_x) {
	system("cls");

	for (int r = 0; r < 24; r++) {
		for (int c = 0; c < 80; c++) {
			cout << board[r][c];
		}
		cout << endl;
	}
}


void draw_player_right(int& player_y, int& player_x) {
	if (player_y >= 0 && player_y < 23 && player_x >= 0 && player_x < 79)
		board[player_y][player_x] = char(201);
}

void draw_player_left(int& player_y, int& player_x) {
	if (player_y >= 0 && player_y < 23 && player_x >= 0 && player_x < 79)
		board[player_y][player_x] = char(187);
}

// Moves the player based on the input direction (W, A, S, D)
void moveplayer(char move_dir, int& player_y, int& player_x) {
	// Clear old player position
	board[player_y][player_x] = ' ';

	// Direction handling
	if (move_dir == 'w' && player_y > 1) player_y--;
	if (move_dir == 's' && player_y < 22) player_y++;
	if (move_dir == 'a' && player_x > 1) player_x--;
	if (move_dir == 'd' && player_x < 78) player_x++;

	// Redraw player
	if (move_dir == 'a' || move_dir == 'w' || move_dir == 's')  draw_player_left(player_y, player_x);;
	if (move_dir == 'd' || move_dir == 'w' || move_dir == 's')  draw_player_right(player_y, player_x);

}


































int main() {
	int player_y = 10, player_x = 10;
	char key = ' ';

	int ct = 0;
	int killed = 0;
	int lastCellCol[9], lastCellRow[15];
	int isWalking = 0, isJumping = 0, isFalling = 0, isShooting = 0, isReloading = 0;
	player Player;
	initializeBoard();

	drawPlayerRightFrame1(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);



	Enemy enemy;
	enemy.createEnemy(21, 40);

	drawBoard(key, player_y, player_x);
	int dispR = 95, dispC = 3;
	system("cls");

	int animation = 0, frame = 1, ResetFrame = 0;
	while (true) {
		clearMap(board, dispR, dispC);
		cout << "Enemy Health: " << enemy.health << endl;
		cout << "Ammo: " << Player.ammo.count << endl;
		if (ct % 2 == 0)
			cout << "Laser mode" << endl;
		else
			cout << "Gun mode" << endl;
		cout << "Controls: F (fire), T (toggle weapon), R (reload), Q (quit)" << endl;
		key = _getch();  // Get the pressed key 

		if (key == 't') {
			ct++;
		}

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
		else if (animation == -1) {
			drawPlayerRightFrame1(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
		}
		else if (animation == -2) {
			DrawPlayerLeftFrame1(board, Player.Row, Player.Col, Player.shootR, Player.shootC, lastCellCol);
		}

		system("cls");
		Clear_LoadMap(board, dispR, dispC);




		if (ct % 2 == 0) {
			if (key == 'f') {
				if (Player.ammo.count > 0) {
					Player.laser.shootLaser(enemy, killed, key, player_y, player_x);
					Player.ammo.use();
				}
				else {
					cout << "Out of ammo!" << endl;
					Sleep(1000);
				}
			}
		}
		else {
			if (key == 'f') {
				if (Player.ammo.count > 0) {
					Player.gun.shootGun(enemy, killed, key, player_y, player_x);
					Player.ammo.use();
				}
				else {
					cout << "Out of ammo!" << endl;
					Sleep(1000);
				}
			}
		}


		if (_kbhit()) {
			char key = _getch();

			if ((key == 'a' || key == 'A') && isFalling == 0) {
				if (Player.Col >= 2) {
					if (isWalking == 2) {
						if (frame == 5) frame = 1;
						else frame++;
					}
					else {
						frame = 1;
					}
					moveLeft(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, lastCellCol, Player.coins);
					animation = 1;
					isWalking = 2;
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
					moveRight(board, Player.Col, Player.Row, Player.maxWidth, Player.maxHeight, lastCellCol, Player.coins);
					animation = 0;
					isWalking = 1;
				}
			}


			if (key == 'r') {
				Player.ammo.reload(5);
				Sleep(1000);
			}

			if (key == 'q' || killed == 1) {
				cout << "\nExiting game... Goodbye!" << endl;
				break;
			}

			Sleep(50);  // Delay to control movement speed
		}
	}
}
