#include <iostream>

using namespace std;

class Caixa {
	public:
	double comprimento;
	double largura;
	double altura;	
};
int main()
{
	Caixa caixa01; // Declarando caixa01 como tipo Caixa
	Caixa caixa02; // Declarando caixa02 como tipo Caixa
	double volume = 0.0; //Variável para guardar o volume de uma caixa 
	
	// Especificação da caixa01
	caixa01.comprimento = 5.0;
	caixa01.largura = 6.0;
	caixa01.altura = 7.0;
	
	// Especificação da caixa02
	caixa02.comprimento = 10.0;
	caixa02.largura = 12.0;
	caixa02.altura = 13.00;
	
	// Volume da caixa01
	volume = caixa01.comprimento * caixa01.largura * caixa01.altura;
	cout << "Volume da caixa01 = " << volume << endl;
	
	// Volume da caixa 02
	volume = caixa02.comprimento * caixa02.largura * caixa02.altura;
	cout << "Volume da caixa02 = " << volume << endl;	
	
}
