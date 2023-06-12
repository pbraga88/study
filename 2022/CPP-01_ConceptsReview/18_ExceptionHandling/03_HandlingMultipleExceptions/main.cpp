#include <iostream>
#include <string>

double calculate_mpg(int miles, int gallons) {
    if (gallons == 0) {
        throw 0;
    }
    if (miles < 0 || gallons < 0 ) {
        throw std::string{"Negative value error"};
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
        std::cerr<<"Sorry, you can't divide by Zero"<<std::endl;
    }
    catch (std::string &str_error) {
        std::cout<<str_error<<std::endl;
    }
    catch (...) {
        std::cout<<"Not mapped error"<<std::endl;
    }

    std::cout<<"Bye"<<std::endl;

    return 0;
}