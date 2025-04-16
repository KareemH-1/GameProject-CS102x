#include <iostream>
using namespace std;
int main() {
	cout << "   " << (char)201;
	for (int i = 0; i < 7;i++) {
		cout << (char)196;
	}
	cout << (char)187;
	cout << endl;
	for (int i = 0; i < 4; i++) {
		cout << "   " << (char)179 << "       " << (char)179 << endl;
	}

	cout << (char)201;
	for (int i = 0; i < 14; i++) {
		cout << (char)196;
	}
	cout << (char)187;
	cout << endl;
	//body
	for (int i = 0; i < 10; i++) {
		cout << (char)179 << "              " << (char)179 << endl;
	}
}
