#include "person.h"
#include <iostream>

using namespace std;

Person::Person()
{

}

Person::Person(string fName, string lName)
{
	firstName = fName;
	lastName = lName;
}

Person::Person(string fName, string lName, int age)
{
	firstName = fName;
	lastName = lName;

	age = age;
}

Person::~Person()
{
	cout<<"Destructor called as a result of the delete keyword being used"<<endl;
}

void Person::SetFirstName(string fName)
{
	this->firstName = fName;
}

string Person::GetFirstName()
{
	return this->firstName;
}

void Person::SetLastName(string lName)
{
	this->lastName = lName;
}

string Person::GetLastName()
{
	return this->lastName;
}

void Person::SayHello()
{
	cout<<"Hello"<<endl;
}