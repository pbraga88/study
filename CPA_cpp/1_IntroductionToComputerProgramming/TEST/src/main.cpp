#include <iostream>

using namespace std;

int main(){

  /*01
  Resposta; 8
  Minha resposta: 8*/
  // int a = 010;
  // cout<<a<<endl;

  /*02
  Resposta; the literal is invalid
  Minha resposta: the literal is invalid */
  // int a = X10; // deve ser declarado como 0X10 ou 0x10
  // cout<<a<<endl;

  /*03
  Resposta: the literal is invalid
  Minha Resposta:16 */
  // int a = 018; // está errado, pois a base octal vai de 0 até 7
  // cout<<a<<endl;

  /*04
  Reposta: first_literal
  Minha Reposta: first_literal*/
  // int #1_literal;
  // int first literal;
  // int first_literal;// <<<<<-----
  // int 1_first_literal;

  /*05
  Resposta: 3.14
  Minha Resposta: 3.14 */
  // float a = 3.14; // <<<<<-----
  // float b = 3_14;
  // float c = 3,14;
  // float d = E14;

  /*06
  Resposta: -0.1
  Minha Resposta: -0.1 */
  // float a = -1e-1;
  // cout<<a<<endl;

  /*07
  Resposta: 1.0
  Minha Resposta: 1.0 */
  // float x = 1./2 + 2./4;
  // cout<<x<<endl;

  /*08
  Resposta: 1
  Minha Resposta: 1 */
  // int k = 1%2 + 4%2;
  // cout<<k<<endl;

  /*09
  Resposta: 5
  Minha Resposta: 5*/
  // int i=3, j=2, k=-1;
  // if(i>0){
  //   if(j<=0){
  //     if(k<0)
  //       k++;
  //     if(k<=0)
  //       k--;
  //   }
  //   if(j>0)
  //     i++;
  // }
  // if(i<=0)
  //   j++;
  // k=i+j+k;
  // cout<<k<<endl;

  /*10
  Resposta: 81010
  Minha Resposta 81010
  Input: 8 */
  int i;
  cin>>i;
  cout<<i<<hex<<i+i<<oct<<i<<endl;

  return 0;
}
