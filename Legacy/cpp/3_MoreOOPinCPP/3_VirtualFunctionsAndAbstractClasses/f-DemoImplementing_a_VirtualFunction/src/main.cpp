#include "Student.h"

void demoFunction1(Person *ptr);
void demoFunction2(Person &ref);

int main()
{
	Person *p = new Student("Jane Smth", 18, "Physics");

	p->display();

	demoFunction1(p); // Chamá a função por ponteiro 
	demoFunction2(*p); // Chama a função por referência

	delete p;

	return 0;
}

void demoFunction1(Person *ptr) // Person *ptr = p;
{
	ptr->display();
}

void demoFunction2(Person &ref) // Person &ref = *p;
{
	ref.display();
}