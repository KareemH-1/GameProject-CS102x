#include <iostream>
#include <windows.h>
using namespace std;

void MoveCursorToTop() {
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

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

void PrintBoard(char board[24][80], HANDLE hConsole) {
    DWORD charsWritten;
    COORD cursorPosition = { 0, 0 };
    SetConsoleCursorPosition(hConsole, cursorPosition);

    wchar_t wideRow[80]; // Buffer for wide-character row
    for (int r = 0; r < 24; r++) {
        // Convert the current row to wide characters
        MultiByteToWideChar(CP_ACP, 0, board[r], 80, wideRow, 80);
        WriteConsoleOutputCharacter(hConsole, wideRow, 80, { 0, (SHORT)r }, &charsWritten);
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

    // Get console handle
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Hide cursor for cleaner animation
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    for (;;) {
        clearBoard(board);
        DrawFrame(board);
        for (int i = 20; i < 30; i++) {
            board[1][i] = '^';
        }
        system("cls");
        PrintBoard(board , hConsole);
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
        PrintBoard(board, hConsole);        Sleep(200);
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
        PrintBoard(board, hConsole);        Sleep(200);
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
        PrintBoard(board, hConsole);        Sleep(200);
        ////////////////////////////////////////////////////////////////////

        clearBoard(board);
        DrawFrame(board);
        for (int i = 20; i < 30; i++) {
            board[1][i] = '^';
        }
        board[4][24] = '/';
        board[4][25] = '\\';
        board[5][23] = '(';
        board[5][26] = ')';
        board[6][24] = '\\';
        board[6][25] = '/';
        system("cls");
        PrintBoard(board, hConsole);
        ////////////////////////////////////////////////////////////////////
        Sleep(200);
        clearBoard(board);
        DrawFrame(board);
        for (int i = 20; i < 30; i++) {
            board[1][i] = '^';
        }
        board[8][24] = '/';
        board[8][25] = '\\';
        board[9][23] = '(';
        board[9][26] = ')';
        board[10][24] = '\\';
        board[10][25] = '/';
        system("cls");
        PrintBoard(board, hConsole);////////////////////////////////////////////////
        Sleep(200);
        clearBoard(board);
        DrawFrame(board);
        for (int i = 20; i < 30; i++) {
            board[1][i] = '^';
        }
        board[12][24] = '/';
        board[12][25] = '\\';
        board[13][23] = '(';
        board[13][26] = ')';
        board[14][24] = '\\';
        board[14][25] = '/';
        system("cls");
        PrintBoard(board, hConsole);
        Sleep(200);

        ////////////////////////////////////////////////////////////////////

        clearBoard(board);
        DrawFrame(board);
        for (int i = 20; i < 30; i++) {
            board[1][i] = '^';
        }
        board[16][24] = '/';
        board[16][25] = '\\';
        board[17][23] = '(';
        board[17][26] = ')';
        board[18][24] = '\\';
        board[18][25] = '/';
        system("cls");
        PrintBoard(board, hConsole);
        Sleep(200);
        ////////////////////////////////////////////////////////////////////

        clearBoard(board);
        DrawFrame(board);
        for (int i = 20; i < 30; i++) {
            board[1][i] = '^';
        }
        board[20][24] = '/';
        board[20][25] = '\\';
        board[21][23] = '(';
        board[21][26] = ')';
        board[22][24] = '\\';
        board[22][25] = '/';
        system("cls");
        PrintBoard(board, hConsole);\
            Sleep(200);
        ////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////

        clearBoard(board);
        DrawFrame(board);
        for (int i = 20; i < 30; i++) {
            board[1][i] = '^';
        }
        board[21][24] = '/';
        board[21][25] = '\\';
        board[22][23] = '(';
        board[22][26] = ')';
        system("cls");
        PrintBoard(board, hConsole);
        Sleep(200);
        ////////////////////////////////////////////////////////////////////
        clearBoard(board);
        DrawFrame(board);
        for (int i = 20; i < 30; i++) {
            board[1][i] = '^';
        }
        board[22][22] = '>';
        board[22][23] = '\'';
        board[22][24] = '#';
        board[22][25] = '&';
        board[22][26] = '&';
        board[22][27] = '<';

        board[21][23] = ';';
        board[21][25] = ':';
        board[21][26] = ';';

        board[20][22] = '^';
        board[20][27] = '^';
        system("cls");
        PrintBoard(board, hConsole);
        Sleep(200);
        ////////////////////////////////////////////////////////////////////
        clearBoard(board);
        DrawFrame(board);
        for (int i = 20; i < 30; i++) {
            board[1][i] = '^';
        }
        board[22][22] = '_';
        board[22][23] = '_';
        board[22][26] = '_';
        board[22][27] = '_';


        board[20][23] = ';';
        board[20][25] = '\'';
        board[20][26] = '.';

        board[19][22] = '^';
        board[19][27] = '^';
        system("cls");
        PrintBoard(board, hConsole);
        Sleep(200);
    }
}
