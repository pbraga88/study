#include <iostream>

using namespace std;

int main() {
	int a;
	short b;
	long c;

	unsigned int d;

	unsigned char x;

	cout<<"Size of int: "<<sizeof(a)<<endl;
	cout<<"Size of short: "<<sizeof(b)<<endl;
	cout<<"Size of long: "<<sizeof(c)<<endl;
	cout<<"unsigned int: "<<sizeof(d)<<endl;

	cout<<"Size of char: "<<sizeof(x)<<endl;

	return 0;
}