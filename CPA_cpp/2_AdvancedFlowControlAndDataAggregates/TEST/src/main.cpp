#include <iostream>
#include <string.h>

using namespace std;

int main(){
/******************if and else**************************/
	// float x;
	// cout<<"Tell me the temperature"<<endl;
	// cin>>x;
	// if(x<20)
	// 	cout<<"Well, it's cold out there!"<<endl;
	// else if(x<30)
	// 	cout<<"That's good, for me!"<<endl;
	// else
	// 	cout<<"It's a bit hot!"<<endl;
/******************************************************/

/****************Loop While*****************************/
	// int max = -99999;
	// int number=0;

	// while(number != -1){
	// 	cin>>number;
	// 	if(number>max)
	// 		max = number;
	// }
	// cout<<max<<endl;
/******************************************************/

/*****************Bit Mask*****************************/
	// int mask = 8;
	// int flagRegister = 0;

	// if(flagRegister & mask)
	// 	cout<<"set"<<endl;
	// else
	// 	cout<<"unset"<<endl;

	// /*To Set the Mask with disjunction*/
	// flagRegister |= mask;
	// if(flagRegister & mask)
	// 	cout<<"set"<<endl;
	// else
	// 	cout<<"unset"<<endl;

	//  /*To unset with conjunction plus negation*/
	// flagRegister &= ~mask;
	// if(flagRegister & mask)
	// 	cout<<"set"<<endl;
	// else
	// 	cout<<"unset"<<endl;

	// /* To flip with XOR*/
	// for(int i = 0; i <= 10; i++){
	// 	flagRegister ^= mask;
	// 	cout<< "flip to: ";
	// 	if(flagRegister & mask)
	// 		cout<<"set"<<endl;
	// 	else
	// 		cout<<"unset"<<endl;
	// }
/******************************************************/

/***************Shifting*******************************/
	// int var = 8;
	// cout<< "valor inicial de var: " << var << endl;
	// var = var << 2;
	// cout<<"var 'shifted' 2 casas pra esquerda: " << var <<endl;

	// var>>=3;
	// cout<<"var 'shifted' 3 casas pra direita: " << var << endl;

// /****************Arrays*********************************/
// 	int array[] = {0,1,2,3,4,5,6,7,8,9};
// 	int size = sizeof(array)/sizeof(array[0]);
// 	cout << size << endl;
/******************************************************/

// /********************Structures******************************/
// 	struct BDATE {
// 		int dia, mes, ano;
// 	};

// 	struct ESTUD {
// 		string nome;
// 		int idade;
// 		BDATE data;
// 	}joao = {"Joao", 10, {02, 04, 2010}};;

// 	ESTUD estudante = {"Paulo", 31, {13, 12, 1988}};
// 	// joao.nome = "Joao";

// 	cout<<estudante.nome<<endl;
// 	cout<<estudante.idade<<endl;
// 	cout<<estudante.data.dia<<endl;
// 	cout<<estudante.data.mes<<endl;
// 	cout<<estudante.data.ano<<endl;

// 	cout<<joao.nome<<endl;
/******************************************************/

/*****************QUIZ********************************/
	// struct A{
	// 	int a;
	// 	char b;
	// };

	// struct B{
	// 	char a;
	// 	int b;
	// };

	// A a = {2, 'A'};
	// B b = {'C', 1};

	// cout<<b.a - a.b - b.b + a.a << endl;
/******************************************************/

/******************Chapter 2 Assessment****************/
	/*Question 01
	Resposta: 1000000000000000.000000
	Minha Resposta:1000000000000000.000000*/
	// double big = 1e15; //double	-> 8 bytes (64 bits)
	// double small = 1e-15;
	// cout<<fixed<<<<big+small<<endl;

	/*Question 02
	Resposta: 05
	Minha Resposta: 05 */
	// int i = 5, j = 0;
	// while(i>0){
	// 	i--;
	// 	j++;
	// }
	// cout<<j<<endl;

	/*Question 3
		Resposta: 113
		Minha Resposta: 113 */
		int a = 1, b = 2;
		int c = a | b;
		int d = c & a;
		int e = d ^ 0; // ^ = XOR. Verdadeiro se os bits comparados forem diferentes
		cout<< e << d << c <<endl;

	/*Question 04
		Resposta: *****
		Minha Resposta: ***** */
	// for(float val = -10.0; val < 100.0; val = -val * 2)
	// 	cout<<"*";
	// cout<<endl;

	/*Question 05
	Resposta: 0
	Minha Resposta: 0 */
	// int a = 1, b = 2;
	// int c = a << b;
	// int d = 1 << c;
	// int e = d >> d;
	// cout<<e<<endl;

	/*Question 06
	Resposta: 4
	Minha Resposta: 4 */
	// int a = 2;
	// switch(a << a){ // Este swhitch não altera o valor de a, somente manipula o valor a ser
	// 								 // considerado para a operação switch case
	// 	case 8:
	// 		cout<<"DEBUG: a="<<a<<endl;
	// 		a++;
	// 	case 4:
	// 		cout<<"DEBUG: a="<<a<<endl;
	// 		a++;
	// 	case 2: break;
	// 	case 1: a--;
	// }
	// cout<<a<<endl;

	/*Question 07
	Resposta: 1
	Minha Resposta: 1 */
	// bool t[5];
	// for(int i = 0; i<5; i++)
	// 	t[4 - i] = !(i % 2);
	// cout << (t[0] && t[2]) <<endl;

	/*Question 08
	Resposta: 5
	Minha Resposta: 5 */
	// int a[] = {4, 0, 3, 1, 2};
	// int b[] = {1, 2, 3, 4, 5};
	//
	// for(int i = 0; i<5; i++){
	// 	b[a[i]] = b[4 - i];
	// 	cout<<"DEBUG: a["<<a[i]<<"]"<<endl;
	// }
	// cout<<b[0]<<b[4]<<endl;

	/*Question 09
	Resposta: 132
	Minha Resposta: 132 */
	// struct str {
	// 	int t[3];
	// 	char s[3];
	// };
	// str z[3];
	// for(int i = 0; i < 3; i++){
	// 	for(int j = 0; j < 3; j++) {
	// 		// Note que aqui a posição z[i].s[j] refere-se a um caracter, portanto o valor
	// 		// z[i].s[j] pode ser, no máximo, igual a 4, levando em conta que as variáveis i e
	// 		// j só podem ir até 2, veja o exemplo:
	// 		// z[2].s[2] = '0' + 2 + 2 = 4
	// 		z[i].s[j] = '0' + i + j;
	// 		cout<<"DEBUG: z["<<i<<"].s["<<j<<"] = "<< z[i].s[j] <<endl;
	// 		z[j].t[i] = i + j;
	// 		cout<<"DEBUG: z["<<j<<"].t["<<i<<"] = "<< z[j].t[i] <<endl;
	// 	}
	// }
	// cout<< z[0].s[1] << z[1].t[2] << z[2].s[0] <<endl;

	/*Question 10
	Resposta: 34
	Minha Resposta: 34 */
// 	struct sct{
// 		int t[2];
// 	};
// 	struct str{
// 		sct t[2];
// 	};
//
// 	str t[2] = {{0,2,4,6}, {1,3,5,7}};
// 	cout<< t[1].t[0].t[1] << t[0].t[1].t[0] <<endl;
//
// 	return 0;

return 0;

}
