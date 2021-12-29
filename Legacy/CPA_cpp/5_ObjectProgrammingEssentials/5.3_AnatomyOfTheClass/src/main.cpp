#include <iostream>
#include "class.h"

using namespace std;

int main(){
  // Classe objeto_1, objeto_2(11);
  // cout<<objeto_1.getValue()<<endl;
  // cout<<objeto_2.getValue()<<endl;

  /*****Copying Constructor*****/
  // Classe object11(100);
  // object11.x = 1;
  // Classe object12 = object11;
	// cout << object11.value << endl;
  // cout << object12.value << endl;
  // cout << object11.x << endl;
  // cout << object12.x << endl;
  //
  // Classe_2 object21(200), object22 = object21;
  // cout << object21.value << endl;
	// cout << object22.value << endl;

  /*****Memory Allocation*****/
  Classe objeto;
  objeto.mem_alloc(100);

  return 0;
}
