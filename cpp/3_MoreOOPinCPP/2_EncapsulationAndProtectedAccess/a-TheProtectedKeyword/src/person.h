#pragma once

#include <string>

using namespace std;

class Person{
	private:
		string firstName;
		string lastName;
	
	protected:
		int age;

	public:
		Person();
		Person(string fName, string lName, int age);
		~Person();

		void SetFirstName(string fName);
		string GetFirstName();

		void SetLastName(string lName);
		string GetLastName();

		void SayHello;

};