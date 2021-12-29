#include <iostream>

using namespace std;

int main() {
	float array[2][5];
	float sumLine1=0, sumLine2=0;
	int l, c;
	
	cout<<"Digite 10 números"<<endl;
	for (l = 0; l < 2; l++) {
		for (c = 0; c < 5; c++) {
			cin>>array[l][c];
		}
	}

	for (l = 0; l < 1; l++) {
		for (c = 0; c < 5; c++)
			sumLine1+=array[l][c];
	}

	for (l = 1; l < 2; l++) {
		for (c = 0; c < 5; c++)
			sumLine2+=array[l][c];
	}

	cout << "Soma da Linha1: " << sumLine1 << endl;
	cout << "Soma da Linha2: " << sumLine2 << endl;

	if(sumLine1>sumLine2)
		cout << "Linha1 é maior!" << endl;
	else if(sumLine2>sumLine1)
		cout << "Linha2 é maior!" << endl;
	else
		cout << "Linhas do mesmo tamanho!" << endl;

	return 0;
}