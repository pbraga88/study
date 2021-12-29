#include <string.h>
#pragma once

using namespace std;

class Course{
	public:
		Course();
		~Course();
	
	protected :
		struct{
			string pNome;
			string uNome;
			int idade;
			string endereco;
			string cidade;
			string telefone;
		}estudante[2];	
		
		struct teacher{
			string tpNome;
			string tuNome;
			int tidade;
			string tendereco;
			string tcidade;
			string ttelefone;
		}professor;
};