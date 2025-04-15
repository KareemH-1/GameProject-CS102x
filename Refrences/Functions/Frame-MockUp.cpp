#include <iostream>
using namespace std;

const int WIDTH = 80;
const int HEIGHT = 24;

void drawGameFrame(char border[HEIGHT][WIDTH]) {
    // Top border
    border[0][0] = '+';
    for (int i = 1; i < WIDTH - 1; i++) border[0][i] = '=';
    border[0][WIDTH - 1] = '+';

    // Middle section with side borders
    for (int i = 1; i < HEIGHT - 1; i++) {
        border[i][0] = '|';
        for (int j = 1; j < WIDTH - 1; j++) border[i][j] = ' ';
        border[i][WIDTH - 1] = '|';
    }

    // Bottom border
    border[HEIGHT - 1][0] = '+';
    for (int i = 1; i < WIDTH - 1; i++) border[HEIGHT - 1][i] = '=';
    border[HEIGHT - 1][WIDTH - 1] = '+';
}

void printGameFrame(char border[HEIGHT][WIDTH]) {
    cout << "\033[34m"; // Blue color
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << border[i][j];
        }
        cout << endl;
    }
    cout << "\033[0m"; // Reset color
}

void drawBar(int health, int deaths, string weapon, int ammo, int armor) {
    char green[] = "\033[32m";
    char blue[] = "\033[34m";
    char red[] = "\033[31m";
    char yellow[] = "\033[33m";
    char cyan[] = "\033[36m";
    char reset[] = "\033[0m";
    char bold[] = "\033[1m";

    cout << "\033[34m"; // Blue color for border
    for (int i = 0; i < WIDTH; i++) cout << "=";
    cout << "\033[0m" << endl;

    cout << blue << "|" << reset << "        HEALTH " << green << bold << health << "%" << reset << "  |  DEATHS " << yellow << bold << deaths << reset << "  |  " << yellow << bold << weapon << reset << "  |  AMMO " << yellow << bold << ammo << reset << "  |  ARMOR " << red << bold << armor << "%" << reset << blue << "         |" << reset << endl;
}

int main() {
    char border[HEIGHT][WIDTH] = {};

    drawGameFrame(border);
    drawBar(10, 0, "Pistol", 24, 100);
    printGameFrame(border);

}