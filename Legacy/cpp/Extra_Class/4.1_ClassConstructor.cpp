#include <iostream>
using namespace std;

class Linha{
	public:
		void setLargura(double larg);
		double getLargura(void);
		Linha(); // Este é o constructor. Tem o mesmo nome da classe e nunca
				 // tem retorno, nem mesmo void()

    private:
    	double largura;
};

// Definições de Member Functions incluindo o 'constructor'
Linha::Linha(void){
	cout<<"Objeto sendo criado"<<endl;
}
void Linha::setLargura(double larg){
	largura = larg;	
}
double Linha::getLargura(void){
	return largura;
}

int main(){
	Linha linha;
	Linha linha_de_pipa;
	
	linha.setLargura(10.0);
	cout<<"Largura da linha: "<<linha.getLargura()<<endl;
	
	linha_de_pipa.setLargura(100);
	cout<<"Largura da linha de Pipa:"<<linha_de_pipa.getLargura();
}