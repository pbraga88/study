#include <iostream>
#include <string>

using namespace std;

int main(){
  /*************** append() ********************/
  // string str1 = "Content", str2 = "appendix";
  // cout<<str1.append(str2)<<endl;

  // string string_one = "content";
  // string string_two;
  // string_two.append(string_one);
  // string_two.append(string_one, 0, 3);
  // string_two.append(2, '!');
  // cout<<string_two<<endl;
  /********************************************/

  /***************** push_back() ***************/
  // string alphabet;
  // for(char c = 'A'; c <= 'Z'; c++)
  //   alphabet.push_back(c);
  // cout<<alphabet<<endl;
  // cout<<alphabet.size()<<endl;
  /********************************************/

  /***************** insert() *****************/
  // string quote = "whyserious", anyword = "monsoon";
  // quote.insert(3,2,' ');
  // quote.insert(4, anyword, 3, 2).append("?!");
  // cout<<quote<<endl;
  /********************************************/

  /***************** assign() *****************/
  // string sky;
  // sky.assign("?!");
  // cout<<sky<<endl;
  // sky.assign(80, '*');
  // cout<<sky<<endl;
  /********************************************/

  /***************** replace() ****************/
  // string ToDo = "I'll think about that in one hour";
  // string Schedule = "today yesterday tomorrow";
  // ToDo.replace(22,11, Schedule,16,8);
  // ToDo.append(4,'!');
  // cout<<ToDo<<endl;

  // string s = "Ola como vai?";
  // string s_2 = "tudo bem tudo certo onde esta";
  // s.replace(4,8, s_2,9,10);
  // s.insert(3,1,',');
  // s.append("!");
  // cout<<s<<endl;
  /********************************************/

  /***************** erase() ******************/
  // string WhereAreWe = "I've got a feeling we're not in Kansas anymore";
  // WhereAreWe.erase(38,8).erase(25,4);
  // cout<<WhereAreWe<<endl;
  //
  // string s = "Ola, tudo bem?";
  // s.erase(3,11);
  // cout<<s<<endl;
  // s.erase();
  // cout<<s<<endl;
  /********************************************/

  /***************** swap() ******************/
  string s = "Agua";
  string s_2 = "Cerveja";
  cout<<"s = "<<s<<". "<<"s_2 = "<<s_2<<endl;
  s.swap(s_2);
  cout<<"s = "<<s<<". "<<"s_2 = "<<s_2<<endl;
  /********************************************/

  return 0;
}
