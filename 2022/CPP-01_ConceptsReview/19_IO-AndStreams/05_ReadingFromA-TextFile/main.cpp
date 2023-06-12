#include <iostream>
#include <fstream>
#include <string>

int main() {
/***********Simple Read**************/
    std::ifstream in_file;
    std::string line;
    int num;
    double total;

    in_file.open("test.txt");
    if(!in_file) {
        std::cerr<<"Error opening file"<<std::endl;
        std::exit(1);
    }
    std::cout<<"File opened"<<std::endl;

    in_file>>line>>num>>total;
    std::cout<<line<<"\n"<<num<<"\n"<<total<<std::endl;

    in_file.close();

/***********Read line by line**************/
    // std::ifstream in_file;
    // std::string line {};
    
    // in_file.open("poem.txt");
    // if (!in_file) {
    //     std::cout<<"Failed to open file"<<std::endl;
    //     std::exit(1);
    // }
    // while (std::getline(in_file, line)) {
    //     std::cout<<line<<std::endl;
    // }
    // in_file.close();
/***********Read a character at a time**************/
    // std::ifstream in_file;
    // std::string line {};
    
    // in_file.open("poem.txt");
    // if (!in_file) {
    //     std::cout<<"Failed to open file"<<std::endl;
    //     std::exit(1);
    // }

    // char c{};
    // while (in_file.get(c)) {
    //     std::cout<<c;
    // }
    // std::cout<<std::endl;
    
    // in_file.close();
    return 0;
}