#include <iostream>
#include <string>

using namespace std;

class Pet{
	protected:
		string Name;
	public:
		Pet(string n){Name = n;}
		void Run(void){cout<<Name<<": I'm running"<<endl;}
};
class Dog:public Pet{
	public:
		Dog(string n):Pet(n){}
		void MakeSound(void){cout<<Name<<": Woof! Woof!"<<endl;}
};
class Cat:public Pet{
	public:
		Cat(string n):Pet(n){}
		void MakeSound(void){cout<<Name<<": Meow! Meow!"<<endl;}
};
class Stray:public Dog{
	public:
		Stray(string nome):Dog(nome){}
};
int main(){
	/* Basic operations */
	// Pet a_pet("pet");
	// Cat a_cat("Tom");
	// Dog a_dog("Spike");

	// a_pet.Run();
	// a_dog.Run();
	// a_dog.MakeSound();
	// a_cat.Run();
	// a_cat.MakeSound();
	/*********************/

	/* Using type cast */
	// Pet *a_pet;
	// a_pet = new Dog("Rex");
	// a_pet->Run();
	// // a_pet->MakeSound(); // Não é permitido, pois o objeto 'a_pet' é da
	// 					   // super classe 'Pet' e o método 'MakeSound()' 
	// 					   // pertence à sub-classe 'Dog'
	
	// static_cast<Cat*>(a_pet)->MakeSound(); // Já, quando o cast é 
							// utilizado é possível acessar o 
							// método MakesSound() da sub-classe. 
							// Aqui, trata-se de um downcast, pois é uma 
							// super classe fazendo cast para uma sub-classe
	// delete a_pet;			

	// // Dog *a_dog = new Pet("Lessie"); // Também não é permitido, pois uma 
	// 					   // sub-classe não pode ser declarada como uma 
	// 					   // super classe
	/*********************/

	/*Lower inheritance*/
	Stray *dog; // Stray é sub-classe de Dog que é sub-classe de Pet
	dog = new Stray("Bito");
	dog->Run();
	dog->MakeSound();

	Pet *a_dog = new Stray("Lessie");
	a_dog->Run();
	static_cast<Dog*>(a_dog)->MakeSound();

	return 0;
}