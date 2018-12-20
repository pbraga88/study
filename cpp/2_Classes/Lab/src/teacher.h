#include <string.h>
#include "course.h"
#pragma once

using namespace std;

class Teacher:Course{
	public:
		Teacher();
		~Teacher();

		void setTeacherDados(string primNome, string ultNome, int id, string end, string cid, string tel);
		string getTeacherpNome(void);
		string getTeacheruNome(void);
		int getTeacherIdade(void);
		string getTeacherEndereco(void);
		string getTeacherCidade(void);
		string getTeacherTel(void);

		void GradeStudent(void);
		void sitInClass(void);
};