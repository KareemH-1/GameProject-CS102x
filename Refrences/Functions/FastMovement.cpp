    #include <iostream>
    #include <conio.h>
    using namespace std;

    const int mapHeight = 20;
    const int mapWidth = 50;
    char gameMap[mapHeight][mapWidth + 1];

    int playerX = 5;
    int playerY = 17;
    int playerWidth = 4;
    int playerHeight = 2;

    int jumpProgress = 0;
    int maxJumpHeight = 7;
    int isJumping = 0;     // 0 = not jumping, 1 = jumping
    int isFalling = 0;     // 0 = not falling, 1 = falling

    void clearMap() {
        for (int i = 0; i < mapHeight; i++) {
            for (int j = 0; j < mapWidth; j++) {
                gameMap[i][j] = ' ';
            }
        }
    }

    void addBorders() {
        for (int i = 0; i < mapHeight; i++) {
            gameMap[i][0] = '|';
            gameMap[i][mapWidth - 1] = '|';
        }
        for (int i = 0; i < mapWidth; i++) {
            gameMap[mapHeight - 1][i] = '=';
        }
    }

    void drawPlayer() {
        for (int i = 0; i < playerHeight; i++) {
            for (int j = 0; j < playerWidth; j++) {
                int drawY = playerY - i;
                int drawX = playerX + j;
                if (drawY >= 0 && drawY < mapHeight && drawX >= 0 && drawX < mapWidth) {
                    gameMap[drawY][drawX] = '#';
                }
            }
        }
    }

    void renderMap() {
        system("cls"); 
        for (int i = 0; i < mapHeight; i++) {
            cout << gameMap[i] << endl;
        }
    }

    void applyGravity() {
        if (playerY + 1 < mapHeight - 1) {
            playerY++;
            isFalling = 1;
        }
        else {
            isFalling = 0;
        }
    }

    void jump() {
        if (isJumping == 1) {
            if (jumpProgress < maxJumpHeight && playerY > 0) {
                playerY--;
                jumpProgress++;
            }
            else {
                isJumping = 0;
                jumpProgress = 0;
                isFalling = 1;
            }
        }
    }

    void updatePhysics() {
        if (isJumping == 1) {
            jump();
        }
        else {
            applyGravity();
        }
    }

    void moveLeft() {
        if (playerX > 1) {
            playerX--;
        }
    }

    void moveRight() {
        if (playerX + playerWidth < mapWidth - 1) {
            playerX++;
        }
    }

    int main() {
        for (;;) {
            clearMap();
            addBorders();
            drawPlayer();
            renderMap();

            if (_kbhit()) {
                char key = _getch();
                if (key == 'a') {
                    moveLeft();
                }
                else if (key == 'd') {
                    moveRight();
                }
                else if (key == 'w') {
                    if (isJumping == 0 && isFalling == 0) {
                        isJumping = 1;
                        jumpProgress = 0;
                    }
                }
                else if (key == 'q') {
                    break;
                }
            }

            updatePhysics();

        }

        return 0;
    }
