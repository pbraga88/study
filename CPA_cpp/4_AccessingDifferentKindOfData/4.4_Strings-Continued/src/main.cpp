#include <iostream>
#include <string>

using namespace std;

int main(){
	/********************Substrings****************/
	// string s = "ABCDEF";
	// s = s.substr(1,1)+s.substr(4)+s.substr();
	// cout<<s<<endl;
	/**********************************************/

	/********************Substrings + size****************/
	// string s = "12345";
	// int string_size = s.size();
	// cout<<string_size<<endl;
	// // Como substring, no final das contas, também é uma string, o uso aninhado
	// // da função substring() é possível. Ou seja, uma substring é aplicada no
	// // retorno da função substring() anterior
	// cout<<s.substr(1).substr(1).substr(1).size()<<endl;
	/***************************************************/

	/****************More of strings Comparison***********/
	// string s = "ABC";
	// cout<<s.compare(1,1,"BC") + s.compare(2,1,s,2,2)<<endl;
	/*****************************************************/

	/******************** Find ***************************/
	// string greeting = "hello there! how are you?";
	// string polite = "hello";
	// int position;
	//
	// if(greeting.find(polite) != string::npos)
	// 	cout<<"Yes, he's polite."<<endl;
	//
	// if(greeting.find('?') != string::npos) // npos null(-1) position
	// 	cout << "And uses correct punctuation!" <<endl;
	// // encontra a string how e imprime a partir dela
	// position = greeting.find("how");
	// cout<<position<<endl;
	// cout<<greeting.substr(position)<<endl;
	// // Encontra o caracter '!' e imprime apenas ele
	// position = greeting.find('!');
	// cout<<position<<endl;
	// cout<<greeting.substr(position, 1)<<endl;

	/*****************************************************/

	/******************** Buffer *************************/
	// string s = "Hi";
	// int size = s.size();
	// int capacity = s.capacity();
	// double max_size = s.max_size();
	// cout<<"Tamanho da string (size): "<<size<<endl;
	// cout<<"Buffer alocado (capacity): "<<capacity<<endl;
	// cout<<"Tamanho máximo de alocação: "<<max_size<<endl;
	// cout<<"==========================="<<endl;
	// for(int i=0; i<100; i++){
	// 		s+=s;
	// 		{
	// 			cout<<"Tamanho da string (size): "<<s.size()<<endl;
	// 			cout<<"Buffer alocado (capacity): "<<s.capacity()<<endl;
	// 			cout<<"Tamanho máximo de alocação: "<<s.max_size()<<endl;
	// 			cout<<"==========================="<<endl;
	// 		}
	// }
	/*****************************************************/

	/***************** Control Buffer size ***************/
	// string s = "ContentoooooooOOOOOO";
	// s.reserve(100);
	// cout<<s.capacity()<<endl;
	//
	// s.reserve(0);
	// cout<<s.capacity()<<endl;
	/*****************************************************/

	/******************** String content *****************/
	// string s = "Hello There";
	// cout<<s<<endl;
	// cout<<"Size: "<<s.size()<<endl;
	// cout<<"Capacity: "<<s.capacity()<<endl;
	// cout<<"=========================="<<endl;
	// s.resize(50);
	// {
	// 	cout<<s<<endl;
	// 	cout<<"Size: "<<s.size()<<endl;
	// 	cout<<"Capacity: "<<s.capacity()<<endl;
	// 	cout<<"=========================="<<endl;
	// }
	//
	// s.resize(20,'!');
	// {
	// 	cout<<s<<endl;
	// 	cout<<"Size: "<<s.size()<<endl;
	// 	cout<<"Capacity: "<<s.capacity()<<endl;
	// 	cout<<(s.empty() ? "yes":"no")<<endl;
	// 	cout<<"=========================="<<endl;
	// }
	//
	// s.clear();
	// {
	// 	cout<<s<<endl;
	// 	cout<<"Size: "<<s.size()<<endl;
	// 	cout<<"Capacity: "<<s.capacity()<<endl;
	// 	cout<<(s.empty() ? "yes":"no")<<endl;
	// 	cout<<"=========================="<<endl;
	// }
  /*****************************************************/

	/*************** Manipulando strings *****************/
	string s = "Content";
	for(unsigned int i = 0; i<s.size(); i++)
		s[i] = s[i] - 'a' + 'A'; // Baseia-se na tabela ASCII para mudar de minúscula
														 // para maiúscula (APENAS EXEMPLO)
	cout<<s<<endl;

	/*****************************************************/
	return 0;
}
