#include <iostream>
#include "teacher.h"
#include "student.h"
#include "course.h"

using namespace std;

int main(){
	Estudante Student1, Student2, Student3;

	Student1.setEstudanteDados("João", "Silva", 20, "Rua A", "Sao Paulo", "1111-1111");
	Student2.setEstudanteDados("Maria", "Souza", 30, "Rua B", "Rio de Janeiro", "2222-2222");
	Student3.setEstudanteDados("Pedro", "Dias", 40, "Rua C", "Minas Gerais", "3333-3333");

	Teacher teacher;
	teacher.setTeacherDados("Alcione", "Vieira", 50, "Rua P", "Sao Paulo", "1010-1010");	

	return 0;
}