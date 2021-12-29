#include <iostream>

using namespace std;

int main(){
	/*****Switch Case*****/
	int i;
	cout << "Enter a number from 1 to 4: " << endl;
	cin >> i;
	switch(i){
		case 1: 
			cout << "one" << endl;
			break;
		case 2: 
			cout << "two" << endl;
			break;
		case 3: 
			// cout << "three" << endl;
			// break;
		case 4: 
			cout << "three or four" << endl;
			break;
		default:
			cout << "wrong" << endl;
	}
	/************************************/
	return 0;
}