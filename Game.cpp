#include <iostream>
using namespace std;

struct player {
	int Row, Col; //Position
	int Health;
	int coins; //Either coins or Level , until decided i will leave it as coins
	int gun; //Either 1 for gun (bullets) or 2 for Lazerbeam (lazer)
	int ammo , maxAmmo; // (ammo/maxAmmo) , max ammo could be 24 for gun , (maxammo == 1) for lazerbeam
	int Reload[2] = {1 , 3}; //coolDown[0] for gun , coolDown[1] for lazerbeam
};

int main() {
	int width = 80, height = 24; // Lets keep the width and height stored as variables incase we want to change them later
    char board[24][80]; // Border for the game frame
}
