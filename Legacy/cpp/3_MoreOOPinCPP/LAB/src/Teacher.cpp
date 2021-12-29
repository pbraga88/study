#include <iostream>
#include <string>
#include "Teacher.h"

using namespace std;

Teacher::Teacher()
{}

Teacher::Teacher(string f_name, string l_name, string race, int age, int phone)
	: Person(first_name, last_name, race, age, phone)
{}

void Teacher::OutputIdentity() const
{
	cout << "I am a teacher." << endl;
}

void Teacher::OutputAge() const
{
	cout << "I am a teacher." << endl;
	Person::OutputAge();
}

Teacher::~Teacher()
{
	cout << "This is the teacher destructor." << endl;
}