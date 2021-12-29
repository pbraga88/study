#pragma once

#include <string>

using namespace std;

class Person{
	private:
		string firstName;
		string lastName;
	
	protected:
		int age; // a variável age, é agora acessível por outras classes que declararem 'public', assim
				 // como as variáveis públicas abaixo 

	public:
		Person();
		Person(string fName, string lName);
		Person(string fName, string lName, int age);
		~Person();

		void SetFirstName(string fName);
		string GetFirstName();

		void SetLastName(string lName);
		string GetLastName();

		void SayHello();

};