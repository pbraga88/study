#include <iostream>
#include <iomanip> // Need to be included for manipulation

void enable_boolalpha() {
    std::cout<<std::boolalpha; // chanfe to state true/false
}

int main() {
    std::cout<<"noboolalpha - default (10 == 10): "<<(10==10)<<std::endl;
    std::cout<<"noboolalpha - default (10 == 20): "<<(10==20)<<std::endl;

    /* Set true/false formatting */
    {
        // std::cout<<std::boolalpha; // chanfe to state true/false
        enable_boolalpha();
        std::cout<<"noboolalpha - default (10 == 10): "<<(10==10)<<std::endl;
        std::cout<<"noboolalpha - default (10 == 20): "<<(10==20)<<std::endl;
    }
    // Settings remain for future cout use
    std::cout<<"noboolalpha - default (10 == 10): "<<(10==10)<<std::endl;
    std::cout<<"noboolalpha - default (10 == 20): "<<(10==20)<<std::endl;

    // Toggle to 0/1
    std::cout<<std::noboolalpha;
    std::cout<<"noboolalpha - default (10 == 10): "<<(10==10)<<std::endl;
    std::cout<<"noboolalpha - default (10 == 20): "<<(10==20)<<std::endl;

    // Set back to true/false using setf method
    std::cout.setf(std::ios::boolalpha);
    std::cout<<"noboolalpha - default (10 == 10): "<<(10==10)<<std::endl;
    std::cout<<"noboolalpha - default (10 == 20): "<<(10==20)<<std::endl;

    // Resets back to default 0/1
    std::cout<<std::resetiosflags(std::ios::boolalpha);
    std::cout<<"noboolalpha - default (10 == 10): "<<(10==10)<<std::endl;
    std::cout<<"noboolalpha - default (10 == 20): "<<(10==20)<<std::endl;

    return 0;
}