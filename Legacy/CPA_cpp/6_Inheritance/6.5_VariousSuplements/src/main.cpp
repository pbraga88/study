#include <iostream>
#include <string>

using namespace std;

// class Class{
// 	int *data;
// public:
// 	// Class(int value):data(value){} // Constrói o objeto passando o valor em 
// 								   // 'value' para 'data'
// 	Class(int value){   // Agora, como a variável 'data' é um ponteiro, ela é 
// 		data = new int;	// iniciada como 'int' e receve 'value'
// 		*data = value;
// 	}
// 	void increment(){(*data)++;}
// 	int value(){return *data;}
// };

// int main(){
// 	Class o1(123);
// 	Class o2 = o1;
// 	Class o3(o2);

// 	o1.increment(); // Incrementa todos os objetos declarados, pois a  
// 					// variável data da classe é um ponteiro
// 	cout<<o1.value()<<endl; 
// 	cout<<o2.value()<<endl;
// 	cout<<o3.value()<<endl;

// 	return 0;
// }
/***********************************************/

/************Utilizando o 'copy constructor'************/
// class Class{
// 	int *data;
// public:
// 	Class(int value){
// 		data = new int;
// 		*data = value;
// 	}
// 	Class(Class &source){ // O 'copy constructor' é utilizado aqui e todos 
// 						  // copiados de um objeto desta classe utilizarão
// 						  // este contrutor
// 		data = new int;
// 		*data = source.value() + 10;
// 		// *data = 10;
// 	}
// 	void increment(){(*data)++;}
// 	int value(){return *data;}
// };

// int main(){
// 	Class o1(123);
// 	Class o2 = o1;
// 	Class o3(o2);

// 	o1.increment();
// 	cout<<o1.value()<<endl; 
// 	cout<<o2.value()<<endl;
// 	cout<<o3.value()<<endl;

// 	return 0;
// }
/***********************************************/

/****O 'copy constructor' como patâmetro de função****/
// class Dummy{
// public:
// 	Dummy(){
// 		cout<<"Inside super class!"<<endl;
// 	}
// 	Dummy(Dummy& fonte){
// 		cout<<"Inside copy constructor!"<<endl;
// 	}
// };
// void func(Dummy dum){
// 	cout<<"Inside function "<<__FUNCTION__<<"()"<<endl;
// }
// int main(){
// 	Dummy o1;
// 	func(o1); // Quando a função é chamada, é passada uma cópia do objeto
// 			  // que será iniciado pelo 'copy constructor'
// 	return 0;
// }
/***********************************************/

/**********Mais sobre 'default constructors'**********/
// class WithConstructor{
// public:
// 	int i;
// 	float f;
// 	//O constructor tem valores padrão para as variáveis 'a' e 'b',
// 	//portanto, pode ser chamado sem que nenhum valor seja fornecido.
// 	WithConstructor(int a = 0, int b = 0):i(a), f(b){}
// 	void Display(void){
// 		cout<<"i="<<i<<",f"<<f<<endl;
// 	}
// };
// int main(){
// 	WithConstructor o1;
// 	WithConstructor* o2;
// 	o2 = new WithConstructor;

// 	o1.Display();
// 	o2->Display();

// 	return 0;
// }
/***********************************************/

/*************Class composition******************/
class A{
public:
	A(){cout<<"Default constructor A"<<endl;}
	A(A &source){
		cout<<"copying constructor A..."<<endl;
	}
	void Do(){cout<<"A does something"<<endl;}
};
class B{
public:
	B(){cout<<"Default constructor B"<<endl;}
	B(B &source){
		cout<<"copying constructor B..."<<endl;
	}
	void Do(){cout<<"B does something else"<<endl;}
};
class Compo{
public:
	Compo(){}
	// Compo(Compo &source){
	Compo(Compo &source):f1(source.f1), f2(source.f2){
		cout<<"copying Compo..."<<endl;
	}
	A f1;
	B f2;
};
int main(){
	Compo compA;
	Compo compB(compA);

	compA.f1.Do();
	compB.f2.Do();

	return 0;
}