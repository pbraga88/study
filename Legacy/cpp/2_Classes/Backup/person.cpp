#include <iostream>
#include "Person.h"

using namespace std;

Person::Person(){
	
}

Person::Person(std::string fName, std::string lName){
	this->firstName = fName;
	this->lastName = lName;
}

Person::Person(std::string fName, std::string lName, int age){
	this->firstName = fName;
	this->lastName = lName;
	this->age = age;
}

Person::~Person(){
	cout<<"Objeto esta sendo apagado"<<endl;
}

void SayHello(){	
}