#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
	struct BDATE {
		int dia, mes, ano;
	};

	struct STUDENT {
		string nome;
		int idade;
		BDATE birthDate;
	};

	STUDENT estudante = {"Paulo", 31, {13, 12, 1988} };

	cout << estudante.birthDate.ano << endl;

	return 0;
}