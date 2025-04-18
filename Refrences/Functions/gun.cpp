
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
void shoot(int posr, int posc) {
    int r = posr + 1;
    int ct = 0;
    int h = 1;

    for (int c = posc + 1; c < 80; c++) {
        if (board[r][c] == ' ') {
            board[r][c] = 'o';
        }
        else {
            h = -1;
        }

        system("cls");
        for (int i = 0; i < 24; i++) {
            for (int j = 0; j < 80; j++) {
                cout << cyan;
                cout << board[i][j];
            }
            cout << endl;
        }

        Sleep(50);
        if (board[r][c] == 'o') {
            board[r][c] = ' ';
        }

        if (h == 1)
            r++;
        else
            r--;

        ct++;
        if (ct == 11)
            break;
    }
}




// Moves the player based on the input direction (W, A, S, D)
void moveplayer(char move_dir, int& player_y, int& player_x) {
    if (move_dir == 'w' && player_y > 0)        player_y--;
    else if (move_dir == 's' && player_y < 23)  player_y++;
    else if (move_dir == 'a' && player_x > 0)   player_x--;
    else if (move_dir == 'd' && player_x < 79)  player_x++;
}



void draw_board() {
    system("cls");
    for (int r = 0; r < 24; r++) {
        for (int c = 0; c < 80; c++) {
            cout << board[r][c];
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
    while (true) {
        if (_kbhit()) {
            hit = _getch();

            // Clear previous gun position
            board[gun_y][gun_x] = ' ';

            if (hit == 'w' && gun_y > 1) gun_y--;
            else if (hit == 's' && gun_y < 22) gun_y++;
            else if (hit == 'a' && gun_x > 1) gun_x--;
            else if (hit == 'd' && gun_x < 78) gun_x++;
            else if (hit == 'f') shoot(gun_y, gun_x);
            else if (hit == 'q') {  
                cout << "\nExiting game... Goodbye!" << endl;
                break;
            }

            // Set new gun position
            board[gun_y][gun_x] = (char)254;

            draw_board();
        }

        Sleep(50);
    }
}

//? Single Bullet shooting
        //* Clear the bullet after drawing
        // if (board[r][c] == 'o')
        // {
        //     board[r][c] = ' ';
        // }
