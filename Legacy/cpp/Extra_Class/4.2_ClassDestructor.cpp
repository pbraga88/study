#include <iostream>

using namespace std;

class Linha{
	public:
		void setComp(double comp);
		double getComp(void);
		Linha(); //Constructor
		~Linha(); //Destructor
	private:
		double comprimento;
};
// Definição das funções membro. Incluindo Contructor e Destructor
Linha::Linha(void){
	cout<<"Objeto esta sendo criado"<<endl;
}
Linha::~Linha(void){
	cout<<"Objeto esta sendo apagado"<<endl;
}
void Linha::setComp(double comp){
	comprimento = comp;
}
double Linha::getComp(void){
	   return comprimento;	
}

int main(){
	Linha linha;
	linha.setComp(10.0);
	
	cout<<"Comprimento da linha: "<<linha.getComp()<<endl;
	
	return 0;
	
}