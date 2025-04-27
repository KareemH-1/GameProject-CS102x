#include <iostream>
#include <conio.h>
using namespace std;
void elevator(char board[24][80], int row, int col, int length) {
    for (int i = 0; i < length; i++) {
        cout << "Hello, Mazen!"
    }
}
void main() {
    char board[24][80];
    int row = 15;
    int col = 30;
    int length = 10; // Length of the elevator

    // Initialize the board with spaces
    for (int r = 0; r < 24; r++) {
        for (int c = 0; c < 80; c++) {
            board[r][c] = ' ';
        }
    }

    // Call the elevator function to draw the elevator
    elevator(board, row, col, length);

    // Print the board
    for (int r = 0; r < 24; r++) {
        for (int c = 0; c < 80; c++) {
            cout << board[r][c];
        }
        cout << endl;
    }

    