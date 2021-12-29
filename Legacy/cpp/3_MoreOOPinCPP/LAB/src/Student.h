#pragma once
#include <string>
#include "Person.h"

using namespace std;

class Student : public Person
{
	public:
		Student();
		Student(string f_name, string l_name, string race, int age, int phone);
		virtual ~Student();

		virtual void OutputIdentity() const;
		virtual void OutputAge() const;
};