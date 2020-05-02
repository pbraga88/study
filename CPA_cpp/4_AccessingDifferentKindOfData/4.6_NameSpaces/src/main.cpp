#include <iostream>

namespace first{
  int mult(int val){
    return val*10;
  }
}

namespace second{
  int x_second = 100;
  int mult(int val){
    return val*x_second;
  }
}

namespace first{
  float div(float var, float sec_var){
    return var/sec_var;
  }
}

namespace second{
  int div(int var, int sec_var){
    return var%sec_var;
  }

}

// namespace{ //Use together with line 63
//   int mult(int val){
//     return 4*val;
//   }
// }

namespace fdm = first;

using namespace std;

int main(){
  /*Using namespace for second{} only*/
  //using namespace second;
  // int x = x_second;
  // cout<<first::mult(5)<<endl;
  // cout<<mult(10)<<endl;
  // cout<<x<<endl;

  /*Using namespace insde a block*/
  // {
  //   using namespace first;
  //   cout<<mult(4)<<endl;
  //   cout<<div(10, 4)<<endl;
  // }
  // {
  //   using namespace second;
  //   cout<<mult(10)<<endl;
  //   cout<<x_second<<endl;
  // }

  /*Selectively decide namespace entity*/
  // using first::mult;
  // using second::div;
  // cout<<mult(50)<<endl;
  // cout<<div(10,4)<<endl;

  /*Use of Anonymous namespace (line 29)*/
  // cout<<mult(4)<<endl;
  // cout<<first::mult(4)<<endl;
  // cout<<second::mult(4)<<endl;

  /* Rename of namespace (line 35)*/
  {
    using namespace fdm;
    cout<<div(10,4)<<endl;
    cout<<mult(5)<<endl;
  }

  return 0;
}
