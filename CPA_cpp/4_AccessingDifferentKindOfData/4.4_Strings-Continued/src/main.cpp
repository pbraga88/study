#include <iostream>
#include <string>

using namespace std;

int main(){
	/********************Substrings****************/
	string s = "ABCDEF";
	s = s.substr(1,1)+s.substr(4)+s.substr(); 
	cout<<s<<endl;

	return 0;
}