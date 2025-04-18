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


    int r = posr + 1;
    int ct = 0;
    int h = 1;
    for (int c = posc + 1; c < 80; c++) {
        if (board[r][c] == ' ')
        {
            board[r][c] = 'o';
        }
        else
        {
            h = -1;
        }

        system("cls");
        for (int i = 0; i < 24; i++) {
            for (int j = 0; j < 80; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }

        Sleep(50);
        if (board[r][c] == 'o')
        {
            board[r][c] = ' ';
        }
        if (h == 1)
            r++;
        else r--;

        ct++;
        if (ct == 11)
            break;
    }
}


//The main function
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
            if (hit == 'q') {
                cout << "\nExiting game... Goodbye!" << endl;
                break;
            }
        }

    }

}



//? Single Bullet shooting
        //* Clear the bullet after drawing
        // if (board[r][c] == 'o')
        // {
        //     board[r][c] = ' ';
        // }


