#include <iostream>
#include "student.h"

using namespace std;

int main()
{
	// Create a Student object using the no-argument constructor
	Student student1;
	student1.displayNameAge();
	student1.displayCourse();

	// Create a Student object using the parameterized constructor
	Student student2("Jane Smith", 18, "Phisics");
	student2.displayNameAge();
	student2.displayCourse();

	return 0;
}