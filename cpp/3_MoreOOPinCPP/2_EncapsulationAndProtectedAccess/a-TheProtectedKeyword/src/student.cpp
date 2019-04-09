#include "student.h"
#include <iostream>

using namespace std;

Student::Student()
{

}

Student::~Student()
{

}

void Student::setAge(int age)
{
	if(age < 5){
		cout<<"Student needs to be at least 5 years old"<<endl;
	}
	else
	{
		this->age = age;
	}
}

int Student::getAge()
{
	return this->age;
}

void Student::SayHello()
{
	cout<<"Hello there!"<<endl;
}