#include <iostream>
#include <conio.h>
using namespace std;
void ElevatePlayer(char board[100][1000], int& dispR, int& dispC, int& pX, int& pY, Elevator elevator[], int nElevators) {
	for (int i = 0; i < nElevators; i++) {
		// Vertical Elevator
		if (elevator[i].whichD == 0) {
			int elTop = elevator[i].row;
			int elLeft = elevator[i].col;
			int elRight = elevator[i].col + elevator[i].length - 1;

			// Same horizontal range logic
			if ((pX - 1) == elTop && pY + 14 - 1 >= elLeft && pY <= elRight) {
				if (elevator[i].direction == 1) { // Up
					pX--;
					scroll(board, pY, pX, 15, 8, dispR, dispC);
				}

				else if (elevator[i].direction == 2) { // Down
					pX++;
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
					pY++;
					scroll(board, pY, pX, 15, 8, dispR, dispC);
				}
				else if (elevator[i].direction == 2) { // Left
					pY--;
					scroll(board, pY, pX, 15, 8, dispR, dispC);
				}
			}
		}

	}

}

    