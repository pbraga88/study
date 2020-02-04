#include <iostream>

using namespace std;

inline int my_func(int nb) {
	return nb * 2;
}

int main() {

	int var = 2;
	var = my_func(var);
	var = my_func(var);
	var = my_func(var);
	var = my_func(var);
	cout << var << endl;

	return 0;
}