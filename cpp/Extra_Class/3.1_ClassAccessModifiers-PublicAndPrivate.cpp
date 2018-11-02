#include <iostream>

using namespace std;

class Caixa {
	public:
		double comprimento;
		void setLargura(double larg);
		double getLargura(void);		
	private:
		double largura;	
};

// Defini��o de 'Member functions'
double Caixa::getLargura(void){
	return largura;
}

void Caixa::setLargura(double larg){
	largura = larg;	
}

int main(){
	Caixa caixa;
	
	caixa.comprimento = 10;
	cout<<"Comprimento da caixa: "<<caixa.comprimento<<endl;
	
	//caixa.largura = 10; // Errado, pq largura � privada
	caixa.setLargura(10); // � preciso usar a 'member function'
	cout<<"Largura da caixa: "<<caixa.getLargura()<<endl;
}