#pragma once
#include <string>

using namespace std;

class Person{
	private:
		string name;

	protected:
		int age;

	public:
		Person();
		Person(const string & name, int age);

		void displayNameAge() const;

};