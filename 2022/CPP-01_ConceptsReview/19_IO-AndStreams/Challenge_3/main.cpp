// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    std::fstream infile;
    std::string word;
    std::string in_substring;

    infile.open("romeoandjuliet.txt");
    if(!infile) {
        std::cout<<"Failed to open file"<<std::endl;
        exit(1);
    }

    // Get substring from user
    std::cout<<"Enter the substring to search for: ";
    cin>>in_substring;

    // Convert input string to lowercase
    std::string original_substring {in_substring};
    std::transform(in_substring.begin(), in_substring.end(), in_substring.begin(), 
                    [](unsigned char c) {return std::tolower(c);});
    
    int counter {0}, total_words{0};
    while (infile>>word){
        total_words+=1;
        // Convert read word to lowercase
        std::transform(word.begin(), word.end(), word.begin(),
                [](unsigned char c) {return std::tolower(c);});
        if (word.find(in_substring) != std::string::npos) {
            counter += 1;
        }
    }

    std::cout<<"The substring "<<original_substring
             <<" was found "<<counter<<" times"
             <<std::endl;
    std::cout<<total_words<<" words were searched..."<<std::endl;

    infile.close();

    return 0;
}

