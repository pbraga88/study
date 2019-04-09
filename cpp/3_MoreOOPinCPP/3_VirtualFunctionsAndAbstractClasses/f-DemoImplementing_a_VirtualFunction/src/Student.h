#pragma once

#include "Person.h"

using namespace std;

class Student : public Person
{
	private:
		string course;

	public:
		Student();
		Student(const string &name, int age, const string &course);

		virtual void display() const;

		virtual ~Student();
};