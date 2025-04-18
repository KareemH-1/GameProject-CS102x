#include <iostream>
using namespace std;

int main() {
    //TEXT COLORS
    cout << "\033[30m========\033[0m"; // Black
    cout << "\033[31m========\033[0m"; // Red
    cout << "\033[32m========\033[0m"; // Green
    cout << "\033[33m========\033[0m"; // Yellow
    cout << "\033[34m========\033[0m"; // Blue
    cout << "\033[35m========\033[0m"; // Magenta
    cout << "\033[36m========\033[0m"; // Cyan
    cout << "\033[37m========\033[0m"; // White
    cout << endl;

    for (int i = 0; i < 8; i++) {
        cout << "\033[1;3" << i << "m========\033[0m" << endl;
    }


	//BACKGROUND COLORS
    cout << "\033[40m        \033[0m"; // Black background
    cout << "\033[41m        \033[0m"; // Red background
    cout << "\033[42m        \033[0m"; // Green background
    cout << "\033[43m        \033[0m"; // Yellow background
    cout << "\033[44m        \033[0m"; // Blue background
    cout << "\033[45m        \033[0m"; // Magenta background
    cout << "\033[46m        \033[0m"; // Cyan background
    cout << "\033[47m        \033[0m"; // White background
    cout << endl;
    
    
    for (int i = 0; i < 8; i++) {
		cout << "\033[4" << i << ";1m                                            \033[0m" << endl;
	}
    //TEXT FORMATTING
    cout << "\033[1mBold Text\033[0m" << endl; // Bold text
    cout << "\033[3mItalic Text\033[0m" << endl; // Italic text
    cout << "\033[4mUnderlined Text\033[0m" << endl; // Underlined text
    cout << "\033[7mInverted Colors\033[0m" << endl; // Inverted colors
    cout << "\033[9mStrikethrough Text\033[0m" << endl; // Strikethrough text


}
