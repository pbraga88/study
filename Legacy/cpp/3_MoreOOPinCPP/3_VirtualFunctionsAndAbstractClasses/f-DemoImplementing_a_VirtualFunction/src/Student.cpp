#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
	: course("[Unassigned Course]")
{}

Student::Student(const string &name, int age, const string &course)
	: Person(name, age), course(course)
{}

void Student::display() const
{
	// Call base-class version of display, to display person-related info.
	Person::display();

	// Now display the student-related info
	cout<<course<<endl;
}

Student::~Student()
{
	cout<<"Goodbye from the Student destructor"<<endl;
}