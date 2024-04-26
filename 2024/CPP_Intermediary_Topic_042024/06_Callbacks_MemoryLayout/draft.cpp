#include <iostream>
#include <iomanip>

int main() {
    double value = 123.45;

    // Print the value in hexadecimal format
    std::cout << std::hexfloat << value << std::endl;

    // Parse the value in hexadecimal format
    double parsed_value;
    std::cin >> std::hexfloat >> parsed_value;

    std::cout << "Parsed value: " << parsed_value << std::endl;

    return 0;
}
