#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string str {"hello "};
    string str2;
    cin>>str2;

    str.append(str2);

    cout<<str<<endl;

    // str.clear();

    // cout<<str<<endl;

    string::iterator it = str.begin();
    for(it; it!=str.end(); it++) {
        cout<<*it;
    }
    cout<<endl;

    cout<<str.size()<<endl;
    cout<<str.length()<<endl;

    return 0;
}