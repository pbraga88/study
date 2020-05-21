#include <iostream>
#include <string>
using namespace std;

/*01
Resposta: CD
Minha Resposta: CD*/
// class A{
//   public:
//     string a(string b){
//       return b.substr(0,2);
//     }
// };
// class B{
//   public:
//     string a(string b){
//       return b.substr(2,2);
//     }
// };
//
// int main(){
//   A a;
//   B b;
//   cout<<a.a(b.a("ABCD"));
//   return 0;
// }


/*02
Resposta:
Minha Resposta: 3.5 */
// class A {
// public:
//     float v;
//     float set(float v) {
//         v += 1.0;
//         this->v = v;
//         return v;
//     }
//     float get(float d) {
//         v += 1.0;
//         return v;
//     }
// };
//
// int main() {
//     A a;
//     cout << a.get(a.set(a.set(0.5)))<<endl;
//     return 0;
// }

/*03
Resposta: 2
Minha Respota: 2*/
// class A {
// public:
//     float v=0;
//     float set(float v) {
//         A::v += 1.0;
//         A::v = v + 1.0;
//         return v;
//     }
//     float get(float v) {
//         v += A::v;
//         return v;
//     }
// };
// int main() {
//     A a;
//     cout << a.get(a.set(a.set(0.5)))<<endl;
//     return 0;
// }

/*04
Resposta: Fail Compilation
Minha Resposta: Fail Compilation*/
// class A {
// public:
//     A() { v = 2.5; }
//     float v;
//     float set(float v) {
//         A::v += 1.0;
//         return v;
//     }
//     float get(float v) {
//         v += A::v;
//         return v;
//     }
// };
// int main() {
//     A a;
//     a.A(); // Irá fazer a compilação falhar
//     cout << a.get(a.set(1.5));
//     return 0;
// }

/*05
Resposta: Fail Compilation
Minhs Respota: Fail Compilation */
// class A {
// public:
//     A(float v) { A::v = v; }
//     float v;
//     float set(float v) {
//         A::v += v;
//         return v;
//     }
//     float get(float v) {
//         return A::v + v;
//     }
// };
//
// int main() {
//     A a,b(1.0); // a causa falha de compilação, pois não passa nenhum valor float
//                 // para o constructor
//     cout << a.get(b.set(1.5));
//     return 0;
// }

/*06
Resposta: 02
Minha Resposta: 02*/
// class A {
//  public:
//      A(A &a) { v = a.get(0.0); }
//      A(float v) { A::v = v; }
//      float v;
//      float set(float v) {
//          A::v += v;
//          return v;
//      }
//      float get(float v) {
//          return A::v + v;
//      }
//  };
//  int main() {
//      A *a = new A(1.0), *b = new A(*a);
//      cout << a->get(b->set(a->v));
//      return 0;
//  }

/*07
Resposta: Compilation fail
Minha Resposta: Compilation fail */
// public:
//     A(float v) { A::v = v; }
//     float v;
//     float set(float v) {
//         A::v = v;
//         return v;
//     }
//     float get(float v) {
//         return A::v;
//     }
// };
//
// int main() {
//     A *a = new A(1.0), *b = new A(*a);
//     cout << a->get(b->set(a->v));
//     return 0;
// }

/*08
Respota: Compilation fails
Minha Resposta: 1*/
// class A{
//   public:
//     A(A *v){A::v=v;}
//     A(){A::v=1.0;}
//     float v;
//     float set(float v){
//       A::v = v;
//       return v;
//     }
//     float get(float v){
//       return A::v;
//     }
// };
// int main(){
//   A a, *b = new A(a);
//   cout<<a->get(b->set(a->v))<<endl;
//   return 0;
// }

/*09
Resposta: 06
Minha Resposta: 06 */
// class A {
// public:
//     float v;
//     A() : v(1.0) {}
//     A(A &a) : v(2.0) {}
//     A(float f) : v(3.0) {}
//     float get() {
//         return A::v;
//     }
// };
// int main() {
//     A a, b(a.get()), c(b);
//     cout << a.v + b.v + c.v;
//     return 0;
// }

/*10
Resposta: 03
Minha Resposta: 03 */
class A {
public:
    float v;
    A(float x) : v(x) {}
};

class B {
public:
    A a;
    float b;
    B(float x) : a(x + 1) { b = a.v; }
};

int main() {
    B b(2.0);
    cout << b.b;
    return 0;
}
