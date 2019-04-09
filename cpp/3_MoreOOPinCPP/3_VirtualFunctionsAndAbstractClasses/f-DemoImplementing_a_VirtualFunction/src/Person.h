#pragma once
#include <string>

using namespace std;

class Person
{
	private:
		string name;

	protected:
		int age;

	public:
		Person();
		Person(const string & name, int age);

		virtual void display() const; // Definição da função virtual. Esse tipo de função pode ser sobrescrita
									  // para que sejam adicionados novos métodos.

		virtual ~Person();
};