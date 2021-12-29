#include <iostream>
#include <string.h>
#include "student.h"

using namespace std;

Estudante::Estudante(){
}

void Estudante::setEstudanteDados(string primNome, string ultNome, int id, string end, string cid, string tel){
	int n;
	for(n = 0; n<=3; n++){
		if(!estudante[n].pNome.size()){
			estudante[n].pNome = primNome;
			estudante[n].uNome = ultNome;
			estudante[n].idade = id;
			estudante[n].endereco = end;
			estudante[n].cidade = cid;
			estudante[n].telefone = tel;
			break;
		}
	}
}

string Estudante::getEstudantepNome(int i){
	return estudante[i].pNome;
}
string Estudante::getEstudanteuNome(int i){
	return estudante[i].uNome;
}
int Estudante::getEstudanteIdade(int i){
	return estudante[i].idade;
}
string Estudante::getEstudanteEndereco(int i){
	return estudante[i].endereco;
}
string Estudante::getEstudanteCidade(int i){
	return estudante[i].cidade;
}
string Estudante::getEstudanteTel(int i){
	return estudante[i].telefone;
}

void Estudante::SitInClass(void){
	cout<<"Sitting in main theater"<<endl;
}

Estudante::~Estudante(){
}