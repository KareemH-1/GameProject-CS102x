#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void moveplayer(char move_dir, int& player_y, int& player_x) {
    if (move_dir == 'w')    player_y--;
    else if (move_dir == 's')    player_y++;
    else if (move_dir == 'a')    player_x--;
    else if (move_dir == 'd')    player_x++;
}

void draw_player(int player_y, int player_x) {
    system("cls");
    for (int r = 0; r < 24; r++) {
        for (int c = 0; c < 80; c++) {
            if (c == player_x && r == player_y)
            {
                cout << (char)233;
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}


int main() {
    int player_y = 10;
    int player_x = 10;
    char key;

    draw_player(player_y,player_x);
    while (true)
    {
        if (_kbhit())
        {
            key = _getch();
            if (key == 'w' || key == 's' || key == 'a' || key == 'd')
            {
                moveplayer(key, player_y, player_x);
                draw_player(player_y, player_x);
            }
        }
        Sleep(50);
    }
}