#include <iostream>
#include <vector>

using namespace std;

int count_numbers(const vector<int> &vec) {
    //---- WRITE YOUR CODE BELOW THIS LINE----
    long unsigned count {0};
    while(count < vec.size()) {
        if (vec.at(count) == -99){
            return count;
        }
        count+=1;
    }
    
    // *vec[0] = 10;
    //---- WRITE YOUR CODE ABOVE THIS LINE----
    //---- DO NOT MODIFY THE CODE BELOW THIS LINE-----
    return count;
}

int main(){

    vector<int> vec{1,2,-99,3,4};
    vector<int> vec1= vec;

    // cout<<count_numbers(vec1[0])<<endl;

    // cout<<count_numbers(vec)<<endl;
    // vec.push_back(10);
    return 0;
}