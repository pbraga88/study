#include <iostream>
#include <fstream>

void read_file(std::string file_name) {
    //---- YOU WRITE YOUR CODE BELOW THIS LINE----
    std::ifstream in_file;
    std::string word{};

    in_file.open(file_name);
    if (!in_file) {
        std::cerr<<"Error opening file"<<std::endl;
    }

    while(in_file>>word) {
        std::cout<<word<<std::endl;
    }
    
    in_file.close();
   
    //---- YOU WRITE YOUR CODE ABOVE THIS LINE----
}


int main() {
    std::string file_name {"test.txt"};

    read_file(file_name);
    

    return 0;
}