#include <windows.h>
#include <iostream>
#pragma comment(lib, "Winmm.lib")

using namespace std;

void playAudio() {
    PlaySound(L"video-game-music-loop-27629.wav",
        NULL,
        SND_FILENAME | SND_ASYNC | SND_LOOP);
}

int main() {
    playAudio();

    cout << "Playing sound on loop..." << endl;

    while (true) {
        Sleep(1000);
    }

    return 0;
}
