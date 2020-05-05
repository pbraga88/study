#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

/* Question 01
   Correct Answer: It prints e
   My Answer: Compilation fails*/
// int main(){
  /*******FOR STUDY AND DEBUG********/
  // char t[3][3];
  // char **p = new char* [2]; // Aloca dois ponteiros do tipo char*
  // *(p+1) = t[0]; // Diz para o segundo ponteiro (p[1]) apontar para t[0],
  //                // que por sua vez aponta para t[0][0]
  //                // t[0] -> t[0][0]
  //                // p[1] -> t[0] -> t[0][0], portanto p[0]->t[0][0]
  //                // Logo, todos os assignements abaixo poderiam ter sido usados
  //                // na linha 13:
  //                // p[1] = &t[0][0];
  //                // p[1] = t[0];
  //                // p[1] = *t;
  //
  // // Todas as declarações abaixo imprimem o mesmo endereço de memória
  // printf("%p\n",(void*)t);
  // printf("%p\n",*t);
  // cout<<(void*)t[0]<<endl;
  // cout<<(void*)*(t)<<endl;
  // // Note que este endereço foi igualado a t[0] na linha 14. Abaixo são maneiras
  // // de imprimir o mesmo endereço de memória
  // printf("%p\n",*(p+1));
  // printf("%p\n",p[1]);
  // cout<<(void*)p[1]<<endl;  // Uma vez que o stream std::cout entende char* como
  // cout<<(void*)*(p+1)<<endl;// um ponteiro para uma string C-style, ele vai tentar
  //                           // imprimir uma string. Para imprimir o endereço, deve-se
  //                           // fazer o typecast com (void*);
  // int acum = 0;
  // for(int i = 0; i<3; i++){
  //   for(int c = 0; c<3; c++)
  //     cout<<"Memory Address t["<<i<<"]["<<c<<"]: "<<t+(c+acum)<<endl;
  //   acum+=3;
  // }
  //
  // for (int i=0; i<9; i++){
  //   // As quatro linhas de código à seguir fazem a mesma coisa:
  //   // - Dereferencia o endereço cujo *p[1] aponta para asignement do valor 'a'+i
  //   //    *(p[1])++ = 'a'+i;
  //   //    ^^^^^^------^^^^^
  //   // - Avança um espaço de memória:
  //   //    *(p[1])++ = 'a'+i;
  //   //    -------^^---------
  //   // *(*(p+1))++ = 'a' + i;
  //   // cout<<*(*(p+1)-1)<<endl;
  //   *(p[1])++ = 'a'+i;
  //   cout<<*(p[1]-1)<<endl;
  // }
  //
  // for(int l=0; l<3; l++){
  //   for(int c = 0; c<3; c++){
  //     cout<<*(*(t+l)+c)<<" ";
  //   }
  //   cout<<endl;
  // }
  // for(int i = 0; i<3; i++){
  //     cout<<*(t+i)<<endl;
  // }
  // cout<<t[1][1]<<endl;
  /*********************************/

//   char t[3][3], *p = (char*)t;
//   for(int i = 0; i < 9; i++)
//     *p++ = 'a' + i;
//   cout<<t[1][1]<<endl;
//   return 0;
// }

/* Question 02
   Correct Answer: 8.8
   My Answer: 8.8*/
// int main(){
//   short s = 1;
//   int i = 2;
//   long l = 3;
//   float f = 4.4;
//   double d = 6.6;
//
//   cout<< s/i + f/i + d/s <<endl;
//   return 0;
// }


/* Question 03
   Correct Answer: It prints 2.5
   My Answer: Compilation fails*/
// int main(){
//   int i = 2;
//   float f = 5.8;
//
//   f = (int)f; // Com esse casting, f passa a valer 5
//   cout<<f<<endl;
//   i = (float)i; // O valor de i continua sendo 2
//   cout<<i<<endl;
//   cout<<f/i<<endl; // 5/2=2.5 -> Vale lembrar que a expressão expande para float
//                    // pois trata-se de um tipo float f dividído por um tipo int i
//   return 0;
// }

/* Question 04
   Correct Answer: Compilation fails
   My Answer: 2*/
// int main(){
//   int i = 2;
//   float f = 4.4;
//
//   cout<<f%float(i)<<endl; // A compilação falha, pois o operador de remainder "%"
//                           // só pode ser aplicado em tipo inteiro
//   return 0;
// }

/* Question 05
   Correct Answer: Compilation fails
   My Answer: Compilation fails*/
// int main(){
//   string s = "a";
//
//   cout<<s<<"b"+"c"<<endl;
//   return 0;
// }

/* Question 06
   Correct Answer: It prints yes
   My Answer: It prints yes */
// int main(){
//   string s1 = "ab";
//   string s2 = "Abc";
//
//   if(s1>s2)
//     cout<<"yes"<<endl;
//   else
//     cout<<"NO"<<endl;
//   return 0;
// }

/* Question 07
   Correct Answer: It prints 0
   My Answer: It prints 0 */
// int main(){
//   string s1 = "Ab";
//   string s2 = "Abc";
//
//   cout<<s1.compare(s1)<<endl;
//   return 0;
// }

/* Question 08
   Correct Answer: It prints 56789
   My Answer: It prints 56789 */
// int main(){
//   string s = "0123456789";
//   cout<<s.substr(3,7).substr(2).substr()<<endl;
//   return 0;
// }

/* Question 10
   Correct Answer: It prints 32
   My Answer: It prints 32 */
namespace S1{
  int A = 1;
}

namespace S2{
  int A =2;
}

int main(void){
  {
    using namespace S1;
    S2::A = A + 1;
  }
  {
    using namespace S2;
    S1::A = A + 1;
  }
  cout<<S1::A<<S2::A<<endl;
  return 0;
}
