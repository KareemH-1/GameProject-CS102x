
#include <iostream>
#include <windows.h>
using namespace std;
int main() {
	while (true)
	{
		char board[24][80];
		int row = 15;
		int col = 30;
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
		/////////////////////////////
	/////////////////////////////
	/////////////////////////////
	/////////////////////////////
	/////////////////////////////
	/////////////////////////////
	/////////////////////////////
	/////////////////////////////
	/////////////////////////////
	/////////////////////////////
		/////////////////////////////


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
	
}
