#include <iostream>
#include "addingStack.h"

using namespace std;

/***********Very basic approach on stacks*************/
// int stack[100];
// int SP = 0;
//
// inline void push(int val){ stack[SP++] = val;}
//
// inline int pop(void){ return stack[--SP];}
//
// int main(){
//   push(3);
//   push(2);
//   push(1);
//
//   cout<<pop()<<endl;
//   cout<<pop()<<endl;
//   cout<<pop()<<endl;
//
//   return 0;
// }
/****************************************************/

/**************Object Oriented Stack****************/
// int main(){
//   Stack pilha_1, pilha_2, pilha_3;
//   pilha_1.push(1);
//   pilha_2.push(pilha_1.pop()+1);
//   pilha_3.push(pilha_2.pop()+1);
//   cout<<pilha_3.pop()<<endl;
//
//   return 0;
// }
/***************************************************/

/**********Object Oriented Stack - inheritance******/
int main(){
  AddingStack pilha;

  for(int i = 0; i<10; i++)
    pilha.push(i);
  cout<<pilha.getSum()<<endl;

  for(int i = 0; i<10; i++)
    cout<<pilha.pop()<<endl;
  cout<<pilha.getSum()<<endl;

  return 0;
}

/***************************************************/
