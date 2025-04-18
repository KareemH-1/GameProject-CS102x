
#include <iostream>
#include <conio.h>
#include <windows.h>  // For Sleep() function to pause the game
using namespace std;


char green[] = "\033[32m";
char blue[] = "\033[34m";
char red[] = "\033[31m";
char yellow[] = "\033[33m";
char cyan[] = "\033[36m";
char reset[] = "\033[0m";
char bold[] = "\033[1m";




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

//The main function
int main() {
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 80; j++) {
            board[i][j] = ' ';
        }
    }

    // Create borders
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

    int gun_y = 15, gun_x = 40;
    board[gun_y][gun_x] = (char)254;
    draw_board();

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
