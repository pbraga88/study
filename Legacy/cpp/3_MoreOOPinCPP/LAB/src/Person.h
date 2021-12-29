#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person{
	public:
		Person();
		Person(string f_name, string l_name, string race, int age, int phone);
		virtual ~Person();

		virtual void OutputIdentity() const;
		virtual void OutputAge() const;

		string first_name;
		string last_name;
		string race;

	private:
		int age;
	
	protected:
		int phone;

};