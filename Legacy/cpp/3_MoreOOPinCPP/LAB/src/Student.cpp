#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

Student::Student()
{}

Student::Student(string f_name, string l_name, string race, int age, int phone)
	: Person(first_name, last_name, race, age, phone)
{}

void Student::OutputIdentity() const
{
	cout << "I am a student." << endl;
}

void Student::OutputAge() const
{
	cout << "I am a student." << endl;
	Person::OutputAge();
}

Student::~Student()
{
	cout << "This is the Student destructor." << endl;
}