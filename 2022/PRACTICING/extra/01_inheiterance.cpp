#include <string>
#include <iostream>
using namespace std;
class BaseAdder
{
public:
    BaseAdder() {}
    ~BaseAdder() {}
    virtual int add(int iOp1, int iOp2) = 0;
    std::string getName() {return std::string("Arithmetic"); }
    void print(void) {
        cout << "My superclass is: " << getName().c_str() << endl;
        cout << add(10,32) << " " << add(10,3) << " " << add(10,10) << endl;
    }
};
// type your code below this line and...
class Adder:public BaseAdder{
    virtual int add(int iOp1, int iOp2){
        return iOp1+iOp2;
    }
};
// ...above this line
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    Adder X;
    X.print();
    return 0;
}