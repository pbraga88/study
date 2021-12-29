#include <iostream>

using namespace std;

class Linha{
	   public:
	   	void setLargura(double larg);
		double getLargura(void);
		Linha(double larg);	// Este é o constructor. E, nesse caso, ele aceita um parâmetro
       private:
       	double largura;
};

// Definição de Member Functions incluindo 'constructor'
/*Linha::Linha(double larg){
	largura = larg;
	cout<<"Objeto sendo criado. Largura = "<<largura<<endl;
	
}*/
Linha::Linha(double larg):largura(larg){	// A função de classe anterior também pode ser declarada desta maneira
	cout<<"Objeto sendo criado. Largura = "<<largura<<endl;
}


void Linha::setLargura(double larg){
	largura = larg;
}

double Linha::getLargura(void){
	return largura;
}

int main(){
	Linha linha(10.0); //Criando minha classe já com parâmetro
	
	// Valor de largura iniciado à partir do constructor
	cout<<"Largura inicial = "<<linha.getLargura()<<endl;
	
	// Alterando o valor da largura
	linha.setLargura(7);
	cout<<"Largura apos alteracao = "<<linha.getLargura()<<endl;
	
}