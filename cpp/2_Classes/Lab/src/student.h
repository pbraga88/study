#include <string.h>
#include "course.h"
#pragma once

using namespace std;

class Estudante:Course{
	public:
		Estudante();
		~Estudante();
		
		void setEstudanteDados(string primNome, string ultNome, int id, string end, string cid, string tel);
		string getEstudantepNome(int i);
		string getEstudanteuNome(int i);
		int getEstudanteIdade(int i);
		string getEstudanteEndereco(int i);
		string getEstudanteCidade(int i);
		string getEstudanteTel(int i);
 
		void SitInClass(void);

};