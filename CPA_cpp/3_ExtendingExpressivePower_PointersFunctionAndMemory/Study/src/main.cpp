#include <iostream>
#include <string>

using namespace std;

/***************** 3.8 - Overloaded Functions *******************/
// int inline bigger(int x, int y, int z){
// 	return x>y ? (x>z ? x : z) : (y>z ? y : z);
// }

// inline int bigger(int x, int y){
// 	return x>y ? x : y;
// }

// int main(){
// 	int a = 10, b =13, c = 21;
// 	cout << bigger(a, b) << endl;
// 	cout << bigger(a, b, c) << endl;
// 	return 0;
// }
/**************************************************************/

/****************** 3.9 - Sorting ****************************/

// Essa técnica é conhecida como 'Bubble Sort'
// void sorting(int *ptr, int size) {
// 	int i;
// 	bool control = true;
// 	int maior;

// 	while (control){
// 		control = false;
// 		for (i = 0; i < size-1; i++){
// 			if (*(ptr+i) > *(ptr+(i+1))) {
// 				maior = ptr[i];
// 				ptr[i] = ptr[i+1];
// 				ptr[i+1] = maior;
// 				control = true;
// 			}
// 		}
// 	}
// }

// int main(){
// 	int size;
// 	int i;
// 	int array[10] = {8, 10, 6, 2, 4, 10, 90, 8, 9, 10};
// 	int *ptr = array;

// 	size = sizeof(array)/sizeof(array[0]);
// 	for(i=0; i<size; i++)
// 		cout<<array[i]<<endl;

// 	cout<<endl;

// 	sorting(ptr, size);

// 	for(i=0; i<size; i++)
// 		cout<<array[i]<<endl;

// 	return 0;
// }

/**************************************************************/

/****************** 3.9_a - Sorting which returns pointer******/
// int *sorting_ptr(int *ptr, int size) {
// 	int *pointer_to_arr = ptr;
// 	int i;
// 	bool control = true;
// 	int maior;

// 	while (control){
// 		control = false;
// 		for (i = 0; i < size-1; i++){
// 			if (*(ptr+i) > *(ptr+(i+1))) {
// 				maior = ptr[i];
// 				ptr[i] = ptr[i+1];
// 				ptr[i+1] = maior;
// 				control = true;
// 			}
// 		}
// 	}
// 	return pointer_to_arr;
// }
/**************************************************************/

/******************** 3.10 - Memory on demand **************************/

// int main(){
	// int *arr;
	// int i;
	// int nb_qty;

	// cout << "How many numbers to sort?" << endl;
	// cin >> nb_qty;
	// arr = new int[nb_qty]; // Creating a memory block
	// cout << "insert your numbers" << endl;
	// for(i=0; i<nb_qty; i++)
	// 	cin >> arr[i];

	// for(i=0; i<nb_qty; i++)
	// 	cout << arr[i] <<" ";
	// sorting(arr, nb_qty);

// 	cout<<endl;

// 	for(i=0; i<nb_qty; i++)
// 		cout << arr[i] << " ";

// 	cout<<endl;

// 	delete [] arr; // Deleting the memory block

// 	return 0;

// 	// cout << 1/sizeof(float)<<endl;


	/**pointer to void example**/
	// void *ptr = new int[10];

	// int *var = (int*)ptr;
	// *(var+1) = 10;

	// cout<<ptr<<endl;
	// cout<<var<<endl;
	// cout<<var[0]<<endl;
	// cout<<var[1]<<endl;
	/**************************/


	/**********Ponteiro de função (Callback)***************/
	// void (*ptr_to_sorting)(int *pointer, int tam) = &sorting;
	// (*ptr_to_sorting)(arr, nb_qty);
	/* O nome da função pode ser utilizado para obter seu
	endereço, portanto a seguinte declaração também funciona
	(sem contar que é mais simples):*/
	// void (*ptr_to_sorting)(int *pointer, int tam) = sorting;
	// ptr_to_sorting(arr, nb_qty);

	// cout<<endl;

	// for(i=0; i<nb_qty; i++)
	// 	cout << arr[i] << " ";
	// cout<<endl;
	/******************************************************/

	/**********Função que retorna ponteiro***************/
	// int *sort = sorting_ptr(arr, nb_qty);

	// cout<<endl;

	// for(i=0; i<nb_qty; i++)
	// 	cout << sort[i] << " ";
	// cout<<endl;
	/******************************************************/

	/**********Ponteiro de função que aponta para uma função que retorna ponteiro********/
	// int *(*ptr_to_sorting_ptr)(int *array, int tam) = sorting_ptr;
	// int *sort_ret = ptr_to_sorting_ptr(arr, nb_qty);

	// cout<<endl;

	// for(i=0; i<nb_qty; i++)
	// 	cout << sort_ret[i] << " ";
	// cout<<endl;
	/*************************************************************************************/

// 	return 0;
// }


/********************* QUIZZ REVIEW *******************************/
// int main(){
// 	char var = 'z';
// 	char x = (var == 'z' ? 'a' : var + 1);
// 	cout<<x<<endl;

// 	return 0;
// }
/*****************************************************************/

