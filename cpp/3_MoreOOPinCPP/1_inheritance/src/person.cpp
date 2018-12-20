#include <iostream>
#include "person.h"

using namespace std;

// No arguments constructor
Person::Person():name("[Unknown name]"), age(0)
{
	cout<<"Hello from Person::Person()"<<endl;
}

// Parameterized Person constructor
Person::Person(const string & name, int age):name(name), age(age)
{
	cout<<"Hello from Person::Person(string, int)"<<endl;
}

void Person::displayNameAge() const
{
	cout << name <<", "<< age << endl;
}