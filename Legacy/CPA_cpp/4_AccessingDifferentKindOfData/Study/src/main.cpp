#include <iostream>
#include <string>

// using namespace std;
//
// int main(){
/******Regular two dimensional array********************************/
	// int rows = 5;
	// int columns = 5;
	// int **array;
	// array = new int* [rows];
	// for(int r = 0; r < rows; r++){
	//  	array[r] = new int[columns];
	//  }
	//  *(*(array)) = 1;
	//  cout<<array[0][0]<<endl;

	//  *(*(array)+2) = 2;
	//  cout<<array[0][2]<<endl;

	//  *(*(array+2)) = 3;
	//  cout<<array[2][0]<<endl;

	//  *(*(array+2)+2) = 10;
	//  cout<<array[2][2]<<endl;

	//  *(*(array+2)+3) = 10;
	//  cout<<array[2][3]<<endl;

	//  for (int r = 0; r<rows; r++){
	//  	for (int c = 0; c<columns; c++)
	//  		cout<<*(*(array+r)+c)<< " "; // Dereferenciando os ponteiros
	//  		// cout<<array[r][c]<<" ";   // Usando notação de matriz
	//  	cout<<endl;
	//  }

	//  // Free the array
	//  for (int r = 0; r<rows; r++)
	//  	delete []array[r]; // free linha por linha
	//  delete []array; // e finalmente, deleta a array
/*****************************************************************/

/******Triangular two dimensional array********************************/

	// int rows = 5;
	// int **array;
	// // Alocando e inicializando a array
	// array = new int*[rows];
	//
	// for(int r = 0; r<rows; r++){
	// 	// array[r] = new int[r+1];
	// 	*(array + r) = new int[r+1];
	// 	for (int c = 0; c <= r; c++)
	// 		// array[r][c] = (r+1)*10 + c + 1;
	// 		// (*(array+r))[c] = (r+1)*10 + c + 1;
	// 		// *((array[r])+c) = (r+1)*10 + c + 1;
	// 		*(*(array+r)+c) = (r+1)*10 + c + 1;
	// }
	//
	// // Print
	// for(int r = 0; r<rows; r++){
	// 	for (int c = 0; c <= r; c++)
	// 		// cout<<array[r][c]<<" ";
	// 		cout<<*(*(array + r) + c)<<" ";
	// 	cout<<endl;
	// }
	//
	// //Delete
	// for(int r = 0; r<rows; r++)
	// 	// delete []array[r];
	// 	delete *(array + r);
	// // delete []array;
	// delete *array;
/*****************************************************************/

	// double d = 1.23;
	// int k = (int)d;
	// cout<<k<<endl;

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
	// for(int i=0; i<10; i++){
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
	// cout<<s.length()<<endl;
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
	// string s = "content";
	// for(unsigned int i = 0; i<s.size(); i++)
	// 	s[i] = s[i] - 'a' + 'A'; // Baseia-se na tabela ASCII para mudar de minúscula
	// 													 // para maiúscula (APENAS EXEMPLO)
	// cout<<s<<endl;

// 	return 0;
// }

// using namespace std;
//
// int main(){
  /*************** append() ********************/
  // string str1 = "Content", str2 = "appendix";
  // cout<<str1.append(str2)<<endl;

  // string string_one = "content";
  // string string_two;
  // string_two.append(string_one);
  // string_two.append(string_one, 0, 3);
  // string_two.append(2, '!');
  // cout<<string_two<<endl;
  /********************************************/

  /***************** push_back() ***************/
  // string alphabet;
  // for(char c = 'A'; c <= 'Z'; c++)
  //   alphabet.push_back(c);
  // cout<<alphabet<<endl;
  // cout<<alphabet.size()<<endl;
  /********************************************/

  /***************** insert() *****************/
  // string quote = "whyserious", anyword = "monsoon";
  // quote.insert(3,2,' ');
  // quote.insert(4, anyword, 3, 2).append("?!");
  // cout<<quote<<endl;
  /********************************************/

  /***************** assign() *****************/
  // string sky;
  // sky.assign("?!");
  // cout<<sky<<endl;
  // sky.assign(80, '*');
  // cout<<sky<<endl;
  /********************************************/

  /***************** replace() ****************/
  // string ToDo = "I'll think about that in one hour";
  // string Schedule = "today yesterday tomorrow";
  // ToDo.replace(22,11, Schedule,16,8);
  // ToDo.append(4,'!');
  // cout<<ToDo<<endl;

  // string s = "Ola como vai?";
  // string s_2 = "tudo bem tudo certo onde esta";
  // s.replace(4,8, s_2,9,10);
  // s.insert(3,1,',');
  // s.append("!");
  // cout<<s<<endl;
  /********************************************/

  /***************** erase() ******************/
  // string WhereAreWe = "I've got a feeling we're not in Kansas anymore";
  // WhereAreWe.erase(38,8).erase(25,4);
  // cout<<WhereAreWe<<endl;
  //
  // string s = "Ola, tudo bem?";
  // s.erase(3,11);
  // cout<<s<<endl;
  // s.erase();
  // cout<<s<<endl;
  /********************************************/

  /***************** swap() ******************/
  // string s = "Agua";
  // string s_2 = "Cerveja";
  // cout<<"s = "<<s<<". "<<"s_2 = "<<s_2<<endl;
  // s.swap(s_2);
  // cout<<"s = "<<s<<". "<<"s_2 = "<<s_2<<endl;
  /********************************************/

//   return 0;
// }

/******************************************************************************/
// namespace first{
//   int mult(int val){
//     return val*10;
//   }
// }
//
// namespace second{
//   int x_second = 100;
//   int mult(int val){
//     return val*x_second;
//   }
// }
//
// namespace first{
//   float div(float var, float sec_var){
//     return var/sec_var;
//   }
// }
//
// namespace second{
//   int div(int var, int sec_var){
//     return var%sec_var;
//   }
//
// }
//
// namespace{ //Use together with line 63
//   int mult(int val){
//     return 4*val;
//   }
// }
//
// // namespace fdm = first;
//
// using namespace std;

// int main(){
//   /*Using namespace for second{} only*/
//   // using namespace second;
//   // int x = x_second;
//   // cout<<first::mult(5)<<endl;
//   // cout<<mult(10)<<endl;
//   // cout<<x<<endl;
//
//   /*Using namespace insde a block*/
//   // {
//   //   using namespace first;
//   //   cout<<mult(4)<<endl;
//   //   cout<<div(10, 4)<<endl;
//   // }
//   // {
//   //   using namespace second;
//   //   cout<<mult(10)<<endl;
//   //   cout<<x_second<<endl;
//   // }
//
//   /*Selectively decide namespace entity*/
//   // using first::mult;
//   // using second::div;
//   // cout<<mult(50)<<endl;
//   // cout<<div(10,4)<<endl;
//
//   /*Use of Anonymous namespace (line 29)*/
//   cout<<mult(4)<<endl;
//   cout<<first::mult(4)<<endl;
//   cout<<second::mult(4)<<endl;

  /* Rename of namespace (line 35)*/
  // {
  //   using namespace fdm;
  //   cout<<div(10,4)<<endl;
  //   cout<<mult(5)<<endl;
  // }

// 	cout<<"b"+"c"<<endl;
//   return 0;
// }
