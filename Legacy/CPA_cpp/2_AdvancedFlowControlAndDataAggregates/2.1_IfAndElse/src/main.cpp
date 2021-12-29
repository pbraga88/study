#include <iostream>

using namespace std;

int main () {
	int x;
	cout << "Enter a number between 10 and 15 :" << endl;
	cin >> x;
	if(x >= 10 && x <= 15)
		cout << "The Hexadecimal form of " <<x<< " is: " << hex << x << endl;
	else if (x < 10)
		cout << "Number minor than 10" << endl;
	else
		cout << "Number bigger than 15" << endl;

	return 0;
}