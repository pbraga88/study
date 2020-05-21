#include <iostream>
#include <string>

using namespace std;
/* Questão 01
Resposta: 10
Minha Resposta: 10*/
// int main(){
//   float *ft[3] = { new float[3], new float[3], new float[3] };
//   float *p;
//   for(int i = 0; i < 3; i++) {
//       p = ft[i];
//       *p = p[1] = *(p + 2) = 10 * i;
//       // cout<<*p<<endl;
//       // cout<<*(p+1)<<endl;
//       // cout<<*(p+2)<<endl;
//       // cout<<endl;
//   }
//   cout << ft[1][1]<<endl;

//   for(int i = 0; i<3; i++)
//     delete [] ft[i];

//   return 0;
// }

/*Questão 02
Resposta: 22
Minha Resposta: 22 */
// int main() {
//      int *it[3];

//      for(int i = 0; i < 3; i++) {
//          it[i] = new int [i + 1];
//          for(int j = 0; j < i + 1; j++)
//              it[i][j] = 10 * i + j;
//      }
//      cout << it[2][2]<<endl;
//      for(int i = 0; i < 3; i++)
//          delete [] it[i];
//      return 0;
//  }

/*Questão 03
Resposta: 8.8
Minha Resposta: 8.8 */
 // int main() {
 //     short s = 1;
 //     int i = 2;
 //     long l = 3;
 //     float f = 4.4;
 //     double d = 6.6;
 
 //     cout << s/i + f/i + d/s <<endl;
 //     return 0;
 // }

/*Questão 04
Resposta: Fail Compilation
Minha Resposta: Fail Compilation */
// #include <string>
// int main() {
//     string s = "a";

//     cout << s  << "b" + "c";
//     return 0;
// }

/*Questão 05
Resposta: abc
Minha Resposta: Fail Compilation*/
// #include <string>
// int main() {
//     string s = "a";

//     cout << s + "b" + "c"; // Aqui, as letras 'b' e 'c' são concatenadas à string
//     return 0;
// }

/*Questão 06
Resposta: yes 
Minha Resposta: yes */
// int main() {
//     string s1 = "ab";
//     string s2 = "Abc";

//     if(s1 > s2)
//         cout << "yes" << endl;
//     else
//         cout << "NO" << endl;
//     return 0;
// }

/*Questão 07
Resposta: ABABB
Minha Resposta: ABBABB*/
// int main() {
//     string s = "AB";
//     s.append(s).push_back(s[s.length() - 1]);
//     cout << s;
//     return 0;
// }

/*Questão 08 
Resposta: Fail Compilation
Minha Resposta: Fail Compilation*/
// namespace SpaceA {
//     int A;
// }
// namespace SpaceB {
//     int A;
// }
// using namespace SpaceA, SpaceB;
// int main() {
//     SpaceA::A = SpaceB::A = 1;
//     std::cout << A + 1;
//     return 0;
// }


// /**/
// int main() {
//     string s1 = "1";
//     string s2 = "12";
   
//     cout << s1.compare(s2);
//     return 0;
// }

// /**/
// int main() {
//     string s = "ABCDEF";
//     for(int i = 1; i < s.length(); i += 2)
//         s[i - 1] = s[i] + 'a' - 'A';
//     cout << s;
//     return 0;
// }

// /**/
// int main() {
//     string s1 = "aleph";
//     string s2 = "alpha";
//     string s;
//     s1.swap(s2);
//     s2.swap(s);
//     s.swap(s2);
//     cout << s2;
//     return 0;
// }

/**/
namespace S {
int A = 1;
}
namespace S {
int B = A + 2 ;
}
int main(void) {
    S::A = S::A + 1;
    { using namespace S;
       ++B;
    }
    cout << S::B << S::A;
    return 0;
}