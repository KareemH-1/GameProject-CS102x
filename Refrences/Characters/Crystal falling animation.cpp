#include <iostream>
#include <windows.h>
using namespace std;



void DrawFrame(char board[24][80]) {
    for (int i = 0; i < 80; i++) {
        board[0][i] = '-';
        board[23][i] = '-';
    }
    for (int i = 0; i < 24; i++) {
        board[i][0] = '|';
        board[i][79] = '|';
    }

    board[0][0] = '#';
    board[0][79] = '#';
    board[23][0] = '#';
    board[23][79] = '#';
}

void PrintBoard(char board[24][80]) {
    for (int r = 0; r < 24; r++) {
        for (int c = 0; c < 80; c++) {
            cout << board[r][c];
        }
        cout << endl;
    }
}

void clearBoard(char board[24][80]) {
    for (int r = 0; r < 24; r++) {
        for (int c = 0; c < 80; c++) {
            board[r][c] = ' ';
        }
    }
}

int main() {
    char board[24][80];

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    for (;;) {
        clearBoard(board);
        DrawFrame(board);
        for (int i = 20; i < 30; i++) {
            board[1][i] = '^';
        }
        system("cls");
        PrintBoard(board);
        Sleep(200);
        ////////////////////////////////////////////////////////////////////
        clearBoard(board);
        DrawFrame(board);
        board[1][20] = '^'; board[1][21] = '^'; board[1][22] = '^';
        board[1][23] = '\'';
        board[1][24] = '-';
        board[1][25] = '-';
        board[1][26] = '\'';
        board[1][27] = '^'; board[1][28] = '^'; board[1][29] = '^';
        system("cls");
        PrintBoard(board);
        Sleep(200);
        ////////////////////////////////////////////////////////////////////
        clearBoard(board);
        DrawFrame(board);
        board[1][20] = '^'; board[1][21] = '^'; 
        board[1][22] = '\'';
        board[1][23] = '-';
        board[1][24] = '_';
        board[1][25] = '_';
        board[1][26] = '-';
        board[1][27] = '\'';
        board[1][28] = '^'; board[1][29] = '^';
        system("cls");
        PrintBoard(board);
        Sleep(200);
        ////////////////////////////////////////////////////////////////////

        clearBoard(board);
        DrawFrame(board);
        for (int i = 21; i < 29; i++) {
            board[1][i] = ' ';
        }
        board[1][20] = '^';
        board[1][21] = '_';
        board[2][22] = ' ';
        board[2][23] = '-';
        board[2][24] = '\\';
        board[2][25] = '/';
        board[2][26] = '-';
        board[2][27] = ' ';
        board[1][28] = '_';
        board[1][29] = '^';
        system("cls");
        PrintBoard(board);
        Sleep(200);
        ////////////////////////////////////////////////////////////////////

        clearBoard(board);
        DrawFrame(board);
        board[4][24] = '/';
        board[4][25] = '\\';
        board[5][23] = '(';
        board[5][26] = ')';
        board[6][24] = '\\';
        board[6][25] = '/';
        system("cls");
        PrintBoard(board);
        Sleep(200);

    }

    return 0;
}
