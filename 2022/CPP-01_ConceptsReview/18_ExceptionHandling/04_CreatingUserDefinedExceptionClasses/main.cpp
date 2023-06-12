#include <iostream>
#include <string>

class DivideByZeroException {
    std::string error_msg {"Sorry, you can't divide by Zero"};
public:
    DivideByZeroException() = default; // The 'default' keyword indicates that the compiler should generate
                                       // the default constructor of the class, which will be a constructor with no
                                       // parameters and an empty body

    void print_error(void) {
        std::cout<<error_msg<<std::endl;
    }
};

class NegativeValueException {
    std::string error_msg {"Sorry, one of your paramteres is negative"};
public:
    NegativeValueException() = default;

    void print_error(void) {
        std::cout<<error_msg<<std::endl;
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
        exc.print_error();
    }
    catch (NegativeValueException &exc) {
        exc.print_error();
    }
    // catch (...) {
    //     std::cout<<"Not mapped error"<<std::endl;
    // }

    std::cout<<"Bye"<<std::endl;

    return 0;
}