#include <iostream>

class MyClass {
private:
  int privateMember = 10; // Private member variable

public:
  static int GetPrivateMember() {
    MyClass instance; // Create an instance temporarily
    return instance.privateMember; // Access through the object
  }
};

int main() {
  // MyClass object not required for static method call
  int value = MyClass::GetPrivateMember();
  std::cout << "Value of private member: " << value << std::endl;
  return 0;
}
