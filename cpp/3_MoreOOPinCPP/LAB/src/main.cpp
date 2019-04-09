#include "Student.h"
#include "Teacher.h"


int main()
{
	Person *student = new Student("Joao", "Maria", "branco", 10, 11112222);

	Person *teacher = new Teacher("Maria", "Joao", "Negra", 25, 22221111);

	student->OutputIdentity();
	student->OutputAge();
	teacher->OutputIdentity();
	teacher->OutputAge();

	delete student;
	delete teacher;

	return 0;
}