#include <iostream>

using namespace std;

int main() {
	int i = ' ';	// i é igual ao valor ASCII de espaço (32)
	char c = 65;
	cout << c << endl;
	c = '\'';
	cout << c << endl;
	c = '\\';			// Para atribuir '\' à variável c, também utiliza-se o escape character backslash
	cout << c << '\n' << '\r' << '\a' << endl;

	c='\47';	// Código ASSCII Octal para apóstrofe
	cout << c << endl;

	c='\x27';	// Código ASSCII Hexadecimal para apóstrofe
	cout << c << endl;

	c = 'A';
	c += 32;
	cout << c << endl;
	c -= ' ';
	cout << c << endl;

	c = 'A';
	c += i;
	cout << c << endl;
	c -= i;
	cout << c << endl;	

}