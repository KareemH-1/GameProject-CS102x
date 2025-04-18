#include <iostream>
#include <conio.h>
#include <windows.h>  // For Sleep() function to pause the game
using namespace std;


char board[24][80];
void shoot() {
    int posr;
    int posc;
    for (int r = 0; r < 24; r++) {
        for (int c = 0; c < 80; c++) {
            if (board[r][c] == (char)254)
            {
                posr = r;
                posc = c;
            }
        }
    }


    int c = posc+1;
    int ct = 0;
    for (int r = posr+1; r < 24; r++) {
        board[r][c] = 'o';
            cout << board[r][c];
            c++;
            ct++;
            if (ct == 11)
            {
                break;
            }
    }


    system("cls");  // Clear screen before drawing
    for (int r = 0; r < 24; r++) {
        for (int c = 0; c < 80; c++) {
            cout << board[r][c];
            if (board[r][c] == 'o')
            {
                Sleep(50);
                board[r][c] == ' ';
            }
        }
        cout << endl;
    }
}


int main() {
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


    board[15][40] = (char)254; // the gun
    for (int r = 0; r < 24; r++) {
        for (int c = 0; c < 80; c++) {
            cout << board[r][c];
        }
        cout << endl;
    }

    char hit;
    for (;;) {
        hit = _getch();  // Get the pressed 
        if (_kbhit)
        {
            if (hit == 'f')
            {
                shoot();
            }
        }

    }

}



///
///////////////
///
