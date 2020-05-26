#include <iostream>
#include <string>

using namespace std;

// class Pet{
// 	protected:
// 		string name;
// 	public:
// 		void NameMe(string name){
// 			this->name = name;
// 		}
// 		void MakeSound(void){
// 			cout<<name<<" says: no comments"<<endl;
// 		}

// 		/*INTERNAL FOR DEBUG*/
// 		void WhatIsMyName(void){
// 			cout<<"My name is: "<<name<<endl;
// 		}
// };
// void PlayWithPetByPointer(string name, Pet *pet){
// 	pet->NameMe(name);
// 	pet->MakeSound();
// }
// void PlayWithPetByReference(string name, Pet &pet){
// 	pet.NameMe(name);
// 	pet.MakeSound();
// }
// void PlayWithPetByValue(string name, Pet pet){
// 	pet.NameMe(name);
// 	pet.MakeSound();
// }
// int main(void){
// 	/*Passing objects by Pointer and by Reference*/
// 	// Pet *p1 = new Pet;
// 	// Pet p2;
// 	// PlayWithPetByPointer("anonymous", p1);
// 	// PlayWithPetByReference("no_name", p2);
// 	// p1->WhatIsMyName();
// 	// p2.WhatIsMyName();
// 	// PlayWithPetByPointer("no_name_by_ptr", &p2);
// 	// PlayWithPetByReference("anonymous_by_ref", *p1);
// 	// p1->WhatIsMyName();
// 	// p2.WhatIsMyName();
// 	/*********************************************/

// 	/*Passing objects by Value*/
// 	Pet p3;
// 	PlayWithPetByValue("Rex", p3); // Os valores aqui são passados por valor, 
// 	p3.WhatIsMyName(); 			   // ou seja, uma cópia do objeto é passado 
// 								   // para a função, logo essa a chamada de  
// 								   // 'WhatIsMyName()' retornará vazia. 
// 	PlayWithPetByReference("Rex", p3);
// 	p3.WhatIsMyName();

// 	return 0;
// }


/*****Passing an object of a subclass******/
class Pet{
	protected:
		string name;
	public:
		Pet(string name){
			this->name = name;
		}
		// void MakeSound(void){
		virtual void MakeSound(void){
			cout<<name<<" is silent."<<endl;
		}
		void ejecutar(void){
			cout<<name<<" corre!"<<endl;
		}
};
class Dog:public Pet{
	public:
		Dog(string name):Pet(name){}
		void MakeSound(void){
			cout<<name<<" says: Woof!"<<endl;
		}
};
class GermanShepherd:public Dog{
	public:
		GermanShepherd(string name):Dog(name){}
		void MakeSound(void){
			cout<<name<<" says: Wuff!"<<endl;
		}
		void Laufen(void){
			cout<<name<<" run (gs)!"<<endl;
		}
};
class MastinEspanol:public Dog{
	public:
		MastinEspanol(string name):Dog(name){}
		void MakeSound(void){
			cout<<name<<" says: Guau!"<<endl;
		}
		void ejecutar(void){
			cout<<name<<" run (mes)!"<<endl;
		}
};

void PlayWithPet(Pet &pet){
	pet.MakeSound();
}
void PlayWithPet(Pet *pet){
	GermanShepherd *gs;
	MastinEspanol *mes;
	Pet *a_pet;
	pet->MakeSound();
	if(gs = dynamic_cast<GermanShepherd *>(pet)){
		gs->Laufen();
	}
	if(mes = dynamic_cast<MastinEspanol *>(pet)){
		mes->ejecutar();
	}
	a_pet = dynamic_cast<MastinEspanol *>(a_pet);
	// a_pet = new MastinEspanol("rex");
	a_pet->ejecutar();
	cout<<endl;
}
int main(void){
	/*Pass subobject by reference*/
	// Pet pet("creature");
	// Dog dog("Dog");
	// GermanShepherd gs("Hund");
	// MastinEspanol mes("Perro");
	// PlayWithPet(pet);
	// PlayWithPet(dog);
	// PlayWithPet(gs);
	// PlayWithPet(mes);
	/**********/

	/*Pass subobject by pointer*/
	Pet *pet = new Pet("creature");
	Dog *dog = new Dog("Dog");
	GermanShepherd *gs = new GermanShepherd("Hund");
	MastinEspanol *mes = new MastinEspanol("Perro");
	PlayWithPet(pet);
	PlayWithPet(dog);
	PlayWithPet(gs);
	PlayWithPet(mes);

	return 0;
}