/********************* TEST REVIEW *******************************/
// int main(){
	/*Questão 01
	  Resposta Certa: 22
	  Minha Reposta: 32 */
	int t[3] = {3, 2, 1}, *ptr = t + 1;
	cout<<"DEBUG: *ptr=" << *ptr<<endl;
	cout<<"DEBUG: ptr=" << ptr<<endl;
	(*(ptr+1))++;
	*ptr++; // Note que aqui a operação de soma '++' é aplicada ao endereço (e não ao valor) do
			// ponteiro 'ptr', fazendo com que ele aponte para 't[2]' ou 't + 2'. Também
			// é possível (e torna a leitura do código mais fácil) somar ao endereço sem
			// o uso do operador '*'. Veja:
			// ptr++;
			// Para alterar o valor cujo o ponteiro aponta (dereferenciar), que aqui
			// é o valor em t[1], pode-se utilizar as seguintes notações:
			// '(*(ptr))++;' ou 'ptr[0]++'
	cout<<"DEBUG: *ptr=" << *ptr<<endl;
	cout<<"DEBUG: ptr=" << ptr<<endl;
	cout << t[1] << t[2] <<endl;

	/*Questão 02
	  Resposta Certa: 4.14
	  Minha Reposta: 4.14 */
	// float x = 3.14, *p=&x;
	// p[0] = ++x;
	// cout<<x<<endl;

	/*Questão 03
	  Resposta Certa: 0
	  Minha Reposta: 1 */
	// float f[2];
	// float *p1 = f, *p2 = p1 + 1;
	// cout<<"DEBUG: p2 = "<<p2<<endl;
	// cout<<"DEBUG: p1 = "<<p1<<endl;
	// cout<<"DEBUG: p2 - p1 = "<<(p2-p1)<<endl; // Aqui, a subtração é de endereço de memória,
	// 										  // ou seja,  como são do tiṕo float e ocupam
	// 										  // 4 Bytes cada, fica (e.g os valores diferem,
	// 										  // obivamente, pois são endereços de memória):
	// 										  // p2 = 0x7fff99947054
	// 										  // p1 = 0x7fff99947050
	// 										  // p2 - p1 = 1

	// cout<<(p2-p1)/sizeof(float)<<endl;

// 	return 0;
// }

	/*Questão 04
	  Resposta Certa: 4
	  Minha Reposta: 4 */
	// float Float(float x){
	// 	return 2 * x / (.5 * x);
	// }
	// void Void(int n){
	// 	float v = n;
	// 	while(n){
	// 		v = Float(v);
	// 		n >>=1;
	// 	}
	// 	cout<<v<<endl;
	// }
	// int main(){
	// 	Void(4);
	// 	return 0;
	// }

	/*Questão 05
	  Resposta Certa: 2
	  Minha Reposta: 2 */
	// int f1(int *a){
	// 	return *a;
	// }
	// int *f2(int *a){
	// 	return a;
	// }
	// int *f3(int &a){
	// 	return &a;
	// }
	// int main(){
	// 	int value = 2;
	// 	cout<<f1(f2(f3(value)))<<endl;
	// }

	/*Questão 06
	  Resposta Certa: 16
	  Minha Reposta: 16 */
	// int fun(int p1 = 1, int p2 = 1){
	// 	return p2<<p1;
	// }
	// int main(){
	// 	cout<<fun(fun(), fun(2))<<endl;
	// 	return 0;
	// }

	/*Questão 07
	  Resposta Certa: xxxxx
	  Minha Reposta: xxxxx*/
	// string fun(string &t, string s = "", int r = 2){
	// 	while(--r)
	// 		s += s;
	// 	t = t + s;
	// 	return s;
	// }
	// int main(){
	// 	string name = "x";
	// 	cout<<fun(name, name);
	// 	cout<<name<<endl;
	// 	return 0;
	// }

	/*Questão 08
	  Resposta Certa: xa
	  Minha Reposta: xa */
	// string fun(string t, string s = "x", int r = 1){
	// 	while(--r)
	// 		s+=s;
	// 	t = t + s;
	// 	return s;
	// }
	// int main(){
	// 	string name = "a";
	// 	cout << fun(name);
	// 	cout << name <<endl;
	// 	return 0;
	// }

	/*Questão 09
	  Resposta Certa: 1111
	  Minha Reposta: 115 */
	// int fun(int t[]){
	// 	t[0] += t[1];
	// 	return t[0];
	// }
	// int main(){
	// 	int t[] = {5, 6, 7};
	// 	// Aqui, é importante lembrar que a função 'fun(int t[])' também pode ser declarada
	// 	// como 'fun(int *t)', ou seja, ela deve receber um ponteiro.
	// 	// Portanto, a seguinte chamada desta função também é válida:
	// 	// int *ptr = t;
	// 	// cout << fun(ptr);
	// 	cout << fun(t);
	// 	cout << t[0] << endl;
	// 	return 0;
	// }

	/*Questão 10
	  Resposta Certa: 5
	  Minha Reposta: 5 */
	int* make(int v){ // int"retorna um ponteiro" make(int v)
		int* p = new int; // int"declaração da variável" p
		*p = v + 1; // "valor apontado por"p = v + 1;
		return p;
	}
	int* play(int& v){ //(int "referencia a variável passada em" v)
		cout << ++v; //Não se esqueça que a adição aqui é aplicada na variável referenciada
					 // por v.
		return &v; // return "endereço de" v;
	}
	void remove(int* v){ // (int"espera por um ponteiro" v)
		delete v;
	}
	int main(){
		remove(play(*make(3)));
		/*LINHAS ABAIXO, PARA DEBUG/ENTENDIMENTO APENAS*/
		// int* ret_make = make(3); // int"declaração da variável" ret_make;
		// int* ret_play = play(*ret_make);//play("value pointed by" ret_make);
		remove(ret_play);

		cout<<endl;
		return 0;
	}
