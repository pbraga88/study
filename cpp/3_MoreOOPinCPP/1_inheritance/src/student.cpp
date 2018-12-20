#include <iostream>
#include "student.h"

using namespace std;

// No argument Student constructor
Student::Student() : course("[Unassigned Course]")
{
	cout << "Hello from Student::Student()" << endl;
}

// Parameterized Student constructor
Student::Student(const string & name, int age, const string & course) : Person(name, age), course(course)
{
	cout << "Hello from Student::Student(string, int, string)" << endl;
}

void Student::displayCourse() const
{
	cout << course <<endl;
}