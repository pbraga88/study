#include <iostream>
#include <string.h>
#include "teacher.h"

using namespace std;

Teacher::Teacher(){
}

void Teacher::setTeacherDados(string primNome, string ultNome, int id, string end, string cid, string tel){
	professor.tpNome = primNome;
	professor.tuNome = ultNome;
	professor.tidade = id;
	professor.tendereco = end;
	professor.tcidade = cid;
	professor.ttelefone = tel;
}

string Teacher::getTeacherpNome(void){
	return professor.tpNome;
}
string Teacher::getTeacheruNome(void){
	return professor.tuNome;
}
int Teacher::getTeacherIdade(void){
	return professor.tidade;
}
string Teacher::getTeacherEndereco(void){
	return professor.tendereco;
}
string Teacher::getTeacherCidade(void){
	return professor.tcidade;
}
string Teacher::getTeacherTel(void){
	return professor.ttelefone;
}

void Teacher::GradeStudent(void){
	cout<<"Student graded"<<endl;
}

void Teacher::sitInClass(void){
	cout<<"Sitting at front of class"<<endl;
}

Teacher::~Teacher(){
}