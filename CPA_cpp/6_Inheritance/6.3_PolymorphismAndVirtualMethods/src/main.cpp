#include <iostream>
#include <string>

using namespace std;

class Pet{
	protected:
		string Name;
	public:
		Pet(string n){Name = n;}
		void Run(void){cout<<Name<<": I'm running"<<endl;}
		void MakeSound(void){cout<<Name<<" the pet says: shh shh"<<endl;}
};
class Dog:public Pet{
	public:
		Dog(string n):Pet(n){}
		void MakeSound(void){cout<<Name<<" the dog says: Woof! Woof!"<<endl;}
};
class Cat:public Pet{
	public:
		Cat(string n):Pet(n){}
		void MakeSound(void){cout<<Name<<" the cat says: Meow! Meow!"<<endl;}
};
class Stray:public Dog{
	public:
		Stray(string nome):Dog(nome){}
};
int main(){
	Dog *dog = new Dog("Rex");
	dog->MakeSound(); // Note que aqui, o método MakeSound() da sub-classe 
					  // sobrescreve o mesmo método da super classe

	// Uppercast é quando as sub-classe faz um cast para super classe:
	static_cast<Pet*>(dog)->MakeSound(); // Aqui, como é feito o uppercast, 
	static_cast<Pet*>(dog)->Run();		 // os dois métodos utilizados são 
										 // da super classe

	Cat *cat = new Cat("Luis");
	cat->MakeSound();
	static_cast<Pet*>(cat)->MakeSound();
	static_cast<Pet*>(cat)->Run();

	return 0;
}