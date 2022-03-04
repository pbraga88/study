#include <iostream>
#include <string>

using namespace std;

void stringConcat(){
    string part1 {"C++"};
    string part2 {"is a powerful"};
    string sentence;
    sentence = part1 + " " + part2 + " langauage";
    // sentence = "C++" + " language"; //WRONG!
    sentence = " " + part2 + " language";

    cout<<sentence<<endl;
}

void substrings() {
    string s1 {"This is a string"};

    cout<<s1.substr(0,4);
    cout<<s1.substr(4,3);
    cout<<s1.substr(9,7)<<endl;
}

void getline_ex(){
    string s1;
    getline(cin, s1, 'q'); // 'q' is the delimeter 
    cout<<s1<<endl;
}

int main() {
    // stringConcat();
    // substrings();
    getline_ex();

    return 0;
}