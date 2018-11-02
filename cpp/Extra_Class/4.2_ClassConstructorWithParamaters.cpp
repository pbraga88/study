#include <iostream>

using namespace std;

class Linha{
	   public:
	   	void setLargura(double larg);
		double getLargura(void);
		Linha(double larg);	// Este � o constructor. E, nesse caso, ele aceita um par�metro
       private:
       	double largura;
};

// Defini��o de Member Functions incluindo 'constructor'
/*Linha::Linha(double larg){
	largura = larg;
	cout<<"Objeto sendo criado. Largura = "<<largura<<endl;
	
}*/
Linha::Linha(double larg):largura(larg){	// A fun��o de classe anterior tamb�m pode ser declarada desta maneira
	cout<<"Objeto sendo criado. Largura = "<<largura<<endl;
}


void Linha::setLargura(double larg){
	largura = larg;
}

double Linha::getLargura(void){
	return largura;
}

int main(){
	Linha linha(10.0); //Criando minha classe j� com par�metro
	
	// Valor de largura iniciado � partir do constructor
	cout<<"Largura inicial = "<<linha.getLargura()<<endl;
	
	// Alterando o valor da largura
	linha.setLargura(7);
	cout<<"Largura apos alteracao = "<<linha.getLargura()<<endl;
	
}