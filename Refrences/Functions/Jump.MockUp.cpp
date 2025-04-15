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

    int isWalking = 0; // 0 = not walking, 1 = left, 2 = right

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
        char input = _getch();
        int moved = 0;

        if (input == 'W' || input == 'w') {
            int jumped = 0;
            if (isWalking == 0) {
                // Straight jump
                for (int i = 0; i < 3; i++) {
                    if (posIHero - 1 > 0 && board[posIHero - 1][posJHero] == ' ') {
                        board[posIHero][posJHero] = ' ';
                        posIHero--;
                        board[posIHero][posJHero] = '#';
                        jumped = 1;
                    }
                    else break;

                    system("cls");
                    for (int i = 0; i < 24; i++) {
                        for (int j = 0; j < 80; j++) cout << board[i][j];
                        cout << endl;
                    }
                }

                // Fall straight
                while (posIHero + 1 < 23 && board[posIHero + 1][posJHero] == ' ') {
                    board[posIHero][posJHero] = ' ';
                    posIHero++;
                    board[posIHero][posJHero] = '#';

                    system("cls");
                    for (int i = 0; i < 24; i++) {
                        for (int j = 0; j < 80; j++) cout << board[i][j];
                        cout << endl;
                    }
                }
            }
            else if (isWalking == 1) {
                // Jump left 
                for (int i = 0; i < 3; i++) {
                    if (posIHero - 1 > 0 && posJHero - 1 > 0 &&
                        board[posIHero - 1][posJHero - 1] == ' ') {
                        board[posIHero][posJHero] = ' ';
                        posIHero--;
                        posJHero--;
                        board[posIHero][posJHero] = '#';
                        jumped = 1;
                    }
                    else break;

                    system("cls");
                    for (int i = 0; i < 24; i++) {
                        for (int j = 0; j < 80; j++) cout << board[i][j];
                        cout << endl;
                    }
                }

                // Fall left
                while (posIHero + 1 < 23 && posJHero - 1 > 0 &&
                    board[posIHero + 1][posJHero - 1] == ' ') {
                    board[posIHero][posJHero] = ' ';
                    posIHero++;
                    posJHero--;
                    board[posIHero][posJHero] = '#';

                    system("cls");
                    for (int i = 0; i < 24; i++) {
                        for (int j = 0; j < 80; j++) cout << board[i][j];
                        cout << endl;
                    }
                }


                //Fix sticking on a wall when jumping left
				if (board[posIHero+1][posJHero] == ' ') {
                    while (posIHero + 1 < 23 && board[posIHero + 1][posJHero] == ' ') {
                        board[posIHero][posJHero] = ' ';
                        posIHero++;
                        board[posIHero][posJHero] = '#';

                        system("cls");
                        for (int i = 0; i < 24; i++) {
                            for (int j = 0; j < 80; j++) cout << board[i][j];
                            cout << endl;
                        }
                    }
				}
            }
            else if (isWalking == 2) {
                // Jump right
                for (int i = 0; i < 3; i++) {
                    if (posIHero - 1 > 0 && posJHero + 1 < 79 &&
                        board[posIHero - 1][posJHero + 1] == ' ') {
                        board[posIHero][posJHero] = ' ';
                        posIHero--;
                        posJHero++;
                        board[posIHero][posJHero] = '#';
                        jumped = 1;
                    }
                    else break;

                    system("cls");
                    for (int i = 0; i < 24; i++) {
                        for (int j = 0; j < 80; j++) cout << board[i][j];
                        cout << endl;
                    }
                }

                // Fall right
                while (posIHero + 1 < 23 && posJHero + 1 < 79 &&
                    board[posIHero + 1][posJHero + 1] == ' ') {
                    board[posIHero][posJHero] = ' ';
                    posIHero++;
                    posJHero++;
                    board[posIHero][posJHero] = '#';

                    system("cls");
                    for (int i = 0; i < 24; i++) {
                        for (int j = 0; j < 80; j++) cout << board[i][j];
                        cout << endl;
                    }
                }

                //Fix sticking on a wall when jumping right
                if (board[posIHero + 1][posJHero] == ' ') {
                    while (posIHero + 1 < 23 && board[posIHero + 1][posJHero] == ' ') {
                        board[posIHero][posJHero] = ' ';
                        posIHero++;
                        board[posIHero][posJHero] = '#';

                        system("cls");
                        for (int i = 0; i < 24; i++) {
                            for (int j = 0; j < 80; j++) cout << board[i][j];
                            cout << endl;
                        }
                    }
                }
            }

            // Fall straight down if jump was blocked
            if (!jumped) {
                while (posIHero + 1 < 23 && board[posIHero + 1][posJHero] == ' ') {
                    board[posIHero][posJHero] = ' ';
                    posIHero++;
                    board[posIHero][posJHero] = '#';

                    system("cls");
                    for (int i = 0; i < 24; i++) {
                        for (int j = 0; j < 80; j++) cout << board[i][j];
                        cout << endl;
                    }
                }
            }

            isWalking = 0; // Reset walking after jump
        }

        else if (input == 'A' || input == 'a') {
            isWalking = 1;
            if (posJHero - 1 > 0 && board[posIHero][posJHero - 1] == ' ') {
                board[posIHero][posJHero] = ' ';
                posJHero--;
                board[posIHero][posJHero] = '#';
                moved = 1;
            }
        }

        else if (input == 'D' || input == 'd') {
            isWalking = 2;
            if (posJHero + 1 < 79 && board[posIHero][posJHero + 1] == ' ') {
                board[posIHero][posJHero] = ' ';
                posJHero++;
                board[posIHero][posJHero] = '#';
                moved = 1;
            }
        }

        // Apply gravity if walking and nothing is under the hero
        if (moved) {
            while (posIHero + 1 < 23 && board[posIHero + 1][posJHero] == ' ') {
                board[posIHero][posJHero] = ' ';
                posIHero++;
                board[posIHero][posJHero] = '#';

                system("cls");
                for (int i = 0; i < 24; i++) {
                    for (int j = 0; j < 80; j++) cout << board[i][j];
                    cout << endl;
                }
            }
        }
    }
}
