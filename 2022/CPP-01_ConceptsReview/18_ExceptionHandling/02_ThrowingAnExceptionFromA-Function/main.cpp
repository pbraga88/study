#include <iostream>

int main() {
    int miles {};
    int gallons {};
    double miles_per_gallon {};

    std::cout<<"Enter the miles driven:";
    std::cin>>miles;
    std::cout<<"Enter the gallons used:";
    std::cin>>gallons;

    try {
        if (gallons == 0) {
            /* Throw by Value and Catch by reference */
            throw 0; //Throw an integer. Can be any value
            // throw 1234567; //eg
        }
        miles_per_gallon = static_cast<double>(miles)/gallons;
        std::cout<<"Result: "<<miles_per_gallon<<std::endl;
    }
    catch (int &any_variable_name) {
        std::cerr<<"Sorry, you can't divide by zero"<<std::endl;
    }
    std::cout<<"Bye"<<std::endl;

    return 0;
}