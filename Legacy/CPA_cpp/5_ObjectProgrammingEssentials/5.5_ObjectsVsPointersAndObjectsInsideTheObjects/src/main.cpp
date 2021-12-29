#include <iostream>

 using namespace std;

 // class Classe{
 //  private:
 //    int value;
 //  public:
 //    Classe(int val){
 //      cout<<"Object constructed."<<endl;
 //      value = val;
 //    }
 //   Classe(){
 //     cout<<"Object constructed."<<endl;
 //     value = 0;
 //   }
 //   ~Classe(){
 //     cout<<"Object destructed. Value: "<<value<<endl;
 //   }
 //   void set_value(int val){
 //     value = val;
 //   }
 //   int get_value(void){
 //     return value;
 //   }
 //   void incAndPrint(){
 //     cout<<"Value: "<<++value<<endl;
 //   }
 //
 // };
 //
 // int main(){
 //   Classe *ptr_1, *ptr_2;
 //
 //   /*As duas declarações abaixo estão corretas*/
 //   // ptr = new Classe;
 //   ptr_1 = new Classe();
 //   ptr_2 = new Classe();
 //
 //   ptr_1->set_value(1);
 //   ptr_2->set_value(2);
 //
 //   ptr_1->incAndPrint();
 //   ptr_2->incAndPrint();
 //
 //   delete ptr_1;
 //   delete ptr_2;
 //   return 0;
 // }

/*****Arrays of pointers to objects*****/
// class Array{
//   int *values;
//   int size;
//
//   public:
//     Array(int sz){
//       size = sz;
//       values = new int [sz];
//       cout<<"Array of "<<size<<" ints constructed."<<endl;
//     }
//     ~Array(){
//       delete []values;
//       cout<<"Array of "<<size<<" ints destructed."<<endl;
//     }
//     int get(int ix){
//       return values[ix];
//     }
//     void set(int ix, int val){
//       values[ix] = val;
//     }
// };
//
// int main(){
//   /*One dimension array*/
//   // Array *ptr;
//   // ptr = new Array(2);
//   //
//   // for(int i = 0; i<2; i++)
//   //   ptr->set(i, i+1000);
//   //
//   // for(int i = 0; i<2; i++)
//   //   cout<<ptr->get(i)<<endl;;
//   //
//   // delete ptr;
//
//   /*Two dimensions array*/
//   // Array *ptr[2];// = {new Array(2), new Array(2)};
//   Array **ptr;
//   ptr = new Array*[2];
//   for(int i = 0; i<2; i++)
//     *(ptr+i) = new Array(2);
//
//   for(int i = 0; i<2; i++){
//     for(int j = 0; j<2; j++)
//       (*(ptr+i))->set(j, j+100);
//       // ptr[i]->set(j, j+100);
//   }
//
//   for(int i = 0; i<2; i++){
//     for(int j = 0; j<2; j++)
//       cout<<(*(ptr+i))->get(j)<<endl;
//   }
//
//   for(int i = 0; i<2; i++)
//     delete *(ptr+i);
//
//   return 0;
// }

/*****Object inside object*****/
class Elemento{
  int valor;
  public:
    Elemento(void){cout<<"Elemento construído."<<endl;}
    Elemento(int numb){cout<<"Elemento "<<numb<<" construído"<<endl;}
    int get(void){
      return valor;
    }
    void set(int val){
      valor = val;
    }
};
class Colecao{
  Elemento elem_1, elem_2;
  public:
    Colecao(void):elem_1(1),elem_2(2) {
      cout<<"Colecao construída."<<endl;
    }

    int get(int elem){
      return elem==1 ? elem_1.get() : elem_2.get();
    }
    void set(int elem, int val){
      if(elem == 1)
        elem_1.set(val);
      else
        elem_2.set(val);
    }
};
int main(){
  Colecao col;

  for(int i=1; i<=2; i++)
    col.set(i, i+1);
  for(int i=1; i<=2; i++)
    cout<<"Elemento #"<<i<<" = "<<col.get(i)<<endl;
  return 0;
}
