#include <iostream>
#include <fstream>
#include <string>

int main() {
    // std::ofstream out_file("output.txt");
    std::ofstream out_file("output.txt", std::ios::app); //Appends to the existing file
    if (!out_file) {
        std::cout<<"Error creating the file"<<std::endl;
        exit(1);
    }

    std::string line;
    std::cout<<"Enter something: ";
    std::getline(std::cin, line);

    out_file<<line<<std::endl;

    out_file.close();

    return 0;
}