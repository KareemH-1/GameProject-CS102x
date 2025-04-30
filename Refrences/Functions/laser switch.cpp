#include <iostream>   // For input/output operations
#include <conio.h>    // For keyboard input functions (_kbhit() and _getch())
#include <windows.h>  // For Sleep() function to pause the game
using namespace std;


char board[24][80];


void moveplayer(char move_dir, int& player_y, int& player_x);
void drawBoard(char move_dir, int& player_y, int& player_x);

struct Enemy {
    int health = 100;
    int row = 20;
    int col = 30;
    int width = 15;  // From col+7 to col+15 = 9 width
    int height = 4;   // From row-3 to row = 4 height

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

void checkEnemyHit(int row, int col, Enemy& enemy, int& checkhit) {
    checkhit = 0;
    // Enemy bounding box
    int top = enemy.row - 3;
    int bottom = enemy.row;
    int left = enemy.col + 6;
    int right = enemy.col + 16;

    if (row >= top && row <= bottom && col >= left && col <= right) {
        checkhit = 1;
    }
}

struct Laser {
    void shootLaser(Enemy& enemy, int& killed, char key, int& player_y, int& player_x) {
        int posr = -1, posc = -1;
        int checkhit = 0;
        int dir = 0;
        for (int r = 0; r < 24; r++) {
            for (int c = 0; c < 80; c++) {
                if (board[r][c] == (char)201){
                    posr = r;
                    posc = c;
                    dir = 1;
                }
                if (board[r][c] == (char)187) {
                    posr = r;
                    posc = c;
                    dir = -1;
                }
            }
        }

        if ((posr != -1 && posc != -1) && dir == 1) {
            int alreadyHit = 0;
            int h = 1;
            while (board[posr][posc + h] == ' ' && h < 20) {
                board[posr][posc + h] = '=';

                // Check for collision with the enemy
                checkEnemyHit(posr, posc + h, enemy, checkhit);
                if (!alreadyHit && (checkhit == 1)) {
                    enemy.health -= 30;  // Laser deals 10 damage
                    cout << "Laser hit! Enemy health: " << enemy.health << endl;
                    if (enemy.health <= 0) {
                        cout << "You killed the duck :(" << endl;
                        killed = 1;
                    }
                    alreadyHit = true;
                }

                h++;
                system("cls");
                for (int r = 0; r < 24; r++) {
                    for (int c = 0; c < 80; c++) {
                        cout << board[r][c];
                        if (_kbhit())
                        {
                            key = _getch();
                            if (key == 'w' || key == 's' || key == 'a' || key == 'd') {
                                moveplayer(key, player_y, player_x);  // Move player
                                drawBoard(key, player_y, player_x);
                            }
                        }
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


        else if ((posr != -1 && posc != -1) && dir == -1) {
            int alreadyHit = 0;
            int h = 1;
            while (board[posr][posc - h] == ' ' && h < 20)
            {
                board[posr][posc - h] = '=';

                // Check for collision with the enemy
                checkEnemyHit(posr, posc - h, enemy, checkhit);
                if (!alreadyHit && (checkhit == 1)) {
                    enemy.health -= 30;  // Laser deals 10 damage
                    cout << "Laser hit! Enemy health: " << enemy.health << endl;
                    if (enemy.health <= 0) {
                        cout << "You killed the duck :(" << endl;
                        killed = 1;
                    }
                    alreadyHit = true;
                }

                h++;
                system("cls");
                for (int r = 0; r < 24; r++) {
                    for (int c = 0; c < 80; c++) {
                        cout << board[r][c];
                        if (_kbhit())
                        {
                            key = _getch();
                            if (key == 'w' || key == 's' || key == 'a' || key == 'd') {
                                moveplayer(key, player_y, player_x);  // Move player
                                drawBoard(key, player_y, player_x);
                            }
                        }
                    }
                    cout << endl;
                }
            }

            int k = h;
            h = 1;

            while (true)
            {
                if (board[posr][posc - h] == '=') {
                    board[posr][posc - h] = ' ';
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
        if (count <= 5)
        {
            count += amount;
            cout << "Ammo reloaded! Current ammo: " << count << endl;
        }
        else
        {
            cout << "You can't reload! ---Your max Ammo is 10" << endl;
        }

    }
};

struct Gun {
    void shootGun(Enemy& enemy, int& killed, char key, int& player_y, int& player_x) {
        int posr = -1, posc = -1;
        int checkhit = 0;
        int dir = 0;
        for (int r = 0; r < 24; r++) {
            for (int c = 0; c < 80; c++) {
                if (board[r][c] == (char)201) {
                    posr = r;
                    posc = c;
                    dir = 1;
                }
                if (board[r][c] == (char)187) {
                    posr = r;
                    posc = c;
                    dir = -1;
                }
            }
        }

        if (posr != -1 && posc != -1 && dir == 1) {
            int r = posr;
            int ct = 0;
            int h = 1;
            int hitRegistered = 0;

            for (int c = posc + 1; c < 80; c++) {
                if (board[r][c] == ' ') {
                    board[r][c] = 'o';
                }
                else {
                    h = -1;
                }

                // Check for collision with the enemy
                checkEnemyHit(r, c, enemy, checkhit);
                if (!hitRegistered && (checkhit == 1)) {
                    enemy.health -= 10;  // Gun deals 10 damage
                    cout << "Bullet hit! Enemy health: " << enemy.health << endl;
                    if (enemy.health <= 0) {
                        cout << "You killed the duck :(" << endl;
                        killed = 1;
                    }
                    hitRegistered = true;
                    board[r][c] = ' ';
                    break;  // Stop the bullet after hit
                }

                system("cls");
                for (int i = 0; i < 24; i++) {
                    for (int j = 0; j < 80; j++) {
                        cout << board[i][j];
                        if (_kbhit())
                        {
                            key = _getch();
                            if (key == 'w' || key == 's' || key == 'a' || key == 'd') {
                                moveplayer(key, player_y, player_x);  // Move player
                                drawBoard(key, player_y, player_x);
                            }
                        }
                    }
                    cout << endl;
                }

                Sleep(50);
                if (board[r][c] == 'o') {
                    board[r][c] = ' ';
                }

                ct++;
                if (ct == 25)
                    break;
            }
        }


        else if ((posr != -1 && posc != -1) && dir == -1) {
            int r = posr;
            int ct = 0;
            int h = 1;
            int hitRegistered = 0;

            for (int c = posc - 1; c > 0; c--) {
                if (board[r][c] == ' ') {
                    board[r][c] = 'o';
                }
                else {
                    h = -1;
                }

                // Check for collision with the enemy
                checkEnemyHit(r, c, enemy, checkhit);
                if (!hitRegistered && (checkhit == 1)) {
                    enemy.health -= 10;  // Gun deals 10 damage
                    cout << "Bullet hit! Enemy health: " << enemy.health << endl;
                    if (enemy.health <= 0) {
                        cout << "You killed the duck :(" << endl;
                        killed = 1;
                    }
                    hitRegistered = true;
                    board[r][c] = ' ';
                    break;  // Stop the bullet after hit
                }

                system("cls");
                for (int i = 0; i < 24; i++) {
                    for (int j = 0; j < 80; j++) {
                        cout << board[i][j];
                        if (_kbhit())
                        {
                            key = _getch();
                            if (key == 'w' || key == 's' || key == 'a' || key == 'd') {
                                moveplayer(key, player_y, player_x);  // Move player
                                drawBoard(key, player_y, player_x);
                            }
                        }
                    }
                    cout << endl;
                }

                Sleep(50);
                if (board[r][c] == 'o') {
                    board[r][c] = ' ';
                }

                ct++;
                if (ct == 25)
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void initializeBoard() {
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
}

void drawBoard(char move_dir, int& player_y, int& player_x) {
    system("cls");

    for (int r = 0; r < 24; r++) {
        for (int c = 0; c < 80; c++) {
            cout << board[r][c];
        }
        cout << endl;
    }
}


void draw_player_right(int& player_y, int& player_x) {
    if (player_y >= 0 && player_y < 23 && player_x >= 0 && player_x < 79)
        board[player_y][player_x] = char(201);
}

void draw_player_left(int& player_y, int& player_x) {
    if (player_y >= 0 && player_y < 23 && player_x >= 0 && player_x < 79)
        board[player_y][player_x] = char(187);
}

// Moves the player based on the input direction (W, A, S, D)
void moveplayer(char move_dir, int& player_y, int& player_x) {
    // Clear old player position
    board[player_y][player_x] = ' ';

    // Direction handling
    if (move_dir == 'w' && player_y > 1) player_y--;
    if (move_dir == 's' && player_y < 22) player_y++;
    if (move_dir == 'a' && player_x > 1) player_x--;
    if (move_dir == 'd' && player_x < 78 ) player_x++;

    // Redraw player
    if (move_dir == 'a' || move_dir == 'w' || move_dir == 's')  draw_player_left(player_y, player_x);;
    if (move_dir == 'd' || move_dir == 'w' || move_dir == 's')  draw_player_right(player_y, player_x);
}


int main() {
    int player_y = 10, player_x = 10;
    char key = ' ';
    int ct = 0;
    int killed = 0;


    initializeBoard();

    draw_player_right(player_y, player_x);


    Enemy enemy;
    enemy.createEnemy(21, 40);

    drawBoard(key, player_y, player_x);

    Player player;

    while (true) {
        drawBoard(key, player_y, player_x);
        cout << "Enemy Health: " << enemy.health << endl;
        cout << "Ammo: " << player.ammo.count << endl;
        if (ct % 2 == 0)
            cout << "Laser mode" << endl;
        else
            cout << "Gun mode" << endl;
        cout << "Controls: F (fire), T (toggle weapon), R (reload), Q (quit)" << endl;
        key = _getch();  // Get the pressed key 

        if (key == 't') {
            ct++;
        }



        if (ct % 2 == 0) {
            if (key == 'f') {
                if (player.ammo.count > 0) {
                    player.laser.shootLaser(enemy, killed, key, player_y, player_x);
                    player.ammo.use();
                }
                else {
                    cout << "Out of ammo!" << endl;
                    Sleep(1000);
                }
            }
        }
        else {
            if (key == 'f') {
                if (player.ammo.count > 0) {
                    player.gun.shootGun(enemy, killed, key, player_y, player_x);
                    player.ammo.use();
                }
                else {
                    cout << "Out of ammo!" << endl;
                    Sleep(1000);
                }
            }
        }



        if (key == 'w' || key == 's' || key == 'a' || key == 'd') {
            moveplayer(key, player_y, player_x);  // Move player
            drawBoard(key, player_y, player_x);
        }

        if (key == 'r') {
            player.ammo.reload(5);
            Sleep(1000);
        }

        if (key == 'q' || killed == 1) {
            cout << "\nExiting game... Goodbye!" << endl;
            break;
        }

        Sleep(50);  // Delay to control movement speed
    }
}
