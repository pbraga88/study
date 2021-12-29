#include <iostream>
#include <string>

using namespace std;

/*Question 01
  Correct Answer: 3
  My Answer:3 */
// int main(){
//   int *t[2] = {new int[2], new int[2]};
//   // reescrevendo a linha acima:
//   // int **t  = new int*[2];
//   // *t = new int[2];
//   // *(t+1) = new int[2];
//   for(int i = 0; i<4; i++)
//     t[i%2][i/2] = i;
//   cout<<t[0][1]+t[1][0]<<endl;
//   delete [] t[0];
//   delete [] t[1];
//   return 0;
// }

/*Question 02
  Correct Answer: 1.5 1
  My Answer:1.5 1 */
// int main(){
//   int i = 2, j = 3;
//   float a = 2, b =3;
//   cout<<float(j)/(float)i <<" "<< (int)b/int(a)<<endl;
// }

/*Question 03
  Correct Answer: 0
  My Answer:0 */
// int main(){
//   double d = 987654321.123456789;
//   float f = d;
//   int i = d==f;
//   cout<<i<<endl;
//   return 0;
// }

/*Question 04
  Correct Answer: 1
  My Answer:1 */
// int main(){
//   double d = 0.9999999;
//   float f = .0;
//   int i = (int)d == int(f);
//   cout<<i<<endl;
//   return 0;
// }

/*Question 05
  Correct Answer:8
  My Answer:8 */
// int main(){
//   int Int = 1;
//   char Char = 3;
//   float Float = 4.9;
//   Int = Int + Char + Float;
//   cout<<Int<<endl;
//   return 0;
// }

/*Question 06
  Correct Answer: 1
  My Answer: 0 */
// int main(){
//   string s = "Skipper", t = "Private";
//   int i = s.compare("Kowalski") > 0;
//   int j = s.compare("Rico") < 0;
//   cout << i + j << endl;
//   return 0;
// }

/*Question 07
  Correct Answer: 2
  My Answer: 2 */
// int main(){
//   string s = "Abc", t = "A";
//   s = s + t;
//   t = t + s;
//   int i = s.compare(t) > 0;
//   int j = s.length() < t.length();
//   cout<<i+j<<endl;
//   return 0;
// }

/*Question 08
  Correct Answer: 0
  My Answer: 0 */
// int main(){
//   string str1, str2;
//   str1 = "ABCDEF";
//   str2 = str1.substr(1,1)+str1.substr(4)+str1.substr();
//   str1 = str2.substr(1,1)+str2.substr(4)+str2.substr();
//   cout<<(str2>str1)<<endl;
//   return 0;
// }

/*Question 09
  Correct Answer: 8
  My Answer: 8 */
// int main(){
//   string s = "A";
//   s = s.append(s).append(s).append(s);
//   cout<<s.length()<<endl;
//   return 0;
// }

/*Question 10
  Correct Answer: 3
  My Answer: 3 */
// namespace alpha{int var = 1;}
// namespace beta{int var = alpha::var + 1;}
// int main(){
//   beta::var += alpha::var;
//   {
//     using namespace beta;
//     cout<<var<<endl;
//   }
//   return 0;
// }
