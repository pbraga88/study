#include <iostream>
#include <string>
#include <exception>

class DivideByZeroException : public std::exception {
public:
    DivideByZeroException() noexcept = default; // The 'noexcept' keyword indicates the the constructor function is not expected to
                                                // throw any exception. If a function marked with the 'noexcept' keyword, throws an
                                                // exception the program will terminate by calling 'std::terminate()'.
                                                //    
                                                // The 'default' keyword indicates that the compiler should generate
                                                // the default constructor of the class, which will be a constructor with no
                                                // parameters and an empty body
    virtual const char* what() const noexcept {
        return "Illegal: You can't divide by zero";
    }
};

class NegativeValueException : public std::exception {
public:
    NegativeValueException() noexcept = default;

    virtual const char* what() const noexcept {
        return "Illegal: One of your paramteres is negative";
    }
};

double calculate_mpg(int miles, int gallons) {
    if (gallons == 0) {
        throw DivideByZeroException();
    }
    if (miles < 0 || gallons < 0 ) {
        throw NegativeValueException();
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
    catch (DivideByZeroException &exc) {
        std::cerr<<exc.what()<<std::endl;
    }
    catch (NegativeValueException &exc) {
        std::cerr<<exc.what()<<std::endl;
    }
    // catch (...) {
    //     std::cout<<"Not mapped error"<<std::endl;
    // }

    std::cout<<"Bye"<<std::endl;

    return 0;
}