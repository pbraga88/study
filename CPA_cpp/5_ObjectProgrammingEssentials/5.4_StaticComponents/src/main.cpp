#include <iostream>

using namespace std;

/*Variáveis estáticas*/
// void func(){
//   // int var = 0;
//   static int var = 0;
//   cout<<var++<<endl;
// }
//
// int main(){
//   for(int i = 0; i<5;i++)
//     func();
//
//   return 0;
// }
/********************/

/*Componentes estáticos da classe*/
// class Classe{
//   public:
//     static int var_1;
//     int var_2;
//     void print_var(){
//       cout<<"Static: "<<++var_1<<" Auto: "<<++var_2<<endl;
//     }
// };
// int Classe::var_1 = 0;
// int main(){
//   Classe instance1, instance2;
//
//   instance1.var_2 = 0;
//   instance2.var_2 = 0;
//
//   // As três declarações à seguir têm o mesmo efeito e irão alterar a variável
//   // estática var_1 para todas as instâncias da classe
//   instance1.var_1 += 1;
//   instance1.var_1 += 1;
//   Classe::var_1 += 1;
//
//   instance1.print_var();
//   instance2.print_var();
//
//   return 0;
// }
/******************************/

/*Variáveis e métodos estáticos de uma classe */
// class Classe{
//   private:
//     static int counter;
//   public:
//     Classe(){
//       counter++;
//     }
//     ~Classe(){
//       if(!(--counter))
//         cout<<"bye bye!"<<endl;
//     }
//     static void how_many(){
//       cout<<counter<<" instances"<<endl;
//     }
// };
// int Classe::counter = 0;
//
// int main(){
//   Classe::how_many();
//   Classe a;
//   Classe b;
//   b.how_many(); // Também pode ser chamada com Classe::how_many() ou a.how_many()
//   Classe c;
//   Classe d;
//   d.how_many(); // Também pode ser chamada com Classe::how_many() ou c.how_many()
//   return 0;
// }
/****************************/

/* Interação entre componentes estáticos e não estáticos */
// class Test{
//   public:
//     // void funN1(){cout<<"non-static"<<endl;}
//     // static void funS1{funN1();}
//
//     static void funN1(){cout<<"static"<<endl;}
//     void funS1(){funN1();}

// };
