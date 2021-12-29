#include <iostream>
#include <string>

using namespace std;

class Pet{
	protected:
		string Name;
	public:
		Pet(string n){
			Name = n;
			MakeSound();
		}

		void Run(void){cout<<"SUPERCLASS: "<<Name<<": I'm running"<<endl;}

		// O método MakeSound() agora é escrito com a palavra-chave 'virtual', 
		// o que possibilita sua redefinição pelas sub-classes
		virtual void MakeSound(void){
			cout<<"SUPERCLASS: "<<Name<<" the pet says: shh shh"<<endl;
		}
		void WakeUp(void){
			MakeSound(); // Uma vez que o polimorfismo foi aplicado no método 
						 // 'MakeSound()', o método chamado será o da 
						 // sub-classe 			
		}				 
};
class Dog:public Pet{
	public:
		Dog(string n):Pet(n){}
		void MakeSound(void){
			cout<<"subclass: Polymorphism applied"<<endl;
			cout<<"subclass: "<<Name<<" the dog says: Woof! Woof!"<<endl;
		}
		void Run(void){cout<<"subclass: "<<Name<<": I'm running"<<endl;}
};
class Cat:public Pet{
	public:
		Cat(string n):Pet(n){}
		void MakeSound(void){
			cout<<"subclass: Polymorphism applied"<<endl;
			cout<<"subclass: "<<Name<<" the cat says: Meow! Meow!"<<endl;
		}
		void Run(void){cout<<"subclass: "<<Name<<": I'm running"<<endl;}
};
class Stray:public Dog{
	public:
		Stray(string nome):Dog(nome){}
};
int main(){
	/*****First Example*****/
	// Dog *dog = new Dog("Rex");
	// dog->MakeSound(); // Note que aqui, o método MakeSound() da sub-classe 
	// 				  // sobrescreve o mesmo método da super classe

	// // Uppercast é quando as sub-classe faz um cast para super classe:
	// static_cast<Pet*>(dog)->MakeSound(); // Aqui, como é feito o uppercast, 
	// static_cast<Pet*>(dog)->Run();		 // os dois métodos utilizados são 
	// 									 // da super classe

	// Cat *cat = new Cat("Luis");
	// cat->MakeSound();
	// static_cast<Pet*>(cat)->MakeSound();
	// static_cast<Pet*>(cat)->Run();
	/************************/

	/*****Second Example*****/
	// Pet *a_pet1, *a_pet2;
	// Cat *a_cat;
	// Dog *a_dog;

	// // A diferença aqui é que os objetos do tipo Pet apontam para os objetos
	// // dos tipos Dog e Cat, respectivamente
	// a_pet1 = a_dog = new Dog("Doggie");
	// a_pet2 = a_cat = new Cat("Kitty");
	// a_pet1->MakeSound(); // O efeito é o mesmo do static-cast anterior: o 
	// 					 // MakeSound() da super classe é chamado
	// a_dog->MakeSound();
	// a_pet2->MakeSound();
	// a_cat->MakeSound();
	/************************/

	/*****Polymorphism*****/
	// Cat *cat = new Cat("Kitten");
	// Dog *dog = new Dog ("Doge");
	// cat->MakeSound();
	// cat->Run();
	// static_cast<Pet*>(cat)->MakeSound(); //Aqui, mesmo fazendo o uppercast, o 
	// 									 // método utilizado é o da sub-classe, 
	// 									 // pois 'MakeSound()' foi redefinido 
	// 									 // utilizando-se de polimorfismo, uma vez 
	// 									 // que o mesmo método foi declarado 
	// 									 // como virtual na super classe  
	
	// static_cast<Pet*>(cat)->Run();// Já aqui, o método utilizado é o da 
	// 							  // super classe, pois tal método não foi 
	// 							  // declarado com a palavra-chave 'virtual'

	// dog->MakeSound();
	// dog->Run();
	// static_cast<Pet*>(dog)->MakeSound();
	// static_cast<Pet*>(dog)->Run();

	/*****More Polymorphism*****/
	Dog *dog = new Dog("Doge");
	Cat *cat = new Cat("Kitten");

	dog->WakeUp();
	cat->WakeUp();

	return 0;
}
