#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count_divisible() {
    
    vector<int> vec {1,3,5,15,16,17,18,19,20,21,25,26,27,30,50,55,56,58,100,200,300,400,500,600,700};
    //---- WRITE YOUR CODE BELOW THIS LINE----
    int count {0};
    
    for (auto elem: vec) {
        if(!(elem%3) || !(elem%5)){
            count++;
        }
    }    
    //---- WRITE YOUR CODE ABOVE THIS LINE----
    //---- DO NOT CHANGE THE CODE BELOW THIS LINE----
    return count;
}

int main(){
    cout<<count_divisible()<<endl;
    // int scores[] {90,80,100};
    // for (auto var: scores) {
    //     cout<<var<<endl;
    // }

    // vector<double> temps {23.5, 25.4, 26.8, 24,2};
    // double mean_temp {0};
    // for (auto var: temps) {
    //     mean_temp+=var;
    // }
    // mean_temp/=temps.size();
    // cout<<mean_temp<<endl;

    // for (auto var: {1.0,2.0,3.0,4.4} ){
    //     cout<<var<<endl;
    // }

    // for(auto c: "some"){
    //     cout<<c<<endl;
    // }

    return 0;
}