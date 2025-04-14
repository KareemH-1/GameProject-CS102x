#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    // Initialize the board
    char board[24][80];
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

    // Initialize the hero's position
    int posIHero = 22;
    int posJHero = 4;
    board[posIHero][posJHero] = '#';

    // Main game loop
    for (;;) {
        // Clear the screen and display the board
        system("cls");
        for (int i = 0; i < 24; i++) {
            for (int j = 0; j < 80; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }

        // user input
        for (;;) {
            char input = _getch();
            int state = 0;
            if (input == 'W' || input == 'w') {
                // Jump Up 3 steps or less depending if there is an obstacle or not
                for (int i = 0; i < 3; i++) {
                    if (posIHero - 1 > 0 && board[posIHero - 1][posJHero] == ' ') {
                        board[posIHero][posJHero] = ' ';
                        posIHero--;
                        board[posIHero][posJHero] = '#';
                    }
                    else {
                        break;
                    }


                    system("cls");
                    for (int i = 0; i < 24; i++) {
                        for (int j = 0; j < 80; j++) {
                            cout << board[i][j];
                        }
                        cout << endl;
                    }

                }

                // Gravity Pulls Down Until the user hits a ground (later wit should be only set to ground because user could fall on an enemy or an object and stay above them)
                while (posIHero + 1 < 23 && board[posIHero + 1][posJHero] == ' ') {
                    board[posIHero][posJHero] = ' ';
                    posIHero++;
                    board[posIHero][posJHero] = '#';

                    system("cls");
                    for (int i = 0; i < 24; i++) {
                        for (int j = 0; j < 80; j++) {
                            cout << board[i][j];
                        }
                        cout << endl;
                    }

                }
            }

        }
    }
}
