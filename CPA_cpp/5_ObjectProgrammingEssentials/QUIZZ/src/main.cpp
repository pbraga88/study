#include <iostream>
using namespace std;

/* Question 01
   Resposta: the program will cause a compilation error
   Minha Resposta: the program will cause a compilation error
*/
// class A{
//   int a;
// };
// int main(void){
//   A a;
//   a.a = 1/2;
//   cout<<a.a<<endl;
//   return 0;
// }

/* Question 02
   Resposta: 0
   Minha Resposta: 0
*/
// class A{
//     int a;
//   public:
//     int b;
//     A(void){a=b=1;}
// };
//
// int main(void){
//     A a;
//     a.b /= 2;
//     cout<<a.b<<endl;
//     return 0;
// }

/* Question 03
   Resposta: 3
   Minha Resposta: 3
*/
// class A{
//     int a;
//   public:
//     A(void){a=1;}
//     int b(void){return ++a;}
// };
//
// int main(void){
//   A a;
//   a.b();
//   cout<<a.b()<<endl;
//   return 0;
// }

/* Question 04
   Resposta: 00
   Minha Resposta: 10
*/
// class A{
//   public:
//     A(){a[0] = 1; a[1] = 0;}
//     int a[2];
//     int b(void){int x=a[0]; a[0]=a[1]; a[1]=x; return x;}
// };
// int main(void){
//   A a;
//   a.b();
//   cout<<a.b();
//   cout<<a.a[1]<<endl;
//   return 0;
// }

/* Question 05
   Resposta: 11
   Minha Resposta: 11
*/
// class A{
//   public:
//     A(){a.a = a.b = 1;}
//     struct {int a,b;}a;
//     int b(void);
// };
//
// int A::b(void) {int x=a.a; a.a=a.b;a.b=x; return x; }
// int main(void){
//   A a;
//   a.a.a = 0;
//   a.b();
//   cout<<a.b();
//   cout<<a.a.b<<endl;
//   return 0;
// }

/* Question 06
   Resposta: 5
   Minha Resposta: 5
*/
// class A{
//   public:
//     int a;
//     A(){ a = 1;}
//     A(int aa) { a = 2; }
//     A(A &aa) { a = 3; }
// };
//
// int main(void){
//   A a(1), b(a);
//   cout<<a.a + b.a<<endl;
//   return 0;
// }

/* Question 07
   Resposta: 1
   Minha Resposta: 1
*/
// int z = 1;
// class A{
//   public:
//     int a;
//     A() {a=1; z++;}
//     A(A& aa){a=3; z++;}
//     ~A(){z--;}
// };
// void fun(void){
//   A a,b(a),c(b);
// }
// int main(void){
//   cout<< z <<endl;
//   return 0;
// }

/* Question 08
   Resposta: the program will cause a compilation error
   Minha Resposta: the program will cause a compilation error
*/
// class A{
//   public:
//     static int a;
//     A(){a = 1; a++;}
//     A(A& aa){ a++; }
// };
// int main(void){
//   A a,b(a),c(b);
//   cout<<A.a<<endl;
//   return 0;
// }

/* Question 09
   Resposta: 3
   Minha Resposta: 3
*/
// class A{
//   public:
//     static int a;
//     A(){a = 0; a++;}
//     A(A& aa){ a++; }
// };
// int A::a = 1;
// int main(void){
//   A a,b(a),c(b);
//   cout<<a.a<<endl;
//   return 0;
// }

/* Question 10
   Resposta: 1
   Minha Resposta: 1
*/
// class A{
//   public:
//     int a;
//     A(){a = 0;}
//     A(int b){a=b+1;}
// };
// class B{
//   public:
//     A a;
//     B() : a(0){}
// };
// int main(void){
//   B *b = new B();
//   cout << b->a.a <<endl;
//   return 0;
// }
