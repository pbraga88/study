#include <iostream>

using namespace std;

int main(){
	int i;
	// Float:
	float FloatArr[4] = {1.0, 2.0, 3.5, 4.9};
	// Char:
	char surname[6] = {'B', 'R', 'A', 'G', 'A', '\0'};
	// Bool:
	bool votes[3] = {1, 0, 1};

	for (i=0; i<4; i++)
		cout<<FloatArr[i]<<" ";
	cout<<endl;

	for (i=0; i<6; i++)
		cout<<surname[i];
	cout<<endl;

	for (i=0; i<3; i++)
		cout<<votes[i];
	cout<<endl;

	return 0;
}