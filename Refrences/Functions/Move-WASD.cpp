#include <iostream>   // For input/output operations
#include <conio.h>    // For keyboard input functions (_kbhit() and _getch())
#include <windows.h>  // For Sleep() function to pause the game
using namespace std;

// Moves the player based on the input direction (W, A, S, D)
void moveplayer(char move_dir, int& player_y, int& player_x) {
    if (move_dir == 'w' && player_y > 0)        player_y--;
    else if (move_dir == 's' && player_y < 23)  player_y++;
    else if (move_dir == 'a' && player_x > 0)   player_x--;
    else if (move_dir == 'd' && player_x < 79)  player_x++;
}

// Clears the screen and redraws the player at the new position
void draw_player(int player_y, int player_x) {
    system("cls");  // Clear the screen

    for (int r = 0; r < 24; r++) {
        for (int c = 0; c < 80; c++) {
            if (c == player_x && r == player_y)
                cout << (char)233;  // Display the player
            else
                cout << ' ';  // Empty space for the grid
        }
        cout << endl;
    }
}

int main() {
    int player_y = 10, player_x = 10;
    char key;

    draw_player(player_y, player_x);  // Initial player position

    while (true) {
        if (_kbhit()) {  // Check for key press
            key = _getch();  // Get the pressed key
            if (key == 'w' || key == 's' || key == 'a' || key == 'd') {
                moveplayer(key, player_y, player_x);  // Move player
                draw_player(player_y, player_x);  // Redraw player
            }
        }
        Sleep(50);  // Delay to control movement speed
    }
}
