#include <iostream>

using namespace std;

class Caixa {
	public:
	double comprimento; // Comprimento da Caixa
	double largura;  // Largura da Caixa
	double altura;	// Altura da Caixa
	
	// Declaração de 'member function'
	double getVolume(void);
	void setComprimento(double comp);
	void setLargura(double larg);
	void setAltura(double alt);
};

// Definição dos 'Member functions'
// O operador '::', também conhecido como 'scope resolution', é utilizado
// quando a função é definida fora da classe
double Caixa::getVolume(void){  
	return comprimento * largura * altura;	
}

void Caixa::setComprimento(double comp){
	comprimento = comp;
}

void Caixa::setLargura(double larg){
	largura = larg;
}

void Caixa::setAltura(double alt){
	altura = alt;
}

// Main Function
int main()
{
	Caixa caixa01; // Declarando caixa01 como tipo Caixa
	Caixa caixa02; // Declarando caixa02 como tipo Caixa
	double volume = 0.0; //Variável para guardar o volume de uma caixa 
	
	// Especificação da caixa01
	caixa01.setComprimento(6.0);
	caixa01.setLargura(7.0);
	caixa01.setAltura(5.0);
	
	// Especificação da caixa02
	caixa02.setComprimento(10.0);
	caixa02.setLargura(12.0);
	caixa02.setAltura(13.0);
	
	// Volume da caixa01
	volume = caixa01.getVolume();
	cout << "Volume da caixa01 = " << volume << endl;
	
	//Volume da caixa 02
	volume = caixa02.getVolume();
	cout << "Volume da caixa02 = " << volume << endl;	
	
}
