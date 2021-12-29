#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

Person::Person()
	: first_name("Unknown first name"), last_name("Unknown last name"), race("Unknown race"), 
		age(0), phone(0)
{}

Person::Person(string f_name, string l_name, string race, int age, int phone)
	:	first_name(f_name), last_name(l_name), race(race), age(age), phone(phone)
{} 

void Person::OutputIdentity() const
{
}

void Person::OutputAge() const
{
	cout<< "I am " << age << " years old." << endl;
}

Person::~Person()
{
	cout<< "This is the Person destructor." << endl;
}