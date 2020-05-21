#include <iostream>

using namespace std;


/***** Simple subclass use *****/
// class Super{
// 	protected: // Como agora a palavra-chave 'protected' é utilizada, a variável
// 			   // storage torna-se acessível pela sub-classe
// 		int storage; 
// 	public: 
// 		void put(int val){storage = val;}
// 		int get(void){return storage;}
// };

// class Sub:public Super{ // Aqui, a keyword 'public' é utilizada como 
// 						// visibility specifier, fazendo com que os métodos 
// 						// públicos da super classe fiquem visíveis
// 	public:
// 		void print(){cout<<storage<<endl;}
// };

// int main(){
// 	// Super object;
// 	// object.put(100);
// 	// object.put(object.get()+1);
// 	// cout<<object.get()<<endl;

// 	// Sub object;
// 	// object.put(100);
// 	// object.put(object.get()+1);
// 	// cout<<object.get()<<endl;

// 	Sub object;
// 	object.put(100);
// 	object.put(object.get()+1);
// 	object.print();
// 	return 0;
// }
/********************************/

/***** Double subclass use *****/
class Super_A{
	protected:
		int value;
	public:
		void set(int val){value = val;}
		int get(void){return value;}
};
class Super_B{
	protected:
		int valor;
	public:
		void poe(int num){valor = num;}
		int tira(void){return valor;}
};
class Sub:public Super_B, public Super_A{
	public:
		void print(){
			cout<<"valor = "<< valor <<endl;
			cout<<"value = "<< value <<endl;
		}
};

int main(){

	Sub objeto;
	objeto.set(1);
	objeto.poe(2);
	objeto.set(objeto.tira() + objeto.get());
	objeto.poe(objeto.tira() + objeto.get());
	objeto.print();

	return 0;
}
