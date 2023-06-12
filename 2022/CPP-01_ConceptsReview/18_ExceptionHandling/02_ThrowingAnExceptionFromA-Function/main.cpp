#include <iostream>

double calculate_mpg(int miles, int gallons) {
    if (gallons <= 0 || miles < 0) {
        throw 0;
    }
    return static_cast<double>(miles)/gallons;
}

int main() {
    int miles {};
    int gallons {};
    double miles_per_gallon {};

    std::cout<<"Enter the miles driven:";
    std::cin>>miles;
    std::cout<<"Enter the gallons used:";
    std::cin>>gallons;

    try {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout<<"Result: "<<miles_per_gallon<<std::endl;
    }
    catch (int &any_variable_name) {
        std::cerr<<"Sorry, invalid input values"<<std::endl;
    }
    std::cout<<"Bye"<<std::endl;

    return 0;
}