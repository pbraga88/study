#include "Person.h"
#include <iostream>

Person::Person()
	: name("[Unknown name]"), age(0)
{}

Person::Person(const string & name, int age)
	: name(name), age(age)
{}

void Person::display() const
{
	cout<< name << ", " << age << endl;
}

Person::~Person()
{
	cout << "Goodbye from the Person destructor!" << endl;
}