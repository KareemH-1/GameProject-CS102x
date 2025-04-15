#include <iostream>
using namespace std;

int WIDTH = 80;
int HEIGHT = 24;

void drawGameFrame(){
    
    // Blue border
    cout << "\033[34m";
    cout << "+";
    for (int i = 1; i < WIDTH-1; i++) cout << "=";
    cout << "+";
    cout << "\033[0m" << endl;

    for (int i = 0; i < HEIGHT; i++) {
        cout << "\033[34m|\033[0m";
        for (int j = 0; j < WIDTH - 2; j++) cout << " ";
        cout << "\033[34m|\033[0m" << endl;
    }

    cout << "\033[34m";
    cout << "+";
    for (int i = 1; i < WIDTH-1; i++) cout << "=";
    cout << "+";
    cout << "\033[0m" << endl;
}
void drawBar(int health,  int deaths,  string weapon, int ammo, int armor) {
    // ANSI color codes as variables
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

    // Print the bar
    cout << blue  << "|" << reset<<  "        HEALTH " << green << bold << health << "%" << reset << "  |  DEATHS " << yellow << bold << deaths << reset << "  |  " << yellow << bold << weapon << reset << "  |  AMMO " << yellow << bold << ammo << reset << "  |  ARMOR " << red << bold << armor << "%" << reset << blue << "          |" << reset << endl;
}

int main() {
    drawBar(10 , 0 , "Pistol" , 24/24 , 100);
    drawGameFrame();

}