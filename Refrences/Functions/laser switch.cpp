#include <iostream>
#include <conio.h>
#include <windows.h>  // For Sleep() function to pause the game
using namespace std;

char board[24][80];

struct Enemy {
    int health = 100;
    int row = 15;
    int col = 50;

    void createEnemy(int row, int col) {
        this->row = row;
        this->col = col;
        board[row - 3][col + 10] = '_';
        board[row - 3][col + 11] = '_';
        board[row - 2][col + 7] = '<';
        board[row - 2][col + 8] = '(';
        board[row - 2][col + 9] = 'o';
        board[row - 2][col + 11] = ')';
        board[row - 2][col + 12] = '_';
        board[row - 2][col + 13] = '_';
        board[row - 2][col + 14] = '_';
        board[row - 1][col + 8] = '(';
        board[row - 1][col + 13] = '.';
        board[row - 1][col + 14] = '_';
        board[row - 1][col + 15] = '>';
        board[row - 0][col + 9] = '`';
        board[row - 0][col + 10] = '-';
        board[row - 0][col + 11] = '-';
        board[row - 0][col + 12] = '-';
        board[row - 0][col + 13] = '-';
        board[row - 0][col + 14] = '\'';
    }
};

struct Laser {
    void shootLaser(Enemy& enemy, int& killed) {
        int posr = -1, posc = -1;
        for (int r = 0; r < 24; r++) {
            for (int c = 0; c < 80; c++) {
                if (board[r][c] == (char)254) {
                    posr = r;
                    posc = c;
                }
            }
        }

        if (posr != -1 && posc != -1) {
            int h = 1;
            while (board[posr][posc + h] == ' ' && h < 20) {
                board[posr][posc + h] = '=';

                // Check for collision with the enemy
                if (posr == enemy.row - 1 && posc + h >= enemy.col && posc + h <= enemy.col + 14) {
                    enemy.health -= 10;  // Laser deals 10 damage
                    cout << "Enemy hit! Health: " << enemy.health << endl;
                    if (enemy.health == 0)
                    {
                        cout << "you killed the duck :(" << endl;
                        killed = 1;
                    }
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
        count += amount;
        cout << "Ammo reloaded! Current ammo: " << count << endl;
    }
};

struct Gun {
    void shootGun(Enemy& enemy, int &killed) {
        int posr = -1, posc = -1;
        for (int r = 0; r < 24; r++) {
            for (int c = 0; c < 80; c++) {
                if (board[r][c] == (char)254) {
                    posr = r;
                    posc = c;
                }
            }
        }

        if (posr != -1 && posc != -1) {
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

                // Check for collision with the enemy
                if (r == enemy.row && c >= enemy.col && c <= enemy.col + 14) {
                    enemy.health -= 10;  // Gun deals 10 damage
                    cout << "Enemy hit! Health: " << enemy.health << endl;
                    if (enemy.health == 0)
                    {
                        cout << "you killed the duck :(" << endl;
                        killed = 1;
                    }
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
                if (h == 1) r++;
                else r--;

                ct++;
                if (ct == 11)
                    break;
            }
        }
    }
};

struct Player {
    int health = 100;
    Ammo ammo;
    Gun gun;
    Laser laser;
};

// The main function
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

    Enemy enemy;
    enemy.createEnemy(16, 50);

    board[15][40] = (char)254; // the laser
    for (int r = 0; r < 24; r++) {
        for (int c = 0; c < 80; c++) {
            cout << board[r][c];
        }
        cout << endl;
    }



    Player player;

    char hit;
    int ct = 0;
    int killed = 0;
    for (;;) {
        system("cls");
        // Redraw the board
        for (int r = 0; r < 24; r++) {
            for (int c = 0; c < 80; c++) {
                cout << board[r][c];
            }
            cout << endl;
        }

        cout << "Enemy Health: " << enemy.health << endl;
        cout << "Ammo: " << player.ammo.count << endl;
        if (ct % 2 == 0)
            cout << "laser mode" << endl;
        else
            cout << "Gun mode" << endl;
        cout << "Controls: F (fire), T (toggle weapon), R (reload), Q (quit)" << endl;

        hit = _getch();  // Get the pressed key
        if (hit == 't') {
            ct++;
        }

        if (ct % 2 == 0) {
            cout << "Laser mode" << endl;
            if (hit == 'f') {
                if (player.ammo.count > 0) {
                    player.laser.shootLaser(enemy, killed);
                    player.ammo.use();

                }
                else {
                    cout << "Out of ammo!" << endl;
                }
            }
        }

        if (ct % 2 != 0) {
            cout << "Gun mode" << endl;
            if (hit == 'f') {
                if (player.ammo.count > 0) {
                    player.gun.shootGun(enemy, killed);
                    player.ammo.use();
                }
                else {
                    cout << "Out of ammo!" << endl;
                }
            }
        }

        if (hit == 'r') {
            player.ammo.reload(5);
        }

        if (hit == 'q' || killed == 1) {
            cout << "\nExiting game... Goodbye!" << endl;
            break;
        }
    }

    return 0;
}
