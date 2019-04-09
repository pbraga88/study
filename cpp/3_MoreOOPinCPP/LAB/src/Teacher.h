#pragma once
#include <string>
#include "Person.h"

using namespace std;

class Teacher : public Person
{
	public:
		Teacher();
		Teacher(string f_name, string l_name, string race, int age, int phone);
		virtual ~Teacher();

		virtual void OutputIdentity() const;
		virtual void OutputAge() const;
};