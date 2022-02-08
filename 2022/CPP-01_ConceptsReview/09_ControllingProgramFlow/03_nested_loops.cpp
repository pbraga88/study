#include <iostream>
#include <vector>

using namespace std;

int calculate_pairs(vector<int> vec) {
    int result {0};
    //----WRITE YOUR CODE BELOW THIS LINE----
    for(size_t i = 0; i<vec.size() - 1; i++){
        for(size_t j = i+1; j<vec.size(); j++){
            result += vec.at(i) * vec.at(j);
        }
    }
     
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    return result;
}

int main(int argc, char** argv){
    vector<int> vec;
    
    for(int i = 1; i<argc; i++){
        vec.push_back(atoi(argv[i]));
    }

    cout<<calculate_pairs(vec)<<endl;

    // DEBUG
    // for(int i = 0; i<argc-1; i++){
    //     cout<<vec.at(i)<<endl;
    // }

    return 0;
}