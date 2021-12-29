#include <iostream>

using namespace std;

class Linha{
	public:
		int getComprimento(void); 
		Linha(int comp); // Constructor simples
		Linha(const Linha &obj); // Cópia do Contructor
		~Linha(); // Destructor 
	private:
		int *ptr;	
};

/****Definição das funções membro, incluindo contructor****/
Linha::Linha(int comp){
	cout<<"Contructor para alocar memory ao ponteiro ptr"<<endl;
	
	// alocando a memória para o ponteiro
	ptr = new int;
	*ptr = comp;	
}

Linha::Linha(const Linha &obj){
	cout<<"Copy do contructor. Alocando ptr"<<endl;
	ptr = new int;
	*ptr = *obj.ptr; // Copia o valor
}

Linha::~Linha(void){
	cout<<"Liberando memory"<<endl;
	delete ptr;
}

int Linha::getComprimento(void){
	return *ptr;
}

void display(Linha obj){
	cout<<"Comprimento da linha: "<<obj.getComprimento()<<endl;
}
/****Main Function****/
int main(){
	Linha linha(10);
	
//	Linha linha2 = linha;
	
	display(linha);
//	display(linha2);
	
	return 0;	
}
